// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:msg/Slip.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SLIP__TRAITS_HPP_
#define CG_MSGS__MSG__DETAIL__SLIP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/msg/detail/slip__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Slip & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: slip
  {
    out << "slip: ";
    rosidl_generator_traits::value_to_yaml(msg.slip, out);
    out << ", ";
  }

  // member: slip_avg
  {
    out << "slip_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.slip_avg, out);
    out << ", ";
  }

  // member: slip_latch
  {
    out << "slip_latch: ";
    rosidl_generator_traits::value_to_yaml(msg.slip_latch, out);
    out << ", ";
  }

  // member: vel
  {
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
    out << ", ";
  }

  // member: vel_avg
  {
    out << "vel_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_avg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Slip & msg,
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

  // member: slip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slip: ";
    rosidl_generator_traits::value_to_yaml(msg.slip, out);
    out << "\n";
  }

  // member: slip_avg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slip_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.slip_avg, out);
    out << "\n";
  }

  // member: slip_latch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "slip_latch: ";
    rosidl_generator_traits::value_to_yaml(msg.slip_latch, out);
    out << "\n";
  }

  // member: vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel: ";
    rosidl_generator_traits::value_to_yaml(msg.vel, out);
    out << "\n";
  }

  // member: vel_avg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vel_avg: ";
    rosidl_generator_traits::value_to_yaml(msg.vel_avg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Slip & msg, bool use_flow_style = false)
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
  const cg_msgs::msg::Slip & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::msg::Slip & msg)
{
  return cg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::msg::Slip>()
{
  return "cg_msgs::msg::Slip";
}

template<>
inline const char * name<cg_msgs::msg::Slip>()
{
  return "cg_msgs/msg/Slip";
}

template<>
struct has_fixed_size<cg_msgs::msg::Slip>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cg_msgs::msg::Slip>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cg_msgs::msg::Slip>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__MSG__DETAIL__SLIP__TRAITS_HPP_
