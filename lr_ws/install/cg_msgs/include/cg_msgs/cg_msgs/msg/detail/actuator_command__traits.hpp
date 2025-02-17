// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:msg/ActuatorCommand.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__TRAITS_HPP_
#define CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/msg/detail/actuator_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ActuatorCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: wheel_velocity
  {
    out << "wheel_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.wheel_velocity, out);
    out << ", ";
  }

  // member: steer_position
  {
    out << "steer_position: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_position, out);
    out << ", ";
  }

  // member: tool_position
  {
    out << "tool_position: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ActuatorCommand & msg,
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

  // member: wheel_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wheel_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.wheel_velocity, out);
    out << "\n";
  }

  // member: steer_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "steer_position: ";
    rosidl_generator_traits::value_to_yaml(msg.steer_position, out);
    out << "\n";
  }

  // member: tool_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tool_position: ";
    rosidl_generator_traits::value_to_yaml(msg.tool_position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ActuatorCommand & msg, bool use_flow_style = false)
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
  const cg_msgs::msg::ActuatorCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::msg::ActuatorCommand & msg)
{
  return cg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::msg::ActuatorCommand>()
{
  return "cg_msgs::msg::ActuatorCommand";
}

template<>
inline const char * name<cg_msgs::msg::ActuatorCommand>()
{
  return "cg_msgs/msg/ActuatorCommand";
}

template<>
struct has_fixed_size<cg_msgs::msg::ActuatorCommand>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cg_msgs::msg::ActuatorCommand>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cg_msgs::msg::ActuatorCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__MSG__DETAIL__ACTUATOR_COMMAND__TRAITS_HPP_
