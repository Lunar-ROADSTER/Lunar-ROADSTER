// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grid_map_msgs:msg/GridMapInfo.idl
// generated code does not contain a copyright notice

#ifndef GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP_INFO__TRAITS_HPP_
#define GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grid_map_msgs/msg/detail/grid_map_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace grid_map_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GridMapInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: resolution
  {
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << ", ";
  }

  // member: length_x
  {
    out << "length_x: ";
    rosidl_generator_traits::value_to_yaml(msg.length_x, out);
    out << ", ";
  }

  // member: length_y
  {
    out << "length_y: ";
    rosidl_generator_traits::value_to_yaml(msg.length_y, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GridMapInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: resolution
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "resolution: ";
    rosidl_generator_traits::value_to_yaml(msg.resolution, out);
    out << "\n";
  }

  // member: length_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length_x: ";
    rosidl_generator_traits::value_to_yaml(msg.length_x, out);
    out << "\n";
  }

  // member: length_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length_y: ";
    rosidl_generator_traits::value_to_yaml(msg.length_y, out);
    out << "\n";
  }

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GridMapInfo & msg, bool use_flow_style = false)
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

}  // namespace grid_map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use grid_map_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grid_map_msgs::msg::GridMapInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  grid_map_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grid_map_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const grid_map_msgs::msg::GridMapInfo & msg)
{
  return grid_map_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<grid_map_msgs::msg::GridMapInfo>()
{
  return "grid_map_msgs::msg::GridMapInfo";
}

template<>
inline const char * name<grid_map_msgs::msg::GridMapInfo>()
{
  return "grid_map_msgs/msg/GridMapInfo";
}

template<>
struct has_fixed_size<grid_map_msgs::msg::GridMapInfo>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<grid_map_msgs::msg::GridMapInfo>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<grid_map_msgs::msg::GridMapInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP_INFO__TRAITS_HPP_
