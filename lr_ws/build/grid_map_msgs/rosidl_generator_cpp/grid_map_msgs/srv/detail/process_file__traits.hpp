// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grid_map_msgs:srv/ProcessFile.idl
// generated code does not contain a copyright notice

#ifndef GRID_MAP_MSGS__SRV__DETAIL__PROCESS_FILE__TRAITS_HPP_
#define GRID_MAP_MSGS__SRV__DETAIL__PROCESS_FILE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grid_map_msgs/srv/detail/process_file__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace grid_map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ProcessFile_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: file_path
  {
    out << "file_path: ";
    rosidl_generator_traits::value_to_yaml(msg.file_path, out);
    out << ", ";
  }

  // member: topic_name
  {
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProcessFile_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: file_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "file_path: ";
    rosidl_generator_traits::value_to_yaml(msg.file_path, out);
    out << "\n";
  }

  // member: topic_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_name: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProcessFile_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace grid_map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use grid_map_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grid_map_msgs::srv::ProcessFile_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  grid_map_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grid_map_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const grid_map_msgs::srv::ProcessFile_Request & msg)
{
  return grid_map_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<grid_map_msgs::srv::ProcessFile_Request>()
{
  return "grid_map_msgs::srv::ProcessFile_Request";
}

template<>
inline const char * name<grid_map_msgs::srv::ProcessFile_Request>()
{
  return "grid_map_msgs/srv/ProcessFile_Request";
}

template<>
struct has_fixed_size<grid_map_msgs::srv::ProcessFile_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grid_map_msgs::srv::ProcessFile_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grid_map_msgs::srv::ProcessFile_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace grid_map_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ProcessFile_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ProcessFile_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ProcessFile_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace grid_map_msgs

namespace rosidl_generator_traits
{

[[deprecated("use grid_map_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grid_map_msgs::srv::ProcessFile_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  grid_map_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grid_map_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const grid_map_msgs::srv::ProcessFile_Response & msg)
{
  return grid_map_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<grid_map_msgs::srv::ProcessFile_Response>()
{
  return "grid_map_msgs::srv::ProcessFile_Response";
}

template<>
inline const char * name<grid_map_msgs::srv::ProcessFile_Response>()
{
  return "grid_map_msgs/srv/ProcessFile_Response";
}

template<>
struct has_fixed_size<grid_map_msgs::srv::ProcessFile_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<grid_map_msgs::srv::ProcessFile_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<grid_map_msgs::srv::ProcessFile_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<grid_map_msgs::srv::ProcessFile>()
{
  return "grid_map_msgs::srv::ProcessFile";
}

template<>
inline const char * name<grid_map_msgs::srv::ProcessFile>()
{
  return "grid_map_msgs/srv/ProcessFile";
}

template<>
struct has_fixed_size<grid_map_msgs::srv::ProcessFile>
  : std::integral_constant<
    bool,
    has_fixed_size<grid_map_msgs::srv::ProcessFile_Request>::value &&
    has_fixed_size<grid_map_msgs::srv::ProcessFile_Response>::value
  >
{
};

template<>
struct has_bounded_size<grid_map_msgs::srv::ProcessFile>
  : std::integral_constant<
    bool,
    has_bounded_size<grid_map_msgs::srv::ProcessFile_Request>::value &&
    has_bounded_size<grid_map_msgs::srv::ProcessFile_Response>::value
  >
{
};

template<>
struct is_service<grid_map_msgs::srv::ProcessFile>
  : std::true_type
{
};

template<>
struct is_service_request<grid_map_msgs::srv::ProcessFile_Request>
  : std::true_type
{
};

template<>
struct is_service_response<grid_map_msgs::srv::ProcessFile_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GRID_MAP_MSGS__SRV__DETAIL__PROCESS_FILE__TRAITS_HPP_
