// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:msg/PlannedTask.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__PLANNED_TASK__TRAITS_HPP_
#define LX_MSGS__MSG__DETAIL__PLANNED_TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/msg/detail/planned_task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'berm_point'
#include "lx_msgs/msg/detail/berm_section__traits.hpp"

namespace lx_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PlannedTask & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_type
  {
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: berm_point
  {
    out << "berm_point: ";
    to_flow_style_yaml(msg.berm_point, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PlannedTask & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
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

  // member: berm_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "berm_point:\n";
    to_block_style_yaml(msg.berm_point, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PlannedTask & msg, bool use_flow_style = false)
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
  const lx_msgs::msg::PlannedTask & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::msg::PlannedTask & msg)
{
  return lx_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::msg::PlannedTask>()
{
  return "lx_msgs::msg::PlannedTask";
}

template<>
inline const char * name<lx_msgs::msg::PlannedTask>()
{
  return "lx_msgs/msg/PlannedTask";
}

template<>
struct has_fixed_size<lx_msgs::msg::PlannedTask>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value && has_fixed_size<lx_msgs::msg::BermSection>::value> {};

template<>
struct has_bounded_size<lx_msgs::msg::PlannedTask>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value && has_bounded_size<lx_msgs::msg::BermSection>::value> {};

template<>
struct is_message<lx_msgs::msg::PlannedTask>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__MSG__DETAIL__PLANNED_TASK__TRAITS_HPP_
