// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:srv/UserInputRecord.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__STRUCT_HPP_
#define LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'empty'
#include "std_msgs/msg/detail/empty__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__UserInputRecord_Request __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__UserInputRecord_Request __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UserInputRecord_Request_
{
  using Type = UserInputRecord_Request_<ContainerAllocator>;

  explicit UserInputRecord_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : empty(_init)
  {
    (void)_init;
  }

  explicit UserInputRecord_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : empty(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _empty_type =
    std_msgs::msg::Empty_<ContainerAllocator>;
  _empty_type empty;

  // setters for named parameter idiom
  Type & set__empty(
    const std_msgs::msg::Empty_<ContainerAllocator> & _arg)
  {
    this->empty = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__UserInputRecord_Request
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__UserInputRecord_Request
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserInputRecord_Request_ & other) const
  {
    if (this->empty != other.empty) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserInputRecord_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserInputRecord_Request_

// alias to use template instance with default allocator
using UserInputRecord_Request =
  lx_msgs::srv::UserInputRecord_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs


#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__UserInputRecord_Response __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__UserInputRecord_Response __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UserInputRecord_Response_
{
  using Type = UserInputRecord_Response_<ContainerAllocator>;

  explicit UserInputRecord_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit UserInputRecord_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__UserInputRecord_Response
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__UserInputRecord_Response
    std::shared_ptr<lx_msgs::srv::UserInputRecord_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UserInputRecord_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const UserInputRecord_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UserInputRecord_Response_

// alias to use template instance with default allocator
using UserInputRecord_Response =
  lx_msgs::srv::UserInputRecord_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs

namespace lx_msgs
{

namespace srv
{

struct UserInputRecord
{
  using Request = lx_msgs::srv::UserInputRecord_Request;
  using Response = lx_msgs::srv::UserInputRecord_Response;
};

}  // namespace srv

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__USER_INPUT_RECORD__STRUCT_HPP_
