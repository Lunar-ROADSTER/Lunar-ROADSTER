// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:srv/Plan.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__PLAN__STRUCT_HPP_
#define LX_MSGS__SRV__DETAIL__PLAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'berm_input'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__Plan_Request __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__Plan_Request __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Plan_Request_
{
  using Type = Plan_Request_<ContainerAllocator>;

  explicit Plan_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->berm_height = 0.0f;
      this->section_length = 0.0f;
      this->new_plan = false;
    }
  }

  explicit Plan_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->berm_height = 0.0f;
      this->section_length = 0.0f;
      this->new_plan = false;
    }
  }

  // field types and members
  using _berm_input_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _berm_input_type berm_input;
  using _berm_height_type =
    float;
  _berm_height_type berm_height;
  using _section_length_type =
    float;
  _section_length_type section_length;
  using _new_plan_type =
    bool;
  _new_plan_type new_plan;

  // setters for named parameter idiom
  Type & set__berm_input(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->berm_input = _arg;
    return *this;
  }
  Type & set__berm_height(
    const float & _arg)
  {
    this->berm_height = _arg;
    return *this;
  }
  Type & set__section_length(
    const float & _arg)
  {
    this->section_length = _arg;
    return *this;
  }
  Type & set__new_plan(
    const bool & _arg)
  {
    this->new_plan = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::Plan_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::Plan_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Plan_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Plan_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__Plan_Request
    std::shared_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__Plan_Request
    std::shared_ptr<lx_msgs::srv::Plan_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Plan_Request_ & other) const
  {
    if (this->berm_input != other.berm_input) {
      return false;
    }
    if (this->berm_height != other.berm_height) {
      return false;
    }
    if (this->section_length != other.section_length) {
      return false;
    }
    if (this->new_plan != other.new_plan) {
      return false;
    }
    return true;
  }
  bool operator!=(const Plan_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Plan_Request_

// alias to use template instance with default allocator
using Plan_Request =
  lx_msgs::srv::Plan_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs


// Include directives for member types
// Member 'plan'
#include "lx_msgs/msg/detail/planned_task__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__Plan_Response __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__Plan_Response __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Plan_Response_
{
  using Type = Plan_Response_<ContainerAllocator>;

  explicit Plan_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit Plan_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _plan_type =
    std::vector<lx_msgs::msg::PlannedTask_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lx_msgs::msg::PlannedTask_<ContainerAllocator>>>;
  _plan_type plan;

  // setters for named parameter idiom
  Type & set__plan(
    const std::vector<lx_msgs::msg::PlannedTask_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<lx_msgs::msg::PlannedTask_<ContainerAllocator>>> & _arg)
  {
    this->plan = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::Plan_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::Plan_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Plan_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Plan_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__Plan_Response
    std::shared_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__Plan_Response
    std::shared_ptr<lx_msgs::srv::Plan_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Plan_Response_ & other) const
  {
    if (this->plan != other.plan) {
      return false;
    }
    return true;
  }
  bool operator!=(const Plan_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Plan_Response_

// alias to use template instance with default allocator
using Plan_Response =
  lx_msgs::srv::Plan_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs

namespace lx_msgs
{

namespace srv
{

struct Plan
{
  using Request = lx_msgs::srv::Plan_Request;
  using Response = lx_msgs::srv::Plan_Response;
};

}  // namespace srv

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__PLAN__STRUCT_HPP_
