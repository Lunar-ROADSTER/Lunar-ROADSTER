// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:srv/UserInputRecord.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__TRAITS_HPP_
#define LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/srv/detail/user_input_record__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'empty'
#include "std_msgs/msg/detail/empty__traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UserInputRecord_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: empty
  {
    out << "empty: ";
    to_flow_style_yaml(msg.empty, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UserInputRecord_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: empty
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "empty:\n";
    to_block_style_yaml(msg.empty, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UserInputRecord_Request & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::UserInputRecord_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::UserInputRecord_Request & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::UserInputRecord_Request>()
{
  return "lx_msgs::srv::UserInputRecord_Request";
}

template<>
inline const char * name<lx_msgs::srv::UserInputRecord_Request>()
{
  return "lx_msgs/srv/UserInputRecord_Request";
}

template<>
struct has_fixed_size<lx_msgs::srv::UserInputRecord_Request>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Empty>::value> {};

template<>
struct has_bounded_size<lx_msgs::srv::UserInputRecord_Request>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Empty>::value> {};

template<>
struct is_message<lx_msgs::srv::UserInputRecord_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UserInputRecord_Response & msg,
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
  const UserInputRecord_Response & msg,
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

inline std::string to_yaml(const UserInputRecord_Response & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::UserInputRecord_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::UserInputRecord_Response & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::UserInputRecord_Response>()
{
  return "lx_msgs::srv::UserInputRecord_Response";
}

template<>
inline const char * name<lx_msgs::srv::UserInputRecord_Response>()
{
  return "lx_msgs/srv/UserInputRecord_Response";
}

template<>
struct has_fixed_size<lx_msgs::srv::UserInputRecord_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::srv::UserInputRecord_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::srv::UserInputRecord_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::srv::UserInputRecord>()
{
  return "lx_msgs::srv::UserInputRecord";
}

template<>
inline const char * name<lx_msgs::srv::UserInputRecord>()
{
  return "lx_msgs/srv/UserInputRecord";
}

template<>
struct has_fixed_size<lx_msgs::srv::UserInputRecord>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::srv::UserInputRecord_Request>::value &&
    has_fixed_size<lx_msgs::srv::UserInputRecord_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::srv::UserInputRecord>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::srv::UserInputRecord_Request>::value &&
    has_bounded_size<lx_msgs::srv::UserInputRecord_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::srv::UserInputRecord>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::srv::UserInputRecord_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::srv::UserInputRecord_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__TRAITS_HPP_
