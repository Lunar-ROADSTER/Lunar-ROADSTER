// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cg_msgs:msg/ActuatorState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cg_msgs/msg/detail/actuator_state__rosidl_typesupport_introspection_c.h"
#include "cg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cg_msgs/msg/detail/actuator_state__functions.h"
#include "cg_msgs/msg/detail/actuator_state__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cg_msgs__msg__ActuatorState__init(message_memory);
}

void cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_fini_function(void * message_memory)
{
  cg_msgs__msg__ActuatorState__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__ActuatorState, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "wheel_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__ActuatorState, wheel_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "steer_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__ActuatorState, steer_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tool_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__ActuatorState, tool_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_members = {
  "cg_msgs__msg",  // message namespace
  "ActuatorState",  // message name
  4,  // number of fields
  sizeof(cg_msgs__msg__ActuatorState),
  cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_member_array,  // message members
  cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_init_function,  // function to initialize message memory (memory has to be allocated)
  cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_type_support_handle = {
  0,
  &cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cg_msgs, msg, ActuatorState)() {
  cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_type_support_handle.typesupport_identifier) {
    cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cg_msgs__msg__ActuatorState__rosidl_typesupport_introspection_c__ActuatorState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
