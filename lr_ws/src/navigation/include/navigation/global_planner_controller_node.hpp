#ifndef GLOBAL_PLANNER_CONTROLLER_NODE_HPP_
#define GLOBAL_PLANNER_CONTROLLER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp" // <<< ADDED for Action Server
#include "nav_msgs/msg/path.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"

#include "lr_msgs/action/follow_path.hpp"

#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <mutex>

namespace lr_global_planner_controller
{

class GlobalPlannerController : public rclcpp::Node
{
public:
    using FollowPath = lr_msgs::action::FollowPath;
    using GoalHandleFollowPath = rclcpp_action::ServerGoalHandle<FollowPath>;

    explicit GlobalPlannerController(const rclcpp::NodeOptions & options);

private:
    // Callbacks
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

    /**
     * @brief Callback to decide if a new goal should be accepted.
     */
    rclcpp_action::GoalResponse handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const FollowPath::Goal> goal);
    
    /**
     * @brief Callback to handle a request to cancel the current goal.
     */
    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<GoalHandleFollowPath> goal_handle);
    
    /**
     * @brief Callback that runs when a new goal is accepted.
     */
    void handle_accepted(
        const std::shared_ptr<GoalHandleFollowPath> goal_handle);

    // Core Pure Pursuit Logic
    void executeController();

    // Helper functions
    geometry_msgs::msg::PoseStamped findTargetPoint();
    double calculateDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2);
    
    // Declaration for the visualization function
    void publishTargetPointMarker(const geometry_msgs::msg::PoseStamped& target_point);
    
    // Subscribers
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;

    // Publishers
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr target_point_pub_;

    // Action Server and goal handle members
    rclcpp_action::Server<FollowPath>::SharedPtr action_server_;
    std::shared_ptr<GoalHandleFollowPath> current_goal_handle_;
    std::mutex goal_handle_mutex_; // Protects access to the goal handle

    // TF
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    // Timer
    rclcpp::TimerBase::SharedPtr controller_timer_;

    // State variables
    nav_msgs::msg::Path current_path_;
    nav_msgs::msg::Odometry current_odometry_;
    bool odom_received_{false};

    // Parameters
    double lookahead_distance_;
    double desired_linear_velocity_;
    double max_angular_velocity_;
    double goal_tolerance_;
    std::string robot_frame_;
    std::string global_frame_;
};

} // namespace lr_global_planner_controller

#endif // GLOBAL_PLANNER_CONTROLLER_NODE_HPP_
