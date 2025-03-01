// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kindr_msgs:msg/VectorAtPosition.idl
// generated code does not contain a copyright notice

#ifndef KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__TRAITS_HPP_
#define KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kindr_msgs/msg/detail/vector_at_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'vector'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace kindr_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const VectorAtPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << ", ";
  }

  // member: vector
  {
    out << "vector: ";
    to_flow_style_yaml(msg.vector, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
    out << ", ";
  }

  // member: position_frame_id
  {
    out << "position_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.position_frame_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const VectorAtPosition & msg,
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

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }

  // member: vector
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vector:\n";
    to_block_style_yaml(msg.vector, out, indentation + 2);
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }

  // member: position_frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.position_frame_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const VectorAtPosition & msg, bool use_flow_style = false)
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

}  // namespace kindr_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kindr_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kindr_msgs::msg::VectorAtPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  kindr_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kindr_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const kindr_msgs::msg::VectorAtPosition & msg)
{
  return kindr_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<kindr_msgs::msg::VectorAtPosition>()
{
  return "kindr_msgs::msg::VectorAtPosition";
}

template<>
inline const char * name<kindr_msgs::msg::VectorAtPosition>()
{
  return "kindr_msgs/msg/VectorAtPosition";
}

template<>
struct has_fixed_size<kindr_msgs::msg::VectorAtPosition>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<kindr_msgs::msg::VectorAtPosition>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<kindr_msgs::msg::VectorAtPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KINDR_MSGS__MSG__DETAIL__VECTOR_AT_POSITION__TRAITS_HPP_
