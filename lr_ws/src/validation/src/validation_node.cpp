/**
 * @file validation_node.cpp
 * @brief Computes terrain slope statistics from point clouds, applies smoothing & trimming,
 *        and publishes a grading/validation summary for traversability.
 *
 * This ROS 2 node subscribes to a fused, world-aligned point cloud and (when enabled) performs:
 *  1) Voxel downsampling for computational efficiency.
 *  2) Surface normal estimation (OMP) and per-point slope (deg) from the vertical (z-axis).
 *  3) Wall/edge masking via slope threshold and height-jump checks.
 *  4) One- or two-pass bilateral smoothing in space–range (meters/degrees).
 *  5) Windowed aggregation with trimmed mean (drop lowest/highest values).
 *
 * After accumulating a window of measurements, it publishes a single summary:
 *  - mean_gradient : Trimmed mean of smoothed slopes (deg).
 *  - rmse_gradient : Trimmed RMS of smoothed slopes (deg).
 *  - max_gradient : Trimmed maximum of smoothed slopes (deg).
 *  - max_traversal_slope : (max_gradient - mean_gradient), a conservative margin (deg).
 *  - grading_success : true if max_traversal_slope <= max_traversal_slope_deg.
 *
 * Processing runs only while `enabled_` is true (toggled by /validation/enable_validation). When a
 * summary is published, the node disables itself, clears accumulators, and waits for the next enable.
 *
 * @version 1.1.0
 * @date 2025-10-13
 *
 * Maintainer: Boxiang (William) Fu  
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /validation/enable_validation : [std_msgs::msg::Bool] Gates processing; true to start accumulation.
 * - /mapping/transformed_pointcloud : [sensor_msgs::msg::PointCloud2] World-aligned (or map-frame) cloud.
 *
 * Publishers:
 * - /validation/elevation_data : [lr_msgs::msg::Validation].
 *
 * Parameters:
 * - average_window          : [int] Number of measurements to accumulate before publishing (default: 10).
 * - trim_count              : [int] Number of low/high samples dropped in trimmed averages (default: 1).
 * - max_traversal_slope_deg : [double] Success threshold for (max - mean) in degrees (default: 5.0).
 * - voxel_leaf_m            : [double] Voxel grid leaf size in meters (default: 0.05).
 * - omp_threads             : [int] Threads for NormalEstimationOMP (default: 8).
 * - knn_normals             : [int] KNN for normal estimation (default: 20).
 * - max_keep_slope_deg      : [double] Points above this slope (deg) are masked as walls (default: 45.0).
 * - wall_jump_thresh_m      : [double] Height jump (m) to mark a local wall/ledge (default: 0.10).
 * - Ksmooth1                : [int] KNN for 1st bilateral smoothing pass (default: 32).
 * - Ksmooth2                : [int] KNN for optional 2nd bilateral pass (default: 16).
 * - do_second_pass          : [bool] Enable the 2nd bilateral pass (default: false).
 * - sigma_spatial_m         : [double] Bilateral spatial sigma (meters) (default: 0.10).
 * - sigma_slope_deg         : [double] Bilateral range sigma (degrees) (default: 5.0).
 */


#include "validation/validation.hpp"
 
namespace lr {
namespace validation {

ValidationNode::ValidationNode() : Node("validation_node")
{
    // Parameters
    this->declare_parameter<int>("average_window", 10);
    this->get_parameter("average_window", average_window_);

    this->declare_parameter<int>("trim_count", 1);
    this->get_parameter("trim_count", trim_count_);

    this->declare_parameter<double>("max_traversal_slope_deg", 5.0);
    this->get_parameter("max_traversal_slope_deg", max_traversal_slope_deg_);

    this->declare_parameter<double>("voxel_leaf_m", 0.05);
    this->get_parameter("voxel_leaf_m", voxel_leaf_m_);

    this->declare_parameter<int>("omp_threads", 8);
    this->get_parameter("omp_threads", omp_threads_);

    this->declare_parameter<int>("knn_normals", 20);
    this->get_parameter("knn_normals", knn_normals_);

    this->declare_parameter<double>("max_keep_slope_deg", 45.0);
    this->get_parameter("max_keep_slope_deg", max_keep_slope_deg_);

    this->declare_parameter<double>("wall_jump_thresh_m", 0.10);
    this->get_parameter("wall_jump_thresh_m", wall_jump_thresh_m_);

    this->declare_parameter<int>("Ksmooth1", 32);
    this->get_parameter("Ksmooth1", Ksmooth1_);

    this->declare_parameter<int>("Ksmooth2", 16);
    this->get_parameter("Ksmooth2", Ksmooth2_);

    this->declare_parameter<bool>("do_second_pass", false);
    this->get_parameter("do_second_pass", do_second_pass_);

    this->declare_parameter<double>("sigma_spatial_m", 0.10);
    this->get_parameter("sigma_spatial_m", sigma_spatial_m_);

    this->declare_parameter<double>("sigma_slope_deg", 5.0);
    this->get_parameter("sigma_slope_deg", sigma_slope_deg_);

    // Publishers
    validation_pub_ = this->create_publisher<lr_msgs::msg::Validation>(
        "/validation/elevation_data", 10);

    // Subscribers
    enable_validation_sub_ = this->create_subscription<std_msgs::msg::Bool>(
        "/validation/enable_validation",
        10,
        std::bind(&ValidationNode::enableCallback, this, std::placeholders::_1)
    );

    pointcloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "/mapping/transformed_pointcloud",
        rclcpp::SensorDataQoS(),
        std::bind(&ValidationNode::cloudCallback, this, std::placeholders::_1)
    );

    // Initialization complete
    RCLCPP_INFO(this->get_logger(), "Validation node initialized");
}


void ValidationNode::enableCallback(const std_msgs::msg::Bool::SharedPtr msg)
{
    enabled_ = msg->data;
    RCLCPP_INFO(this->get_logger(), "Validation enabled: %s", enabled_ ? "true" : "false");
}


void ValidationNode::cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
    if (!enabled_) {
        // Debugging
        // RCLCPP_INFO(this->get_logger(), "Validation is disabled; skipping point cloud processing.");
        return;
    }

    // Convert to PCL
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());
    pcl::fromROSMsg(*msg, *cloud);
    if (cloud->empty()) return;

    // Voxel downsample
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ds(new pcl::PointCloud<pcl::PointXYZ>());
    pcl::VoxelGrid<pcl::PointXYZ> vg;
    vg.setInputCloud(cloud);
    vg.setLeafSize(voxel_leaf_m_, voxel_leaf_m_, voxel_leaf_m_);
    vg.filter(*cloud_ds);
    if (cloud_ds->empty()) return;

    // OMP normals on downsampled cloud
    pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
    ne.setNumberOfThreads(omp_threads_);
    ne.setInputCloud(cloud_ds);
    auto kdtree_normals = std::make_shared<pcl::search::KdTree<pcl::PointXYZ>>();
    ne.setSearchMethod(kdtree_normals);
    ne.setKSearch(knn_normals_);

    pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>());
    ne.compute(*normals);

    // Per-point slope and wall mask
    const size_t N = cloud_ds->size();
    std::vector<float> slope(N, std::numeric_limits<float>::quiet_NaN());
    std::vector<uint8_t> is_wall(N, 0);

    for (size_t i = 0; i < N; ++i) {
        const auto &n = normals->points[i];
        if (!std::isfinite(n.normal_x) || !std::isfinite(n.normal_y) || !std::isfinite(n.normal_z))
            continue;

        // Slope is angle between normal and vertical z-axis
        const float nz = std::max(-1.0f, std::min(1.0f, n.normal_z));
        const float deg = std::acos(std::fabs(nz)) * 180.0f / static_cast<float>(M_PI);
        slope[i] = deg;
        if (deg > max_keep_slope_deg_) is_wall[i] = 1;
    }

    // KdTree for neighbor searches
    pcl::search::KdTree<pcl::PointXYZ> kdt;
    kdt.setInputCloud(cloud_ds);
    std::vector<int> nn; nn.reserve(std::max({Ksmooth1_, Ksmooth2_, knn_normals_}) + 8);
    std::vector<float> dd; dd.reserve(nn.capacity());

    // Strong smoothing: 1st bilateral pass (+ optional 2nd pass)
    std::vector<float> slope_sm1, slope_sm2;
    std::vector<float> slope_final;

    bilateralSmooth(*cloud_ds, slope, slope_sm1, is_wall, kdt, Ksmooth1_);
    if (do_second_pass_) {
        bilateralSmooth(*cloud_ds, slope_sm1, slope_sm2, is_wall, kdt, Ksmooth2_);
        slope_final = slope_sm2;
    } else {
        slope_final = slope_sm1;
    }

    // Compute statistics
    double sum = 0.0, sse = 0.0, max_deg = 0.0; int count = 0;
    for (size_t i = 0; i < N; ++i) {
        const float si = slope_final[i];
        if (!std::isfinite(si) || is_wall[i]) continue;
        sum += static_cast<double>(si);
        sse += static_cast<double>(si) * static_cast<double>(si);
        if (si > max_deg) max_deg = si;
        count++;
    }

    const double mean_deg = sum / static_cast<double>(count);
    const double rmse_deg = std::sqrt(sse / static_cast<double>(count));

    // Publish results
    if (count == 0 || !std::isfinite(mean_deg) || !std::isfinite(rmse_deg) || !std::isfinite(max_deg)) {
        RCLCPP_WARN(this->get_logger(), "No valid points for slope statistics");
        return;
    }

    mean_v_.push_back(mean_deg);
    rmse_v_.push_back(rmse_deg);
    max_v_.push_back(max_deg);

    const bool window_ready = (mean_v_.size() >= static_cast<size_t>(average_window_));
    if (!window_ready) {
        RCLCPP_INFO(this->get_logger(), "Accumulating: %zu/%d",
                    mean_v_.size(), average_window_);
        
        // Debugging
        // RCLCPP_INFO(this->get_logger(),
        //             "Current stats: mean=%.2f deg, rmse=%.2f deg, max=%.2f deg",
        //             mean_deg, rmse_deg, max_deg);
        return;
    }

    const double mean_deg_avg = trimmedAvg(mean_v_);
    const double rmse_deg_avg = trimmedAvg(rmse_v_);
    const double max_deg_avg = trimmedAvg(max_v_);

    const double avg_max_traversal_slope = max_deg_avg - mean_deg_avg;
    const bool avg_grading_success = (avg_max_traversal_slope <= max_traversal_slope_deg_);

    lr_msgs::msg::Validation out_msg;

    out_msg.header.stamp = this->get_clock()->now();
    out_msg.header.frame_id = msg->header.frame_id;

    out_msg.grading_success = avg_grading_success;
    out_msg.mean_gradient = mean_deg_avg;
    out_msg.rmse_gradient = rmse_deg_avg;
    out_msg.max_gradient = max_deg_avg;
    out_msg.max_traversal_slope = avg_max_traversal_slope;

    validation_pub_->publish(out_msg);

    RCLCPP_INFO(this->get_logger(),
                "Validation: success=%s, mean=%.2f deg, rmse=%.2f deg, max=%.2f deg, max_traversal=%.2f deg (thresh=%.2f deg)",
                avg_grading_success ? "true" : "false",
                mean_deg_avg,
                rmse_deg_avg,
                max_deg_avg,
                avg_max_traversal_slope,
                max_traversal_slope_deg_);
    
    enabled_ = false;
    mean_v_.clear();
    rmse_v_.clear();
    max_v_.clear();
}


double ValidationNode::trimmedAvg(const std::vector<double>& data) const
{
    if (data.empty()) return std::numeric_limits<double>::quiet_NaN();

    // If too few points, just return the mean
    if (data.size() < static_cast<size_t>(2 * trim_count_ + 1)) {
        return std::accumulate(data.begin(), data.end(), 0.0) / static_cast<double>(data.size());
    }

    // Sort and remove min/max
    std::vector<double> sorted = data;
    std::sort(sorted.begin(), sorted.end());

    const size_t start = trim_count_;
    const size_t end = sorted.size() - trim_count_;
    const double sum = std::accumulate(sorted.begin() + start, sorted.begin() + end, 0.0);
    return sum / static_cast<double>(sorted.size() - 2 * trim_count_);
}


void ValidationNode::bilateralSmooth(
    const pcl::PointCloud<pcl::PointXYZ> &cloud,
    const std::vector<float> &in_slope,
    std::vector<float> &out_slope,
    std::vector<uint8_t> &is_wall,
    pcl::search::KdTree<pcl::PointXYZ> &kdt,
    int Ksmooth) const
{

    const size_t N = cloud.size();
    out_slope.assign(N, std::numeric_limits<float>::quiet_NaN());

    // Precompute constants
    const float twoSigmaS2 = static_cast<float>(2.0 * sigma_spatial_m_ * sigma_spatial_m_);
    const float twoSigmaR2 = static_cast<float>(2.0 * sigma_slope_deg_ * sigma_slope_deg_);

    std::vector<int> nn;
    nn.reserve(static_cast<size_t>(Ksmooth) + 8);
    std::vector<float> dd;
    dd.reserve(nn.capacity());

    for (size_t i = 0; i < N; ++i)
    {
        if (is_wall[i])
            continue;

        const auto &p = cloud.points[i];
        const float si = in_slope[i];

        if (!std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z) || !std::isfinite(si))
            continue;

        // Nearest neighbor search
        nn.clear();
        dd.clear();
        if (kdt.nearestKSearch(p, Ksmooth, nn, dd) <= 0)
            continue;

        // Height jump check
        bool jumped = false;
        for (int id : nn)
        {
            const auto &q = cloud.points[static_cast<size_t>(id)];
            if (!std::isfinite(q.z))
                continue;
            if (std::fabs(q.z - p.z) > wall_jump_thresh_m_)
            {
                jumped = true;
                break;
            }
        }

        if (jumped)
        {
            is_wall[i] = 1;
            continue;
        }

        // Bilateral filter
        double wsum = 0.0, ssum = 0.0;
        for (size_t k = 0; k < nn.size(); ++k)
        {
            const size_t j = static_cast<size_t>(nn[k]);
            if (is_wall[j])
                continue;

            const float sj = in_slope[j];
            if (!std::isfinite(sj))
                continue;

            const float dist = std::sqrt(dd[k]);
            const float ds = dist; // spatial distance (m)
            const float dr = std::fabs(sj - si); // slope range difference (deg)

            // Gaussian weighting
            const double wg = std::exp(-(ds * ds) / twoSigmaS2) * std::exp(-(dr * dr) / twoSigmaR2);
            wsum += wg;
            ssum += wg * static_cast<double>(sj);
        }

        if (wsum > 0.0)
            out_slope[i] = static_cast<float>(ssum / wsum);
    }
}

} // namespace validation
} // namespace lr