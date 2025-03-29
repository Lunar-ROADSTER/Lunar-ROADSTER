// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:srv/Switch.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__SWITCH__TRAITS_HPP_
#define LX_MSGS__SRV__DETAIL__SWITCH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/srv/detail/switch__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'current_berm_segment'
// Member 'prev_berm_segment'
#include "lx_msgs/msg/detail/berm_section__traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Switch_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: switch_state
  {
    out << "switch_state: ";
    rosidl_generator_traits::value_to_yaml(msg.switch_state, out);
    out << ", ";
  }

  // member: current_berm_segment
  {
    out << "current_berm_segment: ";
    to_flow_style_yaml(msg.current_berm_segment, out);
    out << ", ";
  }

  // member: prev_berm_segment
  {
    out << "prev_berm_segment: ";
    to_flow_style_yaml(msg.prev_berm_segment, out);
    out << ", ";
  }

  // member: first_seg_dump
  {
    out << "first_seg_dump: ";
    rosidl_generator_traits::value_to_yaml(msg.first_seg_dump, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Switch_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: switch_state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "switch_state: ";
    rosidl_generator_traits::value_to_yaml(msg.switch_state, out);
    out << "\n";
  }

  // member: current_berm_segment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_berm_segment:\n";
    to_block_style_yaml(msg.current_berm_segment, out, indentation + 2);
  }

  // member: prev_berm_segment
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "prev_berm_segment:\n";
    to_block_style_yaml(msg.prev_berm_segment, out, indentation + 2);
  }

  // member: first_seg_dump
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "first_seg_dump: ";
    rosidl_generator_traits::value_to_yaml(msg.first_seg_dump, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Switch_Request & msg, bool use_flow_style = false)
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

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::srv::Switch_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::Switch_Request & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::Switch_Request>()
{
  return "lx_msgs::srv::Switch_Request";
}

template<>
inline const char * name<lx_msgs::srv::Switch_Request>()
{
  return "lx_msgs/srv/Switch_Request";
}

template<>
struct has_fixed_size<lx_msgs::srv::Switch_Request>
  : std::integral_constant<bool, has_fixed_size<lx_msgs::msg::BermSection>::value> {};

template<>
struct has_bounded_size<lx_msgs::srv::Switch_Request>
  : std::integral_constant<bool, has_bounded_size<lx_msgs::msg::BermSection>::value> {};

template<>
struct is_message<lx_msgs::srv::Switch_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Switch_Response & msg,
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
  const Switch_Response & msg,
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

inline std::string to_yaml(const Switch_Response & msg, bool use_flow_style = false)
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

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::srv::Switch_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::Switch_Response & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::Switch_Response>()
{
  return "lx_msgs::srv::Switch_Response";
}

template<>
inline const char * name<lx_msgs::srv::Switch_Response>()
{
  return "lx_msgs/srv/Switch_Response";
}

template<>
struct has_fixed_size<lx_msgs::srv::Switch_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::srv::Switch_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::srv::Switch_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::srv::Switch>()
{
  return "lx_msgs::srv::Switch";
}

template<>
inline const char * name<lx_msgs::srv::Switch>()
{
  return "lx_msgs/srv/Switch";
}

template<>
struct has_fixed_size<lx_msgs::srv::Switch>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::srv::Switch_Request>::value &&
    has_fixed_size<lx_msgs::srv::Switch_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::srv::Switch>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::srv::Switch_Request>::value &&
    has_bounded_size<lx_msgs::srv::Switch_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::srv::Switch>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::srv::Switch_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::srv::Switch_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__SRV__DETAIL__SWITCH__TRAITS_HPP_
