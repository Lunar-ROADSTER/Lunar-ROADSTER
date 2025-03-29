// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/Slip.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SLIP__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__SLIP__STRUCT_HPP_

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
# define DEPRECATED__cg_msgs__msg__Slip __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__Slip __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Slip_
{
  using Type = Slip_<ContainerAllocator>;

  explicit Slip_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->slip = 0.0f;
      this->slip_avg = 0.0f;
      this->slip_latch = true;
      this->vel = 0.0f;
      this->vel_avg = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->slip = 0.0f;
      this->slip_avg = 0.0f;
      this->slip_latch = false;
      this->vel = 0.0f;
      this->vel_avg = 0.0f;
    }
  }

  explicit Slip_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->slip = 0.0f;
      this->slip_avg = 0.0f;
      this->slip_latch = true;
      this->vel = 0.0f;
      this->vel_avg = 0.0f;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->slip = 0.0f;
      this->slip_avg = 0.0f;
      this->slip_latch = false;
      this->vel = 0.0f;
      this->vel_avg = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _slip_type =
    float;
  _slip_type slip;
  using _slip_avg_type =
    float;
  _slip_avg_type slip_avg;
  using _slip_latch_type =
    bool;
  _slip_latch_type slip_latch;
  using _vel_type =
    float;
  _vel_type vel;
  using _vel_avg_type =
    float;
  _vel_avg_type vel_avg;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__slip(
    const float & _arg)
  {
    this->slip = _arg;
    return *this;
  }
  Type & set__slip_avg(
    const float & _arg)
  {
    this->slip_avg = _arg;
    return *this;
  }
  Type & set__slip_latch(
    const bool & _arg)
  {
    this->slip_latch = _arg;
    return *this;
  }
  Type & set__vel(
    const float & _arg)
  {
    this->vel = _arg;
    return *this;
  }
  Type & set__vel_avg(
    const float & _arg)
  {
    this->vel_avg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::msg::Slip_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::Slip_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::Slip_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::Slip_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::Slip_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::Slip_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::Slip_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::Slip_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::Slip_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::Slip_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__Slip
    std::shared_ptr<cg_msgs::msg::Slip_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__Slip
    std::shared_ptr<cg_msgs::msg::Slip_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Slip_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->slip != other.slip) {
      return false;
    }
    if (this->slip_avg != other.slip_avg) {
      return false;
    }
    if (this->slip_latch != other.slip_latch) {
      return false;
    }
    if (this->vel != other.vel) {
      return false;
    }
    if (this->vel_avg != other.vel_avg) {
      return false;
    }
    return true;
  }
  bool operator!=(const Slip_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Slip_

// alias to use template instance with default allocator
using Slip =
  cg_msgs::msg::Slip_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__SLIP__STRUCT_HPP_
