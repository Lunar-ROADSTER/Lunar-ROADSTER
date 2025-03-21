// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_localization:srv/SetDatum.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_LOCALIZATION__SRV__DETAIL__SET_DATUM__TRAITS_HPP_
#define ROBOT_LOCALIZATION__SRV__DETAIL__SET_DATUM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_localization/srv/detail/set_datum__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'geo_pose'
#include "geographic_msgs/msg/detail/geo_pose__traits.hpp"

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetDatum_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: geo_pose
  {
    out << "geo_pose: ";
    to_flow_style_yaml(msg.geo_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetDatum_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: geo_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "geo_pose:\n";
    to_block_style_yaml(msg.geo_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetDatum_Request & msg, bool use_flow_style = false)
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
  const robot_localization::srv::SetDatum_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::SetDatum_Request & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::SetDatum_Request>()
{
  return "robot_localization::srv::SetDatum_Request";
}

template<>
inline const char * name<robot_localization::srv::SetDatum_Request>()
{
  return "robot_localization/srv/SetDatum_Request";
}

template<>
struct has_fixed_size<robot_localization::srv::SetDatum_Request>
  : std::integral_constant<bool, has_fixed_size<geographic_msgs::msg::GeoPose>::value> {};

template<>
struct has_bounded_size<robot_localization::srv::SetDatum_Request>
  : std::integral_constant<bool, has_bounded_size<geographic_msgs::msg::GeoPose>::value> {};

template<>
struct is_message<robot_localization::srv::SetDatum_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetDatum_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetDatum_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetDatum_Response & msg, bool use_flow_style = false)
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
  const robot_localization::srv::SetDatum_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::SetDatum_Response & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::SetDatum_Response>()
{
  return "robot_localization::srv::SetDatum_Response";
}

template<>
inline const char * name<robot_localization::srv::SetDatum_Response>()
{
  return "robot_localization/srv/SetDatum_Response";
}

template<>
struct has_fixed_size<robot_localization::srv::SetDatum_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_localization::srv::SetDatum_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_localization::srv::SetDatum_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_localization::srv::SetDatum>()
{
  return "robot_localization::srv::SetDatum";
}

template<>
inline const char * name<robot_localization::srv::SetDatum>()
{
  return "robot_localization/srv/SetDatum";
}

template<>
struct has_fixed_size<robot_localization::srv::SetDatum>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_localization::srv::SetDatum_Request>::value &&
    has_fixed_size<robot_localization::srv::SetDatum_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_localization::srv::SetDatum>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_localization::srv::SetDatum_Request>::value &&
    has_bounded_size<robot_localization::srv::SetDatum_Response>::value
  >
{
};

template<>
struct is_service<robot_localization::srv::SetDatum>
  : std::true_type
{
};

template<>
struct is_service_request<robot_localization::srv::SetDatum_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_localization::srv::SetDatum_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_LOCALIZATION__SRV__DETAIL__SET_DATUM__TRAITS_HPP_
