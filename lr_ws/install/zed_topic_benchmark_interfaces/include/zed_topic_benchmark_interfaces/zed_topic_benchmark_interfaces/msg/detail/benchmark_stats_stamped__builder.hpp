// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__BUILDER_HPP_
#define ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "zed_topic_benchmark_interfaces/msg/detail/benchmark_stats_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace zed_topic_benchmark_interfaces
{

namespace msg
{

namespace builder
{

class Init_BenchmarkStatsStamped_topic_avg_bw
{
public:
  explicit Init_BenchmarkStatsStamped_topic_avg_bw(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & msg)
  : msg_(msg)
  {}
  ::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped topic_avg_bw(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped::_topic_avg_bw_type arg)
  {
    msg_.topic_avg_bw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped msg_;
};

class Init_BenchmarkStatsStamped_topic_bw
{
public:
  explicit Init_BenchmarkStatsStamped_topic_bw(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & msg)
  : msg_(msg)
  {}
  Init_BenchmarkStatsStamped_topic_avg_bw topic_bw(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped::_topic_bw_type arg)
  {
    msg_.topic_bw = std::move(arg);
    return Init_BenchmarkStatsStamped_topic_avg_bw(msg_);
  }

private:
  ::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped msg_;
};

class Init_BenchmarkStatsStamped_topic_avg_freq
{
public:
  explicit Init_BenchmarkStatsStamped_topic_avg_freq(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & msg)
  : msg_(msg)
  {}
  Init_BenchmarkStatsStamped_topic_bw topic_avg_freq(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped::_topic_avg_freq_type arg)
  {
    msg_.topic_avg_freq = std::move(arg);
    return Init_BenchmarkStatsStamped_topic_bw(msg_);
  }

private:
  ::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped msg_;
};

class Init_BenchmarkStatsStamped_topic_freq
{
public:
  explicit Init_BenchmarkStatsStamped_topic_freq(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped & msg)
  : msg_(msg)
  {}
  Init_BenchmarkStatsStamped_topic_avg_freq topic_freq(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped::_topic_freq_type arg)
  {
    msg_.topic_freq = std::move(arg);
    return Init_BenchmarkStatsStamped_topic_avg_freq(msg_);
  }

private:
  ::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped msg_;
};

class Init_BenchmarkStatsStamped_header
{
public:
  Init_BenchmarkStatsStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BenchmarkStatsStamped_topic_freq header(::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BenchmarkStatsStamped_topic_freq(msg_);
  }

private:
  ::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped>()
{
  return zed_topic_benchmark_interfaces::msg::builder::Init_BenchmarkStatsStamped_header();
}

}  // namespace zed_topic_benchmark_interfaces

#endif  // ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__BUILDER_HPP_
