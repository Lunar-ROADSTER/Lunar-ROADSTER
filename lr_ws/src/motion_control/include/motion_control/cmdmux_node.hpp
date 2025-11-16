#pragma once 

#include <rclcpp/rclcpp.hpp>
#include <lr_msgs/msg/mux_mode.hpp>
#include <lr_msgs/msg/actuator_command.hpp>
#include "geometry_msgs/msg/twist.hpp"
// Diagnostics
#include <diagnostic_updater/diagnostic_updater.hpp>
#include <diagnostic_updater/publisher.hpp>

namespace lr {
namespace cmdmux {

class CmdMuxNode : public rclcpp::Node {

public:
  CmdMuxNode();

private: 
  /* Publishers and Subscribers */
  rclcpp::Publisher<lr_msgs::msg::ActuatorCommand>::SharedPtr cmd_pub_;

  rclcpp::Subscription<lr_msgs::msg::MuxMode>::SharedPtr mode_sub_;
  rclcpp::Subscription<lr_msgs::msg::ActuatorCommand>::SharedPtr teleop_sub_;
  rclcpp::Subscription<lr_msgs::msg::ActuatorCommand>::SharedPtr autonomy_sub_;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr gui_cmd_sub_;

  rclcpp::Publisher<diagnostic_msgs::msg::DiagnosticArray>::SharedPtr diagnostic_pub_;

  rclcpp::TimerBase::SharedPtr timer_; // For looping publish

  /* Message data */
  lr_msgs::msg::ActuatorCommand cmd_msg_;
  geometry_msgs::msg::Twist curr_gui_cmd_;
  geometry_msgs::msg::Twist cum_gui_cmd_;

  /* Callbacks */
  void modeCallback(const lr_msgs::msg::MuxMode::SharedPtr msg);
  void teleopCallback(const lr_msgs::msg::ActuatorCommand::SharedPtr msg);
  void autonomyCallback(const lr_msgs::msg::ActuatorCommand::SharedPtr msg);
  void guiCmdCallback(const geometry_msgs::msg::Twist::SharedPtr msg);
  void timerCallback(); // For looping publish in idle mode

  /* Variables */
  uint8_t curr_mux_mode_;

  /* Diagnostics */
  diagnostic_updater::Updater diagnostic_updater_;
  void populateDiagnosticsStatus(diagnostic_updater::DiagnosticStatusWrapper &stat); // Function for updating status information

  // Log topic frequency for /actuator_cmd
  std::unique_ptr<diagnostic_updater::HeaderlessTopicDiagnostic> actuator_cmd_freq_;
  double freq_min_act_cmd_;
  double freq_max_act_cmd_;
  double freq_tol_act_cmd_;
  int freq_window_act_cmd_;

}; // class CmdMuxNode

} // namespace cmdmux
} // namespace lr
