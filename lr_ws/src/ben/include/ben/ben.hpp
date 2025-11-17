#ifndef BEN_H
#define BEN_H

#include "rclcpp/rclcpp.hpp"
#include <rclcpp_action/rclcpp_action.hpp>
#include "nav_msgs/msg/odometry.hpp"
#include "std_msgs/msg/bool.hpp"
#include "std_msgs/msg/string.hpp"
#include <geometry_msgs/msg/pose_array.hpp>
#include <std_msgs/msg/float32_multi_array.hpp>

#include <atomic>
#include <mutex>
#include <optional>
#include <string>
#include <ben/fsm.hpp>
#include <chrono>

#include "lr_msgs/msg/mux_mode.hpp"
#include "lr_msgs/msg/exit_debug.hpp"
#include <lr_msgs/msg/crater_stamped.hpp>
#include <lr_msgs/msg/pose2_d.hpp>
#include <lr_msgs/msg/actuator_command.hpp>

#include <lr_msgs/srv/pose_extract.hpp>
#include <lr_msgs/srv/plan_path.hpp>

#include <lr_msgs/action/crater_detect.hpp>
#include <lr_msgs/action/run_validation.hpp>
#include "lr_msgs/action/follow_path.hpp"

#include "nav_msgs/msg/path.hpp"

namespace lr
{
    namespace ben
    {

        class BenNode : public rclcpp::Node
        {
        private:
            // FSM callback
            int fsm_timer_callback_ms_;
            rclcpp::CallbackGroup::SharedPtr fsm_timer_cb_group_;
            rclcpp::TimerBase::SharedPtr fsm_timer_;
            void fsmTimerCallback();

            // Global robot state
            rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr global_robot_state_sub_;
            nav_msgs::msg::Odometry global_robot_state_;
            void globalRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

            // Odom robot state
            rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_robot_state_sub_;
            nav_msgs::msg::Odometry odom_robot_state_;
            void odomRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

            // Debug trigger
            rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr debug_trigger_sub_;
            bool debug_trigger_ = false;
            void debugTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg);

            // Exit debug trigger
            rclcpp::Subscription<lr_msgs::msg::ExitDebug>::SharedPtr exit_debug_trigger_sub_;
            bool exit_debug_trigger_ = false;
            void exitDebugTriggerCallback(const lr_msgs::msg::ExitDebug::SharedPtr msg);

            // Manual override trigger
            rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr manual_override_trigger_sub_;
            bool manual_override_trigger_ = false;
            void manualOverrideTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg);

            // Verbose trigger
            rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr verbose_trigger_sub_;
            bool verbose_trigger_ = false;
            void verboseTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg);

            // Crater detection
            rclcpp::Subscription<lr_msgs::msg::CraterStamped>::SharedPtr crater_sub_;
            std::optional<lr_msgs::msg::CraterStamped> latest_crater_;
            void onCraterMsgCallback(const lr_msgs::msg::CraterStamped::SharedPtr msg);

            // Finite State Machine
            lr::ben::FSM fsm_;
            rclcpp::Publisher<std_msgs::msg::String>::SharedPtr fsm_state_pub_;
            rclcpp::Time start_time_;

            // FSM state runners
            void fsmRunStartMission();
            void fsmRunGlobalNavPlanner();
            void fsmRunGlobalNavController();
            void fsmRunValidation();
            void fsmRunPerception();
            void fsmRunManipulationPlanner();
            void fsmRunManipulationController();
            void fsmRunEndMission();
            void fsmRunStopped();
            void fsmRunDebug();
            void fsmRunManualOverride();

            // fsmRunStartMission helpers
            rclcpp::Publisher<lr_msgs::msg::MuxMode>::SharedPtr mux_mode_pub_;
            int start_mission_delay_iters_{5};
            int start_mission_delay_count_{0};

            // fsmRunGlobalNavPlanner helpers
            rclcpp::Client<lr_msgs::srv::PlanPath>::SharedPtr global_planner_client_;
            bool planner_req_sent_{false};
            std::mutex global_planner_mutex_;
            // std::chrono::steady_clock::time_point planner_req_started_{};
            // std::chrono::seconds planner_req_timeout_{10};

            rclcpp::Subscription<geometry_msgs::msg::PoseArray>::SharedPtr crater_centroids_sub_;
            rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr crater_diameters_sub_;
            std::vector<geometry_msgs::msg::Pose> crater_centroids_;
            std::vector<float> crater_diameters_;
            int current_crater_index_{0};
            bool got_crater_data_{false};
            int first_time_counter_{0};

            // fsmRunManipulationPlanner helpers
            rclcpp::Client<lr_msgs::srv::PlanPath>::SharedPtr manipulation_planner_client_;
            bool manipulation_req_sent_{false};
            std::mutex manipulation_planner_mutex_;
            int current_goal_pose_idx_{0};
            std::string manipulation_type_{"Forward_manipulation"};
            std::string local_goal_type_{"source"};

            // fsmRunValidation helpers
            int validation_average_window_{10};
            bool validation_do_second_pass_{false};
            int validation_timeout_sec_{20};

            std::mutex validation_mutex_;
            bool validation_goal_active_{false};
            std::optional<bool> validation_last_success_;
            double validation_last_max_z_{0.0};
            int validation_attempts_{0};

            rclcpp::CallbackGroup::SharedPtr validation_cb_group_;
            rclcpp_action::Client<lr_msgs::action::RunValidation>::SharedPtr validation_client_;

            // fsmRunPerception helpers
            std::mutex perception_mutex_;
            std::vector<lr_msgs::msg::Pose2D> goal_poses_;
            std::vector<std::string> goal_pose_types_;
            bool perception_goal_active_{false};
            bool pose_request_inflight_{false};

            rclcpp::CallbackGroup::SharedPtr perception_cb_group_;
            rclcpp::Client<lr_msgs::srv::PoseExtract>::SharedPtr pose_extract_client_;
            rclcpp_action::Client<lr_msgs::action::CraterDetect>::SharedPtr crater_detect_client_;
            std::shared_ptr<rclcpp_action::ClientGoalHandle<lr_msgs::action::CraterDetect>> crater_detect_goal_handle_;

            // fsmNav helpers
            using FollowPath = lr_msgs::action::FollowPath;
            using GoalHandleFollowPath = rclcpp_action::ClientGoalHandle<FollowPath>;

            rclcpp::CallbackGroup::SharedPtr nav_client_cb_group_;
            rclcpp_action::Client<FollowPath>::SharedPtr nav_client_;

            std::mutex nav_mutex_;
            bool nav_goal_active_{false};
            std::optional<bool> nav_last_success_;

            nav_msgs::msg::Path global_path_to_send_;
            nav_msgs::msg::Path manipulation_path_to_send_;

            // fsmRunEndMission helpers
            int end_mission_delay_iters_{5};
            int end_mission_delay_count_{0};

            // fsmRunDebug helpers
            std::string exit_debug_target_state_ = "START_MISSION";
            int exit_debug_crater_index_ = 0;

            // fsmRunManualOverride helpers
            bool entered_once_ = false;

            // Tool Height control
            double tool_height_up_;
            double tool_height_down_;
            double tool_height_up_second_pass_;
            double tool_height_down_second_pass_;

        public:
            // Constructor and destructor
            BenNode();
            ~BenNode() {};
        };

    } // namespace ben
} // namespace lr
#endif
