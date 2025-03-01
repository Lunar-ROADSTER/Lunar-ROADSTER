// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from zed_topic_benchmark_interfaces:msg/BenchmarkStatsStamped.idl
// generated code does not contain a copyright notice

#ifndef ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__STRUCT_HPP_
#define ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped __attribute__((deprecated))
#else
# define DEPRECATED__zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped __declspec(deprecated)
#endif

namespace zed_topic_benchmark_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BenchmarkStatsStamped_
{
  using Type = BenchmarkStatsStamped_<ContainerAllocator>;

  explicit BenchmarkStatsStamped_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_freq = 0.0f;
      this->topic_avg_freq = 0.0f;
      this->topic_bw = 0.0f;
      this->topic_avg_bw = 0.0f;
    }
  }

  explicit BenchmarkStatsStamped_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_freq = 0.0f;
      this->topic_avg_freq = 0.0f;
      this->topic_bw = 0.0f;
      this->topic_avg_bw = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _topic_freq_type =
    float;
  _topic_freq_type topic_freq;
  using _topic_avg_freq_type =
    float;
  _topic_avg_freq_type topic_avg_freq;
  using _topic_bw_type =
    float;
  _topic_bw_type topic_bw;
  using _topic_avg_bw_type =
    float;
  _topic_avg_bw_type topic_avg_bw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__topic_freq(
    const float & _arg)
  {
    this->topic_freq = _arg;
    return *this;
  }
  Type & set__topic_avg_freq(
    const float & _arg)
  {
    this->topic_avg_freq = _arg;
    return *this;
  }
  Type & set__topic_bw(
    const float & _arg)
  {
    this->topic_bw = _arg;
    return *this;
  }
  Type & set__topic_avg_bw(
    const float & _arg)
  {
    this->topic_avg_bw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator> *;
  using ConstRawPtr =
    const zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped
    std::shared_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__zed_topic_benchmark_interfaces__msg__BenchmarkStatsStamped
    std::shared_ptr<zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BenchmarkStatsStamped_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->topic_freq != other.topic_freq) {
      return false;
    }
    if (this->topic_avg_freq != other.topic_avg_freq) {
      return false;
    }
    if (this->topic_bw != other.topic_bw) {
      return false;
    }
    if (this->topic_avg_bw != other.topic_avg_bw) {
      return false;
    }
    return true;
  }
  bool operator!=(const BenchmarkStatsStamped_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BenchmarkStatsStamped_

// alias to use template instance with default allocator
using BenchmarkStatsStamped =
  zed_topic_benchmark_interfaces::msg::BenchmarkStatsStamped_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace zed_topic_benchmark_interfaces

#endif  // ZED_TOPIC_BENCHMARK_INTERFACES__MSG__DETAIL__BENCHMARK_STATS_STAMPED__STRUCT_HPP_
