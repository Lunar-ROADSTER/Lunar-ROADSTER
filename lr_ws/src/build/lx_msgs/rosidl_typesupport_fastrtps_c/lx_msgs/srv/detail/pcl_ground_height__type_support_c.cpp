// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from lx_msgs:srv/PclGroundHeight.idl
// generated code does not contain a copyright notice
#include "lx_msgs/srv/detail/pcl_ground_height__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "lx_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "lx_msgs/srv/detail/pcl_ground_height__struct.h"
#include "lx_msgs/srv/detail/pcl_ground_height__functions.h"
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


// forward declare type support functions


using _PclGroundHeight_Request__ros_msg_type = lx_msgs__srv__PclGroundHeight_Request;

static bool _PclGroundHeight_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PclGroundHeight_Request__ros_msg_type * ros_message = static_cast<const _PclGroundHeight_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: need_height
  {
    cdr << (ros_message->need_height ? true : false);
  }

  return true;
}

static bool _PclGroundHeight_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PclGroundHeight_Request__ros_msg_type * ros_message = static_cast<_PclGroundHeight_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: need_height
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->need_height = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t get_serialized_size_lx_msgs__srv__PclGroundHeight_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PclGroundHeight_Request__ros_msg_type * ros_message = static_cast<const _PclGroundHeight_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name need_height
  {
    size_t item_size = sizeof(ros_message->need_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PclGroundHeight_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lx_msgs__srv__PclGroundHeight_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t max_serialized_size_lx_msgs__srv__PclGroundHeight_Request(
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

  // member: need_height
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
    using DataType = lx_msgs__srv__PclGroundHeight_Request;
    is_plain =
      (
      offsetof(DataType, need_height) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PclGroundHeight_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_lx_msgs__srv__PclGroundHeight_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PclGroundHeight_Request = {
  "lx_msgs::srv",
  "PclGroundHeight_Request",
  _PclGroundHeight_Request__cdr_serialize,
  _PclGroundHeight_Request__cdr_deserialize,
  _PclGroundHeight_Request__get_serialized_size,
  _PclGroundHeight_Request__max_serialized_size
};

static rosidl_message_type_support_t _PclGroundHeight_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PclGroundHeight_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, PclGroundHeight_Request)() {
  return &_PclGroundHeight_Request__type_support;
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
// #include "lx_msgs/srv/detail/pcl_ground_height__struct.h"
// already included above
// #include "lx_msgs/srv/detail/pcl_ground_height__functions.h"
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


using _PclGroundHeight_Response__ros_msg_type = lx_msgs__srv__PclGroundHeight_Response;

static bool _PclGroundHeight_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PclGroundHeight_Response__ros_msg_type * ros_message = static_cast<const _PclGroundHeight_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _PclGroundHeight_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PclGroundHeight_Response__ros_msg_type * ros_message = static_cast<_PclGroundHeight_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t get_serialized_size_lx_msgs__srv__PclGroundHeight_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PclGroundHeight_Response__ros_msg_type * ros_message = static_cast<const _PclGroundHeight_Response__ros_msg_type *>(untyped_ros_message);
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

static uint32_t _PclGroundHeight_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_lx_msgs__srv__PclGroundHeight_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_lx_msgs
size_t max_serialized_size_lx_msgs__srv__PclGroundHeight_Response(
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
    using DataType = lx_msgs__srv__PclGroundHeight_Response;
    is_plain =
      (
      offsetof(DataType, success) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PclGroundHeight_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_lx_msgs__srv__PclGroundHeight_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PclGroundHeight_Response = {
  "lx_msgs::srv",
  "PclGroundHeight_Response",
  _PclGroundHeight_Response__cdr_serialize,
  _PclGroundHeight_Response__cdr_deserialize,
  _PclGroundHeight_Response__get_serialized_size,
  _PclGroundHeight_Response__max_serialized_size
};

static rosidl_message_type_support_t _PclGroundHeight_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PclGroundHeight_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, PclGroundHeight_Response)() {
  return &_PclGroundHeight_Response__type_support;
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
#include "lx_msgs/srv/pcl_ground_height.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t PclGroundHeight__callbacks = {
  "lx_msgs::srv",
  "PclGroundHeight",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, PclGroundHeight_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, PclGroundHeight_Response)(),
};

static rosidl_service_type_support_t PclGroundHeight__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &PclGroundHeight__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, lx_msgs, srv, PclGroundHeight)() {
  return &PclGroundHeight__handle;
}

#if defined(__cplusplus)
}
#endif
