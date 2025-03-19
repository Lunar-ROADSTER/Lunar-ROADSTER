// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:msg/ToolInfo.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__TOOL_INFO__TRAITS_HPP_
#define LX_MSGS__MSG__DETAIL__TOOL_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/msg/detail/tool_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lx_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ToolInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: drum_pos
  {
    out << "drum_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.drum_pos, out);
    out << ", ";
  }

  // member: drum_current
  {
    out << "drum_current: ";
    rosidl_generator_traits::value_to_yaml(msg.drum_current, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ToolInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: drum_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drum_pos: ";
    rosidl_generator_traits::value_to_yaml(msg.drum_pos, out);
    out << "\n";
  }

  // member: drum_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drum_current: ";
    rosidl_generator_traits::value_to_yaml(msg.drum_current, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ToolInfo & msg, bool use_flow_style = false)
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
  const lx_msgs::msg::ToolInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::msg::ToolInfo & msg)
{
  return lx_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::msg::ToolInfo>()
{
  return "lx_msgs::msg::ToolInfo";
}

template<>
inline const char * name<lx_msgs::msg::ToolInfo>()
{
  return "lx_msgs/msg/ToolInfo";
}

template<>
struct has_fixed_size<lx_msgs::msg::ToolInfo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::msg::ToolInfo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::msg::ToolInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__MSG__DETAIL__TOOL_INFO__TRAITS_HPP_
