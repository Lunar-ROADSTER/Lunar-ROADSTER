// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__rosidl_typesupport_introspection_c.h"
#include "zed_topic_benchmark_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__functions.h"
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__init(message_memory);
}

void zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_fini_function(void * message_memory)
{
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_member_array[5] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "topic_freq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped, topic_freq),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "topic_avg_freq",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped, topic_avg_freq),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "topic_bw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped, topic_bw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "topic_avg_bw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped, topic_avg_bw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_members = {
  "zed_topic_benchmark_interfaces__msg",  // message namespace
  "BenchmarkStatsStamped",  // message name
  5,  // number of fields
  sizeof(zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped),
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_member_array,  // message members
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_init_function,  // function to initialize message memory (memory has to be allocated)
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_type_support_handle = {
  0,
  &zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_zed_topic_benchmark_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, zed_topic_benchmark_interfaces, msg, BenchmarkStatsStamped)() {
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_type_support_handle.typesupport_identifier) {
    zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__rosidl_typesupport_introspection_c__BenchmarkStatsStamped_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
