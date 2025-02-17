// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/Pose2D.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__POSE2_D__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__POSE2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/pose2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_Pose2D_yaw
{
public:
  explicit Init_Pose2D_yaw(::cg_msgs::msg::Pose2D & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::Pose2D yaw(::cg_msgs::msg::Pose2D::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::Pose2D msg_;
};

class Init_Pose2D_pt
{
public:
  Init_Pose2D_pt()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Pose2D_yaw pt(::cg_msgs::msg::Pose2D::_pt_type arg)
  {
    msg_.pt = std::move(arg);
    return Init_Pose2D_yaw(msg_);
  }

private:
  ::cg_msgs::msg::Pose2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::Pose2D>()
{
  return cg_msgs::msg::builder::Init_Pose2D_pt();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__POSE2_D__BUILDER_HPP_
