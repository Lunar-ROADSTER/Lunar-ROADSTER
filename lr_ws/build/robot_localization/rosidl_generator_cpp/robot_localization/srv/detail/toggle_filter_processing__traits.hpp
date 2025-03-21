// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_localization:srv/ToggleFilterProcessing.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_LOCALIZATION__SRV__DETAIL__TOGGLE_FILTER_PROCESSING__TRAITS_HPP_
#define ROBOT_LOCALIZATION__SRV__DETAIL__TOGGLE_FILTER_PROCESSING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_localization/srv/detail/toggle_filter_processing__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const ToggleFilterProcessing_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: on
  {
    out << "on: ";
    rosidl_generator_traits::value_to_yaml(msg.on, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ToggleFilterProcessing_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: on
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "on: ";
    rosidl_generator_traits::value_to_yaml(msg.on, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ToggleFilterProcessing_Request & msg, bool use_flow_style = false)
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
  const robot_localization::srv::ToggleFilterProcessing_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::ToggleFilterProcessing_Request & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::ToggleFilterProcessing_Request>()
{
  return "robot_localization::srv::ToggleFilterProcessing_Request";
}

template<>
inline const char * name<robot_localization::srv::ToggleFilterProcessing_Request>()
{
  return "robot_localization/srv/ToggleFilterProcessing_Request";
}

template<>
struct has_fixed_size<robot_localization::srv::ToggleFilterProcessing_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_localization::srv::ToggleFilterProcessing_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_localization::srv::ToggleFilterProcessing_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const ToggleFilterProcessing_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ToggleFilterProcessing_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ToggleFilterProcessing_Response & msg, bool use_flow_style = false)
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
  const robot_localization::srv::ToggleFilterProcessing_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::ToggleFilterProcessing_Response & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::ToggleFilterProcessing_Response>()
{
  return "robot_localization::srv::ToggleFilterProcessing_Response";
}

template<>
inline const char * name<robot_localization::srv::ToggleFilterProcessing_Response>()
{
  return "robot_localization/srv/ToggleFilterProcessing_Response";
}

template<>
struct has_fixed_size<robot_localization::srv::ToggleFilterProcessing_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_localization::srv::ToggleFilterProcessing_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_localization::srv::ToggleFilterProcessing_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_localization::srv::ToggleFilterProcessing>()
{
  return "robot_localization::srv::ToggleFilterProcessing";
}

template<>
inline const char * name<robot_localization::srv::ToggleFilterProcessing>()
{
  return "robot_localization/srv/ToggleFilterProcessing";
}

template<>
struct has_fixed_size<robot_localization::srv::ToggleFilterProcessing>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_localization::srv::ToggleFilterProcessing_Request>::value &&
    has_fixed_size<robot_localization::srv::ToggleFilterProcessing_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_localization::srv::ToggleFilterProcessing>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_localization::srv::ToggleFilterProcessing_Request>::value &&
    has_bounded_size<robot_localization::srv::ToggleFilterProcessing_Response>::value
  >
{
};

template<>
struct is_service<robot_localization::srv::ToggleFilterProcessing>
  : std::true_type
{
};

template<>
struct is_service_request<robot_localization::srv::ToggleFilterProcessing_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_localization::srv::ToggleFilterProcessing_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_LOCALIZATION__SRV__DETAIL__TOGGLE_FILTER_PROCESSING__TRAITS_HPP_
