#include "navigation/global_planner_controller_node.hpp"
#include <algorithm>
#include <chrono>
#include <vector>
#include <functional>
#include "visualization_msgs/msg/marker.hpp"
#include "tf2/time.h"

namespace lr_global_planner_controller
{

using namespace std::placeholders;
using namespace std::chrono_literals;

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
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odometry/filtered/ekf_global_node", 10, std::bind(&GlobalPlannerController::odomCallback, this, _1));

    // Publishers
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/command_vel", 10);
    target_point_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("/lookahead_point", 10);

    // Create the Action Server
    this->action_server_ = rclcpp_action::create_server<FollowPath>(
        this,
        "follow_path",
        std::bind(&GlobalPlannerController::handle_goal, this, _1, _2),
        std::bind(&GlobalPlannerController::handle_cancel, this, _1),
        std::bind(&GlobalPlannerController::handle_accepted, this, _1));
    
    RCLCPP_INFO(this->get_logger(), "Action server 'follow_path' started and ready for goals.");


    // Controller Timer to run the main logic loop
    controller_timer_ = this->create_wall_timer(
        100ms, std::bind(&GlobalPlannerController::executeController, this));
}

void GlobalPlannerController::odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    current_odometry_ = *msg;
    odom_received_ = true;
}

// Action Server handle_goal callback
rclcpp_action::GoalResponse GlobalPlannerController::handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const FollowPath::Goal> goal)
{
    (void)uuid;
    RCLCPP_INFO(this->get_logger(), "Received goal request with path of %zu poses", goal->path.poses.size());

    // Reject the goal if the path is empty
    if (goal->path.poses.empty()) {
        RCLCPP_ERROR(this->get_logger(), "Goal rejected: Path is empty.");
        return rclcpp_action::GoalResponse::REJECT;
    }

    // Accept the new goal.
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

// Action Server handle_cancel callback
rclcpp_action::CancelResponse GlobalPlannerController::handle_cancel(
    const std::shared_ptr<GoalHandleFollowPath> goal_handle)
{
    (void)goal_handle;
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal. Stopping robot.");
    
    // Stop the robot immediately
    geometry_msgs::msg::Twist stop_cmd;
    stop_cmd.linear.x = 0.0;
    stop_cmd.angular.z = 0.0;
    cmd_vel_pub_->publish(stop_cmd);

    // Accept the cancellation
    return rclcpp_action::CancelResponse::ACCEPT;
}

// Action Server handle_accepted callback
void GlobalPlannerController::handle_accepted(
    const std::shared_ptr<GoalHandleFollowPath> goal_handle)
{
    std::lock_guard<std::mutex> lock(goal_handle_mutex_);
    
    // If we have an old goal, abort it.
    if (this->current_goal_handle_) {
        RCLCPP_WARN(this->get_logger(), "Aborting previous goal.");
        auto result = std::make_shared<FollowPath::Result>();
        result->success = false;
        this->current_goal_handle_->abort(result);
    }
    
    // Store the new goal handle and its path
    this->current_goal_handle_ = goal_handle;
    this->current_path_ = goal_handle->get_goal()->path;
    RCLCPP_INFO(this->get_logger(), "New goal accepted and path stored.");
}

double GlobalPlannerController::calculateDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2)
{
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

geometry_msgs::msg::PoseStamped GlobalPlannerController::findTargetPoint()
{
    const auto& robot_pose = current_odometry_.pose.pose;
    geometry_msgs::msg::TransformStamped transform_stamped;
    try {
        transform_stamped = tf_buffer_->lookupTransform(
            robot_frame_, global_frame_, tf2::TimePointZero);
    } catch (const tf2::TransformException & ex) {
        RCLCPP_ERROR(
            this->get_logger(), "Could not get transform from %s to %s: %s",
            global_frame_.c_str(), robot_frame_.c_str(), ex.what());
        return current_path_.poses.back();
    }

    auto closest_it = std::min_element(current_path_.poses.begin(), current_path_.poses.end(),
        [&](const auto& pose1, const auto& pose2) {
            return calculateDistance(robot_pose.position, pose1.pose.position) <
                   calculateDistance(robot_pose.position, pose2.pose.position);
        });

    for (auto it = closest_it; it != current_path_.poses.end(); ++it) {
        geometry_msgs::msg::PoseStamped pose_in_robot_frame;
        tf2::doTransform(*it, pose_in_robot_frame, transform_stamped);
        if (pose_in_robot_frame.pose.position.x > 0) {
            if (calculateDistance(robot_pose.position, it->pose.position) >= lookahead_distance_) {
                return *it;
            }
        }
    }
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
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;
    marker.color.a = 1.0;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 1.0;
    marker.lifetime = rclcpp::Duration::from_seconds(0.5);
    target_point_pub_->publish(marker);
}


void GlobalPlannerController::executeController()
{
    std::shared_ptr<GoalHandleFollowPath> active_goal_handle;
    {
        std::lock_guard<std::mutex> lock(goal_handle_mutex_);
        active_goal_handle = this->current_goal_handle_;
    }

    if (!active_goal_handle || !odom_received_) {
        return;
    }

    if (active_goal_handle->is_canceling()) {
        RCLCPP_INFO(this->get_logger(), "Goal canceled.");
        auto result = std::make_shared<FollowPath::Result>();
        result->success = false;
        active_goal_handle->canceled(result);
        
        // Clear the current goal handle
        std::lock_guard<std::mutex> lock(goal_handle_mutex_);
        this->current_goal_handle_ = nullptr;
        this->current_path_.poses.clear(); // Clear the path
        return;
    }

    // Get current pose and the final goal pose
    const auto& robot_pose = current_odometry_.pose.pose;
    const auto& goal_pose = current_path_.poses.back().pose;
    double distance_to_final_goal = calculateDistance(robot_pose.position, goal_pose.position);

    // Publish Feedback
    auto feedback = std::make_shared<FollowPath::Feedback>();
    feedback->distance_to_goal = distance_to_final_goal;
    active_goal_handle->publish_feedback(feedback);

    // Goal reached logic
    if (distance_to_final_goal < goal_tolerance_) {
        RCLCPP_INFO(this->get_logger(), "Goal reached successfully!");
        geometry_msgs::msg::Twist stop_cmd;
        stop_cmd.linear.x = 0.0;
        stop_cmd.angular.z = 0.0;
        cmd_vel_pub_->publish(stop_cmd);

        // Set goal as succeeded
        auto result = std::make_shared<FollowPath::Result>();
        result->success = true;
        active_goal_handle->succeed(result);

        // Clear the current goal handle
        std::lock_guard<std::mutex> lock(goal_handle_mutex_);
        this->current_goal_handle_ = nullptr;
        this->current_path_.poses.clear(); // Clear the path
        return;
    }

    geometry_msgs::msg::PoseStamped target_point_map = findTargetPoint();
    publishTargetPointMarker(target_point_map);

    geometry_msgs::msg::PoseStamped target_point_robot;
    try {
        target_point_map.header.stamp.sec = 0;
        target_point_map.header.stamp.nanosec = 0;
        
        tf_buffer_->transform(target_point_map, target_point_robot, robot_frame_);

    } catch (const tf2::TransformException & ex) {
        RCLCPP_ERROR(this->get_logger(), "Could not transform target point to %s frame: %s", robot_frame_.c_str(), ex.what());
        
        RCLCPP_ERROR(this->get_logger(), "Aborting goal due to transform error.");
        auto result = std::make_shared<FollowPath::Result>();
        result->success = false;
        active_goal_handle->abort(result);
        
        std::lock_guard<std::mutex> lock(goal_handle_mutex_);
        this->current_goal_handle_ = nullptr;
        this->current_path_.poses.clear();
        return;
    }
    
    double y_lateral_error = target_point_robot.pose.position.y;
    double lookahead_dist_sq = lookahead_distance_ * lookahead_distance_;
    double curvature = (2.0 * y_lateral_error) / lookahead_dist_sq;

    double angular_velocity = curvature / 10.0;

    double clipped_angular_velocity = std::clamp(
        angular_velocity, -max_angular_velocity_, max_angular_velocity_);

    geometry_msgs::msg::Twist cmd_vel;
    cmd_vel.linear.x = desired_linear_velocity_;
    cmd_vel.angular.z = clipped_angular_velocity;

    cmd_vel_pub_->publish(cmd_vel);
}

} // namespace lr_global_planner_controller
