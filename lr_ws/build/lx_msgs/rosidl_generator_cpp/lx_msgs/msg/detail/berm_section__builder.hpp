// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:msg/BermSection.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_SECTION__BUILDER_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_SECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/msg/detail/berm_section__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace msg
{

namespace builder
{

class Init_BermSection_theta
{
public:
  explicit Init_BermSection_theta(::lx_msgs::msg::BermSection & msg)
  : msg_(msg)
  {}
  ::lx_msgs::msg::BermSection theta(::lx_msgs::msg::BermSection::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::msg::BermSection msg_;
};

class Init_BermSection_y
{
public:
  explicit Init_BermSection_y(::lx_msgs::msg::BermSection & msg)
  : msg_(msg)
  {}
  Init_BermSection_theta y(::lx_msgs::msg::BermSection::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_BermSection_theta(msg_);
  }

private:
  ::lx_msgs::msg::BermSection msg_;
};

class Init_BermSection_x
{
public:
  Init_BermSection_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BermSection_y x(::lx_msgs::msg::BermSection::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_BermSection_y(msg_);
  }

private:
  ::lx_msgs::msg::BermSection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::msg::BermSection>()
{
  return lx_msgs::msg::builder::Init_BermSection_x();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__BERM_SECTION__BUILDER_HPP_
