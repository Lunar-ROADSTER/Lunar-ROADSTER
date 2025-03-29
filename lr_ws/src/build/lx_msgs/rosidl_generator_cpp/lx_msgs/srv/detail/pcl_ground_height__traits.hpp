// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:srv/PclGroundHeight.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__TRAITS_HPP_
#define LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/srv/detail/pcl_ground_height__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const PclGroundHeight_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: need_height
  {
    out << "need_height: ";
    rosidl_generator_traits::value_to_yaml(msg.need_height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PclGroundHeight_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: need_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "need_height: ";
    rosidl_generator_traits::value_to_yaml(msg.need_height, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PclGroundHeight_Request & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::PclGroundHeight_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::PclGroundHeight_Request & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::PclGroundHeight_Request>()
{
  return "lx_msgs::srv::PclGroundHeight_Request";
}

template<>
inline const char * name<lx_msgs::srv::PclGroundHeight_Request>()
{
  return "lx_msgs/srv/PclGroundHeight_Request";
}

template<>
struct has_fixed_size<lx_msgs::srv::PclGroundHeight_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::srv::PclGroundHeight_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::srv::PclGroundHeight_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const PclGroundHeight_Response & msg,
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
  const PclGroundHeight_Response & msg,
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

inline std::string to_yaml(const PclGroundHeight_Response & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::PclGroundHeight_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::PclGroundHeight_Response & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::PclGroundHeight_Response>()
{
  return "lx_msgs::srv::PclGroundHeight_Response";
}

template<>
inline const char * name<lx_msgs::srv::PclGroundHeight_Response>()
{
  return "lx_msgs/srv/PclGroundHeight_Response";
}

template<>
struct has_fixed_size<lx_msgs::srv::PclGroundHeight_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::srv::PclGroundHeight_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::srv::PclGroundHeight_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::srv::PclGroundHeight>()
{
  return "lx_msgs::srv::PclGroundHeight";
}

template<>
inline const char * name<lx_msgs::srv::PclGroundHeight>()
{
  return "lx_msgs/srv/PclGroundHeight";
}

template<>
struct has_fixed_size<lx_msgs::srv::PclGroundHeight>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::srv::PclGroundHeight_Request>::value &&
    has_fixed_size<lx_msgs::srv::PclGroundHeight_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::srv::PclGroundHeight>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::srv::PclGroundHeight_Request>::value &&
    has_bounded_size<lx_msgs::srv::PclGroundHeight_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::srv::PclGroundHeight>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::srv::PclGroundHeight_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::srv::PclGroundHeight_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__TRAITS_HPP_
