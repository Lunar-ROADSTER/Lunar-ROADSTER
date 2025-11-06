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

    /**
     * @brief Constructor for the GlobalPlannerController class (Action Server version).
     */
    GlobalPlannerController::GlobalPlannerController(const rclcpp::NodeOptions &options)
        : Node("global_planner_controller", options)
    {
        // --- Declare and retrieve parameters ---
        this->declare_parameter<double>("lookahead_distance", 0.7);
        this->declare_parameter<double>("desired_linear_velocity", 5.0);
        this->declare_parameter<double>("max_angular_velocity", 3.0);
        this->declare_parameter<double>("goal_tolerance", 0.7);
        this->declare_parameter<std::string>("robot_frame", "base_link");
        this->declare_parameter<std::string>("global_frame", "map");
        this->declare_parameter<double>("manipulation_lookahead_distance", 0.2);
        this->declare_parameter<double>("manipulation_goal_tolerance", 0.05);

        // Load standard parameters
        lookahead_distance_ = this->get_parameter("lookahead_distance").as_double();
        desired_linear_velocity_ = this->get_parameter("desired_linear_velocity").as_double();
        max_angular_velocity_ = this->get_parameter("max_angular_velocity").as_double();
        goal_tolerance_ = this->get_parameter("goal_tolerance").as_double();
        robot_frame_ = this->get_parameter("robot_frame").as_string();
        global_frame_ = this->get_parameter("global_frame").as_string();
        manipulation_lookahead_distance_ = this->get_parameter("manipulation_lookahead_distance").as_double();
        manipulation_goal_tolerance_ = this->get_parameter("manipulation_goal_tolerance").as_double();

        RCLCPP_INFO(this->get_logger(), "Parameters Loaded Successfully:");
        RCLCPP_INFO(this->get_logger(), "  lookahead_distance: %.2f m", lookahead_distance_);
        RCLCPP_INFO(this->get_logger(), "  desired_linear_velocity: %.2f m/s", desired_linear_velocity_);
        RCLCPP_INFO(this->get_logger(), "  max_angular_velocity: %.2f rad/s", max_angular_velocity_);
        RCLCPP_INFO(this->get_logger(), "  goal_tolerance: %.2f m", goal_tolerance_);
        RCLCPP_INFO(this->get_logger(), "  robot_frame: %s", robot_frame_.c_str());
        RCLCPP_INFO(this->get_logger(), "  global_frame: %s", global_frame_.c_str());
        RCLCPP_INFO(this->get_logger(), "  manipulation_lookahead_distance: %.2f m", manipulation_lookahead_distance_);
        RCLCPP_INFO(this->get_logger(), "  manipulation_goal_tolerance: %.2f m", manipulation_goal_tolerance_);

        // Initialize TF buffer and listener
        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        // Subscribers
        // odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        //     "/odometry/filtered/ekf_global_node", 10, std::bind(&GlobalPlannerController::odomCallback, this, _1));

        // Publishers
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/command_vel", 10);
        target_point_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("/lookahead_point", 10);

        trail_pub_ = this->create_publisher<nav_msgs::msg::Path>("/tf_trail", 1);
        trail_.header.frame_id = global_frame_;
        trail_.poses.clear();

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

        trail_timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&GlobalPlannerController::sampleTfAndPublishTrail, this));
    }

    /**
     * @brief Callback for odometry messages.
     */
    void GlobalPlannerController::odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        current_odometry_ = *msg;
        odom_received_ = true;
    }

    /**
     * @brief Action Server: Callback to decide if a new goal should be accepted.
     */
    rclcpp_action::GoalResponse GlobalPlannerController::handle_goal(
        const rclcpp_action::GoalUUID &uuid,
        std::shared_ptr<const FollowPath::Goal> goal)
    {
        (void)uuid;
        RCLCPP_INFO(this->get_logger(), "Received goal request with path of %zu poses, direction: %s",
                    goal->path.poses.size(), goal->direction.c_str());

        if (goal->direction != "Forward" &&
            goal->direction != "Backward" &&
            goal->direction != "Forward_manipulation")
        {
            RCLCPP_ERROR(this->get_logger(), "Goal rejected: Invalid direction. Must be 'Forward', 'Backward', or 'Forward_manipulation'.");
            return rclcpp_action::GoalResponse::REJECT;
        }

        if (goal->path.poses.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "Goal rejected: Path is empty.");
            return rclcpp_action::GoalResponse::REJECT;
        }

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    /**
     * @brief Action Server: Callback to handle a request to cancel the current goal.
     */
    rclcpp_action::CancelResponse GlobalPlannerController::handle_cancel(
        const std::shared_ptr<GoalHandleFollowPath> goal_handle)
    {
        (void)goal_handle;
        RCLCPP_INFO(this->get_logger(), "Received request to cancel goal. Stopping robot.");

        geometry_msgs::msg::Twist stop_cmd;
        stop_cmd.linear.x = 0.0;
        stop_cmd.angular.z = 0.0;
        cmd_vel_pub_->publish(stop_cmd);

        return rclcpp_action::CancelResponse::ACCEPT;
    }

    /**
     * @brief Action Server: Callback that runs when a new goal is accepted.
     */
    void GlobalPlannerController::handle_accepted(
        const std::shared_ptr<GoalHandleFollowPath> goal_handle)
    {
        std::lock_guard<std::mutex> lock(goal_handle_mutex_);

        if (this->current_goal_handle_)
        {
            RCLCPP_WARN(this->get_logger(), "Aborting previous goal.");
            auto result = std::make_shared<FollowPath::Result>();
            result->success = false;
            this->current_goal_handle_->abort(result);
        }

        this->current_goal_handle_ = goal_handle;
        this->current_path_ = goal_handle->get_goal()->path;
        this->current_direction_ = goal_handle->get_goal()->direction;
        RCLCPP_INFO(this->get_logger(), "New goal accepted and path stored. Direction: %s", current_direction_.c_str());

        RCLCPP_INFO(this->get_logger(), "Waiting 2 seconds before starting controller...");
        // rclcpp::sleep_for(std::chrono::seconds(2));
        RCLCPP_INFO(this->get_logger(), "Starting controller execution.");

        dev_stats_ = DeviationStats{};
        have_prev_sample_ = false;
        prev_error_ = 0.0;
    }

    /**
     * @brief Helper function to calculate Euclidean distance.
     */
    double GlobalPlannerController::calculateDistance(const geometry_msgs::msg::Point &p1, const geometry_msgs::msg::Point &p2)
    {
        return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
    }

    /**
     * @brief Finds the target point on the path to steer towards.
     * @param current_lookahead_distance The active lookahead distance to use (nav or manipulation).
     */
    geometry_msgs::msg::PoseStamped GlobalPlannerController::findTargetPoint(double current_lookahead_distance)
    {
        // Get robot pose from TF (map -> base_link)
        geometry_msgs::msg::PoseStamped robot_map;
        if (!lookupRobotInMap(robot_map))
        {
            return current_path_.poses.back();
        }
        const auto &robot_pose = robot_map.pose;

        // Transform for map->base_link (to check 'in front/behind')
        geometry_msgs::msg::TransformStamped transform_stamped;
        try
        {
            transform_stamped = tf_buffer_->lookupTransform(
                robot_frame_, global_frame_, tf2::TimePointZero);
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_ERROR(this->get_logger(), "Could not get transform from %s to %s: %s",
                         global_frame_.c_str(), robot_frame_.c_str(), ex.what());
            return current_path_.poses.back();
        }

        // Find closest path pose to robot (in map frame)
        auto closest_it = std::min_element(
            current_path_.poses.begin(), current_path_.poses.end(),
            [&](const auto &p1, const auto &p2)
            {
                return calculateDistance(robot_pose.position, p1.pose.position) <
                       calculateDistance(robot_pose.position, p2.pose.position);
            });

        const bool look_forward = (current_direction_ == "Forward" ||
                                   current_direction_ == "Forward_manipulation");

        // Walk forward from closest, pick first that?s beyond lookahead and in front/behind
        for (auto it = closest_it; it != current_path_.poses.end(); ++it)
        {
            geometry_msgs::msg::PoseStamped pose_in_robot_frame;
            tf2::doTransform(*it, pose_in_robot_frame, transform_stamped);

            const double x_rf = pose_in_robot_frame.pose.position.x;
            if ((look_forward && x_rf > 0.0) || (!look_forward && x_rf < 0.0))
            {
                if (calculateDistance(robot_pose.position, it->pose.position) >= current_lookahead_distance)
                {
                    return *it;
                }
            }
        }

        return current_path_.poses.back();
    }

    /**
     * @brief Publishes the lookahead point as an Rviz marker.
     */
    void GlobalPlannerController::publishTargetPointMarker(const geometry_msgs::msg::PoseStamped &target_point)
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

    /**
     * @brief Gets the robot's current pose in the global frame.
     */
    bool GlobalPlannerController::lookupRobotInMap(geometry_msgs::msg::PoseStamped &out) const
    {
        try
        {
            auto tf = tf_buffer_->lookupTransform(global_frame_, robot_frame_, tf2::TimePointZero);
            out.header = tf.header;
            out.header.frame_id = global_frame_;
            out.pose.position.x = tf.transform.translation.x;
            out.pose.position.y = tf.transform.translation.y;
            out.pose.position.z = tf.transform.translation.z;
            out.pose.orientation = tf.transform.rotation;
            return true;
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_WARN(this->get_logger(), "TF %s<- %s failed: %s",
                        global_frame_.c_str(), robot_frame_.c_str(), ex.what());
            return false;
        }
    }

    /**
     * @brief Calculates the shortest distance from a point to a line segment.
     */
    double GlobalPlannerController::pointToSegmentDistance(
        const geometry_msgs::msg::Point &p,
        const geometry_msgs::msg::Point &a,
        const geometry_msgs::msg::Point &b) const
    {
        const double vx = b.x - a.x, vy = b.y - a.y;
        const double wx = p.x - a.x, wy = p.y - a.y;
        const double vv = vx * vx + vy * vy;
        double t = (vv > 1e-12) ? ((wx * vx + wy * vy) / vv) : 0.0;
        t = std::max(0.0, std::min(1.0, t));
        const double projx = a.x + t * vx;
        const double projy = a.y + t * vy;
        return std::hypot(p.x - projx, p.y - projy);
    }

    /**
     * @brief Calculates the shortest distance from a point to the entire path.
     */
    double GlobalPlannerController::distancePointToPath(
        const geometry_msgs::msg::Point &p,
        const nav_msgs::msg::Path &path) const
    {
        if (path.poses.empty())
            return std::numeric_limits<double>::infinity();
        if (path.poses.size() == 1)
        {
            const auto &q = path.poses.front().pose.position;
            return std::hypot(p.x - q.x, p.y - q.y);
        }
        double best = std::numeric_limits<double>::infinity();
        for (size_t i = 0; i + 1 < path.poses.size(); ++i)
        {
            best = std::min(best,
                            pointToSegmentDistance(p,
                                                   path.poses[i].pose.position,
                                                   path.poses[i + 1].pose.position));
        }
        return best;
    }

    /**
     * @brief Updates the path deviation statistics (for logging/debugging).
     */
    void GlobalPlannerController::updateDeviationStats()
    {
        // This function only runs if there's an active goal, checked in executeController
        if (current_path_.poses.empty())
            return;

        geometry_msgs::msg::PoseStamped robot_map;
        if (!lookupRobotInMap(robot_map))
            return;

        const auto &p = robot_map.pose.position;
        double e = distancePointToPath(p, current_path_);

        if (have_prev_sample_)
        {
            const auto &pp = prev_sample_.pose.position;
            double ds = std::hypot(p.x - pp.x, p.y - pp.y);
            if (ds > 1e-6)
            {
                dev_stats_.path_length += ds;
                dev_stats_.cumulative += 0.5 * (std::abs(prev_error_) + std::abs(e)) * ds;
                dev_stats_.rms += 0.5 * (prev_error_ * prev_error_ + e * e) * ds;
            }
        }

        dev_stats_.max = std::max(dev_stats_.max, std::abs(e));
        dev_stats_.samples += 1;
        prev_sample_ = robot_map;
        prev_error_ = e;
        have_prev_sample_ = true;

        if (dev_stats_.path_length > 1e-6)
        {
            const double mean = dev_stats_.cumulative / dev_stats_.path_length;
            const double rms = std::sqrt(dev_stats_.rms / dev_stats_.path_length);

            const double pct_dev = 100.0 * (mean / dev_stats_.path_length);

            RCLCPP_INFO(
                this->get_logger(),
                "Path deviation: mean=%.3f m, rms=%.3f m, max=%.3f m, cum=%.3f m², len=%.2f m, dev=%.2f%%",
                mean, rms, dev_stats_.max, dev_stats_.cumulative, dev_stats_.path_length, pct_dev);
        }
    }

    /**
     * @brief The main control loop, triggered by a timer.
     */
    void GlobalPlannerController::executeController()
    {
        std::shared_ptr<GoalHandleFollowPath> active_goal_handle;
        {
            std::lock_guard<std::mutex> lock(goal_handle_mutex_);
            active_goal_handle = this->current_goal_handle_;
        }

        if (!active_goal_handle)
        {
            geometry_msgs::msg::Twist stop_cmd;
            cmd_vel_pub_->publish(stop_cmd);
            return;
        }

        if (!active_goal_handle->is_active())
        {
            geometry_msgs::msg::Twist stop_cmd;
            cmd_vel_pub_->publish(stop_cmd);
            return;
        }

        geometry_msgs::msg::PoseStamped robot_map;
        if (!lookupRobotInMap(robot_map))
        {
            geometry_msgs::msg::Twist stop_cmd;
            cmd_vel_pub_->publish(stop_cmd);
            return;
        }

        // Check if the goal has been canceled
        if (active_goal_handle->is_canceling())
        {
            RCLCPP_INFO(this->get_logger(), "Goal canceled by client; stopping.");
            geometry_msgs::msg::Twist stop_cmd;
            cmd_vel_pub_->publish(stop_cmd);
            auto result = std::make_shared<FollowPath::Result>();
            result->success = false;
            active_goal_handle->canceled(result);
            std::lock_guard<std::mutex> lock(goal_handle_mutex_);
            this->current_goal_handle_ = nullptr;
            this->current_path_.poses.clear();
            return;
        }

        updateDeviationStats();

        double current_goal_tolerance;
        double current_lookahead_distance;
        double current_linear_velocity = desired_linear_velocity_;

        if (current_direction_ == "Forward_manipulation" || current_direction_ == "Backward")
        {
            current_goal_tolerance = manipulation_goal_tolerance_;
            current_lookahead_distance = manipulation_lookahead_distance_;
            RCLCPP_INFO_ONCE(this->get_logger(), "Using MANIPULATION/BACKWARD parameters.");
        }
        else // "Forward"
        {
            current_goal_tolerance = goal_tolerance_;
            current_lookahead_distance = lookahead_distance_;
            RCLCPP_INFO_ONCE(this->get_logger(), "Using NAVIGATION (Forward) parameters.");
        }

        if (current_direction_ == "Backward")
        {
            current_linear_velocity = -desired_linear_velocity_; // Set negative velocity for backward
        }

        const auto &robot_pose = robot_map.pose;
        const auto &goal_pose = current_path_.poses.back().pose;
        double distance_to_final_goal = calculateDistance(robot_pose.position, goal_pose.position);

        auto feedback = std::make_shared<FollowPath::Feedback>();
        feedback->distance_to_goal = distance_to_final_goal;
        active_goal_handle->publish_feedback(feedback);

        if (distance_to_final_goal < current_goal_tolerance)
        {
            RCLCPP_INFO(this->get_logger(), "Goal reached successfully!");
            geometry_msgs::msg::Twist stop_cmd;
            stop_cmd.linear.x = 0.0;
            stop_cmd.angular.z = 0.0;
            cmd_vel_pub_->publish(stop_cmd);

            auto result = std::make_shared<FollowPath::Result>();
            result->success = true;
            active_goal_handle->succeed(result);

            std::lock_guard<std::mutex> lock(goal_handle_mutex_);
            this->current_goal_handle_ = nullptr;
            this->current_path_.poses.clear();
            return;
        }

        // --- Start of Control Logic ---
        geometry_msgs::msg::PoseStamped target_point_map = findTargetPoint(current_lookahead_distance);
        publishTargetPointMarker(target_point_map);

        geometry_msgs::msg::PoseStamped target_point_robot;
        try
        {
            target_point_map.header.stamp.sec = 0;
            target_point_map.header.stamp.nanosec = 0;
            tf_buffer_->transform(target_point_map, target_point_robot, robot_frame_);
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_ERROR(this->get_logger(), "Could not transform target point to %s frame: %s", robot_frame_.c_str(), ex.what());
            auto result = std::make_shared<FollowPath::Result>();
            result->success = false;
            active_goal_handle->abort(result);

            std::lock_guard<std::mutex> lock(goal_handle_mutex_);
            this->current_goal_handle_ = nullptr;
            this->current_path_.poses.clear();
            return;
        }

        double y_lateral_error = target_point_robot.pose.position.y;
        double lookahead_dist_sq = current_lookahead_distance * current_lookahead_distance;
        double curvature = (lookahead_dist_sq > 1e-6) ? (2.0 * y_lateral_error) / lookahead_dist_sq : 0.0;

        double angular_velocity = curvature / 10.0;

        double clipped_angular_velocity = std::clamp(
            angular_velocity, -max_angular_velocity_, max_angular_velocity_);

        geometry_msgs::msg::Twist cmd_vel;
        cmd_vel.linear.x = current_linear_velocity;
        cmd_vel.angular.z = clipped_angular_velocity;

        cmd_vel_pub_->publish(cmd_vel);
    }

    /**
     * @brief Timer callback to sample TF and build a trail for Rviz.
     */
    void GlobalPlannerController::sampleTfAndPublishTrail()
    {
        geometry_msgs::msg::PoseStamped pose_map;
        try
        {
            auto tf = tf_buffer_->lookupTransform(global_frame_, robot_frame_, tf2::TimePointZero);

            pose_map.header.stamp = this->get_clock()->now();
            pose_map.header.frame_id = global_frame_;
            pose_map.pose.position.x = tf.transform.translation.x;
            pose_map.pose.position.y = tf.transform.translation.y;
            pose_map.pose.position.z = tf.transform.translation.z;
            pose_map.pose.orientation = tf.transform.rotation;
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_WARN(get_logger(),
                        "Trail TF lookup failed (%s->%s): %s",
                        global_frame_.c_str(), robot_frame_.c_str(), ex.what());
            return;
        }

        bool append = trail_.poses.empty();
        if (!append)
        {
            const auto &q = trail_.poses.back().pose.position;
            const auto &p = pose_map.pose.position;
            append = (std::hypot(p.x - q.x, p.y - q.y) >= trail_min_step_);
        }
        if (!append)
            return;

        trail_.poses.push_back(pose_map);

        if (trail_.poses.size() > trail_max_points_)
        {
            const size_t overflow = trail_.poses.size() - trail_max_points_;
            trail_.poses.erase(trail_.poses.begin(),
                               trail_.poses.begin() + static_cast<long>(overflow));
        }

        trail_.header.stamp = pose_map.header.stamp;
        trail_.header.frame_id = global_frame_;
        trail_pub_->publish(trail_);
    }

} // namespace lr_global_planner_controller
