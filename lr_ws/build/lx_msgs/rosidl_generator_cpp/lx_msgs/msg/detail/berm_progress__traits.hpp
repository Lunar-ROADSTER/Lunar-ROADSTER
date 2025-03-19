// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:msg/BermProgress.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__BERM_PROGRESS__TRAITS_HPP_
#define LX_MSGS__MSG__DETAIL__BERM_PROGRESS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/msg/detail/berm_progress__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'berm_points'
#include "geometry_msgs/msg/detail/point_stamped__traits.hpp"

namespace lx_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BermProgress & msg,
  std::ostream & out)
{
  out << "{";
  // member: berm_points
  {
    if (msg.berm_points.size() == 0) {
      out << "berm_points: []";
    } else {
      out << "berm_points: [";
      size_t pending_items = msg.berm_points.size();
      for (auto item : msg.berm_points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: heights
  {
    if (msg.heights.size() == 0) {
      out << "heights: []";
    } else {
      out << "heights: [";
      size_t pending_items = msg.heights.size();
      for (auto item : msg.heights) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: average_height
  {
    out << "average_height: ";
    rosidl_generator_traits::value_to_yaml(msg.average_height, out);
    out << ", ";
  }

  // member: length
  {
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << ", ";
  }

  // member: peakline_error
  {
    out << "peakline_error: ";
    rosidl_generator_traits::value_to_yaml(msg.peakline_error, out);
    out << ", ";
  }

  // member: timestamps
  {
    if (msg.timestamps.size() == 0) {
      out << "timestamps: []";
    } else {
      out << "timestamps: [";
      size_t pending_items = msg.timestamps.size();
      for (auto item : msg.timestamps) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: volumes
  {
    if (msg.volumes.size() == 0) {
      out << "volumes: []";
    } else {
      out << "volumes: [";
      size_t pending_items = msg.volumes.size();
      for (auto item : msg.volumes) {
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
  const BermProgress & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: berm_points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.berm_points.size() == 0) {
      out << "berm_points: []\n";
    } else {
      out << "berm_points:\n";
      for (auto item : msg.berm_points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: heights
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.heights.size() == 0) {
      out << "heights: []\n";
    } else {
      out << "heights:\n";
      for (auto item : msg.heights) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: average_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "average_height: ";
    rosidl_generator_traits::value_to_yaml(msg.average_height, out);
    out << "\n";
  }

  // member: length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "length: ";
    rosidl_generator_traits::value_to_yaml(msg.length, out);
    out << "\n";
  }

  // member: peakline_error
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "peakline_error: ";
    rosidl_generator_traits::value_to_yaml(msg.peakline_error, out);
    out << "\n";
  }

  // member: timestamps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.timestamps.size() == 0) {
      out << "timestamps: []\n";
    } else {
      out << "timestamps:\n";
      for (auto item : msg.timestamps) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: volumes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.volumes.size() == 0) {
      out << "volumes: []\n";
    } else {
      out << "volumes:\n";
      for (auto item : msg.volumes) {
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

inline std::string to_yaml(const BermProgress & msg, bool use_flow_style = false)
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
  const lx_msgs::msg::BermProgress & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::msg::BermProgress & msg)
{
  return lx_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::msg::BermProgress>()
{
  return "lx_msgs::msg::BermProgress";
}

template<>
inline const char * name<lx_msgs::msg::BermProgress>()
{
  return "lx_msgs/msg/BermProgress";
}

template<>
struct has_fixed_size<lx_msgs::msg::BermProgress>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lx_msgs::msg::BermProgress>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lx_msgs::msg::BermProgress>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__MSG__DETAIL__BERM_PROGRESS__TRAITS_HPP_
