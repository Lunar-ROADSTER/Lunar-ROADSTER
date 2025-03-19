// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:msg/BeaconMultiTag.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__TRAITS_HPP_
#define CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/msg/detail/beacon_multi_tag__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'TagsList'
#include "cg_msgs/msg/detail/beacon_tag__traits.hpp"

namespace cg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BeaconMultiTag & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: TagsList
  {
    if (msg.TagsList.size() == 0) {
      out << "TagsList: []";
    } else {
      out << "TagsList: [";
      size_t pending_items = msg.TagsList.size();
      for (auto item : msg.TagsList) {
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
  const BeaconMultiTag & msg,
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

  // member: TagsList
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.TagsList.size() == 0) {
      out << "TagsList: []\n";
    } else {
      out << "TagsList:\n";
      for (auto item : msg.TagsList) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BeaconMultiTag & msg, bool use_flow_style = false)
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
  const cg_msgs::msg::BeaconMultiTag & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::msg::BeaconMultiTag & msg)
{
  return cg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::msg::BeaconMultiTag>()
{
  return "cg_msgs::msg::BeaconMultiTag";
}

template<>
inline const char * name<cg_msgs::msg::BeaconMultiTag>()
{
  return "cg_msgs/msg/BeaconMultiTag";
}

template<>
struct has_fixed_size<cg_msgs::msg::BeaconMultiTag>
  : std::integral_constant<bool, has_fixed_size<cg_msgs::msg::BeaconTag>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cg_msgs::msg::BeaconMultiTag>
  : std::integral_constant<bool, has_bounded_size<cg_msgs::msg::BeaconTag>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cg_msgs::msg::BeaconMultiTag>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__MSG__DETAIL__BEACON_MULTI_TAG__TRAITS_HPP_
