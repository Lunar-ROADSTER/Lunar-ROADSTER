// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/EncoderTelemetry.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__STRUCT_HPP_

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
# define DEPRECATED__cg_msgs__msg__EncoderTelemetry __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__EncoderTelemetry __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EncoderTelemetry_
{
  using Type = EncoderTelemetry_<ContainerAllocator>;

  explicit EncoderTelemetry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->steer_pos_front = 0l;
      this->steer_pos_rear = 0l;
      this->tool_pos = 0l;
      this->drive_vel_front = 0l;
      this->drive_vel_rear = 0l;
      this->drive_delta_front = 0l;
      this->drive_delta_rear = 0l;
      this->term_byte = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->steer_pos_front = 0l;
      this->steer_pos_rear = 0l;
      this->tool_pos = 0l;
      this->drive_vel_front = 0l;
      this->drive_vel_rear = 0l;
      this->drive_delta_front = 0l;
      this->drive_delta_rear = 0l;
      this->term_byte = 0l;
    }
  }

  explicit EncoderTelemetry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->steer_pos_front = 0l;
      this->steer_pos_rear = 0l;
      this->tool_pos = 0l;
      this->drive_vel_front = 0l;
      this->drive_vel_rear = 0l;
      this->drive_delta_front = 0l;
      this->drive_delta_rear = 0l;
      this->term_byte = 0l;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->steer_pos_front = 0l;
      this->steer_pos_rear = 0l;
      this->tool_pos = 0l;
      this->drive_vel_front = 0l;
      this->drive_vel_rear = 0l;
      this->drive_delta_front = 0l;
      this->drive_delta_rear = 0l;
      this->term_byte = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _steer_pos_front_type =
    int32_t;
  _steer_pos_front_type steer_pos_front;
  using _steer_pos_rear_type =
    int32_t;
  _steer_pos_rear_type steer_pos_rear;
  using _tool_pos_type =
    int32_t;
  _tool_pos_type tool_pos;
  using _drive_vel_front_type =
    int32_t;
  _drive_vel_front_type drive_vel_front;
  using _drive_vel_rear_type =
    int32_t;
  _drive_vel_rear_type drive_vel_rear;
  using _drive_delta_front_type =
    int32_t;
  _drive_delta_front_type drive_delta_front;
  using _drive_delta_rear_type =
    int32_t;
  _drive_delta_rear_type drive_delta_rear;
  using _term_byte_type =
    int32_t;
  _term_byte_type term_byte;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__steer_pos_front(
    const int32_t & _arg)
  {
    this->steer_pos_front = _arg;
    return *this;
  }
  Type & set__steer_pos_rear(
    const int32_t & _arg)
  {
    this->steer_pos_rear = _arg;
    return *this;
  }
  Type & set__tool_pos(
    const int32_t & _arg)
  {
    this->tool_pos = _arg;
    return *this;
  }
  Type & set__drive_vel_front(
    const int32_t & _arg)
  {
    this->drive_vel_front = _arg;
    return *this;
  }
  Type & set__drive_vel_rear(
    const int32_t & _arg)
  {
    this->drive_vel_rear = _arg;
    return *this;
  }
  Type & set__drive_delta_front(
    const int32_t & _arg)
  {
    this->drive_delta_front = _arg;
    return *this;
  }
  Type & set__drive_delta_rear(
    const int32_t & _arg)
  {
    this->drive_delta_rear = _arg;
    return *this;
  }
  Type & set__term_byte(
    const int32_t & _arg)
  {
    this->term_byte = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::msg::EncoderTelemetry_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::EncoderTelemetry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::EncoderTelemetry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::EncoderTelemetry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__EncoderTelemetry
    std::shared_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__EncoderTelemetry
    std::shared_ptr<cg_msgs::msg::EncoderTelemetry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EncoderTelemetry_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->steer_pos_front != other.steer_pos_front) {
      return false;
    }
    if (this->steer_pos_rear != other.steer_pos_rear) {
      return false;
    }
    if (this->tool_pos != other.tool_pos) {
      return false;
    }
    if (this->drive_vel_front != other.drive_vel_front) {
      return false;
    }
    if (this->drive_vel_rear != other.drive_vel_rear) {
      return false;
    }
    if (this->drive_delta_front != other.drive_delta_front) {
      return false;
    }
    if (this->drive_delta_rear != other.drive_delta_rear) {
      return false;
    }
    if (this->term_byte != other.term_byte) {
      return false;
    }
    return true;
  }
  bool operator!=(const EncoderTelemetry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EncoderTelemetry_

// alias to use template instance with default allocator
using EncoderTelemetry =
  cg_msgs::msg::EncoderTelemetry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__ENCODER_TELEMETRY__STRUCT_HPP_
