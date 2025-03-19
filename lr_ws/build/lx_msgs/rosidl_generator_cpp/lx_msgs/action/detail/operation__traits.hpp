// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from lx_msgs:action/Operation.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__ACTION__DETAIL__OPERATION__TRAITS_HPP_
#define LX_MSGS__ACTION__DETAIL__OPERATION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "lx_msgs/action/detail/operation__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'requested_berm_config'
#include "lx_msgs/msg/detail/berm_config__traits.hpp"

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: requested_berm_config
  {
    out << "requested_berm_config: ";
    to_flow_style_yaml(msg.requested_berm_config, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operation_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: requested_berm_config
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "requested_berm_config:\n";
    to_block_style_yaml(msg.requested_berm_config, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operation_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_Goal & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_Goal>()
{
  return "lx_msgs::action::Operation_Goal";
}

template<>
inline const char * name<lx_msgs::action::Operation_Goal>()
{
  return "lx_msgs/action/Operation_Goal";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_Goal>
  : std::integral_constant<bool, has_fixed_size<lx_msgs::msg::BermConfig>::value> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_Goal>
  : std::integral_constant<bool, has_bounded_size<lx_msgs::msg::BermConfig>::value> {};

template<>
struct is_message<lx_msgs::action::Operation_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_Result & msg,
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
  const Operation_Result & msg,
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

inline std::string to_yaml(const Operation_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_Result & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_Result>()
{
  return "lx_msgs::action::Operation_Result";
}

template<>
inline const char * name<lx_msgs::action::Operation_Result>()
{
  return "lx_msgs/action/Operation_Result";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::action::Operation_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operation_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operation_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_Feedback & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_Feedback>()
{
  return "lx_msgs::action::Operation_Feedback";
}

template<>
inline const char * name<lx_msgs::action::Operation_Feedback>()
{
  return "lx_msgs/action/Operation_Feedback";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<lx_msgs::action::Operation_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "lx_msgs/action/detail/operation__traits.hpp"

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operation_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operation_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_SendGoal_Request & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_SendGoal_Request>()
{
  return "lx_msgs::action::Operation_SendGoal_Request";
}

template<>
inline const char * name<lx_msgs::action::Operation_SendGoal_Request>()
{
  return "lx_msgs/action/Operation_SendGoal_Request";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<lx_msgs::action::Operation_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<lx_msgs::action::Operation_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<lx_msgs::action::Operation_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operation_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operation_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_SendGoal_Response & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_SendGoal_Response>()
{
  return "lx_msgs::action::Operation_SendGoal_Response";
}

template<>
inline const char * name<lx_msgs::action::Operation_SendGoal_Response>()
{
  return "lx_msgs/action/Operation_SendGoal_Response";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<lx_msgs::action::Operation_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::action::Operation_SendGoal>()
{
  return "lx_msgs::action::Operation_SendGoal";
}

template<>
inline const char * name<lx_msgs::action::Operation_SendGoal>()
{
  return "lx_msgs/action/Operation_SendGoal";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::action::Operation_SendGoal_Request>::value &&
    has_fixed_size<lx_msgs::action::Operation_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::action::Operation_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::action::Operation_SendGoal_Request>::value &&
    has_bounded_size<lx_msgs::action::Operation_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::action::Operation_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::action::Operation_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::action::Operation_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operation_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operation_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_GetResult_Request & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_GetResult_Request>()
{
  return "lx_msgs::action::Operation_GetResult_Request";
}

template<>
inline const char * name<lx_msgs::action::Operation_GetResult_Request>()
{
  return "lx_msgs/action/Operation_GetResult_Request";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<lx_msgs::action::Operation_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "lx_msgs/action/detail/operation__traits.hpp"

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operation_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operation_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_GetResult_Response & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_GetResult_Response>()
{
  return "lx_msgs::action::Operation_GetResult_Response";
}

template<>
inline const char * name<lx_msgs::action::Operation_GetResult_Response>()
{
  return "lx_msgs/action/Operation_GetResult_Response";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<lx_msgs::action::Operation_Result>::value> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<lx_msgs::action::Operation_Result>::value> {};

template<>
struct is_message<lx_msgs::action::Operation_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<lx_msgs::action::Operation_GetResult>()
{
  return "lx_msgs::action::Operation_GetResult";
}

template<>
inline const char * name<lx_msgs::action::Operation_GetResult>()
{
  return "lx_msgs/action/Operation_GetResult";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<lx_msgs::action::Operation_GetResult_Request>::value &&
    has_fixed_size<lx_msgs::action::Operation_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<lx_msgs::action::Operation_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<lx_msgs::action::Operation_GetResult_Request>::value &&
    has_bounded_size<lx_msgs::action::Operation_GetResult_Response>::value
  >
{
};

template<>
struct is_service<lx_msgs::action::Operation_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<lx_msgs::action::Operation_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<lx_msgs::action::Operation_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "lx_msgs/action/detail/operation__traits.hpp"

namespace lx_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Operation_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Operation_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Operation_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace lx_msgs

namespace rosidl_generator_traits
{

[[deprecated("use lx_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const lx_msgs::action::Operation_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  lx_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use lx_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const lx_msgs::action::Operation_FeedbackMessage & msg)
{
  return lx_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<lx_msgs::action::Operation_FeedbackMessage>()
{
  return "lx_msgs::action::Operation_FeedbackMessage";
}

template<>
inline const char * name<lx_msgs::action::Operation_FeedbackMessage>()
{
  return "lx_msgs/action/Operation_FeedbackMessage";
}

template<>
struct has_fixed_size<lx_msgs::action::Operation_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<lx_msgs::action::Operation_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<lx_msgs::action::Operation_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<lx_msgs::action::Operation_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<lx_msgs::action::Operation_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<lx_msgs::action::Operation>
  : std::true_type
{
};

template<>
struct is_action_goal<lx_msgs::action::Operation_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<lx_msgs::action::Operation_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<lx_msgs::action::Operation_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // LX_MSGS__ACTION__DETAIL__OPERATION__TRAITS_HPP_
