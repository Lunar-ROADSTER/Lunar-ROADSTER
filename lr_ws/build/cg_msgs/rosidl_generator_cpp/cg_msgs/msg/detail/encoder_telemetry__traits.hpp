// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:msg/EncoderTelemetry.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__TRAITS_HPP_
#define CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/msg/detail/encoder_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const EncoderTelemetry & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: steer_pos_front
  {
    out << "steer_pos_front: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_pos_front, out);
    out << ", ";
  }

  // member: steer_pos_rear
  {
    out << "steer_pos_rear: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_pos_rear, out);
    out << ", ";
  }

  // member: tool_pos
  {
    out << "tool_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_pos, out);
    out << ", ";
  }

  // member: drive_vel_front
  {
    out << "drive_vel_front: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_vel_front, out);
    out << ", ";
  }

  // member: drive_vel_rear
  {
    out << "drive_vel_rear: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_vel_rear, out);
    out << ", ";
  }

  // member: drive_delta_front
  {
    out << "drive_delta_front: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_delta_front, out);
    out << ", ";
  }

  // member: drive_delta_rear
  {
    out << "drive_delta_rear: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_delta_rear, out);
    out << ", ";
  }

  // member: term_byte
  {
    out << "term_byte: ";
    rosidl_generator_traits::value_to_yaml(msg.term_byte, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EncoderTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: steer_pos_front
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_pos_front: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_pos_front, out);
    out << "\n";
  }

  // member: steer_pos_rear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_pos_rear: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_pos_rear, out);
    out << "\n";
  }

  // member: tool_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tool_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_pos, out);
    out << "\n";
  }

  // member: drive_vel_front
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drive_vel_front: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_vel_front, out);
    out << "\n";
  }

  // member: drive_vel_rear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drive_vel_rear: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_vel_rear, out);
    out << "\n";
  }

  // member: drive_delta_front
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drive_delta_front: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_delta_front, out);
    out << "\n";
  }

  // member: drive_delta_rear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drive_delta_rear: ";
    rosidl_generator_traits::value_to_yaml(msg.drive_delta_rear, out);
    out << "\n";
  }

  // member: term_byte
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "term_byte: ";
    rosidl_generator_traits::value_to_yaml(msg.term_byte, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EncoderTelemetry & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cg_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cg_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cg_msgs::msg::EncoderTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::msg::EncoderTelemetry & msg)
{
  return cg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::msg::EncoderTelemetry>()
{
  return "cg_msgs::msg::EncoderTelemetry";
}

template<>
inline const char * name<cg_msgs::msg::EncoderTelemetry>()
{
  return "cg_msgs/msg/EncoderTelemetry";
}

template<>
struct has_fixed_size<cg_msgs::msg::EncoderTelemetry>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cg_msgs::msg::EncoderTelemetry>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cg_msgs::msg::EncoderTelemetry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__TRAITS_HPP_
