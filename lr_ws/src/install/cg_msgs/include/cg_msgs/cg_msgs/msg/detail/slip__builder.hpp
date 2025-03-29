// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/Slip.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SLIP__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__SLIP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/slip__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_Slip_vel_avg
{
public:
  explicit Init_Slip_vel_avg(::cg_msgs::msg::Slip & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::Slip vel_avg(::cg_msgs::msg::Slip::_vel_avg_type arg)
  {
    msg_.vel_avg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::Slip msg_;
};

class Init_Slip_vel
{
public:
  explicit Init_Slip_vel(::cg_msgs::msg::Slip & msg)
  : msg_(msg)
  {}
  Init_Slip_vel_avg vel(::cg_msgs::msg::Slip::_vel_type arg)
  {
    msg_.vel = std::move(arg);
    return Init_Slip_vel_avg(msg_);
  }

private:
  ::cg_msgs::msg::Slip msg_;
};

class Init_Slip_slip_latch
{
public:
  explicit Init_Slip_slip_latch(::cg_msgs::msg::Slip & msg)
  : msg_(msg)
  {}
  Init_Slip_vel slip_latch(::cg_msgs::msg::Slip::_slip_latch_type arg)
  {
    msg_.slip_latch = std::move(arg);
    return Init_Slip_vel(msg_);
  }

private:
  ::cg_msgs::msg::Slip msg_;
};

class Init_Slip_slip_avg
{
public:
  explicit Init_Slip_slip_avg(::cg_msgs::msg::Slip & msg)
  : msg_(msg)
  {}
  Init_Slip_slip_latch slip_avg(::cg_msgs::msg::Slip::_slip_avg_type arg)
  {
    msg_.slip_avg = std::move(arg);
    return Init_Slip_slip_latch(msg_);
  }

private:
  ::cg_msgs::msg::Slip msg_;
};

class Init_Slip_slip
{
public:
  explicit Init_Slip_slip(::cg_msgs::msg::Slip & msg)
  : msg_(msg)
  {}
  Init_Slip_slip_avg slip(::cg_msgs::msg::Slip::_slip_type arg)
  {
    msg_.slip = std::move(arg);
    return Init_Slip_slip_avg(msg_);
  }

private:
  ::cg_msgs::msg::Slip msg_;
};

class Init_Slip_header
{
public:
  Init_Slip_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Slip_slip header(::cg_msgs::msg::Slip::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Slip_slip(msg_);
  }

private:
  ::cg_msgs::msg::Slip msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::Slip>()
{
  return cg_msgs::msg::builder::Init_Slip_header();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__SLIP__BUILDER_HPP_
