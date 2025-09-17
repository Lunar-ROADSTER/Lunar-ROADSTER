/**
 * TODO
 *
 * ### CHANGED: Instead of RANSAC on 3-point samples, this version fits a single
 * ###          best-fit plane using **all points** from `/mapping/transformed_pointcloud`
 * ###          via least-squares (PCA of covariance). The plane is then used to
 * ###          detrend the elevation map before gradient computations.
 */

 #include "validation/validation.hpp"

 #include <algorithm>    // ### ADDED
 #include <cmath>        // ### ADDED
 #include <limits>       // ### ADDED
 #include <mutex>        // ### ADDED
 #include <Eigen/Dense>  // ### ADDED: Eigen used for PCA plane fit
 
 // ### ADDED: PointCloud2 reading
 #include <sensor_msgs/msg/point_cloud2.hpp>
 #include <sensor_msgs/point_cloud2_iterator.hpp>
 
 namespace lr {
 namespace validation {
 
 /// ### ADDED: tunables / small filters
 static constexpr bool   kDoSmooth3x3         = true;   // small smoothing to reduce speckle
 static constexpr double kWallJumpThreshM     = 0.25;   // treat >=25 cm step as wall/cliff
 static constexpr double kMaxKeepSlopeDeg     = 60.0;   // ignore slopes steeper than this
 static constexpr int    kPCSubsampleStride   = 3;      // use every N-th point when fitting plane (perf)
 
 // ====== ### ADDED: global storage for the fitted plane from point cloud ======
 // Plane eq: A*x + B*y + C*z + D = 0  (normal (A,B,C) unit length)
 namespace {
 std::mutex             g_plane_mtx;
 Eigen::Vector4d        g_plane_ABCD(0.0, 0.0, 1.0, 0.0);  // default: z=0
 bool                   g_plane_ok = false;
 } // anonymous namespace
 // ============================================================================
 
 // ### ADDED: helper to compute z at (x,y) on plane. Returns false if C≈0 (vertical).
 static inline bool planeZatXY(const Eigen::Vector4d& pl, double x, double y, double& z_out) {
   const double C = pl[2];
   if (std::fabs(C) < 1e-10) return false;
   z_out = -(pl[0]*x + pl[1]*y + pl[3]) / C;
   return true;
 }
 
 // ### ADDED: tiny smoothing (ignores NaNs)
 static inline void smooth3x3_inplace(grid_map::GridMap& m, const char* layer) {
   grid_map::Matrix& data = m[layer];
   const grid_map::Matrix copy = data;
   const int rows = static_cast<int>(copy.rows());
   const int cols = static_cast<int>(copy.cols());
   for (int yy = 0; yy < rows; ++yy) {
	 for (int xx = 0; xx < cols; ++xx) {
	   double sum = 0.0, wsum = 0.0;
	   for (int j = -1; j <= 1; ++j) for (int i = -1; i <= 1; ++i) {
		 const int y2 = yy + j, x2 = xx + i;
		 if (y2 < 0 || y2 >= rows || x2 < 0 || x2 >= cols) continue;
		 const float z = copy(y2, x2);
		 if (!std::isfinite(z)) continue;
		 const int w = (i == 0 && j == 0) ? 4 : ((i == 0 || j == 0) ? 2 : 1);
		 sum  += static_cast<double>(w) * z;
		 wsum += static_cast<double>(w);
	   }
	   if (wsum > 0.0) data(yy, xx) = static_cast<float>(sum / wsum);
	 }
   }
 }
 
 // ### ADDED: compute least-squares plane from PointCloud2 via PCA
 static inline bool fitPlaneFromPointCloud2(const sensor_msgs::msg::PointCloud2& cloud,
											Eigen::Vector4d& plane_out,
											int stride = 1) {
   // Welford's online algorithm for mean/covariance
   std::size_t n = 0;
   Eigen::Vector3d mean = Eigen::Vector3d::Zero();
   Eigen::Matrix3d cov  = Eigen::Matrix3d::Zero();
 
   // Expect fields x,y,z (float32)
   if (cloud.height == 0 || cloud.width == 0) return false;
 
   sensor_msgs::PointCloud2ConstIterator<float> it_x(cloud, "x");
   sensor_msgs::PointCloud2ConstIterator<float> it_y(cloud, "y");
   sensor_msgs::PointCloud2ConstIterator<float> it_z(cloud, "z");
 
   std::size_t idx = 0;
   for (; it_x != it_x.end(); ++it_x, ++it_y, ++it_z, ++idx) {
	 if (stride > 1 && (idx % stride) != 0) continue;
	 const float xf = *it_x, yf = *it_y, zf = *it_z;
	 if (!std::isfinite(xf) || !std::isfinite(yf) || !std::isfinite(zf)) continue;
	 const Eigen::Vector3d x(xf, yf, zf);
	 ++n;
	 const Eigen::Vector3d delta  = x - mean;
	 mean += delta / static_cast<double>(n);
	 const Eigen::Vector3d delta2 = x - mean;
	 cov  += delta * delta2.transpose();
   }
 
   if (n < 30) return false;
   cov /= static_cast<double>(std::max<std::size_t>(1, n - 1));
 
   // PCA: normal is eigenvector with smallest eigenvalue
   Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> es(cov);
   if (es.info() != Eigen::Success) return false;
   const Eigen::Vector3d normal = es.eigenvectors().col(0).normalized(); // smallest
 
   Eigen::Vector3d nvec = normal;
   // Prefer upward-pointing normal if possible
   if (nvec.z() < 0.0) nvec = -nvec;
 
   const double D = -nvec.dot(mean);
   plane_out = Eigen::Vector4d(nvec.x(), nvec.y(), nvec.z(), D);
   return std::isfinite(plane_out[0]) && std::isfinite(plane_out[1]) &&
		  std::isfinite(plane_out[2]) && std::isfinite(plane_out[3]);
 }
 
 // ### ADDED: global subscription handle (not in header to keep this a drop-in .cpp change)
 static std::shared_ptr<rclcpp::Subscription<sensor_msgs::msg::PointCloud2>> g_pc_sub;  // NOLINT
 
 ValidationNode::ValidationNode() : Node("validation_node")
 {
   occupancy_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
	   "/mapping/filtered_local_map", 10,
	   std::bind(&ValidationNode::occupancyCallback, this, std::placeholders::_1));
 
   publish_local_map_sub_ = this->create_subscription<std_msgs::msg::Bool>(
	   "/publish_local_map", 10,
	   std::bind(&ValidationNode::publishLocalMapCallback, this, std::placeholders::_1));
 
   grid_map_pub_ = this->create_publisher<grid_map_msgs::msg::GridMap>("/local_grid_map", 100);
 
   elevation_data_pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/validation/elevation_data", 10);
 
   /// ### ADDED: subscribe to the plane-fitting cloud source
   g_pc_sub = this->create_subscription<sensor_msgs::msg::PointCloud2>(
	   "/mapping/transformed_pointcloud",
	   rclcpp::SensorDataQoS(),
	   [this](const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
		 Eigen::Vector4d plane;
		 if (fitPlaneFromPointCloud2(*msg, plane, kPCSubsampleStride)) {
		   std::lock_guard<std::mutex> lk(g_plane_mtx);
		   g_plane_ABCD = plane;
		   g_plane_ok   = true;
		   RCLCPP_DEBUG(this->get_logger(), "Plane updated: A=%.3f B=%.3f C=%.3f D=%.3f",
						plane[0], plane[1], plane[2], plane[3]);
		 } else {
		   std::lock_guard<std::mutex> lk(g_plane_mtx);
		   g_plane_ok = false;
		 }
	   });
 
   RCLCPP_INFO(this->get_logger(), "Validation node initialized (plane from /mapping/transformed_pointcloud)");
 }
 
 void ValidationNode::occupancyCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
 {
   bool publish_grid_map = publish_callback_.exchange(false);
 
   // Convert map from OccupancyGrid format to GridMap format
   const int width      = static_cast<int>(msg->info.width);
   const int height     = static_cast<int>(msg->info.height);
   const double res     = msg->info.resolution;
 
   grid_map::GridMap map({"elevation"});
   map.setFrameId(msg->header.frame_id);
   map.setGeometry(
	   grid_map::Length(width * res, height * res),
	   res,
	   grid_map::Position(
		   msg->info.origin.position.x + width * res / 2.0,
		   msg->info.origin.position.y + height * res / 2.0));
 
   /// ### CHANGED: unknowns as NaN to avoid fake gradients
   map["elevation"].setConstant(std::numeric_limits<float>::quiet_NaN());
 
   for (int y = 0; y < height; ++y) {
	 for (int x = 0; x < width; ++x) {
	   const int idx = x + y * width;
	   const int flipped_x = width  - 1 - x;
	   const int flipped_y = height - 1 - y;
 
	   const int8_t val = msg->data[idx];
	   if (val >= 0) {
		 const float elevation_m = static_cast<float>(val) / 100.0f;
		 map.at("elevation", grid_map::Index(flipped_x, flipped_y)) = elevation_m;
	   }
	 }
   }
 
   if (kDoSmooth3x3) {
	 smooth3x3_inplace(map, "elevation");
   }
 
   // ### CHANGED: use plane from point cloud to build detrended layer
   map.add("elev_detrended");
   map["elev_detrended"].setConstant(std::numeric_limits<float>::quiet_NaN());
 
   Eigen::Vector4d plane_local;
   bool plane_ok_local = false;
   {
	 std::lock_guard<std::mutex> lk(g_plane_mtx);
	 plane_local     = g_plane_ABCD;
	 plane_ok_local  = g_plane_ok;
   }
 
   if (plane_ok_local) {
	 // Fill residuals (z - z_plane(x,y))
	 for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it) {
	   const float z = map.at("elevation", *it);
	   if (!std::isfinite(z)) continue;
	   grid_map::Position pos;
	   map.getPosition(*it, pos);
	   double zpl;
	   if (!planeZatXY(plane_local, pos.x(), pos.y(), zpl)) continue; // skip if plane vertical
	   map.at("elev_detrended", *it) = static_cast<float>(z - zpl);
	 }
   } else {
	 // Fallback: if no plane yet, use raw elevation
	 map["elev_detrended"] = map["elevation"];
   }
 
   if (publish_grid_map) {
	 auto message_ptr = grid_map::GridMapRosConverter::toMessage(map);
	 grid_map_pub_->publish(*message_ptr);
   }
 
   // === Gradients on detrended surface, with wall filtering ===
   double max_gradient_kept = 0.0;
   const double max_keep_slope_rad = kMaxKeepSlopeDeg * M_PI / 180.0;
 
   for (int y = 1; y < height - 1; ++y) {
	 for (int x = 1; x < width - 1; ++x) {
	   const float zL = map.at("elev_detrended", grid_map::Index(x - 1, y));
	   const float zR = map.at("elev_detrended", grid_map::Index(x + 1, y));
	   const float zD = map.at("elev_detrended", grid_map::Index(x, y - 1));
	   const float zU = map.at("elev_detrended", grid_map::Index(x, y + 1));
	   if (!std::isfinite(zL) || !std::isfinite(zR) || !std::isfinite(zD) || !std::isfinite(zU))
		 continue;
 
	   // Wall/Cliff test using original elevation
	   const float oL = map.at("elevation", grid_map::Index(x - 1, y));
	   const float oR = map.at("elevation", grid_map::Index(x + 1, y));
	   const float oD = map.at("elevation", grid_map::Index(x, y - 1));
	   const float oU = map.at("elevation", grid_map::Index(x, y + 1));
	   if (std::isfinite(oL) && std::isfinite(oR) && std::isfinite(oD) && std::isfinite(oU)) {
		 const float max_jump_lr  = std::fabs(oR - oL);
		 const float max_jump_ud  = std::fabs(oU - oD);
		 const float max_jump_mix = std::max(std::fabs(oR - oU), std::fabs(oL - oD));
		 const float max_jump     = std::max(std::max(max_jump_lr, max_jump_ud), max_jump_mix);
		 if (max_jump > static_cast<float>(kWallJumpThreshM)) continue;
	   }
 
	   const float dz_dx = (zR - zL) / static_cast<float>(2.0 * res);
	   const float dz_dy = (zU - zD) / static_cast<float>(2.0 * res);
	   const double grad = std::hypot(dz_dx, dz_dy);
 
	   if (std::atan(grad) > max_keep_slope_rad) continue;
	   if (grad > max_gradient_kept) max_gradient_kept = grad;
	 }
   }
 
   // Slope (degrees) from filtered max gradient
   const double slope_deg = std::atan(max_gradient_kept) * 180.0 / M_PI;
 
   // Stats on detrended surface
   double sum = 0.0, sse = 0.0;
   int count = 0;
   for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it) {
	 const float zr = map.at("elev_detrended", *it);
	 if (!std::isfinite(zr)) continue;
	 sum += zr;
	 ++count;
   }
   double mean = 0.0;
   if (count > 0) mean = sum / static_cast<double>(count);
   for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it) {
	 const float zr = map.at("elev_detrended", *it);
	 if (!std::isfinite(zr)) continue;
	 const double e = zr - mean;
	 sse += e * e;
   }
   double rmse = (count > 0) ? std::sqrt(sse / static_cast<double>(count)) : 0.0;
 
   // To centimeters for output
   mean *= 100.0;
   rmse *= 100.0;
 
   {
	 std::lock_guard<std::mutex> lk(g_plane_mtx);
	 RCLCPP_INFO(this->get_logger(),
				 "Plane %s: A=%.3f B=%.3f C=%.3f D=%.3f | mean(detrended)=%.2f cm, RMSE=%.2f cm, max slope=%.2f deg",
				 g_plane_ok ? "OK" : "N/A",
				 g_plane_ABCD[0], g_plane_ABCD[1], g_plane_ABCD[2], g_plane_ABCD[3],
				 mean, rmse, slope_deg);
   }
 
   std_msgs::msg::Float64MultiArray elevation_msg;
   elevation_msg.data = {mean, rmse, slope_deg};
   elevation_data_pub_->publish(elevation_msg);
 }
 
 void ValidationNode::publishLocalMapCallback(const std_msgs::msg::Bool::SharedPtr msg)
 {
   publish_callback_ = msg->data;
 }
 
 } // namespace validation
 } // namespace lr
 