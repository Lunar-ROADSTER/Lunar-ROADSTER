// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cg_msgs:msg/BeaconMultiTag.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cg_msgs/msg/detail/beacon_multi_tag__rosidl_typesupport_introspection_c.h"
#include "cg_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cg_msgs/msg/detail/beacon_multi_tag__functions.h"
#include "cg_msgs/msg/detail/beacon_multi_tag__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `TagsList`
#include "cg_msgs/msg/beacon_tag.h"
// Member `TagsList`
#include "cg_msgs/msg/detail/beacon_tag__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cg_msgs__msg__BeaconMultiTag__init(message_memory);
}

void cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_fini_function(void * message_memory)
{
  cg_msgs__msg__BeaconMultiTag__fini(message_memory);
}

size_t cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__size_function__BeaconMultiTag__TagsList(
  const void * untyped_member)
{
  (void)untyped_member;
  return 2;
}

const void * cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__get_const_function__BeaconMultiTag__TagsList(
  const void * untyped_member, size_t index)
{
  const cg_msgs__msg__BeaconTag * member =
    (const cg_msgs__msg__BeaconTag *)(untyped_member);
  return &member[index];
}

void * cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__get_function__BeaconMultiTag__TagsList(
  void * untyped_member, size_t index)
{
  cg_msgs__msg__BeaconTag * member =
    (cg_msgs__msg__BeaconTag *)(untyped_member);
  return &member[index];
}

void cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__fetch_function__BeaconMultiTag__TagsList(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const cg_msgs__msg__BeaconTag * item =
    ((const cg_msgs__msg__BeaconTag *)
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__get_const_function__BeaconMultiTag__TagsList(untyped_member, index));
  cg_msgs__msg__BeaconTag * value =
    (cg_msgs__msg__BeaconTag *)(untyped_value);
  *value = *item;
}

void cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__assign_function__BeaconMultiTag__TagsList(
  void * untyped_member, size_t index, const void * untyped_value)
{
  cg_msgs__msg__BeaconTag * item =
    ((cg_msgs__msg__BeaconTag *)
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__get_function__BeaconMultiTag__TagsList(untyped_member, index));
  const cg_msgs__msg__BeaconTag * value =
    (const cg_msgs__msg__BeaconTag *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__BeaconMultiTag, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "TagsList",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    2,  // array size
    false,  // is upper bound
    offsetof(cg_msgs__msg__BeaconMultiTag, TagsList),  // bytes offset in struct
    NULL,  // default value
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__size_function__BeaconMultiTag__TagsList,  // size() function pointer
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__get_const_function__BeaconMultiTag__TagsList,  // get_const(index) function pointer
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__get_function__BeaconMultiTag__TagsList,  // get(index) function pointer
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__fetch_function__BeaconMultiTag__TagsList,  // fetch(index, &value) function pointer
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__assign_function__BeaconMultiTag__TagsList,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_members = {
  "cg_msgs__msg",  // message namespace
  "BeaconMultiTag",  // message name
  2,  // number of fields
  sizeof(cg_msgs__msg__BeaconMultiTag),
  cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_member_array,  // message members
  cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_init_function,  // function to initialize message memory (memory has to be allocated)
  cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_type_support_handle = {
  0,
  &cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cg_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cg_msgs, msg, BeaconMultiTag)() {
  cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cg_msgs, msg, BeaconTag)();
  if (!cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_type_support_handle.typesupport_identifier) {
    cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cg_msgs__msg__BeaconMultiTag__rosidl_typesupport_introspection_c__BeaconMultiTag_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
