// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/MuxMode.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__MUX_MODE__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__MUX_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/mux_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_MuxMode_mode
{
public:
  Init_MuxMode_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::msg::MuxMode mode(::cg_msgs::msg::MuxMode::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::MuxMode msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::MuxMode>()
{
  return cg_msgs::msg::builder::Init_MuxMode_mode();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__MUX_MODE__BUILDER_HPP_
