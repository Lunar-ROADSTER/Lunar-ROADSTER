// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:msg/MuxMode.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__MUX_MODE__TRAITS_HPP_
#define CG_MSGS__MSG__DETAIL__MUX_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/msg/detail/mux_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MuxMode & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MuxMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MuxMode & msg, bool use_flow_style = false)
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
  const cg_msgs::msg::MuxMode & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::msg::MuxMode & msg)
{
  return cg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::msg::MuxMode>()
{
  return "cg_msgs::msg::MuxMode";
}

template<>
inline const char * name<cg_msgs::msg::MuxMode>()
{
  return "cg_msgs/msg/MuxMode";
}

template<>
struct has_fixed_size<cg_msgs::msg::MuxMode>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cg_msgs::msg::MuxMode>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cg_msgs::msg::MuxMode>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__MSG__DETAIL__MUX_MODE__TRAITS_HPP_
