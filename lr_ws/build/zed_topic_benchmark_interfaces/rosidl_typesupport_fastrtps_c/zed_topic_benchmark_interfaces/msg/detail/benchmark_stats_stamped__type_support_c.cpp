// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "zed_topic_benchmark_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__struct.h"
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_topic_benchmark_interfaces
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_topic_benchmark_interfaces
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_zed_topic_benchmark_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _BenchmarkStatsStamped__ros_msg_type = zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped;

static bool _BenchmarkStatsStamped__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _BenchmarkStatsStamped__ros_msg_type * ros_message = static_cast<const _BenchmarkStatsStamped__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: topic_freq
  {
    cdr << ros_message->topic_freq;
  }

  // Field name: topic_avg_freq
  {
    cdr << ros_message->topic_avg_freq;
  }

  // Field name: topic_bw
  {
    cdr << ros_message->topic_bw;
  }

  // Field name: topic_avg_bw
  {
    cdr << ros_message->topic_avg_bw;
  }

  return true;
}

static bool _BenchmarkStatsStamped__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _BenchmarkStatsStamped__ros_msg_type * ros_message = static_cast<_BenchmarkStatsStamped__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: topic_freq
  {
    cdr >> ros_message->topic_freq;
  }

  // Field name: topic_avg_freq
  {
    cdr >> ros_message->topic_avg_freq;
  }

  // Field name: topic_bw
  {
    cdr >> ros_message->topic_bw;
  }

  // Field name: topic_avg_bw
  {
    cdr >> ros_message->topic_avg_bw;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_topic_benchmark_interfaces
size_t get_serialized_size_zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BenchmarkStatsStamped__ros_msg_type * ros_message = static_cast<const _BenchmarkStatsStamped__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name topic_freq
  {
    size_t item_size = sizeof(ros_message->topic_freq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name topic_avg_freq
  {
    size_t item_size = sizeof(ros_message->topic_avg_freq);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name topic_bw
  {
    size_t item_size = sizeof(ros_message->topic_bw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name topic_avg_bw
  {
    size_t item_size = sizeof(ros_message->topic_avg_bw);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _BenchmarkStatsStamped__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_zed_topic_benchmark_interfaces
size_t max_serialized_size_zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: topic_freq
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: topic_avg_freq
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: topic_bw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: topic_avg_bw
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped;
    is_plain =
      (
      offsetof(DataType, topic_avg_bw) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _BenchmarkStatsStamped__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BenchmarkStatsStamped = {
  "zed_topic_benchmark_interfaces::msg",
  "BenchmarkStatsStamped",
  _BenchmarkStatsStamped__cdr_serialize,
  _BenchmarkStatsStamped__cdr_deserialize,
  _BenchmarkStatsStamped__get_serialized_size,
  _BenchmarkStatsStamped__max_serialized_size
};

static rosidl_message_type_support_t _BenchmarkStatsStamped__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BenchmarkStatsStamped,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, zed_topic_benchmark_interfaces, msg, BenchmarkStatsStamped)() {
  return &_BenchmarkStatsStamped__type_support;
}

#if defined(__cplusplus)
}
#endif
