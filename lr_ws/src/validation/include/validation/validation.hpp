#ifndef VALIDATION_H
#define VALIDATION_H

#include "rclcpp/rclcpp.hpp"
#include <rclcpp_action/rclcpp_action.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <lr_msgs/msg/validation.hpp>
#include "lr_msgs/action/run_validation.hpp"
#include <memory>
#include <std_msgs/msg/bool.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/search/kdtree.h>
#include <pcl/features/normal_3d_omp.h>

#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <cstdint>
#include <functional>
#include <numeric>

namespace lr{
namespace validation{

using RunValidation = lr_msgs::action::RunValidation;
using GoalHandleRV  = rclcpp_action::ServerGoalHandle<RunValidation>;
    
class ValidationNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_sub_;

        // Action Server
        rclcpp_action::Server<RunValidation>::SharedPtr action_server_;
        std::mutex goal_mutex_;
        std::shared_ptr<GoalHandleRV> active_goal_;
        rclcpp::TimerBase::SharedPtr timeout_timer_;
        int collected_ = 0;

        // Action Callbacks
        rclcpp_action::GoalResponse handleGoal(
            const rclcpp_action::GoalUUID & uuid,
            std::shared_ptr<const RunValidation::Goal> goal);

        rclcpp_action::CancelResponse handleCancel(
            const std::shared_ptr<GoalHandleRV> goal_handle);

        void handleAccepted(const std::shared_ptr<GoalHandleRV> goal_handle);

        // Functions
        void resetAccumulators();
        void cloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg);
        double trimmedAvg(const std::vector<double>& data) const;
        void bilateralSmooth(
            const pcl::PointCloud<pcl::PointXYZ>& cloud,
            const std::vector<float>& in_slope,
            std::vector<float>& out_slope,
            std::vector<uint8_t>& is_wall,
            pcl::search::KdTree<pcl::PointXYZ>& kdt,
            int Ksmooth) const;

        // Variables
        int average_window_;
        int trim_count_;
        bool enabled_ = false;
        double max_traversal_slope_deg_; // Max acceptable traversal slope (degrees)
        
        double voxel_leaf_m_;  // Voxel downsampling leaf size (meters)
        int omp_threads_;     // Threads for NormalEstimationOMP
        int knn_normals_;     // K for normal estimation

        double curr_min_z_{std::numeric_limits<double>::infinity()};
        double curr_max_z_{-std::numeric_limits<double>::infinity()};
        pcl::PointXYZ curr_min_pt_{};
        pcl::PointXYZ curr_max_pt_{};

        double max_keep_slope_deg_;
        double wall_jump_thresh_m_;

        int Ksmooth1_;
        int Ksmooth2_;
        bool do_second_pass_;

        double sigma_spatial_m_; // Spatial Gaussian sigma (meters)
        double sigma_slope_deg_; // Slope Gaussian sigma (degrees)

        std::vector<double> mean_v_;
        std::vector<double> rmse_v_;
        std::vector<double> max_v_;
        std::vector<double> min_z_v_;
        std::vector<double> max_z_v_;

    public:
        // Constructor and destructor
        ValidationNode();
        ~ValidationNode(){};
};  

} // namespace validation
} // namespace lr
#endif