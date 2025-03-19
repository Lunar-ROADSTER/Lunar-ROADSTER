// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:srv/EnableWorksystem.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__STRUCT_HPP_
#define CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cg_msgs__srv__EnableWorksystem_Request __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__srv__EnableWorksystem_Request __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EnableWorksystem_Request_
{
  using Type = EnableWorksystem_Request_<ContainerAllocator>;

  explicit EnableWorksystem_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_worksystem = false;
    }
  }

  explicit EnableWorksystem_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_worksystem = false;
    }
  }

  // field types and members
  using _enable_worksystem_type =
    bool;
  _enable_worksystem_type enable_worksystem;

  // setters for named parameter idiom
  Type & set__enable_worksystem(
    const bool & _arg)
  {
    this->enable_worksystem = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__srv__EnableWorksystem_Request
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__srv__EnableWorksystem_Request
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EnableWorksystem_Request_ & other) const
  {
    if (this->enable_worksystem != other.enable_worksystem) {
      return false;
    }
    return true;
  }
  bool operator!=(const EnableWorksystem_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EnableWorksystem_Request_

// alias to use template instance with default allocator
using EnableWorksystem_Request =
  cg_msgs::srv::EnableWorksystem_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cg_msgs


#ifndef _WIN32
# define DEPRECATED__cg_msgs__srv__EnableWorksystem_Response __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__srv__EnableWorksystem_Response __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EnableWorksystem_Response_
{
  using Type = EnableWorksystem_Response_<ContainerAllocator>;

  explicit EnableWorksystem_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->worksystem_enabled = false;
    }
  }

  explicit EnableWorksystem_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->worksystem_enabled = false;
    }
  }

  // field types and members
  using _worksystem_enabled_type =
    bool;
  _worksystem_enabled_type worksystem_enabled;

  // setters for named parameter idiom
  Type & set__worksystem_enabled(
    const bool & _arg)
  {
    this->worksystem_enabled = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__srv__EnableWorksystem_Response
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__srv__EnableWorksystem_Response
    std::shared_ptr<cg_msgs::srv::EnableWorksystem_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EnableWorksystem_Response_ & other) const
  {
    if (this->worksystem_enabled != other.worksystem_enabled) {
      return false;
    }
    return true;
  }
  bool operator!=(const EnableWorksystem_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EnableWorksystem_Response_

// alias to use template instance with default allocator
using EnableWorksystem_Response =
  cg_msgs::srv::EnableWorksystem_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cg_msgs

namespace cg_msgs
{

namespace srv
{

struct EnableWorksystem
{
  using Request = cg_msgs::srv::EnableWorksystem_Request;
  using Response = cg_msgs::srv::EnableWorksystem_Response;
};

}  // namespace srv

}  // namespace cg_msgs

#endif  // CG_MSGS__SRV__DETAIL__ENABLE_WORKSYSTEM__STRUCT_HPP_
