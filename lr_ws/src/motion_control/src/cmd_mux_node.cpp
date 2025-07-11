/**
 * @file cmd_mux_node.cpp
 * @brief Multiplexes teleoperation and autonomy actuator commands based on current control mode and publishes the selected command.
 *
 * This node manages control input routing for different operational modes including IDLE, AUTOGRADER, FULL_AUTONOMY, and FULL_TELEOP.
 * It listens to actuator commands from both autonomy and teleop sources, and selects the appropriate command based on the current multiplexer mode.
 * Additionally, it publishes diagnostic information about command frequency and mux state.
 *
 * @author Boxiang (William) Fu
 * @version 1.0.0
 * @date 2025-06-23
 *
 * Maintainer: Boxiang (William) Fu  
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /mux_mode: [lr_msgs::msg::MuxMode] Updates the active command source mode (e.g. teleop, autonomy).
 * - /teleop_cmd: [lr_msgs::msg::ActuatorCommand] Actuator commands from teleoperation interface.
 * - /autonomy_cmd: [lr_msgs::msg::ActuatorCommand] Actuator commands from the autonomy stack.
 *
 * Publishers:
 * - /actuator_cmd: [lr_msgs::msg::ActuatorCommand] Final multiplexed actuator command sent to the vehicle.
 * - /diagnostics: [diagnostic_msgs::msg::DiagnosticArray] Diagnostic information including command frequency and mux state.
 *
 * Services:
 * - None
 * 
 * @credit Benjamin Younes, Team CraterGrader
 */


#include "motion_control/cmdmux_node.hpp"

namespace lr {
namespace cmdmux {

  CmdMuxNode::CmdMuxNode() : Node("cmd_mux"), diagnostic_updater_(this)
  {
    /* Initialize publishers and subscribers */
    // Actuator command to Arduino
    cmd_pub_ = this->create_publisher<lr_msgs::msg::ActuatorCommand>(
        "/actuator_cmd", 1);

    // Multiplexer mode number
    mode_sub_ = this->create_subscription<lr_msgs::msg::MuxMode>(
        "/mux_mode", 1, std::bind(&CmdMuxNode::modeCallback, this, std::placeholders::_1));

    // Teleop and autonomy control messages
    teleop_sub_ = this->create_subscription<lr_msgs::msg::ActuatorCommand>(
        "/teleop_cmd", 1, std::bind(&CmdMuxNode::teleopCallback, this, std::placeholders::_1));
    autonomy_sub_ = this->create_subscription<lr_msgs::msg::ActuatorCommand>(
        "/autonomy_cmd", 1, std::bind(&CmdMuxNode::autonomyCallback, this, std::placeholders::_1));

    diagnostic_pub_ = this->create_publisher<diagnostic_msgs::msg::DiagnosticArray>(
        "/diagnostics", 1);

    // Timer callback
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(100),
        std::bind(&CmdMuxNode::timerCallback, this));

    // Initialize the current mode to the default mode
    curr_mux_mode_ = lr_msgs::msg::MuxMode::IDLE;

    // Diagnostics
    this->declare_parameter<double>("freq_min_act_cmd", 1.0);
    this->get_parameter("freq_min_act_cmd", freq_min_act_cmd_);
    this->declare_parameter<double>("freq_max_act_cmd", 100.0);
    this->get_parameter("freq_max_act_cmd", freq_max_act_cmd_);
    this->declare_parameter<double>("freq_tol_act_cmd", 0.1);
    this->get_parameter("freq_tol_act_cmd", freq_tol_act_cmd_);
    this->declare_parameter<int>("freq_window_act_cmd", 5);
    this->get_parameter("freq_window_act_cmd", freq_window_act_cmd_);

    // Initialize Diagnostics
    diagnostic_updater_.add("cmd_mux", this, &CmdMuxNode::populateDiagnosticsStatus);
    actuator_cmd_freq_.reset(new diagnostic_updater::HeaderlessTopicDiagnostic("/actuator_cmd", diagnostic_updater_, diagnostic_updater::FrequencyStatusParam(&freq_min_act_cmd_, &freq_max_act_cmd_, freq_tol_act_cmd_, freq_window_act_cmd_)));
  }

void CmdMuxNode::populateDiagnosticsStatus(diagnostic_updater::DiagnosticStatusWrapper &stat)
{
  stat.summary(diagnostic_msgs::msg::DiagnosticStatus::OK, "OK");

  // Report the current mux mode
  if (curr_mux_mode_ == lr_msgs::msg::MuxMode::IDLE) {
    stat.add("Mux Mode", "IDLE");
  }
  else if (curr_mux_mode_ == lr_msgs::msg::MuxMode::AUTOGRADER)
  {
    stat.add("Mux Mode", "AUTOGRADER");
  }
  else if (curr_mux_mode_ == lr_msgs::msg::MuxMode::FULL_AUTONOMY)
  {
    stat.add("Mux Mode", "FULL_AUTONOMY");
  }
  else if (curr_mux_mode_ == lr_msgs::msg::MuxMode::FULL_TELEOP)
  {
    stat.add("Mux Mode", "FULL_TELEOP");
  }
  else if (curr_mux_mode_ > lr_msgs::msg::MuxMode::HIGHEST_VALID_MODE)
  {
    stat.summary(diagnostic_msgs::msg::DiagnosticStatus::ERROR, "Undefined Mux Mode");
    stat.addf("Undefined Mux Mode:", "%u", curr_mux_mode_);
  }
}

void CmdMuxNode::timerCallback()
{
  // Report the current mode
  RCLCPP_INFO(this->get_logger(), "Current multiplexer mode: %d", curr_mux_mode_);

  // Handle message based on current multiplexer mode
  if (curr_mux_mode_ == lr_msgs::msg::MuxMode::IDLE)
  {
    // Publish last message, with wheel velocity set to zero
    cmd_msg_.wheel_velocity = 0.0;
  }

  // Clamp commands
  cmd_msg_.wheel_velocity = std::max(-40.0, std::min(cmd_msg_.wheel_velocity, 40.0)); // [-100.0, 100.0]
  cmd_msg_.steer_position = std::max(-65.0, std::min(cmd_msg_.steer_position, 65.0)); // [-100.0, 100.0]
  cmd_msg_.tool_position = std::max(0.0, std::min(cmd_msg_.tool_position, 100.0)); // [0.0, 100.0]

  // Publish the message
  cmd_msg_.header.stamp = this->get_clock()->now();
  cmd_pub_->publish(cmd_msg_); // Keep using the same message, so last message is retained unless changed
  actuator_cmd_freq_->tick(); // Log frequency for diagnostics
}

void CmdMuxNode::modeCallback(const lr_msgs::msg::MuxMode::SharedPtr msg)
{

  // Check for valid input
  if (msg->mode > lr_msgs::msg::MuxMode::HIGHEST_VALID_MODE)
  {
    // Warn about invalid mode input
    RCLCPP_WARN(this->get_logger(), "Unsupported multiplexer mode request: %d", msg->mode);
    return; // Don't let the mode be updated
  }

  // Set the current mode using the incoming mode number
  curr_mux_mode_ = msg->mode;
}

void CmdMuxNode::teleopCallback(const lr_msgs::msg::ActuatorCommand::SharedPtr msg) {

  // Handle message based on current multiplexer mode
  if (curr_mux_mode_ == lr_msgs::msg::MuxMode::AUTOGRADER)
  {
    // Update only the wheel velocity and steering position inputs
    cmd_msg_.wheel_velocity = msg->wheel_velocity;
    cmd_msg_.steer_position = msg->steer_position;
  }
  else if (curr_mux_mode_ == lr_msgs::msg::MuxMode::FULL_TELEOP)
  {
    // Update the command message directly
    cmd_msg_ = *msg;

    // cmd_msg_.wheel_velocity = -msg->wheel_velocity;
  }
}

void CmdMuxNode::autonomyCallback(const lr_msgs::msg::ActuatorCommand::SharedPtr msg)
{

  // Handle message based on current multiplexer mode
  if (curr_mux_mode_ == lr_msgs::msg::MuxMode::AUTOGRADER)
  {
    // Update only the tool position
    cmd_msg_.tool_position = msg->tool_position;
  }
  else if (curr_mux_mode_ == lr_msgs::msg::MuxMode::FULL_AUTONOMY)
  {
    // Update the command message directly
    cmd_msg_ = *msg;
  }
  
}

} // namespace cmdmux
} // namespace lr