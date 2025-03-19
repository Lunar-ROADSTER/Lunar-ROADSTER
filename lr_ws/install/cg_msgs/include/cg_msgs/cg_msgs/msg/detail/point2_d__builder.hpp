// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/Point2D.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__POINT2_D__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__POINT2_D__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/point2_d__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_Point2D_y
{
public:
  explicit Init_Point2D_y(::cg_msgs::msg::Point2D & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::Point2D y(::cg_msgs::msg::Point2D::_y_type arg)
  {
    msg_.y = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::Point2D msg_;
};

class Init_Point2D_x
{
public:
  Init_Point2D_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Point2D_y x(::cg_msgs::msg::Point2D::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Point2D_y(msg_);
  }

private:
  ::cg_msgs::msg::Point2D msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::Point2D>()
{
  return cg_msgs::msg::builder::Init_Point2D_x();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__POINT2_D__BUILDER_HPP_
