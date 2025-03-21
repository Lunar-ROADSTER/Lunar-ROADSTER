// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_localization:srv/ToLL.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_LOCALIZATION__SRV__DETAIL__TO_LL__TRAITS_HPP_
#define ROBOT_LOCALIZATION__SRV__DETAIL__TO_LL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_localization/srv/detail/to_ll__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'map_point'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const ToLL_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: map_point
  {
    out << "map_point: ";
    to_flow_style_yaml(msg.map_point, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ToLL_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: map_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_point:\n";
    to_block_style_yaml(msg.map_point, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ToLL_Request & msg, bool use_flow_style = false)
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

}  // namespace robot_localization

namespace rosidl_generator_traits
{

[[deprecated("use robot_localization::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_localization::srv::ToLL_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::ToLL_Request & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::ToLL_Request>()
{
  return "robot_localization::srv::ToLL_Request";
}

template<>
inline const char * name<robot_localization::srv::ToLL_Request>()
{
  return "robot_localization/srv/ToLL_Request";
}

template<>
struct has_fixed_size<robot_localization::srv::ToLL_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<robot_localization::srv::ToLL_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<robot_localization::srv::ToLL_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'll_point'
#include "geographic_msgs/msg/detail/geo_point__traits.hpp"

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const ToLL_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ll_point
  {
    out << "ll_point: ";
    to_flow_style_yaml(msg.ll_point, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ToLL_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ll_point
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ll_point:\n";
    to_block_style_yaml(msg.ll_point, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ToLL_Response & msg, bool use_flow_style = false)
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

}  // namespace robot_localization

namespace rosidl_generator_traits
{

[[deprecated("use robot_localization::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const robot_localization::srv::ToLL_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::ToLL_Response & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::ToLL_Response>()
{
  return "robot_localization::srv::ToLL_Response";
}

template<>
inline const char * name<robot_localization::srv::ToLL_Response>()
{
  return "robot_localization/srv/ToLL_Response";
}

template<>
struct has_fixed_size<robot_localization::srv::ToLL_Response>
  : std::integral_constant<bool, has_fixed_size<geographic_msgs::msg::GeoPoint>::value> {};

template<>
struct has_bounded_size<robot_localization::srv::ToLL_Response>
  : std::integral_constant<bool, has_bounded_size<geographic_msgs::msg::GeoPoint>::value> {};

template<>
struct is_message<robot_localization::srv::ToLL_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_localization::srv::ToLL>()
{
  return "robot_localization::srv::ToLL";
}

template<>
inline const char * name<robot_localization::srv::ToLL>()
{
  return "robot_localization/srv/ToLL";
}

template<>
struct has_fixed_size<robot_localization::srv::ToLL>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_localization::srv::ToLL_Request>::value &&
    has_fixed_size<robot_localization::srv::ToLL_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_localization::srv::ToLL>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_localization::srv::ToLL_Request>::value &&
    has_bounded_size<robot_localization::srv::ToLL_Response>::value
  >
{
};

template<>
struct is_service<robot_localization::srv::ToLL>
  : std::true_type
{
};

template<>
struct is_service_request<robot_localization::srv::ToLL_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_localization::srv::ToLL_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_LOCALIZATION__SRV__DETAIL__TO_LL__TRAITS_HPP_
