/**
 * @file cmd_mux_node.cpp
 * @brief Multiplexes teleoperation and autonomy actuator commands based on current control mode and publishes the selected command.
 *
 * This node manages control input routing for different operational modes including IDLE, AUTOGRADER, FULL_AUTONOMY, and FULL_TELEOP.
 * It listens to actuator commands from both autonomy and teleop sources, and selects the appropriate command based on the current multiplexer mode.
 * Additionally, it publishes diagnostic information about command frequency and mux state.
 *
 * @author Boxiang (William) Fu
 * @version 1.0.1
 * @date 2025-11-15
 *
 * Maintainer: Boxiang (William) Fu  
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D?Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /mux_mode: [lr_msgs::msg::MuxMode] Updates the active command source mode (e.g. teleop, autonomy).
 * - /teleop_cmd: [lr_msgs::msg::ActuatorCommand] Actuator commands from teleoperation interface.
 * - /autonomy_cmd: [lr_msgs::msg::ActuatorCommand] Actuator commands from the autonomy stack.
 * - /gui_drive_cmd: [geometry_msgs::msg::Twist] Overlay commands from GUI for driving control.
 * - /gui_tool_cmd: [geometry_msgs::msg::Twist] Overlay commands from GUI for tool control.
 *
 * Publishers:
 * - /actuator_cmd: [lr_msgs::msg::ActuatorCommand] Final multiplexed actuator command sent to the vehicle.
 * - /cum_gui_cmd: [lr_msgs::msg::ActuatorCommand] Cumulative GUI overlay commands for debugging.
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

    gui_cmd_pub_ = this->create_publisher<lr_msgs::msg::ActuatorCommand>(
        "/cum_gui_cmd", 1);

    // Multiplexer mode number
    mode_sub_ = this->create_subscription<lr_msgs::msg::MuxMode>(
        "/mux_mode", 1, std::bind(&CmdMuxNode::modeCallback, this, std::placeholders::_1));

    // Teleop and autonomy control messages
    teleop_sub_ = this->create_subscription<lr_msgs::msg::ActuatorCommand>(
        "/teleop_cmd", 1, std::bind(&CmdMuxNode::teleopCallback, this, std::placeholders::_1));

    autonomy_sub_ = this->create_subscription<lr_msgs::msg::ActuatorCommand>(
        "/autonomy_cmd", 1, std::bind(&CmdMuxNode::autonomyCallback, this, std::placeholders::_1));

    // GUI command subscription
    gui_drive_cmd_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "/gui_drive_cmd",
        10,
        std::bind(&CmdMuxNode::guiDriveCmdCallback, this, std::placeholders::_1));
    
    gui_tool_cmd_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
        "/gui_tool_cmd",
        10,
        std::bind(&CmdMuxNode::guiToolCmdCallback, this, std::placeholders::_1));

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
    this->declare_parameter<double>("clamp_wheel_velocity_min", -40.0);
    this->get_parameter("clamp_wheel_velocity_min", clamp_wheel_velocity_min_);
    this->declare_parameter<double>("clamp_wheel_velocity_max", 40.0);
    this->get_parameter("clamp_wheel_velocity_max", clamp_wheel_velocity_max_);
    this->declare_parameter<double>("clamp_steer_position_min", -65.0);
    this->get_parameter("clamp_steer_position_min", clamp_steer_position_min_);
    this->declare_parameter<double>("clamp_steer_position_max", 65.0);
    this->get_parameter("clamp_steer_position_max", clamp_steer_position_max_);
    this->declare_parameter<double>("clamp_tool_position_min", 0.0);
    this->get_parameter("clamp_tool_position_min", clamp_tool_position_min_);
    this->declare_parameter<double>("clamp_tool_position_max", 100.0);
    this->get_parameter("clamp_tool_position_max", clamp_tool_position_max_);

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
  RCLCPP_INFO_THROTTLE(this->get_logger(), *this->get_clock(), 2000, "Current multiplexer mode: %d", curr_mux_mode_);

  // Handle message based on current multiplexer mode
  if (curr_mux_mode_ == lr_msgs::msg::MuxMode::IDLE)
  {
    // Publish last message, with wheel velocity set to zero
    cmd_msg_.wheel_velocity = 0.0;
  }

  // Add GUI command overlay
  cmd_msg_.wheel_velocity += cum_gui_cmd_.linear.x;
  cmd_msg_.steer_position += cum_gui_cmd_.angular.z;
  cmd_msg_.tool_position += cum_gui_cmd_.linear.z;

  // Clamp commands
  cmd_msg_.wheel_velocity = std::max(clamp_wheel_velocity_min_, std::min(cmd_msg_.wheel_velocity, clamp_wheel_velocity_max_)); // [-100.0, 100.0]
  cmd_msg_.steer_position = std::max(clamp_steer_position_min_, std::min(cmd_msg_.steer_position, clamp_steer_position_max_)); // [-100.0, 100.0]
  cmd_msg_.tool_position = std::max(clamp_tool_position_min_, std::min(cmd_msg_.tool_position, clamp_tool_position_max_)); // [0.0, 100.0]

  // Publish the message
  cmd_msg_.header.stamp = this->get_clock()->now();
  cmd_pub_->publish(cmd_msg_); // Keep using the same message, so last message is retained unless changed
  actuator_cmd_freq_->tick(); // Log frequency for diagnostics

  // Publish cumulative GUI command overlay for debugging
  cum_gui_msg_.wheel_velocity = cum_gui_cmd_.linear.x;
  cum_gui_msg_.steer_position = cum_gui_cmd_.angular.z;
  cum_gui_msg_.tool_position = cum_gui_cmd_.linear.z;

  cum_gui_msg_.header.stamp = this->get_clock()->now();
  gui_cmd_pub_->publish(cum_gui_msg_);
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

void CmdMuxNode::guiDriveCmdCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
  cum_gui_cmd_.linear.x = std::max(clamp_wheel_velocity_min_, std::min(cum_gui_cmd_.linear.x + msg->linear.x, clamp_wheel_velocity_max_));
  cum_gui_cmd_.angular.z = std::max(clamp_steer_position_min_, std::min(cum_gui_cmd_.angular.z + msg->angular.z, clamp_steer_position_max_));

  RCLCPP_WARN(this->get_logger(), "Cumulative GUI command overlay: linear.x=%.2f, angular.z=%.2f", cum_gui_cmd_.linear.x, cum_gui_cmd_.angular.z);
}

void CmdMuxNode::guiToolCmdCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
  cum_gui_cmd_.linear.z = std::max(clamp_tool_position_min_, std::min(cum_gui_cmd_.linear.z + msg->linear.z, clamp_tool_position_max_));

  RCLCPP_WARN(this->get_logger(), "Cumulative GUI tool command overlay: tool_position change=%.2f", cum_gui_cmd_.linear.z);
}

} // namespace cmdmux
} // namespace lr`