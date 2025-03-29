// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lx_msgs:msg/BermSection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lx_msgs/msg/detail/berm_section__rosidl_typesupport_introspection_c.h"
#include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lx_msgs/msg/detail/berm_section__functions.h"
#include "lx_msgs/msg/detail/berm_section__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__msg__BermSection__init(message_memory);
}

void lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_fini_function(void * message_memory)
{
  lx_msgs__msg__BermSection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_member_array[3] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermSection, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermSection, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermSection, theta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_members = {
  "lx_msgs__msg",  // message namespace
  "BermSection",  // message name
  3,  // number of fields
  sizeof(lx_msgs__msg__BermSection),
  lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_member_array,  // message members
  lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_type_support_handle = {
  0,
  &lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, msg, BermSection)() {
  if (!lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_type_support_handle.typesupport_identifier) {
    lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__msg__BermSection__rosidl_typesupport_introspection_c__BermSection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
