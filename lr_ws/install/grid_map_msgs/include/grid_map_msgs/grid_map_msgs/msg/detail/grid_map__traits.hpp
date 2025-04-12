// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grid_map_msgs:msg/GridMap.idl
// generated code does not contain a copyright notice

#ifndef GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP__TRAITS_HPP_
#define GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grid_map_msgs/msg/detail/grid_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'info'
#include "grid_map_msgs/msg/detail/grid_map_info__traits.hpp"
// Member 'data'
#include "std_msgs/msg/detail/float32_multi_array__traits.hpp"

namespace grid_map_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const GridMap & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: layers
  {
    if (msg.layers.size() == 0) {
      out << "layers: []";
    } else {
      out << "layers: [";
      size_t pending_items = msg.layers.size();
      for (auto item : msg.layers) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: basic_layers
  {
    if (msg.basic_layers.size() == 0) {
      out << "basic_layers: []";
    } else {
      out << "basic_layers: [";
      size_t pending_items = msg.basic_layers.size();
      for (auto item : msg.basic_layers) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: data
  {
    if (msg.data.size() == 0) {
      out << "data: []";
    } else {
      out << "data: [";
      size_t pending_items = msg.data.size();
      for (auto item : msg.data) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: outer_start_index
  {
    out << "outer_start_index: ";
    rosidl_generator_traits::value_to_yaml(msg.outer_start_index, out);
    out << ", ";
  }

  // member: inner_start_index
  {
    out << "inner_start_index: ";
    rosidl_generator_traits::value_to_yaml(msg.inner_start_index, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GridMap & msg,
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

  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: layers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.layers.size() == 0) {
      out << "layers: []\n";
    } else {
      out << "layers:\n";
      for (auto item : msg.layers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: basic_layers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.basic_layers.size() == 0) {
      out << "basic_layers: []\n";
    } else {
      out << "basic_layers:\n";
      for (auto item : msg.basic_layers) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: outer_start_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "outer_start_index: ";
    rosidl_generator_traits::value_to_yaml(msg.outer_start_index, out);
    out << "\n";
  }

  // member: inner_start_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inner_start_index: ";
    rosidl_generator_traits::value_to_yaml(msg.inner_start_index, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GridMap & msg, bool use_flow_style = false)
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
  const grid_map_msgs::msg::GridMap & msg,
  std::ostream & out, size_t indentation = 0)
{
  grid_map_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grid_map_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const grid_map_msgs::msg::GridMap & msg)
{
  return grid_map_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<grid_map_msgs::msg::GridMap>()
{
  return "grid_map_msgs::msg::GridMap";
}

template<>
inline const char * name<grid_map_msgs::msg::GridMap>()
{
  return "grid_map_msgs/msg/GridMap";
}

template<>
struct has_fixed_size<grid_map_msgs::msg::GridMap>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grid_map_msgs::msg::GridMap>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grid_map_msgs::msg::GridMap>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRID_MAP_MSGS__MSG__DETAIL__GRID_MAP__TRAITS_HPP_
