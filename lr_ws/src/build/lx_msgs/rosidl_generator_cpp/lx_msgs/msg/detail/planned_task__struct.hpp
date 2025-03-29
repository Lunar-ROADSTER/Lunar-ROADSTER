// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:msg/PlannedTask.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__MSG__DETAIL__PLANNED_TASK__STRUCT_HPP_
#define LX_MSGS__MSG__DETAIL__PLANNED_TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'berm_point'
#include "lx_msgs/msg/detail/berm_section__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__msg__PlannedTask __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__msg__PlannedTask __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PlannedTask_
{
  using Type = PlannedTask_<ContainerAllocator>;

  explicit PlannedTask_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    berm_point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_type = 0ul;
    }
  }

  explicit PlannedTask_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_alloc, _init),
    berm_point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_type = 0ul;
    }
  }

  // field types and members
  using _task_type_type =
    uint32_t;
  _task_type_type task_type;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _berm_point_type =
    lx_msgs::msg::BermSection_<ContainerAllocator>;
  _berm_point_type berm_point;

  // setters for named parameter idiom
  Type & set__task_type(
    const uint32_t & _arg)
  {
    this->task_type = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__berm_point(
    const lx_msgs::msg::BermSection_<ContainerAllocator> & _arg)
  {
    this->berm_point = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::msg::PlannedTask_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::msg::PlannedTask_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::PlannedTask_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::msg::PlannedTask_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__msg__PlannedTask
    std::shared_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__msg__PlannedTask
    std::shared_ptr<lx_msgs::msg::PlannedTask_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PlannedTask_ & other) const
  {
    if (this->task_type != other.task_type) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->berm_point != other.berm_point) {
      return false;
    }
    return true;
  }
  bool operator!=(const PlannedTask_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PlannedTask_

// alias to use template instance with default allocator
using PlannedTask =
  lx_msgs::msg::PlannedTask_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace lx_msgs

#endif  // LX_MSGS__MSG__DETAIL__PLANNED_TASK__STRUCT_HPP_
