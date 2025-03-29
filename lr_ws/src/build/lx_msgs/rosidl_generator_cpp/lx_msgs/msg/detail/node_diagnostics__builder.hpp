// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:msg/NodeDiagnostics.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__BUILDER_HPP_
#define LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/msg/detail/node_diagnostics__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace msg
{

namespace builder
{

class Init_NodeDiagnostics_node_name
{
public:
  explicit Init_NodeDiagnostics_node_name(::lx_msgs::msg::NodeDiagnostics & msg)
  : msg_(msg)
  {}
  ::lx_msgs::msg::NodeDiagnostics node_name(::lx_msgs::msg::NodeDiagnostics::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::msg::NodeDiagnostics msg_;
};

class Init_NodeDiagnostics_stamp
{
public:
  Init_NodeDiagnostics_stamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NodeDiagnostics_node_name stamp(::lx_msgs::msg::NodeDiagnostics::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return Init_NodeDiagnostics_node_name(msg_);
  }

private:
  ::lx_msgs::msg::NodeDiagnostics msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::msg::NodeDiagnostics>()
{
  return lx_msgs::msg::builder::Init_NodeDiagnostics_stamp();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__NODE_DIAGNOSTICS__BUILDER_HPP_
