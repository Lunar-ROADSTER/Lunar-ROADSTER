// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from lx_msgs:srv/Switch.idl
// generated code does not contain a copyright notice
#include "lx_msgs/srv/detail/switch__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "lx_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "lx_msgs/srv/detail/switch__struct.h"
#include "lx_msgs/srv/detail/switch__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "lx_msgs/msg/detail/berm_section__functions.h"  // current_berm_segment, prev_berm_segment

// forward declare type support functions
size_t get_serialized_size_lx_msgs__msg__BermSection(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_lx_msgs__msg__BermSection(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, msg, BermSection)();


using _Switch_Request__ros_msg_type = lx_msgs__srv__Switch_Request;

static bool _Switch_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Switch_Request__ros_msg_type * ros_message = static_cast<const _Switch_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: switch_state
  {
    cdr << (ros_message->switch_state ? true : false);
  }

  // Field name: current_berm_segment
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, lx_msgs, msg, BermSection
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->current_berm_segment, cdr))
    {
      return false;
    }
  }

  // Field name: prev_berm_segment
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, lx_msgs, msg, BermSection
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->prev_berm_segment, cdr))
    {
      return false;
    }
  }

  // Field name: first_seg_dump
  {
    cdr << (ros_message->first_seg_dump ? true : false);
  }

  return true;
}

static bool _Switch_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Switch_Request__ros_msg_type * ros_message = static_cast<_Switch_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: switch_state
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->switch_state = tmp ? true : false;
  }

  // Field name: current_berm_segment
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, lx_msgs, msg, BermSection
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->current_berm_segment))
    {
      return false;
    }
  }

  // Field name: prev_berm_segment
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, lx_msgs, msg, BermSection
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->prev_berm_segment))
    {
      return false;
    }
  }

  // Field name: first_seg_dump
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->first_seg_dump = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t get_serialized_size_lx_msgs__srv__Switch_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Switch_Request__ros_msg_type * ros_message = static_cast<const _Switch_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name switch_state
  {
    size_t item_size = sizeof(ros_message->switch_state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current_berm_segment

  current_alignment += get_serialized_size_lx_msgs__msg__BermSection(
    &(ros_message->current_berm_segment), current_alignment);
  // field.name prev_berm_segment

  current_alignment += get_serialized_size_lx_msgs__msg__BermSection(
    &(ros_message->prev_berm_segment), current_alignment);
  // field.name first_seg_dump
  {
    size_t item_size = sizeof(ros_message->first_seg_dump);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Switch_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lx_msgs__srv__Switch_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t max_serialized_size_lx_msgs__srv__Switch_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: switch_state
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: current_berm_segment
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_lx_msgs__msg__BermSection(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: prev_berm_segment
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_lx_msgs__msg__BermSection(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: first_seg_dump
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = lx_msgs__srv__Switch_Request;
    is_plain =
      (
      offsetof(DataType, first_seg_dump) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Switch_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_lx_msgs__srv__Switch_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Switch_Request = {
  "lx_msgs::srv",
  "Switch_Request",
  _Switch_Request__cdr_serialize,
  _Switch_Request__cdr_deserialize,
  _Switch_Request__get_serialized_size,
  _Switch_Request__max_serialized_size
};

static rosidl_message_type_support_t _Switch_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Switch_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, Switch_Request)() {
  return &_Switch_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "lx_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "lx_msgs/srv/detail/switch__struct.h"
// already included above
// #include "lx_msgs/srv/detail/switch__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _Switch_Response__ros_msg_type = lx_msgs__srv__Switch_Response;

static bool _Switch_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Switch_Response__ros_msg_type * ros_message = static_cast<const _Switch_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _Switch_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Switch_Response__ros_msg_type * ros_message = static_cast<_Switch_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t get_serialized_size_lx_msgs__srv__Switch_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Switch_Response__ros_msg_type * ros_message = static_cast<const _Switch_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Switch_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lx_msgs__srv__Switch_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t max_serialized_size_lx_msgs__srv__Switch_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = lx_msgs__srv__Switch_Response;
    is_plain =
      (
      offsetof(DataType, success) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Switch_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_lx_msgs__srv__Switch_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Switch_Response = {
  "lx_msgs::srv",
  "Switch_Response",
  _Switch_Response__cdr_serialize,
  _Switch_Response__cdr_deserialize,
  _Switch_Response__get_serialized_size,
  _Switch_Response__max_serialized_size
};

static rosidl_message_type_support_t _Switch_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Switch_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, Switch_Response)() {
  return &_Switch_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "lx_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "lx_msgs/srv/switch.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t Switch__callbacks = {
  "lx_msgs::srv",
  "Switch",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, Switch_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, Switch_Response)(),
};

static rosidl_service_type_support_t Switch__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &Switch__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, Switch)() {
  return &Switch__handle;
}

#if defined(__cplusplus)
}
#endif
