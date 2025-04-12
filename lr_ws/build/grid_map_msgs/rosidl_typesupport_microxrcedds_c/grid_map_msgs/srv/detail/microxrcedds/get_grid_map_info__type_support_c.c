// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from grid_map_msgs:srv/GetGridMapInfo.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/srv/detail/get_grid_map_info__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "grid_map_msgs/srv/detail/get_grid_map_info__struct.h"
#include "grid_map_msgs/srv/detail/get_grid_map_info__functions.h"

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

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


typedef grid_map_msgs__srv__GetGridMapInfo_Request _GetGridMapInfo_Request__ros_msg_type;

static bool _GetGridMapInfo_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetGridMapInfo_Request__ros_msg_type * ros_message = (_GetGridMapInfo_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: structure_needs_at_least_one_member
  rv = ucdr_serialize_uint8_t(cdr, ros_message->structure_needs_at_least_one_member);

  return rv;
}

static bool _GetGridMapInfo_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetGridMapInfo_Request__ros_msg_type * ros_message = (_GetGridMapInfo_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: structure_needs_at_least_one_member
  rv = ucdr_deserialize_uint8_t(cdr, &ros_message->structure_needs_at_least_one_member);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t get_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetGridMapInfo_Request__ros_msg_type * ros_message = (const _GetGridMapInfo_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  {
    const size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GetGridMapInfo_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t max_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: structure_needs_at_least_one_member
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint8_t)) + sizeof(uint8_t);

  return current_alignment - initial_alignment;
}

static size_t _GetGridMapInfo_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetGridMapInfo_Request = {
  "grid_map_msgs::srv",
  "GetGridMapInfo_Request",
  _GetGridMapInfo_Request__cdr_serialize,
  _GetGridMapInfo_Request__cdr_deserialize,
  _GetGridMapInfo_Request__get_serialized_size,
  get_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Request,
  _GetGridMapInfo_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMapInfo_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetGridMapInfo_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMapInfo_Request)() {
  return &_GetGridMapInfo_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <stdint.h>
// already included above
// #include <stdio.h>
// already included above
// #include <string.h>
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
// already included above
// #include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
// already included above
// #include "grid_map_msgs/srv/detail/get_grid_map_info__struct.h"
// already included above
// #include "grid_map_msgs/srv/detail/get_grid_map_info__functions.h"

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

#define MICROXRCEDDS_PADDING sizeof(uint32_t)

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "grid_map_msgs/msg/detail/grid_map_info__functions.h"  // info

// forward declare type support functions
size_t get_serialized_size_grid_map_msgs__msg__GridMapInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_grid_map_msgs__msg__GridMapInfo(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMapInfo)();


typedef grid_map_msgs__srv__GetGridMapInfo_Response _GetGridMapInfo_Response__ros_msg_type;

static bool _GetGridMapInfo_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetGridMapInfo_Response__ros_msg_type * ros_message = (_GetGridMapInfo_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: info
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMapInfo
      )()->data))->cdr_serialize(&ros_message->info, cdr);

  return rv;
}

static bool _GetGridMapInfo_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetGridMapInfo_Response__ros_msg_type * ros_message = (_GetGridMapInfo_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: info
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMapInfo
      )()->data))->cdr_deserialize(cdr, &ros_message->info);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t get_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetGridMapInfo_Response__ros_msg_type * ros_message = (const _GetGridMapInfo_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: info
  current_alignment +=
    get_serialized_size_grid_map_msgs__msg__GridMapInfo(&ros_message->info, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GetGridMapInfo_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t max_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: info
  current_alignment +=
    max_serialized_size_grid_map_msgs__msg__GridMapInfo(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _GetGridMapInfo_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetGridMapInfo_Response = {
  "grid_map_msgs::srv",
  "GetGridMapInfo_Response",
  _GetGridMapInfo_Response__cdr_serialize,
  _GetGridMapInfo_Response__cdr_deserialize,
  _GetGridMapInfo_Response__get_serialized_size,
  get_serialized_size_grid_map_msgs__srv__GetGridMapInfo_Response,
  _GetGridMapInfo_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMapInfo_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetGridMapInfo_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMapInfo_Response)() {
  return &_GetGridMapInfo_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "grid_map_msgs/srv/get_grid_map_info.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetGridMapInfo__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMapInfo",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMapInfo_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMapInfo_Response),
};

static rosidl_service_type_support_t GetGridMapInfo__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &GetGridMapInfo__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMapInfo)() {
  return &GetGridMapInfo__handle;
}

#if defined(__cplusplus)
}
#endif
