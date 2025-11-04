/**
 * @file validation_node.cpp
 * @brief Action-based terrain validation: accumulates point clouds, smooths/filters slopes,
 *        streams progress as feedback, and returns a final traversability summary as the action result.
 *
 * This ROS 2 node subscribes to a fused, world-aligned point cloud and (when enabled) performs:
 *  1) Voxel downsampling for computational efficiency.
 *  2) Surface normal estimation (OMP) and per-point slope (deg) from the vertical (z-axis).
 *  3) Wall/edge masking via slope threshold and height-jump checks.
 *  4) One- or two-pass bilateral smoothing in space–range (meters/degrees).
 *  5) Windowed aggregation with trimmed mean (drop lowest/highest values).
 *
 * Processing runs only while `enabled_` is true (toggled by action /validation/run). When a
 * summary is published, the node disables itself, clears accumulators, and waits for the next enable.
 *
 * @version 2.1.1
 * @date 2025-10-22
 *
 * Maintainer: Boxiang (William) Fu  
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /sensing/transformed_pointcloud : [sensor_msgs::msg::PointCloud2] base_link-aligned cloud.
 *
 * Actions:
 * - /validation/run : [lr_msgs::action::RunValidation] Triggers a validation run with feedback/result.
 * 
 * Execution model:
 * - Action name:          /validation/run
 * - Action type:          lr_msgs::action::RunValidation
 * - Single active goal:   New goals are rejected while one is executing.
 * - Start/stop:           Accumulation begins on goal acceptance and ends on success, cancel, or timeout.
 * 
 * Goal fields (overrides; if 0/false, use node params):
 * - average_window : [int] Number of measurements to accumulate before computing the result.
 * - do_second_pass : [bool] Enable the 2nd bilateral smoothing pass.
 * - timeout_sec    : [int] Abort if not finished before this many seconds (0 = no timeout).
 * 
 * Feedback (sent after each processed cloud):
 * - collected               : [int] k out of average_window
 * - current_mean_gradient   : [double] Mean slope (deg) for the latest cloud
 * - current_rmse_gradient   : [double] RMS slope (deg) for the latest cloud
 * - current_max_gradient    : [double] Max slope (deg) for the latest cloud
 * - current_min_z           : [double] Minimum z (m) for the latest cloud
 * - current_max_z           : [double] Maximum z (m) for the latest cloud
 * - current_avg_z           : [double] Average z (m) for the latest cloud
 * 
 * Result (returned on success/abort):
 * - grading_success     : [bool] True if (max_gradient - mean_gradient) <= max_traversal_slope_deg
 * - mean_gradient       : [double] Trimmed mean of smoothed slopes (deg)
 * - rmse_gradient       : [double] Trimmed RMS of smoothed slopes (deg)
 * - max_gradient        : [double] Trimmed maximum of smoothed slopes (deg)
 * - min_z               : [double] Trimmed minimum z (m)
 * - max_z               : [double] Trimmed maximum z (m)
 * - avg_z               : [double] Trimmed average z (m)
 * - max_traversal_slope : [double] (max_gradient - mean_gradient), a conservative margin (deg)
 * - frame_id            : [string] Frame of the analyzed cloud
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
 * 
 * Example (CLI with feedback):
 * ros2 action send_goal /validation/run lr_msgs/action/RunValidation \
 *   '{"average_window": 10, "do_second_pass": true, "timeout_sec": 0}' --feedback
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

    // Subscribers
    pointcloud_sub_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
        "/sensing/transformed_pointcloud",
        rclcpp::SensorDataQoS(),
        std::bind(&ValidationNode::cloudCallback, this, std::placeholders::_1)
    );

    // Action Servers
    action_server_ = rclcpp_action::create_server<RunValidation>(
        this,
        "/validation/run",
        std::bind(&ValidationNode::handleGoal, this, std::placeholders::_1, std::placeholders::_2),
        std::bind(&ValidationNode::handleCancel, this, std::placeholders::_1),
        std::bind(&ValidationNode::handleAccepted, this, std::placeholders::_1)
    );

    // Initialization complete
    RCLCPP_INFO(this->get_logger(), "Validation action server initialized");
}


rclcpp_action::GoalResponse ValidationNode::handleGoal(const rclcpp_action::GoalUUID &, std::shared_ptr<const RunValidation::Goal> goal)
{
    (void)goal;
    std::scoped_lock lk(goal_mutex_);
    if (active_goal_)
    {
        RCLCPP_WARN(this->get_logger(), "Rejecting new goal: another goal is active.");
        return rclcpp_action::GoalResponse::REJECT;
    }
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}


rclcpp_action::CancelResponse ValidationNode::handleCancel(const std::shared_ptr<GoalHandleRV> goal_handle)
{
    std::scoped_lock lk(goal_mutex_);
    if (active_goal_ && goal_handle == active_goal_)
    {
        enabled_ = false;
        resetAccumulators();
        RCLCPP_INFO(this->get_logger(), "Validation goal canceled.");
        return rclcpp_action::CancelResponse::ACCEPT;
    }
    return rclcpp_action::CancelResponse::REJECT;
}


void ValidationNode::handleAccepted(const std::shared_ptr<GoalHandleRV> goal_handle)
{
    std::scoped_lock lk(goal_mutex_);
    active_goal_ = goal_handle;

    const auto &g = *goal_handle->get_goal();
    if (g.average_window > 0)
        average_window_ = g.average_window;
    if (g.do_second_pass)
        do_second_pass_ = g.do_second_pass;

    if (g.timeout_sec > 0)
    {
        timeout_timer_ = this->create_wall_timer(
            std::chrono::seconds(g.timeout_sec),
            [this, gh = goal_handle]()
            {
                std::scoped_lock lk(goal_mutex_);
                if (!active_goal_ || gh != active_goal_)
                    return;
                enabled_ = false;
                resetAccumulators();
                auto res = RunValidation::Result();
                RCLCPP_WARN(this->get_logger(), "Validation timed out.");
                gh->abort(std::make_shared<RunValidation::Result>(res));
                active_goal_.reset();
                timeout_timer_.reset();
            });
    }
    else
    {
        timeout_timer_.reset();
    }

    // Start accumulation
    resetAccumulators();
    enabled_ = true;
    RCLCPP_INFO(this->get_logger(), "Validation goal started (average_window=%d, 2nd_pass=%s, timeout_sec=%d).",
                average_window_, do_second_pass_ ? "true" : "false", g.timeout_sec);
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

    // Compute min/max z and points
    double min_z = std::numeric_limits<double>::infinity();
    double max_z = -std::numeric_limits<double>::infinity();
    pcl::PointXYZ min_pt, max_pt;

    for (size_t i = 0; i < N; ++i)
    {
        if (is_wall[i])
            continue;
        const auto &p = cloud_ds->points[i];
        if (!std::isfinite(p.x) || !std::isfinite(p.y) || !std::isfinite(p.z))
            continue;
        const double z = static_cast<double>(p.z);
        if (z < min_z)
        {
            min_z = z;
            min_pt = p;
        }
        if (z > max_z)
        {
            max_z = z;
            max_pt = p;
        }
    }

    if (!std::isfinite(min_z) || !std::isfinite(max_z))
    {
        RCLCPP_WARN(this->get_logger(), "No valid non-wall points for extrema");
        return;
    }

    curr_min_z_ = min_z;
    curr_max_z_ = max_z;
    curr_min_pt_ = min_pt;
    curr_max_pt_ = max_pt;

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
    const double curr_avg_z = 0.5 * (curr_min_z_ + curr_max_z_);

    // Publish results
    if (count == 0 || !std::isfinite(mean_deg) || !std::isfinite(rmse_deg) || !std::isfinite(max_deg)) {
        RCLCPP_WARN(this->get_logger(), "No valid points for slope statistics");
        return;
    }

    // Send action feedback
    {
        std::scoped_lock lk(goal_mutex_);
        if (active_goal_) {
        auto fb = RunValidation::Feedback();
        fb.collected = ++collected_;
        fb.current_mean_gradient = mean_deg;
        fb.current_rmse_gradient = rmse_deg;
        fb.current_max_gradient  = max_deg;
        fb.current_min_z = curr_min_z_;
        fb.current_max_z = curr_max_z_;
        fb.current_avg_z = curr_avg_z;
        active_goal_->publish_feedback(std::make_shared<RunValidation::Feedback>(fb));
        }
    }

    mean_v_.push_back(mean_deg);
    rmse_v_.push_back(rmse_deg);
    max_v_.push_back(max_deg);
    min_z_v_.push_back(curr_min_z_);
    max_z_v_.push_back(curr_max_z_);

    const bool window_ready = (mean_v_.size() >= static_cast<size_t>(average_window_));
    if (!window_ready) {
        RCLCPP_INFO(this->get_logger(), "Accumulating: %zu/%d",
                    mean_v_.size(), average_window_);
        
        RCLCPP_INFO(this->get_logger(),
                    "Current stats: mean=%.2f deg, rmse=%.2f deg, max=%.2f deg, max_z=%.2f m, min_z=%.2f m avg_z=%.2f m",
                    mean_deg, rmse_deg, max_deg, curr_max_z_, curr_min_z_, curr_avg_z);
        return;
    }

    const double mean_deg_avg = trimmedAvg(mean_v_);
    const double rmse_deg_avg = trimmedAvg(rmse_v_);
    const double max_deg_avg = trimmedAvg(max_v_);
    const double min_z_avg = trimmedAvg(min_z_v_);
    const double max_z_avg = trimmedAvg(max_z_v_);
    const double avg_z_avg = 0.5 * (min_z_avg + max_z_avg);

    const double avg_max_traversal_slope = max_deg_avg - mean_deg_avg;
    const bool avg_grading_success = (avg_max_traversal_slope <= max_traversal_slope_deg_);

    // Send action result
    {
        std::scoped_lock lk(goal_mutex_);
        if (active_goal_)
        {
            
            RunValidation::Result res;
            res.grading_success = avg_grading_success;
            res.mean_gradient = mean_deg_avg;
            res.rmse_gradient = rmse_deg_avg;
            res.max_gradient = max_deg_avg;
            res.min_z = min_z_avg;
            res.max_z = max_z_avg;
            res.avg_z = avg_z_avg;
            res.max_traversal_slope = avg_max_traversal_slope;
            res.frame_id = msg->header.frame_id;
            active_goal_->succeed(std::make_shared<RunValidation::Result>(res));
            
            RCLCPP_INFO(this->get_logger(),
                        "Validation DONE: success=%s mean=%.2f rmse=%.2f max=%.2f max_trav=%.2f min_z=%.2f max_z=%.2f avg_z=%.2f (th=%.2f)",
                        avg_grading_success ? "true" : "false",
                        mean_deg_avg, rmse_deg_avg, max_deg_avg,
                        avg_max_traversal_slope, min_z_avg, max_z_avg, avg_z_avg, max_traversal_slope_deg_);
            active_goal_.reset();
        }
    }
    
    enabled_ = false;
    resetAccumulators();
    timeout_timer_.reset();
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


void ValidationNode::resetAccumulators()
{
    mean_v_.clear();
    rmse_v_.clear();
    max_v_.clear();
    min_z_v_.clear();
    max_z_v_.clear();

    curr_min_z_ = std::numeric_limits<double>::infinity();
    curr_max_z_ = -std::numeric_limits<double>::infinity();
    curr_min_pt_ = {};
    curr_max_pt_ = {};

    collected_ = 0;
}

} // namespace validation
} // namespace lr