// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lx_msgs:msg/BermProgress.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lx_msgs/msg/detail/berm_progress__rosidl_typesupport_introspection_c.h"
#include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lx_msgs/msg/detail/berm_progress__functions.h"
#include "lx_msgs/msg/detail/berm_progress__struct.h"


// Include directives for member types
// Member `berm_points`
#include "geometry_msgs/msg/point_stamped.h"
// Member `berm_points`
#include "geometry_msgs/msg/detail/point_stamped__rosidl_typesupport_introspection_c.h"
// Member `heights`
// Member `timestamps`
// Member `volumes`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__msg__BermProgress__init(message_memory);
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_fini_function(void * message_memory)
{
  lx_msgs__msg__BermProgress__fini(message_memory);
}

size_t lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__berm_points(
  const void * untyped_member)
{
  const geometry_msgs__msg__PointStamped__Sequence * member =
    (const geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  return member->size;
}

const void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__berm_points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__PointStamped__Sequence * member =
    (const geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__berm_points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__PointStamped__Sequence * member =
    (geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__berm_points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__PointStamped * item =
    ((const geometry_msgs__msg__PointStamped *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__berm_points(untyped_member, index));
  geometry_msgs__msg__PointStamped * value =
    (geometry_msgs__msg__PointStamped *)(untyped_value);
  *value = *item;
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__berm_points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__PointStamped * item =
    ((geometry_msgs__msg__PointStamped *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__berm_points(untyped_member, index));
  const geometry_msgs__msg__PointStamped * value =
    (const geometry_msgs__msg__PointStamped *)(untyped_value);
  *item = *value;
}

bool lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__berm_points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__PointStamped__Sequence * member =
    (geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  geometry_msgs__msg__PointStamped__Sequence__fini(member);
  return geometry_msgs__msg__PointStamped__Sequence__init(member, size);
}

size_t lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__heights(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__heights(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__heights(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__heights(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__heights(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__heights(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__heights(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__heights(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__timestamps(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__timestamps(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__timestamps(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__timestamps(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__timestamps(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__timestamps(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__timestamps(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__timestamps(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__volumes(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__volumes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__volumes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__volumes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__volumes(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__volumes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__volumes(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__volumes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_member_array[7] = {
  {
    "berm_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermProgress, berm_points),  // bytes offset in struct
    NULL,  // default value
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__berm_points,  // size() function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__berm_points,  // get_const(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__berm_points,  // get(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__berm_points,  // fetch(index, &value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__berm_points,  // assign(index, value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__berm_points  // resize(index) function pointer
  },
  {
    "heights",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermProgress, heights),  // bytes offset in struct
    NULL,  // default value
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__heights,  // size() function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__heights,  // get_const(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__heights,  // get(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__heights,  // fetch(index, &value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__heights,  // assign(index, value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__heights  // resize(index) function pointer
  },
  {
    "average_height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermProgress, average_height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermProgress, length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "peakline_error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermProgress, peakline_error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "timestamps",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermProgress, timestamps),  // bytes offset in struct
    NULL,  // default value
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__timestamps,  // size() function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__timestamps,  // get_const(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__timestamps,  // get(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__timestamps,  // fetch(index, &value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__timestamps,  // assign(index, value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__timestamps  // resize(index) function pointer
  },
  {
    "volumes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermProgress, volumes),  // bytes offset in struct
    NULL,  // default value
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__size_function__BermProgress__volumes,  // size() function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_const_function__BermProgress__volumes,  // get_const(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__get_function__BermProgress__volumes,  // get(index) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__fetch_function__BermProgress__volumes,  // fetch(index, &value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__assign_function__BermProgress__volumes,  // assign(index, value) function pointer
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__resize_function__BermProgress__volumes  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_members = {
  "lx_msgs__msg",  // message namespace
  "BermProgress",  // message name
  7,  // number of fields
  sizeof(lx_msgs__msg__BermProgress),
  lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_member_array,  // message members
  lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_type_support_handle = {
  0,
  &lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, msg, BermProgress)() {
  lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PointStamped)();
  if (!lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_type_support_handle.typesupport_identifier) {
    lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__msg__BermProgress__rosidl_typesupport_introspection_c__BermProgress_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
