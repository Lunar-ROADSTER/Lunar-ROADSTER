// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__TRAITS_HPP_
#define ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace zed_topic_benchmark_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const BenchmarkStatsStamped & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: topic_freq
  {
    out << "topic_freq: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_freq, out);
    out << ", ";
  }

  // member: topic_avg_freq
  {
    out << "topic_avg_freq: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_avg_freq, out);
    out << ", ";
  }

  // member: topic_bw
  {
    out << "topic_bw: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_bw, out);
    out << ", ";
  }

  // member: topic_avg_bw
  {
    out << "topic_avg_bw: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_avg_bw, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BenchmarkStatsStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: topic_freq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_freq: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_freq, out);
    out << "\n";
  }

  // member: topic_avg_freq
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_avg_freq: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_avg_freq, out);
    out << "\n";
  }

  // member: topic_bw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_bw: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_bw, out);
    out << "\n";
  }

  // member: topic_avg_bw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "topic_avg_bw: ";
    rosidl_generator_traits::value_to_yaml(msg.topic_avg_bw, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BenchmarkStatsStamped & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace zed_topic_benchmark_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use zed_topic_benchmark_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & msg,
  std::ostream & out, size_t indentation = 0)
{
  zed_topic_benchmark_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use zed_topic_benchmark_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & msg)
{
  return zed_topic_benchmark_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>()
{
  return "zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped";
}

template<>
inline const char * name<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>()
{
  return "zed_topic_benchmark_interfaces/msg/BenchmarkStatsStamped";
}

template<>
struct has_fixed_size<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__TRAITS_HPP_
