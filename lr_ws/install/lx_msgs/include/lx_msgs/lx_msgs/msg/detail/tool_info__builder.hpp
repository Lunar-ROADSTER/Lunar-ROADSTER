// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:msg/ToolInfo.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__TOOL_INFO__BUILDER_HPP_
#define LX_MSGS__MSG__DETAIL__TOOL_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/msg/detail/tool_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace msg
{

namespace builder
{

class Init_ToolInfo_drum_current
{
public:
  explicit Init_ToolInfo_drum_current(::lx_msgs::msg::ToolInfo & msg)
  : msg_(msg)
  {}
  ::lx_msgs::msg::ToolInfo drum_current(::lx_msgs::msg::ToolInfo::_drum_current_type arg)
  {
    msg_.drum_current = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::msg::ToolInfo msg_;
};

class Init_ToolInfo_drum_pos
{
public:
  Init_ToolInfo_drum_pos()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ToolInfo_drum_current drum_pos(::lx_msgs::msg::ToolInfo::_drum_pos_type arg)
  {
    msg_.drum_pos = std::move(arg);
    return Init_ToolInfo_drum_current(msg_);
  }

private:
  ::lx_msgs::msg::ToolInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::msg::ToolInfo>()
{
  return lx_msgs::msg::builder::Init_ToolInfo_drum_pos();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__TOOL_INFO__BUILDER_HPP_
