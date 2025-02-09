// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_Trajectory_tool_positions
{
public:
  explicit Init_Trajectory_tool_positions(::cg_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::Trajectory tool_positions(::cg_msgs::msg::Trajectory::_tool_positions_type arg)
  {
    msg_.tool_positions = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_velocity_targets
{
public:
  explicit Init_Trajectory_velocity_targets(::cg_msgs::msg::Trajectory & msg)
  : msg_(msg)
  {}
  Init_Trajectory_tool_positions velocity_targets(::cg_msgs::msg::Trajectory::_velocity_targets_type arg)
  {
    msg_.velocity_targets = std::move(arg);
    return Init_Trajectory_tool_positions(msg_);
  }

private:
  ::cg_msgs::msg::Trajectory msg_;
};

class Init_Trajectory_path
{
public:
  Init_Trajectory_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_velocity_targets path(::cg_msgs::msg::Trajectory::_path_type arg)
  {
    msg_.path = std::move(arg);
    return Init_Trajectory_velocity_targets(msg_);
  }

private:
  ::cg_msgs::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::Trajectory>()
{
  return cg_msgs::msg::builder::Init_Trajectory_path();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
