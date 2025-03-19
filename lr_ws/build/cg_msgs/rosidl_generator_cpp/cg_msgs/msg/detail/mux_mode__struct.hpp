// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/MuxMode.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__MUX_MODE__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__MUX_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cg_msgs__msg__MuxMode __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__MuxMode __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MuxMode_
{
  using Type = MuxMode_<ContainerAllocator>;

  explicit MuxMode_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = 3;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = 0;
    }
  }

  explicit MuxMode_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->mode = 3;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t IDLE =
    0u;
  static constexpr uint8_t AUTOGRADER =
    1u;
  static constexpr uint8_t FULL_AUTONOMY =
    2u;
  static constexpr uint8_t FULL_TELEOP =
    3u;
  static constexpr uint8_t HIGHEST_VALID_MODE =
    3u;

  // pointer types
  using RawPtr =
    cg_msgs::msg::MuxMode_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::MuxMode_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::MuxMode_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::MuxMode_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__MuxMode
    std::shared_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__MuxMode
    std::shared_ptr<cg_msgs::msg::MuxMode_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MuxMode_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const MuxMode_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MuxMode_

// alias to use template instance with default allocator
using MuxMode =
  cg_msgs::msg::MuxMode_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MuxMode_<ContainerAllocator>::IDLE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MuxMode_<ContainerAllocator>::AUTOGRADER;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MuxMode_<ContainerAllocator>::FULL_AUTONOMY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MuxMode_<ContainerAllocator>::FULL_TELEOP;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t MuxMode_<ContainerAllocator>::HIGHEST_VALID_MODE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__MUX_MODE__STRUCT_HPP_
