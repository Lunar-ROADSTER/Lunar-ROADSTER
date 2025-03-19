// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:msg/PlannedTask.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__PLANNED_TASK__BUILDER_HPP_
#define LX_MSGS__MSG__DETAIL__PLANNED_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/msg/detail/planned_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace msg
{

namespace builder
{

class Init_PlannedTask_berm_point
{
public:
  explicit Init_PlannedTask_berm_point(::lx_msgs::msg::PlannedTask & msg)
  : msg_(msg)
  {}
  ::lx_msgs::msg::PlannedTask berm_point(::lx_msgs::msg::PlannedTask::_berm_point_type arg)
  {
    msg_.berm_point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::msg::PlannedTask msg_;
};

class Init_PlannedTask_pose
{
public:
  explicit Init_PlannedTask_pose(::lx_msgs::msg::PlannedTask & msg)
  : msg_(msg)
  {}
  Init_PlannedTask_berm_point pose(::lx_msgs::msg::PlannedTask::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_PlannedTask_berm_point(msg_);
  }

private:
  ::lx_msgs::msg::PlannedTask msg_;
};

class Init_PlannedTask_task_type
{
public:
  Init_PlannedTask_task_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PlannedTask_pose task_type(::lx_msgs::msg::PlannedTask::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_PlannedTask_pose(msg_);
  }

private:
  ::lx_msgs::msg::PlannedTask msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::msg::PlannedTask>()
{
  return lx_msgs::msg::builder::Init_PlannedTask_task_type();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__PLANNED_TASK__BUILDER_HPP_
