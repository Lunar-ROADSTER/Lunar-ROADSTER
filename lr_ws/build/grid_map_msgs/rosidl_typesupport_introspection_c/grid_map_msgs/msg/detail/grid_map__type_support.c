// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grid_map_msgs:msg/GridMap.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grid_map_msgs/msg/detail/grid_map__rosidl_typesupport_introspection_c.h"
#include "grid_map_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grid_map_msgs/msg/detail/grid_map__functions.h"
#include "grid_map_msgs/msg/detail/grid_map__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `info`
#include "grid_map_msgs/msg/grid_map_info.h"
// Member `info`
#include "grid_map_msgs/msg/detail/grid_map_info__rosidl_typesupport_introspection_c.h"
// Member `layers`
// Member `basic_layers`
#include "rosidl_runtime_c/string_functions.h"
// Member `data`
#include "std_msgs/msg/float32_multi_array.h"
// Member `data`
#include "std_msgs/msg/detail/float32_multi_array__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grid_map_msgs__msg__GridMap__init(message_memory);
}

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_fini_function(void * message_memory)
{
  grid_map_msgs__msg__GridMap__fini(message_memory);
}

size_t grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__layers(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__layers(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__layers(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__layers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__layers(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__layers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__layers(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__layers(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__basic_layers(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__basic_layers(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__basic_layers(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__basic_layers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__basic_layers(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__basic_layers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__basic_layers(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__basic_layers(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__data(
  const void * untyped_member)
{
  const std_msgs__msg__Float32MultiArray__Sequence * member =
    (const std_msgs__msg__Float32MultiArray__Sequence *)(untyped_member);
  return member->size;
}

const void * grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__data(
  const void * untyped_member, size_t index)
{
  const std_msgs__msg__Float32MultiArray__Sequence * member =
    (const std_msgs__msg__Float32MultiArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void * grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__data(
  void * untyped_member, size_t index)
{
  std_msgs__msg__Float32MultiArray__Sequence * member =
    (std_msgs__msg__Float32MultiArray__Sequence *)(untyped_member);
  return &member->data[index];
}

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const std_msgs__msg__Float32MultiArray * item =
    ((const std_msgs__msg__Float32MultiArray *)
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__data(untyped_member, index));
  std_msgs__msg__Float32MultiArray * value =
    (std_msgs__msg__Float32MultiArray *)(untyped_value);
  *value = *item;
}

void grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  std_msgs__msg__Float32MultiArray * item =
    ((std_msgs__msg__Float32MultiArray *)
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__data(untyped_member, index));
  const std_msgs__msg__Float32MultiArray * value =
    (const std_msgs__msg__Float32MultiArray *)(untyped_value);
  *item = *value;
}

bool grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__data(
  void * untyped_member, size_t size)
{
  std_msgs__msg__Float32MultiArray__Sequence * member =
    (std_msgs__msg__Float32MultiArray__Sequence *)(untyped_member);
  std_msgs__msg__Float32MultiArray__Sequence__fini(member);
  return std_msgs__msg__Float32MultiArray__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_member_array[7] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMap, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMap, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "layers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMap, layers),  // bytes offset in struct
    NULL,  // default value
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__layers,  // size() function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__layers,  // get_const(index) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__layers,  // get(index) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__layers,  // fetch(index, &value) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__layers,  // assign(index, value) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__layers  // resize(index) function pointer
  },
  {
    "basic_layers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMap, basic_layers),  // bytes offset in struct
    NULL,  // default value
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__basic_layers,  // size() function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__basic_layers,  // get_const(index) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__basic_layers,  // get(index) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__basic_layers,  // fetch(index, &value) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__basic_layers,  // assign(index, value) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__basic_layers  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMap, data),  // bytes offset in struct
    NULL,  // default value
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__size_function__GridMap__data,  // size() function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_const_function__GridMap__data,  // get_const(index) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__get_function__GridMap__data,  // get(index) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__fetch_function__GridMap__data,  // fetch(index, &value) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__assign_function__GridMap__data,  // assign(index, value) function pointer
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__resize_function__GridMap__data  // resize(index) function pointer
  },
  {
    "outer_start_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMap, outer_start_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inner_start_index",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grid_map_msgs__msg__GridMap, inner_start_index),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_members = {
  "grid_map_msgs__msg",  // message namespace
  "GridMap",  // message name
  7,  // number of fields
  sizeof(grid_map_msgs__msg__GridMap),
  grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_member_array,  // message members
  grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_init_function,  // function to initialize message memory (memory has to be allocated)
  grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle = {
  0,
  &grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grid_map_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, msg, GridMap)() {
  grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grid_map_msgs, msg, GridMapInfo)();
  grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Float32MultiArray)();
  if (!grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle.typesupport_identifier) {
    grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grid_map_msgs__msg__GridMap__rosidl_typesupport_introspection_c__GridMap_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
