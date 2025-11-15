/**
 * TODO:
 * Update date: 2025-11-01
 */

#include "ben/ben.hpp"

namespace lr
{
    namespace ben
    {

        BenNode::BenNode() : Node("ben_node")
        {
            // Parameters
            this->declare_parameter<bool>("debug_trigger", false);
            this->get_parameter("debug_trigger", debug_trigger_);

            this->declare_parameter<bool>("verbose_trigger", false);
            this->get_parameter("verbose_trigger", verbose_trigger_);

            this->declare_parameter<int>("fsm_timer_callback_ms", 2000);
            this->get_parameter("fsm_timer_callback_ms", fsm_timer_callback_ms_);

            this->declare_parameter<std::string>("exit_debug_target_state", "START_MISSION");
            this->get_parameter("exit_debug_target_state", exit_debug_target_state_);

            this->declare_parameter<int>("exit_debug_crater_index", 0);
            this->get_parameter("exit_debug_crater_index", exit_debug_crater_index_);

            this->declare_parameter<int>("start_mission_delay_iterations", 5);
            this->get_parameter("start_mission_delay_iterations", start_mission_delay_iters_);

            this->declare_parameter<int>("validation_average_window", 10);
            this->get_parameter("validation_average_window", validation_average_window_);

            this->declare_parameter<bool>("validation_do_second_pass", false);
            this->get_parameter("validation_do_second_pass", validation_do_second_pass_);

            this->declare_parameter<int>("validation_timeout_sec", 20);
            this->get_parameter("validation_timeout_sec", validation_timeout_sec_);

            this->declare_parameter<int>("end_mission_delay_iterations", 5);
            this->get_parameter("end_mission_delay_iterations", end_mission_delay_iters_);

            this->declare_parameter<double>("tool_height_up", 100.0);
            this->get_parameter("tool_height_up", tool_height_up_);

            this->declare_parameter<double>("tool_height_down", 10.0);
            this->get_parameter("tool_height_down", tool_height_down_);

            this->declare_parameter<double>("tool_height_up_second_pass_", 100.0);
            this->get_parameter("tool_height_up", tool_height_up_second_pass_);

            this->declare_parameter<double>("tool_height_down_second_pass_", 0.0);
            this->get_parameter("tool_height_down", tool_height_down_second_pass_);

            // FSM callback
            fsm_timer_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            fsm_timer_ = this->create_wall_timer(std::chrono::milliseconds(fsm_timer_callback_ms_),
                                                 std::bind(&BenNode::fsmTimerCallback, this), fsm_timer_cb_group_);

            // Global robot state subscriber
            global_robot_state_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
                "/odometry/filtered/ekf_global_node", 1, std::bind(&BenNode::globalRobotStateCallback, this, std::placeholders::_1));

            // Odom robot state subscriber
            odom_robot_state_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
                "/odometry/filtered/ekf_odom_node", 1, std::bind(&BenNode::odomRobotStateCallback, this, std::placeholders::_1));

            // Debug trigger subscriber
            debug_trigger_sub_ = this->create_subscription<std_msgs::msg::Bool>(
                "/ben_debug_trigger", 1, std::bind(&BenNode::debugTriggerCallback, this, std::placeholders::_1));

            // Exit debug trigger subscriber
            exit_debug_trigger_sub_ = this->create_subscription<lr_msgs::msg::ExitDebug>(
                "/ben_exit_debug_trigger", 1, std::bind(&BenNode::exitDebugTriggerCallback, this, std::placeholders::_1));

            // Verbose trigger subscriber
            verbose_trigger_sub_ = this->create_subscription<std_msgs::msg::Bool>(
                "/ben_verbose_trigger", 1, std::bind(&BenNode::verboseTriggerCallback, this, std::placeholders::_1));

            // Manual override trigger subscriber
            manual_override_trigger_sub_ = this->create_subscription<std_msgs::msg::Bool>(
                "/ben_manual_override_trigger", 1, std::bind(&BenNode::manualOverrideTriggerCallback, this, std::placeholders::_1));

            // Mux mode publisher
            mux_mode_pub_ = this->create_publisher<lr_msgs::msg::MuxMode>("/mux_mode", 1);

            // Validation action client
            validation_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            validation_client_ = rclcpp_action::create_client<lr_msgs::action::RunValidation>(this, "/validation/run", validation_cb_group_);

            // Perception callback group, subscriber, service client and action client
            perception_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);

            rclcpp::SubscriptionOptions sub_opts;
            sub_opts.callback_group = perception_cb_group_;

            auto qos = rclcpp::QoS(1)
                           .best_effort();
            qos.durability(rmw_qos_durability_policy_t::RMW_QOS_POLICY_DURABILITY_VOLATILE);

            crater_sub_ = this->create_subscription<lr_msgs::msg::CraterStamped>(
                "/crater_detection/crater",
                qos,
                std::bind(&BenNode::onCraterMsgCallback, this, std::placeholders::_1),
                sub_opts);

            pose_extract_client_ = this->create_client<lr_msgs::srv::PoseExtract>(
                "generate_crater_goals",
                rmw_qos_profile_services_default,
                perception_cb_group_);

            crater_detect_client_ = rclcpp_action::create_client<lr_msgs::action::CraterDetect>(
                this,
                "/detect_crater",
                perception_cb_group_);

            nav_client_cb_group_ = this->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
            nav_client_ = rclcpp_action::create_client<FollowPath>(this, "/follow_path", nav_client_cb_group_);

            crater_centroids_sub_ = this->create_subscription<geometry_msgs::msg::PoseArray>(
                "/crater_centroids",
                10,
                [this](const geometry_msgs::msg::PoseArray::ConstSharedPtr msg)
                {
                    crater_centroids_ = msg->poses;
                    if (!crater_centroids_.empty())
                        got_crater_data_ = true;
                    // RCLCPP_INFO(this->get_logger(), "[BEN] Received %zu crater centroids.", crater_centroids_.size());
                });

            crater_diameters_sub_ = this->create_subscription<std_msgs::msg::Float32MultiArray>(
                "/crater_diameters",
                10,
                [this](const std_msgs::msg::Float32MultiArray::ConstSharedPtr msg)
                {
                    crater_diameters_ = msg->data;
                    // RCLCPP_INFO(this->get_logger(), "[BEN] Received %zu crater diameters.", crater_diameters_.size());
                });

            global_planner_client_ = this->create_client<lr_msgs::srv::PlanPath>("/global_astar_planner/plan_path");
            manipulation_planner_client_ = this->create_client<lr_msgs::srv::PlanPath>("/manipulation_planner/plan_path");

            // Log initialization
            RCLCPP_INFO(this->get_logger(), "[INIT] Behaviour Executive Node initialized.");
        }

        // Callbacks
        // --------------------------------------------------------------------------------------------------------------------- //

        void BenNode::fsmTimerCallback()
        {
            RCLCPP_INFO(this->get_logger(), "-------------------------------------------------------------------------");
            RCLCPP_INFO(this->get_logger(), "[FSM] Current State: %s", fsm_.currStateToString().c_str());

            switch (fsm_.getCurrState())
            {

            case lr::ben::FSM::State::START_MISSION:
                fsmRunStartMission();
                break;

            case lr::ben::FSM::State::GLOBAL_NAV_PLANNER:
                fsmRunGlobalNavPlanner();
                break;

            case lr::ben::FSM::State::GLOBAL_NAV_CONTROLLER:
                fsmRunGlobalNavController();
                break;

            case lr::ben::FSM::State::VALIDATION:
                fsmRunValidation();
                break;

            case lr::ben::FSM::State::PERCEPTION:
                fsmRunPerception();
                break;

            case lr::ben::FSM::State::MANIPULATION_PLANNER:
                fsmRunManipulationPlanner();
                break;

            case lr::ben::FSM::State::MANIPULATION_CONTROLLER:
                fsmRunManipulationController();
                break;

            case lr::ben::FSM::State::END_MISSION:
                fsmRunEndMission();
                break;

            case lr::ben::FSM::State::STOPPED:
                fsmRunStopped();
                break;

            case lr::ben::FSM::State::DEBUG:
                fsmRunDebug();
                break;

            case lr::ben::FSM::State::MANUAL_OVERRIDE:
                fsmRunManualOverride();
                break;

            default:
                RCLCPP_WARN(this->get_logger(), "[FSM] State not recognized!");
                break;
            }
        }

        void BenNode::debugTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg)
        {
            debug_trigger_ = msg->data;

            if (debug_trigger_)
            {
                RCLCPP_INFO(this->get_logger(), "[DEBUG] Debug mode triggered. Transitioning to DEBUG state.");

                fsm_.setCurrState(lr::ben::FSM::State::DEBUG);
            }

            debug_trigger_ = false;
        }

        void BenNode::exitDebugTriggerCallback(const lr_msgs::msg::ExitDebug::SharedPtr msg)
        {
            if (fsm_.getCurrState() != lr::ben::FSM::State::DEBUG)
            {
                RCLCPP_WARN(this->get_logger(),
                            "[EXIT_DEBUG] Exit debug requested but not currently in DEBUG state (current state: %s). Ignoring.",
                            fsm_.currStateToString().c_str());
                return;
            }

            exit_debug_trigger_ = true;
            exit_debug_target_state_ = msg->current_state;
            exit_debug_crater_index_ = msg->current_crater_index;
            current_crater_index_ = exit_debug_crater_index_;
            validation_attempts_ = 0;
            first_time_counter_ = 0;

            RCLCPP_INFO(this->get_logger(),
                        "[EXIT_DEBUG] Requested exit from DEBUG to state '%s' at crater index %d.",
                        exit_debug_target_state_.c_str(),
                        exit_debug_crater_index_);
        }

        void BenNode::verboseTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg)
        {
            verbose_trigger_ = msg->data;

            if (verbose_trigger_)
            {
                RCLCPP_INFO(this->get_logger(), "[VERBOSE] Verbose mode triggered.");
            }
        }

        void BenNode::manualOverrideTriggerCallback(const std_msgs::msg::Bool::SharedPtr msg)
        {
            if (fsm_.getCurrState() != lr::ben::FSM::State::MANUAL_OVERRIDE &&
                fsm_.getCurrState() != lr::ben::FSM::State::DEBUG)
            {
                RCLCPP_WARN(this->get_logger(),
                            "[MANUAL_OVERRIDE] Manual override requested but not currently in MANUAL_OVERRIDE or DEBUG state (current state: %s). Ignoring.",
                            fsm_.currStateToString().c_str());
                return;
            }

            manual_override_trigger_ = msg->data;

            if (manual_override_trigger_)
            {
                RCLCPP_INFO(this->get_logger(), "[MANUAL_OVERRIDE] Requesting to enter MANUAL_OVERRIDE state.");
            }
            else
            {
                RCLCPP_INFO(this->get_logger(), "[MANUAL_OVERRIDE] Requesting to exit MANUAL_OVERRIDE state.");
            }
        }

        void BenNode::odomRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
        {
            odom_robot_state_ = *msg;
        }

        void BenNode::globalRobotStateCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
        {
            global_robot_state_ = *msg;
        }

        void BenNode::onCraterMsgCallback(const lr_msgs::msg::CraterStamped::SharedPtr msg)
        {
            std::lock_guard<std::mutex> lock(perception_mutex_);

            latest_crater_ = *msg;
            RCLCPP_INFO(get_logger(),
                        "[CRATER MSG] Crater update — pos=(%.2f, %.2f, %.2f) diam=%.2f",
                        msg->point.x, msg->point.y, msg->point.z, msg->diameter);

            if (pose_request_inflight_)
            {
                RCLCPP_DEBUG(get_logger(), "[CRATER MSG] Pose request already in flight; storing latest crater.");
            }
        }

        // FSM state computations
        // --------------------------------------------------------------------------------------------------------------------- //
        void BenNode::fsmRunStartMission()
        {
            // Turn rover to FULL_AUTONOMY mode
            if (start_mission_delay_count_ == 0)
            {
                lr_msgs::msg::MuxMode mux_msg;
                mux_msg.mode = 2;
                mux_mode_pub_->publish(mux_msg);
                RCLCPP_INFO(this->get_logger(), "[FSM: START_MISSION] Changing MUX mode to FULL_AUTONOMY.");
            }

            // Wait for some time to ensure mode switch
            if (start_mission_delay_count_ < start_mission_delay_iters_)
            {
                start_mission_delay_count_++;
                lr_msgs::msg::MuxMode mux_msg;
                mux_msg.mode = 2;
                mux_mode_pub_->publish(mux_msg);
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: START_MISSION] Waiting for MUX mode switch... (%d/%d)",
                            start_mission_delay_count_,
                            start_mission_delay_iters_);
                return;
            }

            start_mission_delay_count_ = 0;

            got_crater_data_ = false;
            current_crater_index_ = 0;
            first_time_counter_ = 0;

            RCLCPP_INFO(this->get_logger(), "[FSM: START_MISSION] Transitioning to GLOBAL_NAV_PLANNER.");
            fsm_.setCurrState(lr::ben::FSM::State::GLOBAL_NAV_PLANNER);
        }

        void BenNode::fsmRunGlobalNavPlanner()
        {
            std::lock_guard<std::mutex> lock(global_planner_mutex_);

            RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_PLANNER] Running global navigation planner...");

            if (!got_crater_data_ || crater_centroids_.empty())
            {
                RCLCPP_WARN(this->get_logger(), "[FSM: GLOBAL_NAV_PLANNER] No crater data yet. Holding...");
                return;
            }

            if (current_crater_index_ >= static_cast<int>(crater_centroids_.size()))
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_PLANNER] All craters processed. Transitioning to END_MISSION.");
                fsm_.setCurrState(lr::ben::FSM::State::END_MISSION);
                return;
            }

            if (!global_planner_client_->wait_for_service(std::chrono::seconds(5)))
            {
                RCLCPP_WARN(this->get_logger(), "[FSM: GLOBAL_NAV_PLANNER] Planner service not available yet. Holding...");
                return;
            }

            if (planner_req_sent_)
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_PLANNER] Request already sent. Waiting for next cycle...");
                return;
            }

            if (current_crater_index_ == 2)
                current_crater_index_++;

            auto request = std::make_shared<lr_msgs::srv::PlanPath::Request>();
            request->goal.header.stamp = this->now();
            request->goal.header.frame_id = "map";
            request->goal.pose.position = crater_centroids_[current_crater_index_].position;

            if (current_crater_index_ == 0)
            {
                request->goal.pose.position.x += 0.05;
                request->goal.pose.position.y += 0.01;
                request->goal.pose.orientation.x = 0.0;
                request->goal.pose.orientation.y = 0.0;
                request->goal.pose.orientation.z = 0.011;
                request->goal.pose.orientation.w = 0.999;
            }
            else if (current_crater_index_ == 1)
            {
                request->goal.pose.orientation.x = 0.0;
                request->goal.pose.orientation.y = 0.0;
                request->goal.pose.orientation.z = 0.785;
                request->goal.pose.orientation.w = 0.619;
            }
            else if (current_crater_index_ == 3)
            {
                request->goal.pose.orientation.x = 0.0;
                request->goal.pose.orientation.y = 0.0;
                request->goal.pose.orientation.z = -0.998;
                request->goal.pose.orientation.w = 0.065;
            }
            else if (current_crater_index_ == 4)
            {
                request->goal.pose.orientation.x = 0.0;
                request->goal.pose.orientation.y = 0.0;
                request->goal.pose.orientation.z = -0.684;
                request->goal.pose.orientation.w = 0.729;
            }
            else
            {
                request->goal.pose.orientation.x = 0.0;
                request->goal.pose.orientation.y = 0.0;
                request->goal.pose.orientation.z = 0.0;
                request->goal.pose.orientation.w = 0.0;
            }

            request->smooth = true;

            RCLCPP_INFO(this->get_logger(),
                        "[FSM: GLOBAL_NAV_PLANNER] Sending crater #%d goal (x=%.2f, y=%.2f)...",
                        current_crater_index_,
                        request->goal.pose.position.x,
                        request->goal.pose.position.y);

            planner_req_sent_ = true;

            auto future_result = global_planner_client_->async_send_request(
                request,
                [this](rclcpp::Client<lr_msgs::srv::PlanPath>::SharedFuture future)
                {
                    std::lock_guard<std::mutex> lock(global_planner_mutex_);

                    auto response = future.get();
                    planner_req_sent_ = false;

                    if (!response->success)
                    {
                        RCLCPP_ERROR(this->get_logger(),
                                     "[FSM: GLOBAL_NAV_PLANNER] Planning failed for crater #%d: %s",
                                     current_crater_index_,
                                     response->message.c_str());
                        return;
                    }

                    RCLCPP_INFO(this->get_logger(),
                                "[FSM: GLOBAL_NAV_PLANNER] Planning success for crater #%d. Path size = %zu",
                                current_crater_index_,
                                response->path.poses.size());

                    global_path_to_send_ = response->path;

                    RCLCPP_INFO(this->get_logger(),
                                "[FSM: GLOBAL_NAV_PLANNER] Transitioning to GLOBAL_NAV_CONTROLLER.");
                    fsm_.setCurrState(lr::ben::FSM::State::GLOBAL_NAV_CONTROLLER);
                });

            RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_PLANNER] Sent plan request for crater #%d.", current_crater_index_);
        }

        void BenNode::fsmRunGlobalNavController()
        {
            std::lock_guard<std::mutex> lock(nav_mutex_);
            if (nav_goal_active_)
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Goal is already active, waiting for result...");
                return;
            }

            if (nav_last_success_.has_value())
            {
                bool success = *nav_last_success_;
                nav_last_success_.reset();

                if (success)
                {
                    RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Path following SUCCEEDED.");
                    if (first_time_counter_ == 0)
                    {
                        first_time_counter_++;
                        RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Running Nav again...");
                        fsm_.setCurrState(lr::ben::FSM::State::GLOBAL_NAV_PLANNER);
                    }
                    else
                    {
                        RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Transitioning to VALIDATION.");
                        fsm_.setCurrState(lr::ben::FSM::State::VALIDATION);
                    }
                }
                else
                {
                    RCLCPP_WARN(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Path following FAILED or was CANCELED. Holding in state.");
                }
                return;
            }

            if (!global_path_to_send_.poses.empty())
            {
                if (!nav_client_ || !nav_client_->wait_for_action_server(std::chrono::seconds(1)))
                {
                    RCLCPP_WARN(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Action server '/follow_path' not available. Waiting...");
                    return;
                }

                // Create and send the goal
                auto goal_msg = FollowPath::Goal();
                goal_msg.path = global_path_to_send_;
                goal_msg.direction = "Forward"; // Global navigation is always "Forward"
                goal_msg.tool_position = tool_height_up_;

                global_path_to_send_.poses.clear();

                RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Sending path goal (direction: Forward).");

                nav_goal_active_ = true;

                auto send_goal_options = rclcpp_action::Client<FollowPath>::SendGoalOptions();

                send_goal_options.result_callback =
                    [this](const GoalHandleFollowPath::WrappedResult &result)
                {
                    std::lock_guard<std::mutex> lock(nav_mutex_);
                    nav_goal_active_ = false;
                    if (result.code == rclcpp_action::ResultCode::SUCCEEDED)
                    {
                        nav_last_success_ = result.result->success;
                    }
                    else
                    {
                        nav_last_success_ = false; // Goal was aborted, canceled, or rejected
                    }
                    RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Goal finished.");
                };

                send_goal_options.feedback_callback =
                    [this](GoalHandleFollowPath::SharedPtr, const std::shared_ptr<const FollowPath::Feedback> feedback)
                {
                    if (verbose_trigger_)
                    {
                        RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Feedback: Distance to goal: %.2f m", feedback->distance_to_goal);
                    }
                };

                nav_client_->async_send_goal(goal_msg, send_goal_options);
            }
            else
            {
                RCLCPP_WARN(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] No global path to follow. Holding in state.");
                return;
            }
        }

        void BenNode::fsmRunValidation()
        {
            std::lock_guard<std::mutex> lock(validation_mutex_);

            if (!validation_goal_active_)
            {
                // Previous goal completed, check result
                if (validation_last_success_.has_value())
                {
                    const bool ok = *validation_last_success_;
                    validation_last_success_.reset();

                    if (ok)
                    {
                        RCLCPP_INFO(this->get_logger(),
                                    "[FSM: VALIDATION] Grading SUCCESS. Transitioning to GLOBAL_NAV_PLANNER.");
                        validation_attempts_ = 0;
                        first_time_counter_ = 0;
                        current_crater_index_++;
                        fsm_.setCurrState(lr::ben::FSM::State::GLOBAL_NAV_PLANNER);
                        return;
                    }
                    else
                    {
                        RCLCPP_WARN(this->get_logger(),
                                    "[FSM: VALIDATION] Grading FAILED. Transitioning to PERCEPTION.");
                        validation_attempts_++;
                        if (validation_attempts_ > 2)
                        {
                            RCLCPP_INFO(this->get_logger(), "[FSM: VALIDATION] Grading not satisfacory even after 3 attempts. Moving to next crater. Transitioning to GLOBAL_NAV_PLANNER.");
                            validation_attempts_ = 0;
                            first_time_counter_ = 0;
                            current_crater_index_++;
                            fsm_.setCurrState(lr::ben::FSM::State::GLOBAL_NAV_PLANNER);
                        }
                        else
                        {
                            fsm_.setCurrState(lr::ben::FSM::State::PERCEPTION);
                        }
                        return;
                    }
                }

                // No active goal, send a new one
                if (!validation_client_->action_server_is_ready())
                {
                    RCLCPP_WARN(this->get_logger(),
                                "[FSM: VALIDATION] Validation server not ready yet. Holding in VALIDATION.");
                    return;
                }

                lr_msgs::action::RunValidation::Goal goal;
                goal.average_window = validation_average_window_;
                goal.do_second_pass = validation_do_second_pass_;
                goal.timeout_sec = validation_timeout_sec_;

                rclcpp_action::Client<lr_msgs::action::RunValidation>::SendGoalOptions opts;

                // Intermediate feedback
                opts.feedback_callback =
                    [this](rclcpp_action::ClientGoalHandle<lr_msgs::action::RunValidation>::SharedPtr,
                           const std::shared_ptr<const lr_msgs::action::RunValidation::Feedback> fb)
                {
                    RCLCPP_INFO(this->get_logger(), "[FSM: VALIDATION] Feedback: collected=%d/%d",
                                fb->collected, validation_average_window_);

                    if (verbose_trigger_)
                    {
                        RCLCPP_INFO(this->get_logger(),
                                    "[FSM: VALIDATION] Verbose Feedback: mean=%.2f rmse=%.2f max=%.2f min_z=%.2f max_z=%.2f avg_z=%.2f",
                                    fb->current_mean_gradient,
                                    fb->current_rmse_gradient,
                                    fb->current_max_gradient,
                                    fb->current_min_z,
                                    fb->current_max_z,
                                    fb->current_avg_z);
                    }
                };

                // Final result
                opts.result_callback =
                    [this](const rclcpp_action::ClientGoalHandle<lr_msgs::action::RunValidation>::WrappedResult &res)
                {
                    std::lock_guard<std::mutex> lock(validation_mutex_);
                    validation_goal_active_ = false;

                    if (res.code == rclcpp_action::ResultCode::SUCCEEDED && res.result)
                    {
                        validation_last_success_ = res.result->grading_success;
                        validation_last_max_z_ = res.result->max_z;
                        RCLCPP_INFO(this->get_logger(),
                                    "[FSM: VALIDATION] Result: success=%s mean=%.2f rmse=%.2f max=%.2f max_trav=%.2f min_z=%.2f max_z=%.2f avg_z=%.2f",
                                    res.result->grading_success ? "true" : "false",
                                    res.result->mean_gradient,
                                    res.result->rmse_gradient,
                                    res.result->max_gradient,
                                    res.result->max_traversal_slope,
                                    res.result->min_z,
                                    res.result->max_z,
                                    res.result->avg_z);
                    }
                    else
                    {
                        validation_goal_active_ = false;
                        validation_last_success_.reset();
                        RCLCPP_WARN(this->get_logger(),
                                    "[FSM: VALIDATION] Result: Aborted/Cancelled/Error (code=%d). Trying again.",
                                    static_cast<int>(res.code));
                    }
                };

                // Goal acceptance
                opts.goal_response_callback =
                    [this](std::shared_ptr<rclcpp_action::ClientGoalHandle<lr_msgs::action::RunValidation>> gh)
                {
                    std::lock_guard<std::mutex> lock(validation_mutex_);

                    if (!gh)
                    {
                        validation_goal_active_ = false;
                        validation_last_success_ = false;
                        RCLCPP_WARN(this->get_logger(), "[FSM: VALIDATION] Goal rejected.");
                        return;
                    }
                    validation_goal_active_ = true;
                    RCLCPP_INFO(this->get_logger(), "[FSM: VALIDATION] Goal accepted.");
                };

                (void)validation_client_->async_send_goal(goal, opts);
                RCLCPP_INFO(this->get_logger(), "[FSM: VALIDATION] Sent validation goal. Waiting for result.");
                return;
            }

            RCLCPP_INFO(this->get_logger(), "[FSM: VALIDATION] Goal in progress. Waiting for result.");
        }

        void BenNode::fsmRunPerception()
        {
            std::lock_guard<std::mutex> lock(perception_mutex_);

            // Skip perceptionif not the first attempt
            if (validation_attempts_ > 1)
            {
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: PERCEPTION] Skipping perception on attempt %d. Transitioning to MANIPULATION_PLANNER.",
                            validation_attempts_);
                fsm_.setCurrState(lr::ben::FSM::State::MANIPULATION_PLANNER);
                return;
            }

            // Start crater detection action if not already active
            if (!perception_goal_active_)
            {
                if (!crater_detect_client_->action_server_is_ready())
                {
                    RCLCPP_WARN(this->get_logger(), "[FSM: PERCEPTION] Crater detection action server not available yet. Holding in PERCEPTION.");
                    return;
                }

                lr_msgs::action::CraterDetect::Goal goal;
                goal.start_detection = true;

                rclcpp_action::Client<lr_msgs::action::CraterDetect>::SendGoalOptions opts;

                // Intermediate feedback
                opts.feedback_callback =
                    [this](rclcpp_action::ClientGoalHandle<lr_msgs::action::CraterDetect>::SharedPtr,
                           const std::shared_ptr<const lr_msgs::action::CraterDetect::Feedback> fb)
                {
                    if (fb && verbose_trigger_)
                    {
                        RCLCPP_INFO_THROTTLE(
                            this->get_logger(),
                            *this->get_clock(),
                            2000,
                            "[FSM: PERCEPTION] Verbose Feedback: craters detected so far: %d",
                            fb->num_craters_detected);
                    }
                };

                // Final result
                opts.result_callback =
                    [this](const rclcpp_action::ClientGoalHandle<lr_msgs::action::CraterDetect>::WrappedResult &result)
                {
                    std::lock_guard<std::mutex> lock(perception_mutex_);

                    if (result.code != rclcpp_action::ResultCode::SUCCEEDED)
                    {
                        RCLCPP_WARN(this->get_logger(), "Result code: %s",
                                    (result.code == rclcpp_action::ResultCode::SUCCEEDED ? "SUCCEEDED" : result.code == rclcpp_action::ResultCode::ABORTED ? "ABORTED"
                                                                                                     : result.code == rclcpp_action::ResultCode::CANCELED  ? "CANCELED"
                                                                                                                                                           : "UNKNOWN"));

                        perception_goal_active_ = false;
                    }
                    else
                    {
                        RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Result: detect_crater action succeeded.");
                    }
                };

                // Goal acceptance
                opts.goal_response_callback =
                    [this](std::shared_ptr<rclcpp_action::ClientGoalHandle<lr_msgs::action::CraterDetect>> gh)
                {
                    if (!gh)
                    {
                        RCLCPP_WARN(this->get_logger(), "[FSM: PERCEPTION] Crater detection goal rejected.");
                        perception_goal_active_ = false;
                        return;
                    }

                    RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Crater detection goal accepted.");
                    crater_detect_goal_handle_ = gh;
                };

                crater_detect_client_->async_send_goal(goal, opts);
                perception_goal_active_ = true;
                RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Sent detect_crater goal. Waiting for result.");
                return;
            }

            // Wait for a crater message to arrive
            if (!latest_crater_)
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Waiting for /crater_detection/crater update...");
                return;
            }

            // Avoid concurrent service calls
            if (pose_request_inflight_)
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Pose extraction already in progress.");
                return;
            }

            // Ensure the pose-extract service is ready
            if (!pose_extract_client_->service_is_ready())
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Waiting for generate_crater_goals service...");
                return;
            }

            // Call the pose-extract service to get goal poses
            auto request = std::make_shared<lr_msgs::srv::PoseExtract::Request>();
            request->centroid = latest_crater_->point;
            request->diameter = static_cast<float>(latest_crater_->diameter);

            RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Requested crater goals from service.");

            pose_request_inflight_ = true;
            pose_extract_client_->async_send_request(
                request,
                [this](rclcpp::Client<lr_msgs::srv::PoseExtract>::SharedFuture future)
                {
                    std::lock_guard<std::mutex> lock(perception_mutex_);
                    pose_request_inflight_ = false;

                    try
                    {
                        auto response = future.get();
                        goal_poses_ = response->goal_poses;
                        goal_pose_types_ = response->goal_types;

                        if (!response->success || goal_poses_.empty())
                        {
                            RCLCPP_WARN(this->get_logger(),
                                        "[FSM: PERCEPTION] Pose extraction failed: %s",
                                        response->message.c_str());
                            latest_crater_.reset();
                            return;
                        }

                        RCLCPP_INFO(this->get_logger(),
                                    "[FSM: PERCEPTION] Pose extraction succeeded: %s",
                                    response->message.c_str());

                        if (verbose_trigger_)
                        {
                            for (size_t i = 0; i < goal_poses_.size(); ++i)
                            {
                                const auto &pose = goal_poses_[i];
                                const auto type = (i < goal_pose_types_.size()) ? goal_pose_types_[i] : "unknown";
                                RCLCPP_INFO(this->get_logger(),
                                            "[FSM: PERCEPTION] Verbose: goal[%zu] type=%s x=%.2f y=%.2f yaw=%.2f",
                                            i, type.c_str(), pose.pt.x, pose.pt.y, pose.yaw);
                            }
                        }

                        // if (crater_detect_goal_handle_)
                        // {
                        //     crater_detect_client_->async_cancel_goal(crater_detect_goal_handle_);
                        //     crater_detect_goal_handle_.reset();
                        // }

                        latest_crater_.reset();
                        perception_goal_active_ = false;
                    }
                    catch (const std::exception &e)
                    {
                        RCLCPP_ERROR(this->get_logger(),
                                     "[FSM: PERCEPTION] Pose extraction request threw: %s",
                                     e.what());
                        latest_crater_.reset();
                    }
                });

            RCLCPP_INFO(this->get_logger(), "[FSM: PERCEPTION] Transitioning to MANIPULATION_PLANNER.");
            fsm_.setCurrState(lr::ben::FSM::State::MANIPULATION_PLANNER);
        }

        void BenNode::fsmRunManipulationPlanner()
        {
            std::lock_guard<std::mutex> lock(manipulation_planner_mutex_);

            RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_PLANNER] Running manipulation planner...");

            if (goal_poses_.empty())
            {
                RCLCPP_WARN(this->get_logger(), "[FSM: MANIPULATION_PLANNER] No goal poses from perception. Returning to PERCEPTION.");
                current_goal_pose_idx_ = 0;
                fsm_.setCurrState(lr::ben::FSM::State::PERCEPTION);
                return;
            }

            if (current_goal_pose_idx_ >= static_cast<int>(goal_poses_.size()))
            {
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: MANIPULATION_PLANNER] Completed all %zu manipulation goal poses. Transitioning to VALIDATION.",
                            goal_poses_.size());
                // goal_poses_.clear();
                current_goal_pose_idx_ = 0;
                fsm_.setCurrState(lr::ben::FSM::State::VALIDATION);
                return;
            }

            if (!manipulation_planner_client_->wait_for_service(std::chrono::seconds(5)))
            {
                RCLCPP_WARN(this->get_logger(), "[FSM: MANIPULATION_PLANNER] Manipulation planner service not available yet. Holding...");
                return;
            }

            if (manipulation_req_sent_)
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_PLANNER] Request already sent. Waiting for next cycle...");
                return;
            }

            const auto &goal_pose = goal_poses_[current_goal_pose_idx_];
            std::string type = goal_pose_types_[current_goal_pose_idx_];

            // if (type == "source")
            // {
            //     RCLCPP_INFO(this->get_logger(),
            //                 "[FSM: MANIPULATION_PLANNER] Skipping goal %d (type=source).",
            //                 current_goal_pose_idx_);
            //     ++current_goal_pose_idx_;

            //     return;
            // }
            local_goal_type_ = type;
            if (type == "source" || type == "sink" || type == "source_backblade")
                manipulation_type_ = "Forward_manipulation";
            else
                manipulation_type_ = "Backward";

            auto request = std::make_shared<lr_msgs::srv::PlanPath::Request>();
            request->goal.header.stamp = this->now();
            request->goal.header.frame_id = "map";
            request->goal.pose.position.x = goal_pose.pt.x;
            request->goal.pose.position.y = goal_pose.pt.y;
            request->goal.pose.orientation.w = 1.0;
            request->smooth = true;

            RCLCPP_INFO(this->get_logger(),
                        "[FSM: MANIPULATION_PLANNER] Planning to pose %d/%zu (x=%.2f, y=%.2f) type_raw=%s -> action=%s",
                        current_goal_pose_idx_, goal_poses_.size(),
                        goal_pose.pt.x, goal_pose.pt.y,
                        type.c_str(), manipulation_type_.c_str());

            manipulation_req_sent_ = true;

            auto future_result = manipulation_planner_client_->async_send_request(
                request,
                [this](rclcpp::Client<lr_msgs::srv::PlanPath>::SharedFuture future)
                {
                    std::lock_guard<std::mutex> lock(manipulation_planner_mutex_);

                    manipulation_req_sent_ = false;
                    auto response = future.get();

                    if (!response->success)
                    {
                        RCLCPP_ERROR(this->get_logger(),
                                     "[FSM: MANIPULATION_PLANNER] Planning failed for pose index %d: %s",
                                     current_goal_pose_idx_, response->message.c_str());
                        return;
                    }

                    RCLCPP_INFO(this->get_logger(),
                                "[FSM: MANIPULATION_PLANNER] Planning success for pose index %d. Path size = %zu",
                                current_goal_pose_idx_, response->path.poses.size());

                    manipulation_path_to_send_ = response->path;
                    ++current_goal_pose_idx_;

                    RCLCPP_INFO(this->get_logger(),
                                "[FSM: MANIPULATION_PLANNER] Transitioning to MANIPULATION_CONTROLLER.");
                    fsm_.setCurrState(lr::ben::FSM::State::MANIPULATION_CONTROLLER);
                });

            RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_PLANNER] Sent plan request for pose index %d.", current_goal_pose_idx_);
        }

        void BenNode::fsmRunManipulationController()
        {
            std::lock_guard<std::mutex> lock(nav_mutex_);

            if (nav_goal_active_)
            {
                RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] Goal is already active, waiting for result...");
                return;
            }

            if (nav_last_success_.has_value())
            {
                bool success = *nav_last_success_;
                nav_last_success_.reset();

                if (success)
                {
                    RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] Path following SUCCEEDED.");
                    RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] Transitioning to VALIDATION.");
                    fsm_.setCurrState(lr::ben::FSM::State::MANIPULATION_PLANNER);
                }
                else
                {
                    RCLCPP_WARN(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] Path following FAILED or was CANCELED. Holding in state.");
                }
                return;
            }

            if (!manipulation_path_to_send_.poses.empty())
            {
                if (!nav_client_ || !nav_client_->wait_for_action_server(std::chrono::seconds(1)))
                {
                    RCLCPP_WARN(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] Action server '/follow_path' not available. Waiting...");
                    return;
                }

                // Create and send the goal
                auto goal_msg = FollowPath::Goal();
                goal_msg.path = manipulation_path_to_send_;
                goal_msg.direction = manipulation_type_; // Get direction from planner state

                manipulation_path_to_send_.poses.clear();
                manipulation_type_.clear();

                if (local_goal_type_ == "source" || local_goal_type_ == "source_backblade")
                {
                    if (validation_attempts_ > 1)
                    {
                        goal_msg.tool_position = tool_height_up_second_pass_;
                    }
                    else
                    {
                        goal_msg.tool_position = tool_height_up_;
                    }
                }
                else if (local_goal_type_ == "sink" || local_goal_type_ == "sink_backblade")
                {
                    if (validation_attempts_ > 1)
                    {
                        goal_msg.tool_position = 0.0;
                        RCLCPP_INFO(this->get_logger(), "Tool going lower ...");
                    }
                    else
                    {
                        goal_msg.tool_position = tool_height_down_;
                    }
                }
                RCLCPP_INFO(this->get_logger(), "Tool position: %.f", goal_msg.tool_position);

                RCLCPP_INFO(this->get_logger(), "Validation attempt number: %d", validation_attempts_);

                RCLCPP_INFO(this->get_logger(), "[FSM: GLOBAL_NAV_CONTROLLER] Sending path goal (direction: Forward).");
                nav_goal_active_ = true;

                auto send_goal_options = rclcpp_action::Client<FollowPath>::SendGoalOptions();

                send_goal_options.result_callback =
                    [this](const GoalHandleFollowPath::WrappedResult &result)
                {
                    std::lock_guard<std::mutex> lock(nav_mutex_);
                    nav_goal_active_ = false;
                    if (result.code == rclcpp_action::ResultCode::SUCCEEDED)
                    {
                        nav_last_success_ = result.result->success;
                    }
                    else
                    {
                        nav_last_success_ = false; // Goal was aborted, canceled, or rejected
                    }
                    RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] Goal finished.");
                };

                send_goal_options.feedback_callback =
                    [this](GoalHandleFollowPath::SharedPtr, const std::shared_ptr<const FollowPath::Feedback> feedback)
                {
                    if (verbose_trigger_)
                    {
                        RCLCPP_INFO(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] Feedback: Distance to goal: %.2f m", feedback->distance_to_goal);
                    }
                };

                nav_client_->async_send_goal(goal_msg, send_goal_options);
            }
            else
            {
                RCLCPP_WARN(this->get_logger(), "[FSM: MANIPULATION_CONTROLLER] No global path to follow. Holding in state.");
                return;
            }
        }

        void BenNode::fsmRunEndMission()
        {
            // Turn rover to IDLE mode
            if (end_mission_delay_count_ == 0)
            {
                lr_msgs::msg::MuxMode mux_msg;
                mux_msg.mode = 0;
                mux_mode_pub_->publish(mux_msg);
                RCLCPP_INFO(this->get_logger(), "[FSM: END_MISSION] Changing MUX mode to IDLE.");
            }

            // Wait for some time to ensure mode switch
            if (end_mission_delay_count_ < end_mission_delay_iters_)
            {
                end_mission_delay_count_++;
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: END_MISSION] Waiting for MUX mode switch... (%d/%d)",
                            end_mission_delay_count_,
                            end_mission_delay_iters_);
                return;
            }

            end_mission_delay_count_ = 0;
            RCLCPP_INFO(this->get_logger(), "[FSM: END_MISSION] Mission ended. Transitioning to STOPPED.");
            fsm_.setCurrState(lr::ben::FSM::State::STOPPED);
        }

        void BenNode::fsmRunStopped()
        {
            RCLCPP_INFO(this->get_logger(), "[FSM: STOPPED] Mission has ended. Robot is stopped.");
        }

        void BenNode::fsmRunDebug()
        {
            RCLCPP_INFO(this->get_logger(), "[FSM: DEBUG] Debug state active.");

            if (manual_override_trigger_)
            {
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: DEBUG] Manual override requested. Transitioning to MANUAL_OVERRIDE.");
                fsm_.setCurrState(lr::ben::FSM::State::MANUAL_OVERRIDE);
                return;
            }

            if (exit_debug_trigger_)
            {
                exit_debug_trigger_ = false;

                auto target = fsm_.stringToState(exit_debug_target_state_);
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: DEBUG] Exiting DEBUG state to target state '%s' at crater index %d.",
                            exit_debug_target_state_.c_str(),
                            exit_debug_crater_index_);

                fsm_.setCurrState(target);
            }
        }

        void BenNode::fsmRunManualOverride()
        {
            RCLCPP_INFO(this->get_logger(), "[FSM: MANUAL_OVERRIDE] Manual override state active.");

            if (!entered_once_)
            {
                lr_msgs::msg::MuxMode mux_msg;
                mux_msg.mode = 3;
                mux_mode_pub_->publish(mux_msg);

                entered_once_ = true;
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: MANUAL_OVERRIDE] Entered MANUAL_OVERRIDE: Changing MUX mode to FULL_TELEOP.");
            }

            if (!manual_override_trigger_)
            {
                lr_msgs::msg::MuxMode mux_msg;
                mux_msg.mode = 0;
                mux_mode_pub_->publish(mux_msg);

                RCLCPP_INFO(this->get_logger(),
                            "[FSM: MANUAL_OVERRIDE] Exiting MANUAL_OVERRIDE: Changing MUX mode to FULL_AUTONOMY.");

                entered_once_ = false;
                RCLCPP_INFO(this->get_logger(),
                            "[FSM: MANUAL_OVERRIDE] Transitioning back to DEBUG.");
                fsm_.setCurrState(lr::ben::FSM::State::DEBUG);
                return;
            }
        }

    } // namespace ben
} // namespace lr
