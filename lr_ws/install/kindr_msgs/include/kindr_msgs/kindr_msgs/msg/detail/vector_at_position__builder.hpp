// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kindr_msgs:msg/VectorAtPosition.idl
// generated code does not contain a copyright notice

#ifndef KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__BUILDER_HPP_
#define KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kindr_msgs/msg/detail/vector_at_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kindr_msgs
{

namespace msg
{

namespace builder
{

class Init_VectorAtPosition_position_frame_id
{
public:
  explicit Init_VectorAtPosition_position_frame_id(::kindr_msgs::msg::VectorAtPosition & msg)
  : msg_(msg)
  {}
  ::kindr_msgs::msg::VectorAtPosition position_frame_id(::kindr_msgs::msg::VectorAtPosition::_position_frame_id_type arg)
  {
    msg_.position_frame_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kindr_msgs::msg::VectorAtPosition msg_;
};

class Init_VectorAtPosition_position
{
public:
  explicit Init_VectorAtPosition_position(::kindr_msgs::msg::VectorAtPosition & msg)
  : msg_(msg)
  {}
  Init_VectorAtPosition_position_frame_id position(::kindr_msgs::msg::VectorAtPosition::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_VectorAtPosition_position_frame_id(msg_);
  }

private:
  ::kindr_msgs::msg::VectorAtPosition msg_;
};

class Init_VectorAtPosition_vector
{
public:
  explicit Init_VectorAtPosition_vector(::kindr_msgs::msg::VectorAtPosition & msg)
  : msg_(msg)
  {}
  Init_VectorAtPosition_position vector(::kindr_msgs::msg::VectorAtPosition::_vector_type arg)
  {
    msg_.vector = std::move(arg);
    return Init_VectorAtPosition_position(msg_);
  }

private:
  ::kindr_msgs::msg::VectorAtPosition msg_;
};

class Init_VectorAtPosition_name
{
public:
  explicit Init_VectorAtPosition_name(::kindr_msgs::msg::VectorAtPosition & msg)
  : msg_(msg)
  {}
  Init_VectorAtPosition_vector name(::kindr_msgs::msg::VectorAtPosition::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_VectorAtPosition_vector(msg_);
  }

private:
  ::kindr_msgs::msg::VectorAtPosition msg_;
};

class Init_VectorAtPosition_type
{
public:
  explicit Init_VectorAtPosition_type(::kindr_msgs::msg::VectorAtPosition & msg)
  : msg_(msg)
  {}
  Init_VectorAtPosition_name type(::kindr_msgs::msg::VectorAtPosition::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_VectorAtPosition_name(msg_);
  }

private:
  ::kindr_msgs::msg::VectorAtPosition msg_;
};

class Init_VectorAtPosition_header
{
public:
  Init_VectorAtPosition_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VectorAtPosition_type header(::kindr_msgs::msg::VectorAtPosition::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_VectorAtPosition_type(msg_);
  }

private:
  ::kindr_msgs::msg::VectorAtPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kindr_msgs::msg::VectorAtPosition>()
{
  return kindr_msgs::msg::builder::Init_VectorAtPosition_header();
}

}  // namespace kindr_msgs

#endif  // KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__BUILDER_HPP_
