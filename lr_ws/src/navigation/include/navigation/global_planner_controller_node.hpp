#ifndef GLOBAL_PLANNER_CONTROLLER_NODE_HPP_
#define GLOBAL_PLANNER_CONTROLLER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
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
#include <mutex>  // For thread-safe goal handling
#include <limits> // For std::numeric_limits

/**
 * @struct DeviationStats
 * @brief Holds statistics about the robot's deviation from the path.
 */
struct DeviationStats
{
    double cumulative = 0.0;  // ? |e| ds   [m²]
    double mean = 0.0;        // length-weighted average |e| [m]
    double rms = 0.0;         // sqrt(? e² ds / path_length) [m]
    double max = 0.0;         // max |e| [m]
    double path_length = 0.0; // robot-traveled arc length used for weighting [m]
    size_t samples = 0;       // number of deviation samples
};

namespace lr_global_planner_controller
{
    /**
     * @class GlobalPlannerController
     * @brief An action server to control a robot along a given path using Pure Pursuit.
     */
    class GlobalPlannerController : public rclcpp::Node
    {
    public:
        // Define type aliases for the action
        using FollowPath = lr_msgs::action::FollowPath;
        using GoalHandleFollowPath = rclcpp_action::ServerGoalHandle<FollowPath>;

        /**
         * @brief Constructor for the GlobalPlannerController class.
         * @param options Node options for ROS2.
         */
        explicit GlobalPlannerController(const rclcpp::NodeOptions &options);

    private:
        // --- Action Server Callbacks ---

        /**
         * @brief Callback to decide if a new goal (path) should be accepted.
         */
        rclcpp_action::GoalResponse handle_goal(
            const rclcpp_action::GoalUUID &uuid,
            std::shared_ptr<const FollowPath::Goal> goal);

        /**
         * @brief Callback to handle a request to cancel the current goal.
         */
        rclcpp_action::CancelResponse handle_cancel(
            const std::shared_ptr<GoalHandleFollowPath> goal_handle);

        /**
         * @brief Callback that runs when a new goal is accepted and execution begins.
         */
        void handle_accepted(
            const std::shared_ptr<GoalHandleFollowPath> goal_handle);

        // --- Core Controller Logic ---

        /**
         * @brief The main control loop, triggered by a timer.
         */
        void executeController();

        /**
         * @brief Finds the target point on the path to steer towards.
         */
        geometry_msgs::msg::PoseStamped findTargetPoint();

        // --- Subscriber Callbacks ---

        /**
         * @brief Callback for odometry messages.
         */
        void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

        // --- Helper & Utility Functions ---

        /**
         * @brief Calculates the Euclidean distance between two points.
         */
        double calculateDistance(const geometry_msgs::msg::Point &p1, const geometry_msgs::msg::Point &p2);

        /**
         * @brief Publishes a visualization marker for the current target point.
         */
        void publishTargetPointMarker(const geometry_msgs::msg::PoseStamped &target_point);

        /**
         * @brief Looks up the robot's current pose in the global frame.
         */
        bool lookupRobotInMap(geometry_msgs::msg::PoseStamped &out) const;

        /**
         * @brief Calculates the shortest distance from a point to a line segment.
         */
        double pointToSegmentDistance(const geometry_msgs::msg::Point &p,
                                      const geometry_msgs::msg::Point &a,
                                      const geometry_msgs::msg::Point &b) const;

        /**
         * @brief Calculates the shortest distance from a point to the entire path.
         */
        double distancePointToPath(const geometry_msgs::msg::Point &p,
                                   const nav_msgs::msg::Path &path) const;

        /**
         * @brief Updates the running statistics of path deviation.
         */
        void updateDeviationStats();

        // --- ROS2 Members (Publishers, Subscribers, etc.) ---

        // Subscribers
        rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;

        // Publishers
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
        rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr target_point_pub_;

        // Action Server
        rclcpp_action::Server<FollowPath>::SharedPtr action_server_;

        // TF
        std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

        // Timer
        rclcpp::TimerBase::SharedPtr controller_timer_;

        // --- State Variables ---

        // Goal Handling
        std::shared_ptr<GoalHandleFollowPath> current_goal_handle_;
        std::mutex goal_handle_mutex_; // Protects access to the current_goal_handle_
        nav_msgs::msg::Path current_path_;
        std::string current_direction_; // To store "Forward" or "Backward"

        // Robot State
        nav_msgs::msg::Odometry current_odometry_;
        bool odom_received_{false};

        // Path Deviation Statistics
        DeviationStats dev_stats_;
        bool have_prev_sample_ = false;
        geometry_msgs::msg::PoseStamped prev_sample_;
        double prev_error_ = 0.0;

        // Parameters
        double lookahead_distance_;
        double desired_linear_velocity_;
        double max_angular_velocity_;
        double goal_tolerance_;
        std::string robot_frame_;
        std::string global_frame_;

        rclcpp::Publisher<nav_msgs::msg::Path>::SharedPtr trail_pub_;
        rclcpp::TimerBase::SharedPtr trail_timer_;
        nav_msgs::msg::Path trail_;

        double trail_min_step_{0.05};
        size_t trail_max_points_{50000};

        void sampleTfAndPublishTrail();
    };

} // namespace lr_global_planner_controller

#endif // GLOBAL_PLANNER_CONTROLLER_NODE_HPP_
