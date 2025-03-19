// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cg_msgs:msg/Trajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cg_msgs/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"
#include "cg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cg_msgs/msg/detail/trajectory__functions.h"
#include "cg_msgs/msg/detail/trajectory__struct.h"


// Include directives for member types
// Member `path`
#include "cg_msgs/msg/pose2_d.h"
// Member `path`
#include "cg_msgs/msg/detail/pose2_d__rosidl_typesupport_introspection_c.h"
// Member `velocity_targets`
// Member `tool_positions`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cg_msgs__msg__Trajectory__init(message_memory);
}

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function(void * message_memory)
{
  cg_msgs__msg__Trajectory__fini(message_memory);
}

size_t cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__path(
  const void * untyped_member)
{
  const cg_msgs__msg__Pose2D__Sequence * member =
    (const cg_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return member->size;
}

const void * cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__path(
  const void * untyped_member, size_t index)
{
  const cg_msgs__msg__Pose2D__Sequence * member =
    (const cg_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__path(
  void * untyped_member, size_t index)
{
  cg_msgs__msg__Pose2D__Sequence * member =
    (cg_msgs__msg__Pose2D__Sequence *)(untyped_member);
  return &member->data[index];
}

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__path(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const cg_msgs__msg__Pose2D * item =
    ((const cg_msgs__msg__Pose2D *)
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__path(untyped_member, index));
  cg_msgs__msg__Pose2D * value =
    (cg_msgs__msg__Pose2D *)(untyped_value);
  *value = *item;
}

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__path(
  void * untyped_member, size_t index, const void * untyped_value)
{
  cg_msgs__msg__Pose2D * item =
    ((cg_msgs__msg__Pose2D *)
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__path(untyped_member, index));
  const cg_msgs__msg__Pose2D * value =
    (const cg_msgs__msg__Pose2D *)(untyped_value);
  *item = *value;
}

bool cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__path(
  void * untyped_member, size_t size)
{
  cg_msgs__msg__Pose2D__Sequence * member =
    (cg_msgs__msg__Pose2D__Sequence *)(untyped_member);
  cg_msgs__msg__Pose2D__Sequence__fini(member);
  return cg_msgs__msg__Pose2D__Sequence__init(member, size);
}

size_t cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__velocity_targets(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__velocity_targets(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__velocity_targets(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__velocity_targets(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__velocity_targets(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__velocity_targets(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__velocity_targets(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__velocity_targets(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__tool_positions(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__tool_positions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__tool_positions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__tool_positions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__tool_positions(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__tool_positions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__tool_positions(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__tool_positions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[3] = {
  {
    "path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__Trajectory, path),  // bytes offset in struct
    NULL,  // default value
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__path,  // size() function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__path,  // get_const(index) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__path,  // get(index) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__path,  // fetch(index, &value) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__path,  // assign(index, value) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__path  // resize(index) function pointer
  },
  {
    "velocity_targets",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__Trajectory, velocity_targets),  // bytes offset in struct
    NULL,  // default value
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__velocity_targets,  // size() function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__velocity_targets,  // get_const(index) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__velocity_targets,  // get(index) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__velocity_targets,  // fetch(index, &value) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__velocity_targets,  // assign(index, value) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__velocity_targets  // resize(index) function pointer
  },
  {
    "tool_positions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__Trajectory, tool_positions),  // bytes offset in struct
    NULL,  // default value
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__tool_positions,  // size() function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__tool_positions,  // get_const(index) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__tool_positions,  // get(index) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__tool_positions,  // fetch(index, &value) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__tool_positions,  // assign(index, value) function pointer
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__tool_positions  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members = {
  "cg_msgs__msg",  // message namespace
  "Trajectory",  // message name
  3,  // number of fields
  sizeof(cg_msgs__msg__Trajectory),
  cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array,  // message members
  cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle = {
  0,
  &cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cg_msgs, msg, Trajectory)() {
  cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cg_msgs, msg, Pose2D)();
  if (!cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier) {
    cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cg_msgs__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
