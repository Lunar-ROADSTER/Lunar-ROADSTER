// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/ActuatorCommand.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/actuator_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_ActuatorCommand_tool_position
{
public:
  explicit Init_ActuatorCommand_tool_position(::cg_msgs::msg::ActuatorCommand & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::ActuatorCommand tool_position(::cg_msgs::msg::ActuatorCommand::_tool_position_type arg)
  {
    msg_.tool_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::ActuatorCommand msg_;
};

class Init_ActuatorCommand_steer_position
{
public:
  explicit Init_ActuatorCommand_steer_position(::cg_msgs::msg::ActuatorCommand & msg)
  : msg_(msg)
  {}
  Init_ActuatorCommand_tool_position steer_position(::cg_msgs::msg::ActuatorCommand::_steer_position_type arg)
  {
    msg_.steer_position = std::move(arg);
    return Init_ActuatorCommand_tool_position(msg_);
  }

private:
  ::cg_msgs::msg::ActuatorCommand msg_;
};

class Init_ActuatorCommand_wheel_velocity
{
public:
  explicit Init_ActuatorCommand_wheel_velocity(::cg_msgs::msg::ActuatorCommand & msg)
  : msg_(msg)
  {}
  Init_ActuatorCommand_steer_position wheel_velocity(::cg_msgs::msg::ActuatorCommand::_wheel_velocity_type arg)
  {
    msg_.wheel_velocity = std::move(arg);
    return Init_ActuatorCommand_steer_position(msg_);
  }

private:
  ::cg_msgs::msg::ActuatorCommand msg_;
};

class Init_ActuatorCommand_header
{
public:
  Init_ActuatorCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActuatorCommand_wheel_velocity header(::cg_msgs::msg::ActuatorCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ActuatorCommand_wheel_velocity(msg_);
  }

private:
  ::cg_msgs::msg::ActuatorCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::ActuatorCommand>()
{
  return cg_msgs::msg::builder::Init_ActuatorCommand_header();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__BUILDER_HPP_
