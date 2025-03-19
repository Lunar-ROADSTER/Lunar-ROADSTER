// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cg_msgs:srv/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__SITE_MAP__TRAITS_HPP_
#define CG_MSGS__SRV__DETAIL__SITE_MAP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cg_msgs/srv/detail/site_map__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SiteMap_Request & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SiteMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SiteMap_Request & msg, bool use_flow_style = false)
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
  const cg_msgs::srv::SiteMap_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::SiteMap_Request & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::SiteMap_Request>()
{
  return "cg_msgs::srv::SiteMap_Request";
}

template<>
inline const char * name<cg_msgs::srv::SiteMap_Request>()
{
  return "cg_msgs/srv/SiteMap_Request";
}

template<>
struct has_fixed_size<cg_msgs::srv::SiteMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cg_msgs::srv::SiteMap_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cg_msgs::srv::SiteMap_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'site_map'
#include "cg_msgs/msg/detail/site_map__traits.hpp"

namespace cg_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SiteMap_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: site_map
  {
    out << "site_map: ";
    to_flow_style_yaml(msg.site_map, out);
    out << ", ";
  }

  // member: map_fully_explored
  {
    out << "map_fully_explored: ";
    rosidl_generator_traits::value_to_yaml(msg.map_fully_explored, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SiteMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: site_map
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "site_map:\n";
    to_block_style_yaml(msg.site_map, out, indentation + 2);
  }

  // member: map_fully_explored
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "map_fully_explored: ";
    rosidl_generator_traits::value_to_yaml(msg.map_fully_explored, out);
    out << "\n";
  }

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

inline std::string to_yaml(const SiteMap_Response & msg, bool use_flow_style = false)
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
  const cg_msgs::srv::SiteMap_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cg_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cg_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const cg_msgs::srv::SiteMap_Response & msg)
{
  return cg_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cg_msgs::srv::SiteMap_Response>()
{
  return "cg_msgs::srv::SiteMap_Response";
}

template<>
inline const char * name<cg_msgs::srv::SiteMap_Response>()
{
  return "cg_msgs/srv/SiteMap_Response";
}

template<>
struct has_fixed_size<cg_msgs::srv::SiteMap_Response>
  : std::integral_constant<bool, has_fixed_size<cg_msgs::msg::SiteMap>::value> {};

template<>
struct has_bounded_size<cg_msgs::srv::SiteMap_Response>
  : std::integral_constant<bool, has_bounded_size<cg_msgs::msg::SiteMap>::value> {};

template<>
struct is_message<cg_msgs::srv::SiteMap_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cg_msgs::srv::SiteMap>()
{
  return "cg_msgs::srv::SiteMap";
}

template<>
inline const char * name<cg_msgs::srv::SiteMap>()
{
  return "cg_msgs/srv/SiteMap";
}

template<>
struct has_fixed_size<cg_msgs::srv::SiteMap>
  : std::integral_constant<
    bool,
    has_fixed_size<cg_msgs::srv::SiteMap_Request>::value &&
    has_fixed_size<cg_msgs::srv::SiteMap_Response>::value
  >
{
};

template<>
struct has_bounded_size<cg_msgs::srv::SiteMap>
  : std::integral_constant<
    bool,
    has_bounded_size<cg_msgs::srv::SiteMap_Request>::value &&
    has_bounded_size<cg_msgs::srv::SiteMap_Response>::value
  >
{
};

template<>
struct is_service<cg_msgs::srv::SiteMap>
  : std::true_type
{
};

template<>
struct is_service_request<cg_msgs::srv::SiteMap_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cg_msgs::srv::SiteMap_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CG_MSGS__SRV__DETAIL__SITE_MAP__TRAITS_HPP_
