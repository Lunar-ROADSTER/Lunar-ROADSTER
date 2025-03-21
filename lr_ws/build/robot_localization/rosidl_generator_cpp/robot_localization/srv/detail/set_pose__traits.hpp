// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from robot_localization:srv/SetPose.idl
// generated code does not contain a copyright notice

#ifndef ROBOT_LOCALIZATION__SRV__DETAIL__SET_POSE__TRAITS_HPP_
#define ROBOT_LOCALIZATION__SRV__DETAIL__SET_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "robot_localization/srv/detail/set_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__traits.hpp"

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPose_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPose_Request & msg, bool use_flow_style = false)
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
  const robot_localization::srv::SetPose_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::SetPose_Request & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::SetPose_Request>()
{
  return "robot_localization::srv::SetPose_Request";
}

template<>
inline const char * name<robot_localization::srv::SetPose_Request>()
{
  return "robot_localization/srv/SetPose_Request";
}

template<>
struct has_fixed_size<robot_localization::srv::SetPose_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::PoseWithCovarianceStamped>::value> {};

template<>
struct has_bounded_size<robot_localization::srv::SetPose_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::PoseWithCovarianceStamped>::value> {};

template<>
struct is_message<robot_localization::srv::SetPose_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace robot_localization
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetPose_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetPose_Response & msg, bool use_flow_style = false)
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
  const robot_localization::srv::SetPose_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  robot_localization::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use robot_localization::srv::to_yaml() instead")]]
inline std::string to_yaml(const robot_localization::srv::SetPose_Response & msg)
{
  return robot_localization::srv::to_yaml(msg);
}

template<>
inline const char * data_type<robot_localization::srv::SetPose_Response>()
{
  return "robot_localization::srv::SetPose_Response";
}

template<>
inline const char * name<robot_localization::srv::SetPose_Response>()
{
  return "robot_localization/srv/SetPose_Response";
}

template<>
struct has_fixed_size<robot_localization::srv::SetPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<robot_localization::srv::SetPose_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<robot_localization::srv::SetPose_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<robot_localization::srv::SetPose>()
{
  return "robot_localization::srv::SetPose";
}

template<>
inline const char * name<robot_localization::srv::SetPose>()
{
  return "robot_localization/srv/SetPose";
}

template<>
struct has_fixed_size<robot_localization::srv::SetPose>
  : std::integral_constant<
    bool,
    has_fixed_size<robot_localization::srv::SetPose_Request>::value &&
    has_fixed_size<robot_localization::srv::SetPose_Response>::value
  >
{
};

template<>
struct has_bounded_size<robot_localization::srv::SetPose>
  : std::integral_constant<
    bool,
    has_bounded_size<robot_localization::srv::SetPose_Request>::value &&
    has_bounded_size<robot_localization::srv::SetPose_Response>::value
  >
{
};

template<>
struct is_service<robot_localization::srv::SetPose>
  : std::true_type
{
};

template<>
struct is_service_request<robot_localization::srv::SetPose_Request>
  : std::true_type
{
};

template<>
struct is_service_response<robot_localization::srv::SetPose_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROBOT_LOCALIZATION__SRV__DETAIL__SET_POSE__TRAITS_HPP_
