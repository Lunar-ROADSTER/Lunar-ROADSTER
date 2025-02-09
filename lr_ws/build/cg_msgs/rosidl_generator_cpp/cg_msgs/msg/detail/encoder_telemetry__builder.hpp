// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/EncoderTelemetry.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/encoder_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_EncoderTelemetry_term_byte
{
public:
  explicit Init_EncoderTelemetry_term_byte(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  ::cg_msgs::msg::EncoderTelemetry term_byte(::cg_msgs::msg::EncoderTelemetry::_term_byte_type arg)
  {
    msg_.term_byte = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_drive_delta_rear
{
public:
  explicit Init_EncoderTelemetry_drive_delta_rear(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  Init_EncoderTelemetry_term_byte drive_delta_rear(::cg_msgs::msg::EncoderTelemetry::_drive_delta_rear_type arg)
  {
    msg_.drive_delta_rear = std::move(arg);
    return Init_EncoderTelemetry_term_byte(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_drive_delta_front
{
public:
  explicit Init_EncoderTelemetry_drive_delta_front(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  Init_EncoderTelemetry_drive_delta_rear drive_delta_front(::cg_msgs::msg::EncoderTelemetry::_drive_delta_front_type arg)
  {
    msg_.drive_delta_front = std::move(arg);
    return Init_EncoderTelemetry_drive_delta_rear(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_drive_vel_rear
{
public:
  explicit Init_EncoderTelemetry_drive_vel_rear(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  Init_EncoderTelemetry_drive_delta_front drive_vel_rear(::cg_msgs::msg::EncoderTelemetry::_drive_vel_rear_type arg)
  {
    msg_.drive_vel_rear = std::move(arg);
    return Init_EncoderTelemetry_drive_delta_front(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_drive_vel_front
{
public:
  explicit Init_EncoderTelemetry_drive_vel_front(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  Init_EncoderTelemetry_drive_vel_rear drive_vel_front(::cg_msgs::msg::EncoderTelemetry::_drive_vel_front_type arg)
  {
    msg_.drive_vel_front = std::move(arg);
    return Init_EncoderTelemetry_drive_vel_rear(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_tool_pos
{
public:
  explicit Init_EncoderTelemetry_tool_pos(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  Init_EncoderTelemetry_drive_vel_front tool_pos(::cg_msgs::msg::EncoderTelemetry::_tool_pos_type arg)
  {
    msg_.tool_pos = std::move(arg);
    return Init_EncoderTelemetry_drive_vel_front(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_steer_pos_rear
{
public:
  explicit Init_EncoderTelemetry_steer_pos_rear(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  Init_EncoderTelemetry_tool_pos steer_pos_rear(::cg_msgs::msg::EncoderTelemetry::_steer_pos_rear_type arg)
  {
    msg_.steer_pos_rear = std::move(arg);
    return Init_EncoderTelemetry_tool_pos(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_steer_pos_front
{
public:
  explicit Init_EncoderTelemetry_steer_pos_front(::cg_msgs::msg::EncoderTelemetry & msg)
  : msg_(msg)
  {}
  Init_EncoderTelemetry_steer_pos_rear steer_pos_front(::cg_msgs::msg::EncoderTelemetry::_steer_pos_front_type arg)
  {
    msg_.steer_pos_front = std::move(arg);
    return Init_EncoderTelemetry_steer_pos_rear(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

class Init_EncoderTelemetry_header
{
public:
  Init_EncoderTelemetry_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_EncoderTelemetry_steer_pos_front header(::cg_msgs::msg::EncoderTelemetry::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_EncoderTelemetry_steer_pos_front(msg_);
  }

private:
  ::cg_msgs::msg::EncoderTelemetry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::EncoderTelemetry>()
{
  return cg_msgs::msg::builder::Init_EncoderTelemetry_header();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__BUILDER_HPP_
