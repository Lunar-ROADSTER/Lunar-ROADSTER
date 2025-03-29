// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:msg/BermConfig.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_CONFIG__TRAITS_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_CONFIG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/msg/detail/berm_config__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'berm_configuration'
#include "geometry_msgs/msg/detail/point_stamped__traits.hpp"

namespace lx_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BermConfig & msg,
  std::ostream & out)
{
  out << "{";
  // member: berm_configuration
  {
    if (msg.berm_configuration.size() == 0) {
      out << "berm_configuration: []";
    } else {
      out << "berm_configuration: [";
      size_t pending_items = msg.berm_configuration.size();
      for (auto item : msg.berm_configuration) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BermConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: berm_configuration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.berm_configuration.size() == 0) {
      out << "berm_configuration: []\n";
    } else {
      out << "berm_configuration:\n";
      for (auto item : msg.berm_configuration) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BermConfig & msg, bool use_flow_style = false)
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
  const lx_msgs::msg::BermConfig & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::msg::BermConfig & msg)
{
  return lx_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::msg::BermConfig>()
{
  return "lx_msgs::msg::BermConfig";
}

template<>
inline const char * name<lx_msgs::msg::BermConfig>()
{
  return "lx_msgs/msg/BermConfig";
}

template<>
struct has_fixed_size<lx_msgs::msg::BermConfig>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lx_msgs::msg::BermConfig>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lx_msgs::msg::BermConfig>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__MSG__DETAIL__BERM_CONFIG__TRAITS_HPP_
