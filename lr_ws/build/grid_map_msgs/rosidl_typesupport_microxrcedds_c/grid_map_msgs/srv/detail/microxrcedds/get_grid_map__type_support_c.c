// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from grid_map_msgs:srv/GetGridMap.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/srv/detail/get_grid_map__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "grid_map_msgs/srv/detail/get_grid_map__struct.h"
#include "grid_map_msgs/srv/detail/get_grid_map__functions.h"

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

#include "rosidl_runtime_c/string.h"  // frame_id, layers
#include "rosidl_runtime_c/string_functions.h"  // frame_id, layers

// forward declare type support functions


typedef grid_map_msgs__srv__GetGridMap_Request _GetGridMap_Request__ros_msg_type;

static bool _GetGridMap_Request__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetGridMap_Request__ros_msg_type * ros_message = (_GetGridMap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: frame_id
 {
    uint32_t string_len = (ros_message->frame_id.data == NULL) ? 0 : (uint32_t)strlen(ros_message->frame_id.data) + 1;
    ros_message->frame_id.size = (ros_message->frame_id.data == NULL) ? 0 : string_len - 1 ;
    rv = ucdr_serialize_sequence_char(cdr, ros_message->frame_id.data, string_len);
  }
  // Member: position_x
  rv = ucdr_serialize_double(cdr, ros_message->position_x);
  // Member: position_y
  rv = ucdr_serialize_double(cdr, ros_message->position_y);
  // Member: length_x
  rv = ucdr_serialize_double(cdr, ros_message->length_x);
  // Member: length_y
  rv = ucdr_serialize_double(cdr, ros_message->length_y);
  // Member: layers
  {
    const size_t size = ros_message->layers.size;
    rv = ucdr_serialize_uint32_t(cdr, size);
    for (size_t i = 0; rv && i < size; ++i) {
      uint32_t string_len = (ros_message->layers.data[i].data == NULL) ? 0 : (uint32_t)strlen(ros_message->layers.data[i].data) + 1;
      ros_message->layers.data[i].size = (ros_message->layers.data[i].data == NULL) ? 0 : string_len - 1;
      rv = ucdr_serialize_sequence_char(cdr, ros_message->layers.data[i].data, string_len);
    }
  }

  return rv;
}

static bool _GetGridMap_Request__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetGridMap_Request__ros_msg_type * ros_message = (_GetGridMap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: frame_id
  {
    size_t capacity = ros_message->frame_id.capacity;
    uint32_t string_size;
    rv = ucdr_deserialize_sequence_char(cdr, ros_message->frame_id.data, capacity, &string_size);
    if (rv) {
      ros_message->frame_id.size = (string_size == 0) ? 0 : string_size - 1;
    } else if(string_size > capacity){
      cdr->error = false;
      cdr->last_data_size = 1;
      ros_message->frame_id.size = 0;
      ucdr_align_to(cdr, sizeof(char));
      ucdr_advance_buffer(cdr, string_size);
    }
  }
  // Field name: position_x
  rv = ucdr_deserialize_double(cdr, &ros_message->position_x);
  // Field name: position_y
  rv = ucdr_deserialize_double(cdr, &ros_message->position_y);
  // Field name: length_x
  rv = ucdr_deserialize_double(cdr, &ros_message->length_x);
  // Field name: length_y
  rv = ucdr_deserialize_double(cdr, &ros_message->length_y);
  // Field name: layers
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->layers.capacity){
      return 0;
    }
    ros_message->layers.size = size;

    for (size_t i = 0; rv && i < size; i++) {
      size_t capacity = ros_message->layers.data[i].capacity;
      uint32_t string_size;
      char * data = ros_message->layers.data[i].data;
      rv = ucdr_deserialize_sequence_char(cdr, data, capacity, &string_size);
      if (rv) {
        ros_message->layers.data[i].size = (string_size == 0) ? 0 : string_size - 1;
      } else if(string_size > capacity){
        cdr->error = false;
        cdr->last_data_size = 1;
        ros_message->layers.data[i].size = 0;
        ucdr_align_to(cdr, sizeof(char));
        ucdr_advance_buffer(cdr, string_size);
      }
    }
  }
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t get_serialized_size_grid_map_msgs__srv__GetGridMap_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetGridMap_Request__ros_msg_type * ros_message = (const _GetGridMap_Request__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: frame_id
  current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
  current_alignment += ros_message->frame_id.size + 1;
  // Member: position_x
  {
    const size_t item_size = sizeof(ros_message->position_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: position_y
  {
    const size_t item_size = sizeof(ros_message->position_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: length_x
  {
    const size_t item_size = sizeof(ros_message->length_x);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: length_y
  {
    const size_t item_size = sizeof(ros_message->length_y);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: layers
  {
    const size_t sequence_size = ros_message->layers.size;
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
      current_alignment += ros_message->layers.data[i].size + 1;
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GetGridMap_Request__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_grid_map_msgs__srv__GetGridMap_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t max_serialized_size_grid_map_msgs__srv__GetGridMap_Request(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: frame_id
  *full_bounded = false;
  // Member: position_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: position_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: length_x
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: length_y
  current_alignment += ucdr_alignment(current_alignment, sizeof(double)) + sizeof(double);
  // Member: layers
  {
    *full_bounded = false;
  }

  return current_alignment - initial_alignment;
}

static size_t _GetGridMap_Request__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_grid_map_msgs__srv__GetGridMap_Request(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetGridMap_Request = {
  "grid_map_msgs::srv",
  "GetGridMap_Request",
  _GetGridMap_Request__cdr_serialize,
  _GetGridMap_Request__cdr_deserialize,
  _GetGridMap_Request__get_serialized_size,
  get_serialized_size_grid_map_msgs__srv__GetGridMap_Request,
  _GetGridMap_Request__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMap_Request__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetGridMap_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMap_Request)() {
  return &_GetGridMap_Request__type_support;
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
// #include "grid_map_msgs/srv/detail/get_grid_map__struct.h"
// already included above
// #include "grid_map_msgs/srv/detail/get_grid_map__functions.h"

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

#include "grid_map_msgs/msg/detail/grid_map__functions.h"  // map

// forward declare type support functions
size_t get_serialized_size_grid_map_msgs__msg__GridMap(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_grid_map_msgs__msg__GridMap(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMap)();


typedef grid_map_msgs__srv__GetGridMap_Response _GetGridMap_Response__ros_msg_type;

static bool _GetGridMap_Response__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GetGridMap_Response__ros_msg_type * ros_message = (_GetGridMap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: map
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMap
      )()->data))->cdr_serialize(&ros_message->map, cdr);

  return rv;
}

static bool _GetGridMap_Response__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GetGridMap_Response__ros_msg_type * ros_message = (_GetGridMap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: map
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMap
      )()->data))->cdr_deserialize(cdr, &ros_message->map);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t get_serialized_size_grid_map_msgs__srv__GetGridMap_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GetGridMap_Response__ros_msg_type * ros_message = (const _GetGridMap_Response__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: map
  current_alignment +=
    get_serialized_size_grid_map_msgs__msg__GridMap(&ros_message->map, current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _GetGridMap_Response__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_grid_map_msgs__srv__GetGridMap_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t max_serialized_size_grid_map_msgs__srv__GetGridMap_Response(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: map
  current_alignment +=
    max_serialized_size_grid_map_msgs__msg__GridMap(full_bounded, current_alignment);

  return current_alignment - initial_alignment;
}

static size_t _GetGridMap_Response__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_grid_map_msgs__srv__GetGridMap_Response(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GetGridMap_Response = {
  "grid_map_msgs::srv",
  "GetGridMap_Response",
  _GetGridMap_Response__cdr_serialize,
  _GetGridMap_Response__cdr_deserialize,
  _GetGridMap_Response__get_serialized_size,
  get_serialized_size_grid_map_msgs__srv__GetGridMap_Response,
  _GetGridMap_Response__max_serialized_size
};

static rosidl_message_type_support_t _GetGridMap_Response__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GetGridMap_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMap_Response)() {
  return &_GetGridMap_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_microxrcedds_c/service_type_support.h"
// already included above
// #include "rosidl_typesupport_microxrcedds_c/identifier.h"
// already included above
// #include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "grid_map_msgs/srv/get_grid_map.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t GetGridMap__callbacks = {
  "grid_map_msgs::srv",
  "GetGridMap",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMap_Request),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMap_Response),
};

static rosidl_service_type_support_t GetGridMap__handle = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &GetGridMap__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, srv, GetGridMap)() {
  return &GetGridMap__handle;
}

#if defined(__cplusplus)
}
#endif
