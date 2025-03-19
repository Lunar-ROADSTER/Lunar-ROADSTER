// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lx_msgs:msg/RoverCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lx_msgs/msg/detail/rover_command__rosidl_typesupport_introspection_c.h"
#include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lx_msgs/msg/detail/rover_command__functions.h"
#include "lx_msgs/msg/detail/rover_command__struct.h"


// Include directives for member types
// Member `mobility_twist`
#include "geometry_msgs/msg/twist.h"
// Member `mobility_twist`
#include "geometry_msgs/msg/detail/twist__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__msg__RoverCommand__init(message_memory);
}

void lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_fini_function(void * message_memory)
{
  lx_msgs__msg__RoverCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_member_array[3] = {
  {
    "mobility_twist",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__RoverCommand, mobility_twist),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "actuator_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__RoverCommand, actuator_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "drum_speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__RoverCommand, drum_speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_members = {
  "lx_msgs__msg",  // message namespace
  "RoverCommand",  // message name
  3,  // number of fields
  sizeof(lx_msgs__msg__RoverCommand),
  lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_member_array,  // message members
  lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_type_support_handle = {
  0,
  &lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, msg, RoverCommand)() {
  lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Twist)();
  if (!lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_type_support_handle.typesupport_identifier) {
    lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__msg__RoverCommand__rosidl_typesupport_introspection_c__RoverCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
