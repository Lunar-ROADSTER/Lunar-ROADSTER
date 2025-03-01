// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kindr_msgs:msg/VectorAtPosition.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kindr_msgs/msg/detail/vector_at_position__rosidl_typesupport_introspection_c.h"
#include "kindr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kindr_msgs/msg/detail/vector_at_position__functions.h"
#include "kindr_msgs/msg/detail/vector_at_position__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `name`
// Member `position_frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `vector`
#include "geometry_msgs/msg/vector3.h"
// Member `vector`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"
// Member `position`
#include "geometry_msgs/msg/point.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kindr_msgs__msg__VectorAtPosition__init(message_memory);
}

void kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_fini_function(void * message_memory)
{
  kindr_msgs__msg__VectorAtPosition__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kindr_msgs__msg__VectorAtPosition, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kindr_msgs__msg__VectorAtPosition, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kindr_msgs__msg__VectorAtPosition, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vector",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kindr_msgs__msg__VectorAtPosition, vector),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kindr_msgs__msg__VectorAtPosition, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position_frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kindr_msgs__msg__VectorAtPosition, position_frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_members = {
  "kindr_msgs__msg",  // message namespace
  "VectorAtPosition",  // message name
  6,  // number of fields
  sizeof(kindr_msgs__msg__VectorAtPosition),
  kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_member_array,  // message members
  kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_init_function,  // function to initialize message memory (memory has to be allocated)
  kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_type_support_handle = {
  0,
  &kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kindr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kindr_msgs, msg, VectorAtPosition)() {
  kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_type_support_handle.typesupport_identifier) {
    kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kindr_msgs__msg__VectorAtPosition__rosidl_typesupport_introspection_c__VectorAtPosition_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
