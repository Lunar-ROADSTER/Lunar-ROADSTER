// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:srv/Plan.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__PLAN__TRAITS_HPP_
#define LX_MSGS__SRV__DETAIL__PLAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/srv/detail/plan__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'berm_input'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Plan_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: berm_input
  {
    if (msg.berm_input.size() == 0) {
      out << "berm_input: []";
    } else {
      out << "berm_input: [";
      size_t pending_items = msg.berm_input.size();
      for (auto item : msg.berm_input) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: berm_height
  {
    out << "berm_height: ";
    rosidl_generator_traits::value_to_yaml(msg.berm_height, out);
    out << ", ";
  }

  // member: section_length
  {
    out << "section_length: ";
    rosidl_generator_traits::value_to_yaml(msg.section_length, out);
    out << ", ";
  }

  // member: new_plan
  {
    out << "new_plan: ";
    rosidl_generator_traits::value_to_yaml(msg.new_plan, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Plan_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: berm_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.berm_input.size() == 0) {
      out << "berm_input: []\n";
    } else {
      out << "berm_input:\n";
      for (auto item : msg.berm_input) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: berm_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "berm_height: ";
    rosidl_generator_traits::value_to_yaml(msg.berm_height, out);
    out << "\n";
  }

  // member: section_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "section_length: ";
    rosidl_generator_traits::value_to_yaml(msg.section_length, out);
    out << "\n";
  }

  // member: new_plan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "new_plan: ";
    rosidl_generator_traits::value_to_yaml(msg.new_plan, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Plan_Request & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::Plan_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::Plan_Request & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::Plan_Request>()
{
  return "lx_msgs::srv::Plan_Request";
}

template<>
inline const char * name<lx_msgs::srv::Plan_Request>()
{
  return "lx_msgs/srv/Plan_Request";
}

template<>
struct has_fixed_size<lx_msgs::srv::Plan_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lx_msgs::srv::Plan_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lx_msgs::srv::Plan_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'plan'
#include "lx_msgs/msg/detail/planned_task__traits.hpp"

namespace lx_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Plan_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: plan
  {
    if (msg.plan.size() == 0) {
      out << "plan: []";
    } else {
      out << "plan: [";
      size_t pending_items = msg.plan.size();
      for (auto item : msg.plan) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Plan_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: plan
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.plan.size() == 0) {
      out << "plan: []\n";
    } else {
      out << "plan:\n";
      for (auto item : msg.plan) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Plan_Response & msg, bool use_flow_style = false)
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
  const lx_msgs::srv::Plan_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::srv::Plan_Response & msg)
{
  return lx_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::srv::Plan_Response>()
{
  return "lx_msgs::srv::Plan_Response";
}

template<>
inline const char * name<lx_msgs::srv::Plan_Response>()
{
  return "lx_msgs/srv/Plan_Response";
}

template<>
struct has_fixed_size<lx_msgs::srv::Plan_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<lx_msgs::srv::Plan_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<lx_msgs::srv::Plan_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::srv::Plan>()
{
  return "lx_msgs::srv::Plan";
}

template<>
inline const char * name<lx_msgs::srv::Plan>()
{
  return "lx_msgs/srv/Plan";
}

template<>
struct has_fixed_size<lx_msgs::srv::Plan>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::srv::Plan_Request>::value &&
    has_fixed_size<lx_msgs::srv::Plan_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::srv::Plan>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::srv::Plan_Request>::value &&
    has_bounded_size<lx_msgs::srv::Plan_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::srv::Plan>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::srv::Plan_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::srv::Plan_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // LX_MSGS__SRV__DETAIL__PLAN__TRAITS_HPP_
