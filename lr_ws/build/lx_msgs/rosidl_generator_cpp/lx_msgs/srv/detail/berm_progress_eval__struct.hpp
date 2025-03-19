// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:srv/BermProgressEval.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__STRUCT_HPP_
#define LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__BermProgressEval_Request __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__BermProgressEval_Request __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BermProgressEval_Request_
{
  using Type = BermProgressEval_Request_<ContainerAllocator>;

  explicit BermProgressEval_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->need_metrics = false;
    }
  }

  explicit BermProgressEval_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->need_metrics = false;
    }
  }

  // field types and members
  using _need_metrics_type =
    bool;
  _need_metrics_type need_metrics;

  // setters for named parameter idiom
  Type & set__need_metrics(
    const bool & _arg)
  {
    this->need_metrics = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__BermProgressEval_Request
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__BermProgressEval_Request
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BermProgressEval_Request_ & other) const
  {
    if (this->need_metrics != other.need_metrics) {
      return false;
    }
    return true;
  }
  bool operator!=(const BermProgressEval_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BermProgressEval_Request_

// alias to use template instance with default allocator
using BermProgressEval_Request =
  lx_msgs::srv::BermProgressEval_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs


// Include directives for member types
// Member 'progress'
#include "lx_msgs/msg/detail/berm_progress__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__BermProgressEval_Response __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__BermProgressEval_Response __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BermProgressEval_Response_
{
  using Type = BermProgressEval_Response_<ContainerAllocator>;

  explicit BermProgressEval_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : progress(_init)
  {
    (void)_init;
  }

  explicit BermProgressEval_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : progress(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _progress_type =
    lx_msgs::msg::BermProgress_<ContainerAllocator>;
  _progress_type progress;

  // setters for named parameter idiom
  Type & set__progress(
    const lx_msgs::msg::BermProgress_<ContainerAllocator> & _arg)
  {
    this->progress = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__BermProgressEval_Response
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__BermProgressEval_Response
    std::shared_ptr<lx_msgs::srv::BermProgressEval_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BermProgressEval_Response_ & other) const
  {
    if (this->progress != other.progress) {
      return false;
    }
    return true;
  }
  bool operator!=(const BermProgressEval_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BermProgressEval_Response_

// alias to use template instance with default allocator
using BermProgressEval_Response =
  lx_msgs::srv::BermProgressEval_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs

namespace lx_msgs
{

namespace srv
{

struct BermProgressEval
{
  using Request = lx_msgs::srv::BermProgressEval_Request;
  using Response = lx_msgs::srv::BermProgressEval_Response;
};

}  // namespace srv

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__BERM_PROGRESS_EVAL__STRUCT_HPP_
