// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:msg/ActuatorState.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__ACTUATOR_STATE__STRUCT_HPP_
#define CG_MSGS__MSG__DETAIL__ACTUATOR_STATE__STRUCT_HPP_

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
# define DEPRECATED__cg_msgs__msg__ActuatorState __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__msg__ActuatorState __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActuatorState_
{
  using Type = ActuatorState_<ContainerAllocator>;

  explicit ActuatorState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->wheel_velocity = 0.0;
      this->steer_position = 0.0;
      this->tool_position = 0.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->wheel_velocity = 0.0;
      this->steer_position = 0.0;
      this->tool_position = 0.0;
    }
  }

  explicit ActuatorState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->wheel_velocity = 0.0;
      this->steer_position = 0.0;
      this->tool_position = 0.0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->wheel_velocity = 0.0;
      this->steer_position = 0.0;
      this->tool_position = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _wheel_velocity_type =
    double;
  _wheel_velocity_type wheel_velocity;
  using _steer_position_type =
    double;
  _steer_position_type steer_position;
  using _tool_position_type =
    double;
  _tool_position_type tool_position;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__wheel_velocity(
    const double & _arg)
  {
    this->wheel_velocity = _arg;
    return *this;
  }
  Type & set__steer_position(
    const double & _arg)
  {
    this->steer_position = _arg;
    return *this;
  }
  Type & set__tool_position(
    const double & _arg)
  {
    this->tool_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::msg::ActuatorState_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::msg::ActuatorState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::ActuatorState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::msg::ActuatorState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__msg__ActuatorState
    std::shared_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__msg__ActuatorState
    std::shared_ptr<cg_msgs::msg::ActuatorState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActuatorState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->wheel_velocity != other.wheel_velocity) {
      return false;
    }
    if (this->steer_position != other.steer_position) {
      return false;
    }
    if (this->tool_position != other.tool_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActuatorState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActuatorState_

// alias to use template instance with default allocator
using ActuatorState =
  cg_msgs::msg::ActuatorState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__ACTUATOR_STATE__STRUCT_HPP_
