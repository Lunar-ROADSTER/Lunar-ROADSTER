// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:srv/SaveMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__SAVE_MAP__TRAITS_HPP_
#define CG_MSGS__SRV__DETAIL__SAVE_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/srv/detail/save_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveMap_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: filepath
  {
    out << "filepath: ";
    rosidl_generator_traits::value_to_yaml(msg.filepath, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: filepath
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filepath: ";
    rosidl_generator_traits::value_to_yaml(msg.filepath, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveMap_Request & msg, bool use_flow_style = false)
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
  const cg_msgs::srv::SaveMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::SaveMap_Request & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::SaveMap_Request>()
{
  return "cg_msgs::srv::SaveMap_Request";
}

template<>
inline const char * name<cg_msgs::srv::SaveMap_Request>()
{
  return "cg_msgs/srv/SaveMap_Request";
}

template<>
struct has_fixed_size<cg_msgs::srv::SaveMap_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cg_msgs::srv::SaveMap_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cg_msgs::srv::SaveMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveMap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: map_saved
  {
    out << "map_saved: ";
    rosidl_generator_traits::value_to_yaml(msg.map_saved, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: map_saved
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_saved: ";
    rosidl_generator_traits::value_to_yaml(msg.map_saved, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveMap_Response & msg, bool use_flow_style = false)
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
  const cg_msgs::srv::SaveMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::SaveMap_Response & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::SaveMap_Response>()
{
  return "cg_msgs::srv::SaveMap_Response";
}

template<>
inline const char * name<cg_msgs::srv::SaveMap_Response>()
{
  return "cg_msgs/srv/SaveMap_Response";
}

template<>
struct has_fixed_size<cg_msgs::srv::SaveMap_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cg_msgs::srv::SaveMap_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cg_msgs::srv::SaveMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cg_msgs::srv::SaveMap>()
{
  return "cg_msgs::srv::SaveMap";
}

template<>
inline const char * name<cg_msgs::srv::SaveMap>()
{
  return "cg_msgs/srv/SaveMap";
}

template<>
struct has_fixed_size<cg_msgs::srv::SaveMap>
  : std::integral_constant<
    bool,
    has_fixed_size<cg_msgs::srv::SaveMap_Request>::value &&
    has_fixed_size<cg_msgs::srv::SaveMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<cg_msgs::srv::SaveMap>
  : std::integral_constant<
    bool,
    has_bounded_size<cg_msgs::srv::SaveMap_Request>::value &&
    has_bounded_size<cg_msgs::srv::SaveMap_Response>::value
  >
{
};

template<>
struct is_service<cg_msgs::srv::SaveMap>
  : std::true_type
{
};

template<>
struct is_service_request<cg_msgs::srv::SaveMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cg_msgs::srv::SaveMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__SRV__DETAIL__SAVE_MAP__TRAITS_HPP_
