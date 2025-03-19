// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:srv/BermProgressEval.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__TRAITS_HPP_
#define LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/srv/detail/berm_progress_eval__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const BermProgressEval_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: need_metrics
  {
    out << "need_metrics: ";
    rosidl_generator_traits::value_to_yaml(msg.need_metrics, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BermProgressEval_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: need_metrics
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "need_metrics: ";
    rosidl_generator_traits::value_to_yaml(msg.need_metrics, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BermProgressEval_Request & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::BermProgressEval_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::BermProgressEval_Request & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::BermProgressEval_Request>()
{
  return "lx_msgs::srv::BermProgressEval_Request";
}

template<>
inline const char * name<lx_msgs::srv::BermProgressEval_Request>()
{
  return "lx_msgs/srv/BermProgressEval_Request";
}

template<>
struct has_fixed_size<lx_msgs::srv::BermProgressEval_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::srv::BermProgressEval_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::srv::BermProgressEval_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'progress'
#include "lx_msgs/msg/detail/berm_progress__traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const BermProgressEval_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: progress
  {
    out << "progress: ";
    to_flow_style_yaml(msg.progress, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BermProgressEval_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress:\n";
    to_block_style_yaml(msg.progress, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BermProgressEval_Response & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::BermProgressEval_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::BermProgressEval_Response & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::BermProgressEval_Response>()
{
  return "lx_msgs::srv::BermProgressEval_Response";
}

template<>
inline const char * name<lx_msgs::srv::BermProgressEval_Response>()
{
  return "lx_msgs/srv/BermProgressEval_Response";
}

template<>
struct has_fixed_size<lx_msgs::srv::BermProgressEval_Response>
  : std::integral_constant<bool, has_fixed_size<lx_msgs::msg::BermProgress>::value> {};

template<>
struct has_bounded_size<lx_msgs::srv::BermProgressEval_Response>
  : std::integral_constant<bool, has_bounded_size<lx_msgs::msg::BermProgress>::value> {};

template<>
struct is_message<lx_msgs::srv::BermProgressEval_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::srv::BermProgressEval>()
{
  return "lx_msgs::srv::BermProgressEval";
}

template<>
inline const char * name<lx_msgs::srv::BermProgressEval>()
{
  return "lx_msgs/srv/BermProgressEval";
}

template<>
struct has_fixed_size<lx_msgs::srv::BermProgressEval>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::srv::BermProgressEval_Request>::value &&
    has_fixed_size<lx_msgs::srv::BermProgressEval_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::srv::BermProgressEval>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::srv::BermProgressEval_Request>::value &&
    has_bounded_size<lx_msgs::srv::BermProgressEval_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::srv::BermProgressEval>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::srv::BermProgressEval_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::srv::BermProgressEval_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__TRAITS_HPP_
