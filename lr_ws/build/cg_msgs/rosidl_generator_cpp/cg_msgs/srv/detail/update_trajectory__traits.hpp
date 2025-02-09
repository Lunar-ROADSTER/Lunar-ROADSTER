// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:srv/UpdateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__TRAITS_HPP_
#define CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/srv/detail/update_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'trajectory'
#include "cg_msgs/msg/detail/trajectory__traits.hpp"

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UpdateTrajectory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: trajectory
  {
    out << "trajectory: ";
    to_flow_style_yaml(msg.trajectory, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UpdateTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "trajectory:\n";
    to_block_style_yaml(msg.trajectory, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UpdateTrajectory_Request & msg, bool use_flow_style = false)
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
  const cg_msgs::srv::UpdateTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::UpdateTrajectory_Request & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::UpdateTrajectory_Request>()
{
  return "cg_msgs::srv::UpdateTrajectory_Request";
}

template<>
inline const char * name<cg_msgs::srv::UpdateTrajectory_Request>()
{
  return "cg_msgs/srv/UpdateTrajectory_Request";
}

template<>
struct has_fixed_size<cg_msgs::srv::UpdateTrajectory_Request>
  : std::integral_constant<bool, has_fixed_size<cg_msgs::msg::Trajectory>::value> {};

template<>
struct has_bounded_size<cg_msgs::srv::UpdateTrajectory_Request>
  : std::integral_constant<bool, has_bounded_size<cg_msgs::msg::Trajectory>::value> {};

template<>
struct is_message<cg_msgs::srv::UpdateTrajectory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const UpdateTrajectory_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: updated_trajectory
  {
    out << "updated_trajectory: ";
    rosidl_generator_traits::value_to_yaml(msg.updated_trajectory, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UpdateTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: updated_trajectory
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "updated_trajectory: ";
    rosidl_generator_traits::value_to_yaml(msg.updated_trajectory, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UpdateTrajectory_Response & msg, bool use_flow_style = false)
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
  const cg_msgs::srv::UpdateTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::UpdateTrajectory_Response & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::UpdateTrajectory_Response>()
{
  return "cg_msgs::srv::UpdateTrajectory_Response";
}

template<>
inline const char * name<cg_msgs::srv::UpdateTrajectory_Response>()
{
  return "cg_msgs/srv/UpdateTrajectory_Response";
}

template<>
struct has_fixed_size<cg_msgs::srv::UpdateTrajectory_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cg_msgs::srv::UpdateTrajectory_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cg_msgs::srv::UpdateTrajectory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cg_msgs::srv::UpdateTrajectory>()
{
  return "cg_msgs::srv::UpdateTrajectory";
}

template<>
inline const char * name<cg_msgs::srv::UpdateTrajectory>()
{
  return "cg_msgs/srv/UpdateTrajectory";
}

template<>
struct has_fixed_size<cg_msgs::srv::UpdateTrajectory>
  : std::integral_constant<
    bool,
    has_fixed_size<cg_msgs::srv::UpdateTrajectory_Request>::value &&
    has_fixed_size<cg_msgs::srv::UpdateTrajectory_Response>::value
  >
{
};

template<>
struct has_bounded_size<cg_msgs::srv::UpdateTrajectory>
  : std::integral_constant<
    bool,
    has_bounded_size<cg_msgs::srv::UpdateTrajectory_Request>::value &&
    has_bounded_size<cg_msgs::srv::UpdateTrajectory_Response>::value
  >
{
};

template<>
struct is_service<cg_msgs::srv::UpdateTrajectory>
  : std::true_type
{
};

template<>
struct is_service_request<cg_msgs::srv::UpdateTrajectory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cg_msgs::srv::UpdateTrajectory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__TRAITS_HPP_
