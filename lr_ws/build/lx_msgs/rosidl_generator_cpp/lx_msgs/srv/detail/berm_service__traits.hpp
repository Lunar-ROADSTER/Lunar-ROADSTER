// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:srv/BermService.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__BERM_SERVICE__TRAITS_HPP_
#define LX_MSGS__SRV__DETAIL__BERM_SERVICE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/srv/detail/berm_service__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'berm'
#include "lx_msgs/msg/detail/berm_config__traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const BermService_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: berm
  {
    out << "berm: ";
    to_flow_style_yaml(msg.berm, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BermService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: berm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "berm:\n";
    to_block_style_yaml(msg.berm, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BermService_Request & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::BermService_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::BermService_Request & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::BermService_Request>()
{
  return "lx_msgs::srv::BermService_Request";
}

template<>
inline const char * name<lx_msgs::srv::BermService_Request>()
{
  return "lx_msgs/srv/BermService_Request";
}

template<>
struct has_fixed_size<lx_msgs::srv::BermService_Request>
  : std::integral_constant<bool, has_fixed_size<lx_msgs::msg::BermConfig>::value> {};

template<>
struct has_bounded_size<lx_msgs::srv::BermService_Request>
  : std::integral_constant<bool, has_bounded_size<lx_msgs::msg::BermConfig>::value> {};

template<>
struct is_message<lx_msgs::srv::BermService_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const BermService_Response & msg,
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
  const BermService_Response & msg,
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

inline std::string to_yaml(const BermService_Response & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::BermService_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::BermService_Response & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::BermService_Response>()
{
  return "lx_msgs::srv::BermService_Response";
}

template<>
inline const char * name<lx_msgs::srv::BermService_Response>()
{
  return "lx_msgs/srv/BermService_Response";
}

template<>
struct has_fixed_size<lx_msgs::srv::BermService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::srv::BermService_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::srv::BermService_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::srv::BermService>()
{
  return "lx_msgs::srv::BermService";
}

template<>
inline const char * name<lx_msgs::srv::BermService>()
{
  return "lx_msgs/srv/BermService";
}

template<>
struct has_fixed_size<lx_msgs::srv::BermService>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::srv::BermService_Request>::value &&
    has_fixed_size<lx_msgs::srv::BermService_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::srv::BermService>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::srv::BermService_Request>::value &&
    has_bounded_size<lx_msgs::srv::BermService_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::srv::BermService>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::srv::BermService_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::srv::BermService_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__SRV__DETAIL__BERM_SERVICE__TRAITS_HPP_
