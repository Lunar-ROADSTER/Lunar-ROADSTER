// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:msg/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SITE_MAP__TRAITS_HPP_
#define CG_MSGS__MSG__DETAIL__SITE_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/msg/detail/site_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SiteMap & msg,
  std::ostream & out)
{
  out << "{";
  // member: height_map
  {
    if (msg.height_map.size() == 0) {
      out << "height_map: []";
    } else {
      out << "height_map: [";
      size_t pending_items = msg.height_map.size();
      for (auto item : msg.height_map) {
        rosidl_generator_traits::value_to_yaml(item, out);
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
  const SiteMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: height_map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.height_map.size() == 0) {
      out << "height_map: []\n";
    } else {
      out << "height_map:\n";
      for (auto item : msg.height_map) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SiteMap & msg, bool use_flow_style = false)
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
  const cg_msgs::msg::SiteMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::msg::SiteMap & msg)
{
  return cg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::msg::SiteMap>()
{
  return "cg_msgs::msg::SiteMap";
}

template<>
inline const char * name<cg_msgs::msg::SiteMap>()
{
  return "cg_msgs/msg/SiteMap";
}

template<>
struct has_fixed_size<cg_msgs::msg::SiteMap>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cg_msgs::msg::SiteMap>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cg_msgs::msg::SiteMap>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__MSG__DETAIL__SITE_MAP__TRAITS_HPP_
