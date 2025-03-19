// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from lx_msgs:msg/BermConfig.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "lx_msgs/msg/detail/berm_config__rosidl_typesupport_introspection_c.h"
#include "lx_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "lx_msgs/msg/detail/berm_config__functions.h"
#include "lx_msgs/msg/detail/berm_config__struct.h"


// Include directives for member types
// Member `berm_configuration`
#include "geometry_msgs/msg/point_stamped.h"
// Member `berm_configuration`
#include "geometry_msgs/msg/detail/point_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  lx_msgs__msg__BermConfig__init(message_memory);
}

void lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_fini_function(void * message_memory)
{
  lx_msgs__msg__BermConfig__fini(message_memory);
}

size_t lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__size_function__BermConfig__berm_configuration(
  const void * untyped_member)
{
  const geometry_msgs__msg__PointStamped__Sequence * member =
    (const geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  return member->size;
}

const void * lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__get_const_function__BermConfig__berm_configuration(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__PointStamped__Sequence * member =
    (const geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void * lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__get_function__BermConfig__berm_configuration(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__PointStamped__Sequence * member =
    (geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  return &member->data[index];
}

void lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__fetch_function__BermConfig__berm_configuration(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__PointStamped * item =
    ((const geometry_msgs__msg__PointStamped *)
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__get_const_function__BermConfig__berm_configuration(untyped_member, index));
  geometry_msgs__msg__PointStamped * value =
    (geometry_msgs__msg__PointStamped *)(untyped_value);
  *value = *item;
}

void lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__assign_function__BermConfig__berm_configuration(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__PointStamped * item =
    ((geometry_msgs__msg__PointStamped *)
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__get_function__BermConfig__berm_configuration(untyped_member, index));
  const geometry_msgs__msg__PointStamped * value =
    (const geometry_msgs__msg__PointStamped *)(untyped_value);
  *item = *value;
}

bool lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__resize_function__BermConfig__berm_configuration(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__PointStamped__Sequence * member =
    (geometry_msgs__msg__PointStamped__Sequence *)(untyped_member);
  geometry_msgs__msg__PointStamped__Sequence__fini(member);
  return geometry_msgs__msg__PointStamped__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_member_array[1] = {
  {
    "berm_configuration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(lx_msgs__msg__BermConfig, berm_configuration),  // bytes offset in struct
    NULL,  // default value
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__size_function__BermConfig__berm_configuration,  // size() function pointer
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__get_const_function__BermConfig__berm_configuration,  // get_const(index) function pointer
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__get_function__BermConfig__berm_configuration,  // get(index) function pointer
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__fetch_function__BermConfig__berm_configuration,  // fetch(index, &value) function pointer
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__assign_function__BermConfig__berm_configuration,  // assign(index, value) function pointer
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__resize_function__BermConfig__berm_configuration  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_members = {
  "lx_msgs__msg",  // message namespace
  "BermConfig",  // message name
  1,  // number of fields
  sizeof(lx_msgs__msg__BermConfig),
  lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_member_array,  // message members
  lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_init_function,  // function to initialize message memory (memory has to be allocated)
  lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_type_support_handle = {
  0,
  &lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_lx_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, lx_msgs, msg, BermConfig)() {
  lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PointStamped)();
  if (!lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_type_support_handle.typesupport_identifier) {
    lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &lx_msgs__msg__BermConfig__rosidl_typesupport_introspection_c__BermConfig_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
