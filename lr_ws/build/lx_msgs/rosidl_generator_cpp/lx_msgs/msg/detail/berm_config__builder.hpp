// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:msg/BermConfig.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_CONFIG__BUILDER_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_CONFIG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/msg/detail/berm_config__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace msg
{

namespace builder
{

class Init_BermConfig_berm_configuration
{
public:
  Init_BermConfig_berm_configuration()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::msg::BermConfig berm_configuration(::lx_msgs::msg::BermConfig::_berm_configuration_type arg)
  {
    msg_.berm_configuration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::msg::BermConfig msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::msg::BermConfig>()
{
  return lx_msgs::msg::builder::Init_BermConfig_berm_configuration();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__BERM_CONFIG__BUILDER_HPP_
