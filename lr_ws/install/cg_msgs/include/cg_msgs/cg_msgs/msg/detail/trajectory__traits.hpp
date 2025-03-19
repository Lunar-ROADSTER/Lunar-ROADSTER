// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
#define CG_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'path'
#include "cg_msgs/msg/detail/pose2_d__traits.hpp"

namespace cg_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Trajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: path
  {
    if (msg.path.size() == 0) {
      out << "path: []";
    } else {
      out << "path: [";
      size_t pending_items = msg.path.size();
      for (auto item : msg.path) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: velocity_targets
  {
    if (msg.velocity_targets.size() == 0) {
      out << "velocity_targets: []";
    } else {
      out << "velocity_targets: [";
      size_t pending_items = msg.velocity_targets.size();
      for (auto item : msg.velocity_targets) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tool_positions
  {
    if (msg.tool_positions.size() == 0) {
      out << "tool_positions: []";
    } else {
      out << "tool_positions: [";
      size_t pending_items = msg.tool_positions.size();
      for (auto item : msg.tool_positions) {
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
  const Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.path.size() == 0) {
      out << "path: []\n";
    } else {
      out << "path:\n";
      for (auto item : msg.path) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: velocity_targets
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocity_targets.size() == 0) {
      out << "velocity_targets: []\n";
    } else {
      out << "velocity_targets:\n";
      for (auto item : msg.velocity_targets) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tool_positions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tool_positions.size() == 0) {
      out << "tool_positions: []\n";
    } else {
      out << "tool_positions:\n";
      for (auto item : msg.tool_positions) {
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

inline std::string to_yaml(const Trajectory & msg, bool use_flow_style = false)
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
  const cg_msgs::msg::Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::msg::Trajectory & msg)
{
  return cg_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::msg::Trajectory>()
{
  return "cg_msgs::msg::Trajectory";
}

template<>
inline const char * name<cg_msgs::msg::Trajectory>()
{
  return "cg_msgs/msg/Trajectory";
}

template<>
struct has_fixed_size<cg_msgs::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cg_msgs::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cg_msgs::msg::Trajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
