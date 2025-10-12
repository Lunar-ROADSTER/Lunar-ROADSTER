#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <sensor_msgs/point_cloud2_iterator.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/conversions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/common/eigen.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/integral_image_normal.h>

#include <Eigen/Dense>
#include <cmath>
#include <limits>

class ValidationNode : public rclcpp::Node {
public:
  ValidationNode() : Node("validation_node") {
    radius_ = this->declare_parameter("neighbor_radius", 0.2);  // [m]
    min_neighbors_ = this->declare_parameter("min_neighbors", 10);

    sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
      "mapping/transformed_pointcloud", rclcpp::SensorDataQoS(),
      std::bind(&ValidationNode::cloudCallback, this, std::placeholders::_1));

    pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
      "/validation/elevation_data", 10);

    RCLCPP_INFO(this->get_logger(),
                "validation_node_pc_gradient: subscribed to mapping/transformed_pointcloud");
  }

private:

void cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
  // --- Tunables (consider promoting to ROS params) ---
  constexpr float voxel_leaf_m          = 0.05f;   // 5 cm
  constexpr int   knn_normals           = 20;      // K for normals
  constexpr float max_keep_slope_deg    = 60.0f;   // discard "walls" above this slope
  constexpr float wall_jump_thresh_m    = 0.25f;   // >= 25 cm jump -> treat as wall

  // Smoothing knobs (stronger smoothing)
  constexpr int   Ksmooth1              = 32;      // 1st pass KNN
  constexpr int   Ksmooth2              = 16;      // 2nd pass KNN (optional)
  constexpr bool  do_second_pass        = false;

  // Bilateral weights: spatial + range (slope) domains
  constexpr float sigma_spatial_m       = 0.10f;   // ~10 cm spatial scale
  constexpr float sigma_slope_deg       = 5.0f;    // slope similarity scale (deg)
  // ---------------------------------------------------

  // Convert to PCL
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
  pcl::fromROSMsg(*msg, *cloud);
  if (cloud->empty()) return;

  // 1) Voxel downsample (unorganized)
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ds(new pcl::PointCloud<pcl::PointXYZ>());
  pcl::VoxelGrid<pcl::PointXYZ> vg;
  vg.setInputCloud(cloud);
  vg.setLeafSize(voxel_leaf_m, voxel_leaf_m, voxel_leaf_m);
  vg.filter(*cloud_ds);
  if (cloud_ds->empty()) return;

  // 2) OMP normals on downsampled cloud
  pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
  ne.setNumberOfThreads(8);
  ne.setInputCloud(cloud_ds);
  auto kdtree_normals = std::make_shared<pcl::search::KdTree<pcl::PointXYZ>>();
  ne.setSearchMethod(kdtree_normals);
  ne.setKSearch(knn_normals);

  pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>());
  ne.compute(*normals);

  // 3) Per-point slope (deg) + initial "wall" mask (verticality)
  const size_t N = cloud_ds->size();
  std::vector<float> slope(N, std::numeric_limits<float>::quiet_NaN());
  std::vector<uint8_t> is_wall(N, 0);
  for (size_t i = 0; i < N; ++i) {
    const auto &nr = (*normals)[i];
    if (!std::isfinite(nr.normal_z)) continue;
    const float nz = std::max(-1.0f, std::min(1.0f, nr.normal_z)); // clamp for acos
    const float deg = std::acos(std::fabs(nz)) * 180.0f / static_cast<float>(M_PI);
    slope[i] = deg;
    if (deg > max_keep_slope_deg) is_wall[i] = 1;  // too steep ? mark as wall
  }

  // 4) Single KdTree for smoothing + jump checks
  pcl::search::KdTree<pcl::PointXYZ> kdt;
  kdt.setInputCloud(cloud_ds);
  std::vector<int>   nn; nn.reserve(std::max({Ksmooth1, Ksmooth2, knn_normals}) + 8);
  std::vector<float> dd; dd.reserve(nn.capacity());

  auto bilateral_pass = [&](const std::vector<float>& in_slope,
                            std::vector<float>& out_slope,
                            int Ksmooth) {
    out_slope.assign(N, std::numeric_limits<float>::quiet_NaN());

    const float twoSigmaS2 = 2.0f * sigma_spatial_m * sigma_spatial_m;
    const float twoSigmaR2 = 2.0f * sigma_slope_deg * sigma_slope_deg;

    for (size_t i = 0; i < N; ++i) {
      if (is_wall[i]) continue; // keep walls filtered
      const auto &p = cloud_ds->points[i];
      const float si = in_slope[i];
      if (!std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z) || !std::isfinite(si))
        continue;

      nn.clear(); dd.clear();
      if (kdt.nearestKSearch(p, Ksmooth, nn, dd) <= 0) continue;

      // Jump test: if any neighbor has |?z| > threshold, mark this point as wall and skip
      bool jumped = false;
      for (int id : nn) {
        const auto &q = cloud_ds->points[static_cast<size_t>(id)];
        if (!std::isfinite(q.z)) continue;
        if (std::fabs(q.z - p.z) > wall_jump_thresh_m) { jumped = true; break; }
      }
      if (jumped) { is_wall[i] = 1; continue; }

      double wsum = 0.0, ssum = 0.0;
      for (size_t k = 0; k < nn.size(); ++k) {
        const size_t j = static_cast<size_t>(nn[k]);
        if (is_wall[j]) continue;
        const float sj = in_slope[j];
        if (!std::isfinite(sj)) continue;

        // dd[k] from KdTree is squared distance; take sqrt once.
        const float dist = std::sqrt(dd[k]);
        const float ds   = dist;
        const float dr   = std::fabs(sj - si);  // slope range difference (deg)

        const double wg = std::exp(-(ds*ds)/twoSigmaS2) * std::exp(-(dr*dr)/twoSigmaR2);
        wsum += wg;
        ssum += wg * static_cast<double>(sj);
      }
      if (wsum > 0.0) out_slope[i] = static_cast<float>(ssum / wsum);
    }
  };

  // 5) Strong smoothing: 1st bilateral pass (+ optional 2nd pass)
  std::vector<float> slope_sm1, slope_sm2;
  bilateral_pass(slope, slope_sm1, Ksmooth1);
  const std::vector<float>& slope_final = [&]()->const std::vector<float>& {
    if (do_second_pass) {
      bilateral_pass(slope_sm1, slope_sm2, Ksmooth2);
      return slope_sm2;
    }
    return slope_sm1;
  }();

  // 6) Stats over smoothed slopes (skip walls/NaNs)
  double sum = 0.0, sse = 0.0, max_deg = 0.0; int count = 0;
  for (size_t i = 0; i < N; ++i) {
    if (is_wall[i]) continue;
    const float v = slope_final[i];
    if (!std::isfinite(v)) continue;
    sum += v; sse += static_cast<double>(v) * v;
    if (v > max_deg) max_deg = v;
    ++count;
  }

  // Fallback: if nothing after smoothing, try raw (still excluding walls)
  if (count == 0) {
    for (size_t i = 0; i < N; ++i) {
      if (is_wall[i]) continue;
      const float v = slope[i];
      if (!std::isfinite(v)) continue;
      sum += v; sse += static_cast<double>(v) * v;
      if (v > max_deg) max_deg = v;
      ++count;
    }
    if (count == 0) {
      RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                           "No finite non-wall slope values (raw or smoothed).");
      return;
    }
  }

  const double mean_deg = sum / static_cast<double>(count);
  const double rmse_deg = std::sqrt(sse / static_cast<double>(count));
  const double out_max_minus_mean = max_deg - mean_deg;

  // 7) Publish and log
  std_msgs::msg::Float64MultiArray out;
  out.data = {mean_deg, rmse_deg, out_max_minus_mean};
  pub_->publish(out);

  RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
      "Bilateral-smoothed slope (no-walls): mean=%.2f  RMSE=%.2f  (max-mean)=%.2f  (pts=%d)",
      mean_deg, rmse_deg, out_max_minus_mean, count);
}




// void cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
//   // --- Tunables (you can promote these to ROS params later) ---
//   constexpr float voxel_leaf_m          = 0.05f;   // 5 cm
//   constexpr int   knn_normals           = 20;      // K for normals
//   constexpr int   knn_smooth            = 16;      // K for smoothing
//   constexpr float max_keep_slope_deg    = 20.0f;   // discard "walls" above this slope
//   constexpr float wall_jump_thresh_m    = 0.05f;   // >= 25 cm jump -> treat as wall
//   // ------------------------------------------------------------

//   // Convert to PCL
//   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
//   pcl::fromROSMsg(*msg, *cloud);
//   if (cloud->empty()) return;

//   // 1) Voxel downsample (unorganized)
//   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ds(new pcl::PointCloud<pcl::PointXYZ>());
//   pcl::VoxelGrid<pcl::PointXYZ> vg;
//   vg.setInputCloud(cloud);
//   vg.setLeafSize(voxel_leaf_m, voxel_leaf_m, voxel_leaf_m);
//   vg.filter(*cloud_ds);
//   if (cloud_ds->empty()) return;

//   // 2) OMP normals on downsampled cloud
//   pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
//   ne.setNumberOfThreads(8);
//   ne.setInputCloud(cloud_ds);
//   auto kdtree_normals = std::make_shared<pcl::search::KdTree<pcl::PointXYZ>>();
//   ne.setSearchMethod(kdtree_normals);
//   ne.setKSearch(knn_normals);

//   pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>());
//   ne.compute(*normals);

//   // 3) Per-point slope (deg) and initial "wall" mask via verticality
//   const size_t N = cloud_ds->size();
//   std::vector<float> slope(N, std::numeric_limits<float>::quiet_NaN());
//   std::vector<uint8_t> is_wall(N, 0);
//   for (size_t i = 0; i < N; ++i) {
//     const auto &nr = (*normals)[i];
//     if (!std::isfinite(nr.normal_z)) continue;
//     const float nz = std::max(-1.0f, std::min(1.0f, nr.normal_z)); // clamp for acos
//     const float deg = std::acos(std::fabs(nz)) * 180.0f / static_cast<float>(M_PI);
//     slope[i] = deg;
//     if (deg > max_keep_slope_deg) is_wall[i] = 1;  // too steep ? mark as wall
//   }

//   // 4) Build KdTree once for smoothing + jump checks
//   pcl::search::KdTree<pcl::PointXYZ> kdt;
//   kdt.setInputCloud(cloud_ds);
//   std::vector<int>   nn; nn.reserve(std::max(knn_smooth, knn_normals) + 8);
//   std::vector<float> dd; dd.reserve(std::max(knn_smooth, knn_normals) + 8);

//   // 5) KNN smoothing of slope with "wall" suppression
//   std::vector<float> slope_smooth(N, std::numeric_limits<float>::quiet_NaN());
//   for (size_t i = 0; i < N; ++i) {
//     if (is_wall[i]) continue;                         // already a wall by verticality
//     const auto &p = cloud_ds->points[i];
//     if (!std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z)) continue;
//     if (!std::isfinite(slope[i])) continue;

//     nn.clear(); dd.clear();
//     if (kdt.nearestKSearch(p, knn_smooth, nn, dd) <= 0) continue;

//     // Height-jump wall test: if any neighbor differs in z by > threshold, mark as wall
//     bool jumped = false;
//     for (int id : nn) {
//       const auto &q = cloud_ds->points[static_cast<size_t>(id)];
//       if (!std::isfinite(q.z)) continue;
//       if (std::fabs(q.z - p.z) > wall_jump_thresh_m) { jumped = true; break; }
//     }
//     if (jumped) { is_wall[i] = 1; continue; }

//     // Average neighbor slopes (ignore neighbors that are walls or NaN)
//     float sum = 0.f; int cnt = 0;
//     for (int id : nn) {
//       const size_t j = static_cast<size_t>(id);
//       if (is_wall[j]) continue;
//       const float sj = slope[j];
//       if (std::isfinite(sj)) { sum += sj; ++cnt; }
//     }
//     if (cnt > 0) slope_smooth[i] = sum / static_cast<float>(cnt);
//   }

//   // 6) Stats over smoothed slopes (skip walls/NaNs)
//   double sum = 0.0, sse = 0.0, max_deg = 0.0; int count = 0;
//   for (size_t i = 0; i < N; ++i) {
//     if (is_wall[i]) continue;
//     const float v = slope_smooth[i];
//     if (!std::isfinite(v)) continue;
//     sum += v; sse += static_cast<double>(v) * v;
//     if (v > max_deg) max_deg = v;
//     ++count;
//   }

//   // Fallback: if nothing after smoothing, try raw (still excluding walls)
//   if (count == 0) {
//     for (size_t i = 0; i < N; ++i) {
//       if (is_wall[i]) continue;
//       const float v = slope[i];
//       if (!std::isfinite(v)) continue;
//       sum += v; sse += static_cast<double>(v) * v;
//       if (v > max_deg) max_deg = v;
//       ++count;
//     }
//     if (count == 0) {
//       RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
//                            "No finite non-wall slope values (raw or smoothed).");
//       return;
//     }
//   }

//   const double mean_deg = sum / static_cast<double>(count);
//   const double rmse_deg = std::sqrt(sse / static_cast<double>(count));
//   const double out_max_minus_mean = max_deg - mean_deg; // keep your original output shape

//   // 7) Publish and log
//   std_msgs::msg::Float64MultiArray out;
//   out.data = {mean_deg, rmse_deg, out_max_minus_mean};
//   pub_->publish(out);

//   RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
//       "Smoothed slope (no-walls): mean=%.2f  RMSE=%.2f  (max-mean)=%.2f  (pts=%d)",
//       mean_deg, rmse_deg, out_max_minus_mean, count);
// }


// void cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
//   // Convert to PCL
//   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
//   pcl::fromROSMsg(*msg, *cloud);
//   if (cloud->empty()) return;

//   // 1) Voxel downsample (keeps things fast; cloud becomes unorganized)
//   pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ds(new pcl::PointCloud<pcl::PointXYZ>());
//   pcl::VoxelGrid<pcl::PointXYZ> vg;
//   vg.setInputCloud(cloud);
//   vg.setLeafSize(0.05f, 0.05f, 0.05f);  // 5 cm (tune)
//   vg.filter(*cloud_ds);
//   if (cloud_ds->empty()) return;

//   // 2) OMP normals on downsampled cloud (KNN=20 by default)
//   pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
//   ne.setNumberOfThreads(8);  // tune for your Orin
//   ne.setInputCloud(cloud_ds);
//   auto kdtree_ptr = std::make_shared<pcl::search::KdTree<pcl::PointXYZ>>();
//   ne.setSearchMethod(kdtree_ptr);
//   ne.setKSearch(20);

//   pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>());
//   ne.compute(*normals);

//   // 3) Per-point slope (degrees) from normals
//   const size_t N = cloud_ds->size();
//   std::vector<float> slope(N, std::numeric_limits<float>::quiet_NaN());
//   for (size_t i = 0; i < N; ++i) {
//     const auto &nr = (*normals)[i];
//     if (!std::isfinite(nr.normal_z)) continue;
//     const float nz = std::max(-1.0f, std::min(1.0f, nr.normal_z));  // clamp
//     slope[i] = std::acos(std::fabs(nz)) * 180.0f / static_cast<float>(M_PI);
//   }

//   // 4) KNN smoothing of slope in 3D (unorganized cloud)
//   pcl::search::KdTree<pcl::PointXYZ> kdt;
//   kdt.setInputCloud(cloud_ds);
//   std::vector<int>    nn; nn.reserve(32);
//   std::vector<float>  dd; dd.reserve(32);

//   std::vector<float> slope_smooth(N, std::numeric_limits<float>::quiet_NaN());
//   const int Ksmooth = 16;  // tune 8?32

//   for (size_t i = 0; i < N; ++i) {
//     const auto &p = cloud_ds->points[i];
//     if (!std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z)) continue;
//     if (!std::isfinite(slope[i])) continue;

//     nn.clear(); dd.clear();
//     if (kdt.nearestKSearch(p, Ksmooth, nn, dd) <= 0) continue;

//     float s = 0.f; int c = 0;
//     for (int id : nn) {
//       const float si = slope[static_cast<size_t>(id)];
//       if (std::isfinite(si)) { s += si; ++c; }
//     }
//     if (c > 0) slope_smooth[i] = s / static_cast<float>(c);
//   }

//   // 5) Stats over smoothed slope
//   double sum = 0.0, sse = 0.0, max_deg = 0.0; int count = 0;
//   for (size_t i = 0; i < N; ++i) {
//     const float v = slope_smooth[i];
//     if (!std::isfinite(v)) continue;
//     sum += v;
//     sse += static_cast<double>(v) * v;
//     if (v > max_deg) max_deg = v;
//     ++count;
//   }

//   // Fallback: if smoothing produced no finite values, compute stats over raw slope
//   if (count == 0) {
//     for (size_t i = 0; i < N; ++i) {
//       const float v = slope[i];
//       if (!std::isfinite(v)) continue;
//       sum += v; sse += static_cast<double>(v) * v; if (v > max_deg) max_deg = v; ++count;
//     }
//     if (count == 0) {
//       RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
//                            "No finite slope values (raw or smoothed).");
//       return;
//     }
//   }

//   const double mean_deg = sum / static_cast<double>(count);
//   const double rmse_deg = std::sqrt(sse / static_cast<double>(count));
//   const double out_max_deg = max_deg - mean_deg;

//   // 6) Publish and log
//   std_msgs::msg::Float64MultiArray out;
//   out.data = {mean_deg, rmse_deg, out_max_deg};
//   pub_->publish(out);

//   RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 1000,
//       "Smoothed slope (deg): mean=%.2f  RMSE=%.2f  max=%.2f  (pts=%d)",
//       mean_deg, rmse_deg, out_max_deg, count);
// }


  // parameters
  double radius_;
  int min_neighbors_;

  // ROS
  rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr sub_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pub_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ValidationNode>());
  rclcpp::shutdown();
  return 0;
}
