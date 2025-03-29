// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:msg/RoverCommand.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__ROVER_COMMAND__TRAITS_HPP_
#define LX_MSGS__MSG__DETAIL__ROVER_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/msg/detail/rover_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'mobility_twist'
#include "geometry_msgs/msg/detail/twist__traits.hpp"

namespace lx_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RoverCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: mobility_twist
  {
    out << "mobility_twist: ";
    to_flow_style_yaml(msg.mobility_twist, out);
    out << ", ";
  }

  // member: actuator_speed
  {
    out << "actuator_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.actuator_speed, out);
    out << ", ";
  }

  // member: drum_speed
  {
    out << "drum_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.drum_speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RoverCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mobility_twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mobility_twist:\n";
    to_block_style_yaml(msg.mobility_twist, out, indentation + 2);
  }

  // member: actuator_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "actuator_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.actuator_speed, out);
    out << "\n";
  }

  // member: drum_speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drum_speed: ";
    rosidl_generator_traits::value_to_yaml(msg.drum_speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RoverCommand & msg, bool use_flow_style = false)
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

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::msg::RoverCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::msg::RoverCommand & msg)
{
  return lx_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::msg::RoverCommand>()
{
  return "lx_msgs::msg::RoverCommand";
}

template<>
inline const char * name<lx_msgs::msg::RoverCommand>()
{
  return "lx_msgs/msg/RoverCommand";
}

template<>
struct has_fixed_size<lx_msgs::msg::RoverCommand>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct has_bounded_size<lx_msgs::msg::RoverCommand>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Twist>::value> {};

template<>
struct is_message<lx_msgs::msg::RoverCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__MSG__DETAIL__ROVER_COMMAND__TRAITS_HPP_
