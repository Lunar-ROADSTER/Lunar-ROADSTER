// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "zed_topic_benchmark_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__struct.hpp"

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

#include "fastcdr/Cdr.h"

namespace zed_topic_benchmark_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_topic_benchmark_interfaces
cdr_serialize(
  const zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_topic_benchmark_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_topic_benchmark_interfaces
get_serialized_size(
  const zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_topic_benchmark_interfaces
max_serialized_size_BenchmarkStatsStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace zed_topic_benchmark_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_zed_topic_benchmark_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, zed_topic_benchmark_interfaces, msg, BenchmarkStatsStamped)();

#ifdef __cplusplus
}
#endif

#endif  // ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
