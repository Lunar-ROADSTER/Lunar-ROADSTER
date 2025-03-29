// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:msg/BermSection.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_SECTION__TRAITS_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_SECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/msg/detail/berm_section__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lx_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BermSection & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BermSection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BermSection & msg, bool use_flow_style = false)
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
  const lx_msgs::msg::BermSection & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::msg::BermSection & msg)
{
  return lx_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::msg::BermSection>()
{
  return "lx_msgs::msg::BermSection";
}

template<>
inline const char * name<lx_msgs::msg::BermSection>()
{
  return "lx_msgs/msg/BermSection";
}

template<>
struct has_fixed_size<lx_msgs::msg::BermSection>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::msg::BermSection>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::msg::BermSection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__MSG__DETAIL__BERM_SECTION__TRAITS_HPP_
