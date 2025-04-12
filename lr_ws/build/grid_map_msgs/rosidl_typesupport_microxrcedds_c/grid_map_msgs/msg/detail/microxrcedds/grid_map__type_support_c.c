// generated from rosidl_typesupport_microxrcedds_c/resource/idl__type_support_c.c.em
// with input from grid_map_msgs:msg/GridMap.idl
// generated code does not contain a copyright notice
#include "grid_map_msgs/msg/detail/grid_map__rosidl_typesupport_microxrcedds_c.h"


#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "rosidl_typesupport_microxrcedds_c/identifier.h"
#include "rosidl_typesupport_microxrcedds_c/message_type_support.h"
#include "grid_map_msgs/msg/rosidl_typesupport_microxrcedds_c__visibility_control.h"
#include "grid_map_msgs/msg/detail/grid_map__struct.h"
#include "grid_map_msgs/msg/detail/grid_map__functions.h"

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
#include "rosidl_runtime_c/string.h"  // basic_layers, layers
#include "rosidl_runtime_c/string_functions.h"  // basic_layers, layers
#include "std_msgs/msg/detail/float32_multi_array__functions.h"  // data
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
size_t get_serialized_size_grid_map_msgs__msg__GridMapInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_grid_map_msgs__msg__GridMapInfo(
  bool * full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMapInfo)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_grid_map_msgs
size_t get_serialized_size_std_msgs__msg__Float32MultiArray(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_grid_map_msgs
size_t max_serialized_size_std_msgs__msg__Float32MultiArray(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_grid_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Float32MultiArray)();
ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_grid_map_msgs
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_grid_map_msgs
size_t max_serialized_size_std_msgs__msg__Header(
  bool * full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_IMPORT_grid_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header)();


typedef grid_map_msgs__msg__GridMap _GridMap__ros_msg_type;

static bool _GridMap__cdr_serialize(
  const void * untyped_ros_message,
  ucdrBuffer * cdr)
{
  (void) untyped_ros_message;
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }

  _GridMap__ros_msg_type * ros_message = (_GridMap__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Member: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_serialize(&ros_message->header, cdr);
  // Member: info
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMapInfo
      )()->data))->cdr_serialize(&ros_message->info, cdr);
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
  // Member: basic_layers
  {
    const size_t size = ros_message->basic_layers.size;
    rv = ucdr_serialize_uint32_t(cdr, size);
    for (size_t i = 0; rv && i < size; ++i) {
      uint32_t string_len = (ros_message->basic_layers.data[i].data == NULL) ? 0 : (uint32_t)strlen(ros_message->basic_layers.data[i].data) + 1;
      ros_message->basic_layers.data[i].size = (ros_message->basic_layers.data[i].data == NULL) ? 0 : string_len - 1;
      rv = ucdr_serialize_sequence_char(cdr, ros_message->basic_layers.data[i].data, string_len);
    }
  }
  // Member: data
  {
    const size_t size = ros_message->data.size;
    rv = ucdr_serialize_uint32_t(cdr, size);

    if(rv == true){
      for(size_t i = 0; i < size; i++){
        rv = ((const message_type_support_callbacks_t *)(
          ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Float32MultiArray
          )()->data))->cdr_serialize(&ros_message->data.data[i], cdr);
        if(rv == false){
          break;
        }
      }
    }
  }
  // Member: outer_start_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message->outer_start_index);
  // Member: inner_start_index
  rv = ucdr_serialize_uint16_t(cdr, ros_message->inner_start_index);

  return rv;
}

static bool _GridMap__cdr_deserialize(
  ucdrBuffer * cdr,
  void * untyped_ros_message)
{
  (void) cdr;

  bool rv = false;

  if (!untyped_ros_message) {
    return false;
  }
  _GridMap__ros_msg_type * ros_message = (_GridMap__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  // Field name: header
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Header
      )()->data))->cdr_deserialize(cdr, &ros_message->header);
  // Field name: info
  rv = ((const message_type_support_callbacks_t *)(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMapInfo
      )()->data))->cdr_deserialize(cdr, &ros_message->info);
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
  // Field name: basic_layers
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->basic_layers.capacity){
      return 0;
    }
    ros_message->basic_layers.size = size;

    for (size_t i = 0; rv && i < size; i++) {
      size_t capacity = ros_message->basic_layers.data[i].capacity;
      uint32_t string_size;
      char * data = ros_message->basic_layers.data[i].data;
      rv = ucdr_deserialize_sequence_char(cdr, data, capacity, &string_size);
      if (rv) {
        ros_message->basic_layers.data[i].size = (string_size == 0) ? 0 : string_size - 1;
      } else if(string_size > capacity){
        cdr->error = false;
        cdr->last_data_size = 1;
        ros_message->basic_layers.data[i].size = 0;
        ucdr_align_to(cdr, sizeof(char));
        ucdr_advance_buffer(cdr, string_size);
      }
    }
  }
  // Field name: data
  {
    uint32_t size;
    rv = ucdr_deserialize_uint32_t(cdr, &size);

    if(size > ros_message->data.capacity){
      return 0;
    }

    ros_message->data.size = size;
    for(size_t i = 0; i < size; i++){
      rv = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Float32MultiArray
        )()->data))->cdr_deserialize(cdr, &ros_message->data.data[i]);
      if(rv == false){
        break;
      }
    }
  }
  // Field name: outer_start_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message->outer_start_index);
  // Field name: inner_start_index
  rv = ucdr_deserialize_uint16_t(cdr, &ros_message->inner_start_index);
  return rv;
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t get_serialized_size_grid_map_msgs__msg__GridMap(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  if (!untyped_ros_message) {
    return 0;
  }

  const _GridMap__ros_msg_type * ros_message = (const _GridMap__ros_msg_type *)(untyped_ros_message);
  (void)ros_message;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    get_serialized_size_std_msgs__msg__Header(&ros_message->header, current_alignment);
  // Member: info
  current_alignment +=
    get_serialized_size_grid_map_msgs__msg__GridMapInfo(&ros_message->info, current_alignment);
  // Member: layers
  {
    const size_t sequence_size = ros_message->layers.size;
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
      current_alignment += ros_message->layers.data[i].size + 1;
    }
  }
  // Member: basic_layers
  {
    const size_t sequence_size = ros_message->basic_layers.size;
    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;
      current_alignment += ros_message->basic_layers.data[i].size + 1;
    }
  }
  // Member: data
  {
    const size_t sequence_size = ros_message->data.size;

    current_alignment += ucdr_alignment(current_alignment, MICROXRCEDDS_PADDING) + MICROXRCEDDS_PADDING;

    for(size_t i = 0; i < sequence_size; i++){
      size_t element_size = ((const message_type_support_callbacks_t *)(
        ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, std_msgs, msg, Float32MultiArray
        )()->data))->get_serialized_size_with_initial_alignment(&ros_message->data.data[i], current_alignment);
      uint8_t alignment_size = (element_size < MICROXRCEDDS_PADDING) ? element_size : MICROXRCEDDS_PADDING;
      current_alignment += ucdr_alignment(current_alignment, alignment_size) + element_size;
    }
  }
  // Member: outer_start_index
  {
    const size_t item_size = sizeof(ros_message->outer_start_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }
  // Member: inner_start_index
  {
    const size_t item_size = sizeof(ros_message->inner_start_index);
    current_alignment += ucdr_alignment(current_alignment, item_size) + item_size;
  }

  return current_alignment - initial_alignment;
}

static uint32_t _GridMap__get_serialized_size(const void * untyped_ros_message)
{
  return (uint32_t)(
    get_serialized_size_grid_map_msgs__msg__GridMap(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_MICROXRCEDDS_C_PUBLIC_grid_map_msgs
size_t max_serialized_size_grid_map_msgs__msg__GridMap(
  bool * full_bounded,
  size_t current_alignment)
{
  (void) current_alignment;
  *full_bounded = true;

  const size_t initial_alignment = current_alignment;

  // Member: header
  current_alignment +=
    max_serialized_size_std_msgs__msg__Header(full_bounded, current_alignment);
  // Member: info
  current_alignment +=
    max_serialized_size_grid_map_msgs__msg__GridMapInfo(full_bounded, current_alignment);
  // Member: layers
  {
    *full_bounded = false;
  }
  // Member: basic_layers
  {
    *full_bounded = false;
  }
  // Member: data
  {
    *full_bounded = false;
  }
  // Member: outer_start_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);
  // Member: inner_start_index
  current_alignment += ucdr_alignment(current_alignment, sizeof(uint16_t)) + sizeof(uint16_t);

  return current_alignment - initial_alignment;
}

static size_t _GridMap__max_serialized_size()
{
  bool full_bounded;
  return max_serialized_size_grid_map_msgs__msg__GridMap(&full_bounded, 0);
}

static message_type_support_callbacks_t __callbacks_GridMap = {
  "grid_map_msgs::msg",
  "GridMap",
  _GridMap__cdr_serialize,
  _GridMap__cdr_deserialize,
  _GridMap__get_serialized_size,
  get_serialized_size_grid_map_msgs__msg__GridMap,
  _GridMap__max_serialized_size
};

static rosidl_message_type_support_t _GridMap__type_support = {
  ROSIDL_TYPESUPPORT_MICROXRCEDDS_C__IDENTIFIER_VALUE,
  &__callbacks_GridMap,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_microxrcedds_c, grid_map_msgs, msg, GridMap)() {
  return &_GridMap__type_support;
}

#if defined(__cplusplus)
}
#endif
