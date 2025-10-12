#ifndef GLOBAL_PLANNER_CONTROLLER_NODE_HPP_
#define GLOBAL_PLANNER_CONTROLLER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/path.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "geometry_msgs/msg/pose_stamped.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"

// *** ADDED: This header provides the required TF2 transform definitions for geometry_msgs ***
#include "tf2_geometry_msgs/tf2_geometry_msgs.hpp"


namespace lr_global_planner_controller
{

class GlobalPlannerController : public rclcpp::Node
{
public:
    explicit GlobalPlannerController(const rclcpp::NodeOptions & options);

private:
    // Callbacks
    void pathCallback(const nav_msgs::msg::Path::SharedPtr msg);
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

    // Main controller logic
    void executeController();

    // Helper functions
    geometry_msgs::msg::PoseStamped findTargetPoint();
    double calculateDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2);
    
    // Declaration for the visualization function
    void publishTargetPointMarker(const geometry_msgs::msg::PoseStamped& target_point);

    // Subscribers
    rclcpp::Subscription<nav_msgs::msg::Path>::SharedPtr path_sub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;

    // Publishers
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr target_point_pub_;

    // TF
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    // Timer
    rclcpp::TimerBase::SharedPtr controller_timer_;

    // State variables
    nav_msgs::msg::Path current_path_;
    nav_msgs::msg::Odometry current_odometry_;
    bool path_received_{false};
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