// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__STRUCT_H_
#define ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/BenchmarkStatsStamped in the package zed_topic_benchmark_interfaces.
/**
  * Standard Header
 */
typedef struct zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped
{
  std_msgs__msg__Header header;
  /// Instant Frequency
  float topic_freq;
  /// Average Frequency
  float topic_avg_freq;
  /// Instant Bandwidth
  float topic_bw;
  /// Average Bandwidth
  float topic_avg_bw;
} zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped;

// Struct for a sequence of zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped.
typedef struct zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence
{
  zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__STRUCT_H_
