#include "navigation/global_planner_controller_node.hpp"
#include <algorithm>
#include <chrono> // Required for std::chrono literals
#include <vector> // Required for std::vector

// New include for visualization markers
#include "visualization_msgs/msg/marker.hpp"

// This header is needed for tf2::TimePointZero
#include "tf2/time.h"

namespace lr_global_planner_controller
{

GlobalPlannerController::GlobalPlannerController(const rclcpp::NodeOptions & options)
: Node("global_planner_controller", options)
{
    // Declare and retrieve parameters from the configuration file
    this->declare_parameter<double>("lookahead_distance", 0.5);
    this->declare_parameter<double>("desired_linear_velocity", 5.0);
    this->declare_parameter<double>("max_angular_velocity", 3.0);
    this->declare_parameter<double>("goal_tolerance", 0.25);
    this->declare_parameter<std::string>("robot_frame", "base_link");
    this->declare_parameter<std::string>("global_frame", "map");

    lookahead_distance_ = this->get_parameter("lookahead_distance").as_double();
    desired_linear_velocity_ = this->get_parameter("desired_linear_velocity").as_double();
    max_angular_velocity_ = this->get_parameter("max_angular_velocity").as_double();
    goal_tolerance_ = this->get_parameter("goal_tolerance").as_double();
    robot_frame_ = this->get_parameter("robot_frame").as_string();
    global_frame_ = this->get_parameter("global_frame").as_string();

    RCLCPP_INFO(this->get_logger(), "Parameters Loaded Successfully:");
    RCLCPP_INFO(this->get_logger(), "  lookahead_distance: %.2f m", lookahead_distance_);
    RCLCPP_INFO(this->get_logger(), "  desired_linear_velocity: %.2f m/s", desired_linear_velocity_);
    RCLCPP_INFO(this->get_logger(), "  max_angular_velocity: %.2f rad/s", max_angular_velocity_);
    RCLCPP_INFO(this->get_logger(), "  goal_tolerance: %.2f m", goal_tolerance_);
    RCLCPP_INFO(this->get_logger(), "  robot_frame: %s", robot_frame_.c_str());
    RCLCPP_INFO(this->get_logger(), "  global_frame: %s", global_frame_.c_str());

    // Initialize TF buffer and listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // Subscribers
    path_sub_ = this->create_subscription<nav_msgs::msg::Path>(
        "/planned_path", 10, std::bind(&GlobalPlannerController::pathCallback, this, std::placeholders::_1));
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odometry/filtered/ekf_global_node", 10, std::bind(&GlobalPlannerController::odomCallback, this, std::placeholders::_1));

    // Publishers
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/command_vel", 10);
    target_point_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("/lookahead_point", 10);


    // Controller Timer to run the main logic loop
    controller_timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100), std::bind(&GlobalPlannerController::executeController, this));
}

void GlobalPlannerController::pathCallback(const nav_msgs::msg::Path::SharedPtr msg)
{
    current_path_ = *msg;
    path_received_ = !msg->poses.empty();
    if (path_received_) {
        RCLCPP_INFO(this->get_logger(), "Received new path with %zu poses.", msg->poses.size());
    }
}

void GlobalPlannerController::odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    current_odometry_ = *msg;
    odom_received_ = true;
}

double GlobalPlannerController::calculateDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2)
{
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

// *** MODIFIED: This function is now more robust ***
geometry_msgs::msg::PoseStamped GlobalPlannerController::findTargetPoint()
{
    // Get the current robot pose
    const auto& robot_pose = current_odometry_.pose.pose;

    // Get the transform from the global frame to the robot's frame
    geometry_msgs::msg::TransformStamped transform_stamped;
    try {
        transform_stamped = tf_buffer_->lookupTransform(
            robot_frame_, global_frame_, tf2::TimePointZero);
    } catch (const tf2::TransformException & ex) {
        RCLCPP_ERROR(
            this->get_logger(), "Could not get transform from %s to %s: %s",
            global_frame_.c_str(), robot_frame_.c_str(), ex.what());
        // As a fallback, return the last point of the path
        return current_path_.poses.back();
    }

    // Find the closest point on the path to the robot to start our search from
    auto closest_it = std::min_element(current_path_.poses.begin(), current_path_.poses.end(),
        [&](const auto& pose1, const auto& pose2) {
            return calculateDistance(robot_pose.position, pose1.pose.position) <
                   calculateDistance(robot_pose.position, pose2.pose.position);
        });

    // Iterate from the closest point to find the lookahead point
    for (auto it = closest_it; it != current_path_.poses.end(); ++it) {
        geometry_msgs::msg::PoseStamped pose_in_robot_frame;
        // Transform the path point to the robot's frame
        tf2::doTransform(*it, pose_in_robot_frame, transform_stamped);

        // Check if the point is in front of the robot
        if (pose_in_robot_frame.pose.position.x > 0) {
            // Check if the point is beyond the lookahead distance
            if (calculateDistance(robot_pose.position, it->pose.position) >= lookahead_distance_) {
                return *it; // This is our target point
            }
        }
    }

    // If no suitable point is found (e.g., near the end of the path), return the last point
    return current_path_.poses.back();
}


void GlobalPlannerController::publishTargetPointMarker(const geometry_msgs::msg::PoseStamped& target_point)
{
    auto marker = visualization_msgs::msg::Marker();
    marker.header.frame_id = global_frame_;
    marker.header.stamp = this->get_clock()->now();
    marker.ns = "lookahead_point";
    marker.id = 0;
    marker.type = visualization_msgs::msg::Marker::SPHERE;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.pose = target_point.pose;
    marker.scale.x = 0.3; // 30 cm diameter sphere
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;
    marker.color.a = 1.0; // Don't forget to set the alpha!
    marker.color.r = 0.0;
    marker.color.g = 1.0; // Make it cyan for high visibility
    marker.color.b = 1.0;
    marker.lifetime = rclcpp::Duration::from_seconds(0.5); // Marker lasts for 0.5 seconds

    target_point_pub_->publish(marker);
}


void GlobalPlannerController::executeController()
{
    if (!path_received_ || !odom_received_) {
        return;
    }

    const auto& robot_pose = current_odometry_.pose.pose;
    const auto& goal_pose = current_path_.poses.back().pose;

    if (calculateDistance(robot_pose.position, goal_pose.position) < goal_tolerance_) {
        RCLCPP_INFO(this->get_logger(), "Goal reached!");
        geometry_msgs::msg::Twist stop_cmd;
        stop_cmd.linear.x = 0.0;
        stop_cmd.angular.z = 0.0;
        cmd_vel_pub_->publish(stop_cmd);
        path_received_ = false;
        return;
    }

    geometry_msgs::msg::PoseStamped target_point_map = findTargetPoint();

    publishTargetPointMarker(target_point_map);

    geometry_msgs::msg::PoseStamped target_point_robot;
    try {
        // Explicitly set the timestamp to zero to request the latest transform from TF2.
        target_point_map.header.stamp.sec = 0;
        target_point_map.header.stamp.nanosec = 0;
        
        tf_buffer_->transform(target_point_map, target_point_robot, robot_frame_);

    } catch (const tf2::TransformException & ex) {
        RCLCPP_ERROR(this->get_logger(), "Could not transform target point to %s frame: %s", robot_frame_.c_str(), ex.what());
        return;
    }
    
    // Pure Pursuit lateral error calculation
    double y_lateral_error = target_point_robot.pose.position.y;
    double lookahead_dist_sq = lookahead_distance_ * lookahead_distance_;
    // The curvature is 2*y / L^2, where y is the lateral error and L is the lookahead distance
    double curvature = (2.0 * y_lateral_error) / lookahead_dist_sq;

    // Calculate required angular velocity: v = w * r => w = v / r = v * curvature
    double angular_velocity = curvature / 10.0;

    // Clamp the angular velocity to the maximum allowed value
    double clipped_angular_velocity = std::clamp(
        angular_velocity, -max_angular_velocity_, max_angular_velocity_);

    geometry_msgs::msg::Twist cmd_vel;
    cmd_vel.linear.x = desired_linear_velocity_;
    cmd_vel.angular.z = clipped_angular_velocity;

    cmd_vel_pub_->publish(cmd_vel);
}

} // namespace lr_global_planner_controller