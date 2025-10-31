#ifndef BEN_H
#define BEN_H

#include "rclcpp/rclcpp.hpp"
#include <rclcpp_action/rclcpp_action.hpp>
#include "nav_msgs/msg/odometry.hpp"
#include "std_msgs/msg/bool.hpp"
#include <atomic>
#include <mutex>
#include <optional>
#include <string>
#include <ben/fsm.hpp>

#include "lr_msgs/msg/mux_mode.hpp"
#include <lr_msgs/action/run_validation.hpp>


namespace lr{
namespace ben{

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

        // Verbose trigger
        rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr verbose_trigger_sub_;
        bool verbose_trigger_ = false;
        void verboseTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg);

        // Finite State Machine
        lr::ben::FSM fsm_;

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

        // fsmRunStartMission helpers
        rclcpp::Publisher<lr_msgs::msg::MuxMode>::SharedPtr mux_mode_pub_;

        // fsmRunValidation helpers
        int  validation_average_window_{10};
        bool validation_do_second_pass_{false};
        int  validation_timeout_sec_{20};

        std::mutex validation_mutex_;
        bool validation_goal_active_{false};
        std::optional<bool> validation_last_success_;
        double validation_last_max_z_{0.0};
        int validation_attempts_{0};

        rclcpp::CallbackGroup::SharedPtr validation_cb_group_;
        rclcpp_action::Client<lr_msgs::action::RunValidation>::SharedPtr validation_client_;


    public:
        // Constructor and destructor
        BenNode();
        ~BenNode(){};
};  

} // namespace ben
} // namespace lr
#endif