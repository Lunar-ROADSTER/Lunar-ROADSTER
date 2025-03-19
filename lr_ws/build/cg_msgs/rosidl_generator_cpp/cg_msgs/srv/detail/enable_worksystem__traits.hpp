// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:srv/EnableWorksystem.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__TRAITS_HPP_
#define CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/srv/detail/enable_worksystem__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const EnableWorksystem_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: enable_worksystem
  {
    out << "enable_worksystem: ";
    rosidl_generator_traits::value_to_yaml(msg.enable_worksystem, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EnableWorksystem_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: enable_worksystem
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enable_worksystem: ";
    rosidl_generator_traits::value_to_yaml(msg.enable_worksystem, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EnableWorksystem_Request & msg, bool use_flow_style = false)
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

}  // namespace cg_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cg_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cg_msgs::srv::EnableWorksystem_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::EnableWorksystem_Request & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::EnableWorksystem_Request>()
{
  return "cg_msgs::srv::EnableWorksystem_Request";
}

template<>
inline const char * name<cg_msgs::srv::EnableWorksystem_Request>()
{
  return "cg_msgs/srv/EnableWorksystem_Request";
}

template<>
struct has_fixed_size<cg_msgs::srv::EnableWorksystem_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cg_msgs::srv::EnableWorksystem_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cg_msgs::srv::EnableWorksystem_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const EnableWorksystem_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: worksystem_enabled
  {
    out << "worksystem_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.worksystem_enabled, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const EnableWorksystem_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: worksystem_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "worksystem_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.worksystem_enabled, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const EnableWorksystem_Response & msg, bool use_flow_style = false)
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

}  // namespace cg_msgs

namespace rosidl_generator_traits
{

[[deprecated("use cg_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cg_msgs::srv::EnableWorksystem_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::EnableWorksystem_Response & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::EnableWorksystem_Response>()
{
  return "cg_msgs::srv::EnableWorksystem_Response";
}

template<>
inline const char * name<cg_msgs::srv::EnableWorksystem_Response>()
{
  return "cg_msgs/srv/EnableWorksystem_Response";
}

template<>
struct has_fixed_size<cg_msgs::srv::EnableWorksystem_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cg_msgs::srv::EnableWorksystem_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cg_msgs::srv::EnableWorksystem_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cg_msgs::srv::EnableWorksystem>()
{
  return "cg_msgs::srv::EnableWorksystem";
}

template<>
inline const char * name<cg_msgs::srv::EnableWorksystem>()
{
  return "cg_msgs/srv/EnableWorksystem";
}

template<>
struct has_fixed_size<cg_msgs::srv::EnableWorksystem>
  : std::integral_constant<
    bool,
    has_fixed_size<cg_msgs::srv::EnableWorksystem_Request>::value &&
    has_fixed_size<cg_msgs::srv::EnableWorksystem_Response>::value
  >
{
};

template<>
struct has_bounded_size<cg_msgs::srv::EnableWorksystem>
  : std::integral_constant<
    bool,
    has_bounded_size<cg_msgs::srv::EnableWorksystem_Request>::value &&
    has_bounded_size<cg_msgs::srv::EnableWorksystem_Response>::value
  >
{
};

template<>
struct is_service<cg_msgs::srv::EnableWorksystem>
  : std::true_type
{
};

template<>
struct is_service_request<cg_msgs::srv::EnableWorksystem_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cg_msgs::srv::EnableWorksystem_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__TRAITS_HPP_
