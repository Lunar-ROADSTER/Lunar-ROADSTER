// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from grid_map_msgs:srv/ProcessFile.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/srv/detail/process_file__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "grid_map_msgs/srv/detail/process_file__struct.h"
#include "grid_map_msgs/srv/detail/process_file__functions.h"

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

#include "rosidl_runtime_c/string.h"  // file_path, topic_name
#include "rosidl_runtime_c/string_functions.h"  // file_path, topic_name

// forward declare type support functions


typedef grid_map_msgs__srv__ProcessFile_Request _ProcessFile_Request__ros_msg_type;

static bool _ProcessFile_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ProcessFile_Request__ros_msg_type * ros_message = (_ProcessFile_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: file_path
 {
    uint32_t string_len = (ros_message->file_path.data == NULL) ? 0 : (uint32_t)strlen(ros_message->file_path.data) + 1;
    ros_message->file_path.size = (ros_message->file_path.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->file_path.data, string_len);
  }
  // Member: topic_name
 {
    uint32_t string_len = (ros_message->topic_name.data == NULL) ? 0 : (uint32_t)strlen(ros_message->topic_name.data) + 1;
    ros_message->topic_name.size = (ros_message->topic_name.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->topic_name.data, string_len);
  }

  return rv;
}

static bool _ProcessFile_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ProcessFile_Request__ros_msg_type * ros_message = (_ProcessFile_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: file_path
  {
    size_t capacity = ros_message->file_path.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->file_path.data, capacity, &string_size);
    if (rv) {
      ros_message->file_path.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->file_path.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: topic_name
  {
    size_t capacity = ros_message->topic_name.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->topic_name.data, capacity, &string_size);
    if (rv) {
      ros_message->topic_name.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->topic_name.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t get_serialized_size_grid_map_msgs__srv__ProcessFile_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ProcessFile_Request__ros_msg_type * ros_message = (const _ProcessFile_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: file_path
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->file_path.size + 1;
  // Member: topic_name
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->topic_name.size + 1;

  return current_alignment - initial_alignment;
}

static uint32_t _ProcessFile_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_grid_map_msgs__srv__ProcessFile_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t max_serialized_size_grid_map_msgs__srv__ProcessFile_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: file_path
  *full_bounded = false;
  // Member: topic_name
  *full_bounded = false;

  return current_alignment - initial_alignment;
}

static size_t _ProcessFile_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_grid_map_msgs__srv__ProcessFile_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ProcessFile_Request = {
  "grid_map_msgs::srv",
  "ProcessFile_Request",
  _ProcessFile_Request__cdr_serialize,
  _ProcessFile_Request__cdr_deserialize,
  _ProcessFile_Request__get_serialized_size,
  get_serialized_size_grid_map_msgs__srv__ProcessFile_Request,
  _ProcessFile_Request__max_serialized_size
};

static rosidl_message_type_support_t _ProcessFile_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ProcessFile_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, ProcessFile_Request)() {
  return &_ProcessFile_Request__type_support;
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
// #include "grid_map_msgs/srv/detail/process_file__struct.h"
// already included above
// #include "grid_map_msgs/srv/detail/process_file__functions.h"

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


typedef grid_map_msgs__srv__ProcessFile_Response _ProcessFile_Response__ros_msg_type;

static bool _ProcessFile_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _ProcessFile_Response__ros_msg_type * ros_message = (_ProcessFile_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: success
  rv = ucdr_serialize_bool(cdr, (ros_message->success) ? 0x01 : 0x00);

  return rv;
}

static bool _ProcessFile_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _ProcessFile_Response__ros_msg_type * ros_message = (_ProcessFile_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: success
  rv = ucdr_deserialize_bool(cdr, &ros_message->success);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t get_serialized_size_grid_map_msgs__srv__ProcessFile_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _ProcessFile_Response__ros_msg_type * ros_message = (const _ProcessFile_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: success
  {
    const size_t item_size = sizeof(ros_message->success);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ProcessFile_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_grid_map_msgs__srv__ProcessFile_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t max_serialized_size_grid_map_msgs__srv__ProcessFile_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: success
  current_alignment += ucdr_alignment(current_alignment, sizeof(bool)) + sizeof(bool);

  return current_alignment - initial_alignment;
}

static size_t _ProcessFile_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_grid_map_msgs__srv__ProcessFile_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_ProcessFile_Response = {
  "grid_map_msgs::srv",
  "ProcessFile_Response",
  _ProcessFile_Response__cdr_serialize,
  _ProcessFile_Response__cdr_deserialize,
  _ProcessFile_Response__get_serialized_size,
  get_serialized_size_grid_map_msgs__srv__ProcessFile_Response,
  _ProcessFile_Response__max_serialized_size
};

static rosidl_message_type_support_t _ProcessFile_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_ProcessFile_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, ProcessFile_Response)() {
  return &_ProcessFile_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "grid_map_msgs/srv/process_file.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ProcessFile__callbacks = {
  "grid_map_msgs::srv",
  "ProcessFile",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, ProcessFile_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, ProcessFile_Response),
};

static rosidl_service_type_support_t ProcessFile__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &ProcessFile__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, ProcessFile)() {
  return &ProcessFile__handle;
}

#if defined(__cplusplus)
}
#endif
