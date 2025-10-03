#ifndef GLOBAL_PLANNER_CONTROLLER_HPP_
#define GLOBAL_PLANNER_CONTROLLER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/path.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

namespace lr_global_planner_controller
{

/**
 * @class GlobalPlannerController
 * @brief A ROS2 node to control a robot along a given path using the Pure Pursuit algorithm.
 */
class GlobalPlannerController : public rclcpp::Node
{
public:
    /**
     * @brief Constructor for the GlobalPlannerController class.
     * @param options
     */
    explicit GlobalPlannerController(const rclcpp::NodeOptions & options);

private:
    // ROS2 Callbacks
    void pathCallback(const nav_msgs::msg::Path::SharedPtr msg);
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

    // Core Pure Pursuit Logic
    void executeController();
    double calculateDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2);
    geometry_msgs::msg::PoseStamped findTargetPoint();

    // ROS2 Subscribers, Publisher, and Timer
    rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr path_sub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::TimerBase::SharedPtr controller_timer_;

    // TF2 for coordinate transformations
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    // State variables
    nav_msgs::msg::Path current_path_;
    nav_msgs::msg::Odometry current_odometry_;
    bool path_received_ = false;
    bool odom_received_ = false;

    // Parameters loaded from the config file
    double lookahead_distance_;
    double desired_linear_velocity_;
    double max_angular_velocity_;
    double goal_tolerance_;
    std::string robot_frame_;
    std::string global_frame_;
};

} // namespace lr_global_planner_controller

#endif // GLOBAL_PLANNER_CONTROLLER_HPP_

