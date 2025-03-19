// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:msg/RoverCommand.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__ROVER_COMMAND__BUILDER_HPP_
#define LX_MSGS__MSG__DETAIL__ROVER_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/msg/detail/rover_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace msg
{

namespace builder
{

class Init_RoverCommand_drum_speed
{
public:
  explicit Init_RoverCommand_drum_speed(::lx_msgs::msg::RoverCommand & msg)
  : msg_(msg)
  {}
  ::lx_msgs::msg::RoverCommand drum_speed(::lx_msgs::msg::RoverCommand::_drum_speed_type arg)
  {
    msg_.drum_speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::msg::RoverCommand msg_;
};

class Init_RoverCommand_actuator_speed
{
public:
  explicit Init_RoverCommand_actuator_speed(::lx_msgs::msg::RoverCommand & msg)
  : msg_(msg)
  {}
  Init_RoverCommand_drum_speed actuator_speed(::lx_msgs::msg::RoverCommand::_actuator_speed_type arg)
  {
    msg_.actuator_speed = std::move(arg);
    return Init_RoverCommand_drum_speed(msg_);
  }

private:
  ::lx_msgs::msg::RoverCommand msg_;
};

class Init_RoverCommand_mobility_twist
{
public:
  Init_RoverCommand_mobility_twist()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RoverCommand_actuator_speed mobility_twist(::lx_msgs::msg::RoverCommand::_mobility_twist_type arg)
  {
    msg_.mobility_twist = std::move(arg);
    return Init_RoverCommand_actuator_speed(msg_);
  }

private:
  ::lx_msgs::msg::RoverCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::msg::RoverCommand>()
{
  return lx_msgs::msg::builder::Init_RoverCommand_mobility_twist();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__ROVER_COMMAND__BUILDER_HPP_
