// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:srv/Switch.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__SWITCH__STRUCT_HPP_
#define LX_MSGS__SRV__DETAIL__SWITCH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'current_berm_segment'
// Member 'prev_berm_segment'
#include "lx_msgs/msg/detail/berm_section__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__Switch_Request __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__Switch_Request __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Switch_Request_
{
  using Type = Switch_Request_<ContainerAllocator>;

  explicit Switch_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_berm_segment(_init),
    prev_berm_segment(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->switch_state = false;
      this->first_seg_dump = false;
    }
  }

  explicit Switch_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_berm_segment(_alloc, _init),
    prev_berm_segment(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->switch_state = false;
      this->first_seg_dump = false;
    }
  }

  // field types and members
  using _switch_state_type =
    bool;
  _switch_state_type switch_state;
  using _current_berm_segment_type =
    lx_msgs::msg::BermSection_<ContainerAllocator>;
  _current_berm_segment_type current_berm_segment;
  using _prev_berm_segment_type =
    lx_msgs::msg::BermSection_<ContainerAllocator>;
  _prev_berm_segment_type prev_berm_segment;
  using _first_seg_dump_type =
    bool;
  _first_seg_dump_type first_seg_dump;

  // setters for named parameter idiom
  Type & set__switch_state(
    const bool & _arg)
  {
    this->switch_state = _arg;
    return *this;
  }
  Type & set__current_berm_segment(
    const lx_msgs::msg::BermSection_<ContainerAllocator> & _arg)
  {
    this->current_berm_segment = _arg;
    return *this;
  }
  Type & set__prev_berm_segment(
    const lx_msgs::msg::BermSection_<ContainerAllocator> & _arg)
  {
    this->prev_berm_segment = _arg;
    return *this;
  }
  Type & set__first_seg_dump(
    const bool & _arg)
  {
    this->first_seg_dump = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::Switch_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::Switch_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Switch_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Switch_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__Switch_Request
    std::shared_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__Switch_Request
    std::shared_ptr<lx_msgs::srv::Switch_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Switch_Request_ & other) const
  {
    if (this->switch_state != other.switch_state) {
      return false;
    }
    if (this->current_berm_segment != other.current_berm_segment) {
      return false;
    }
    if (this->prev_berm_segment != other.prev_berm_segment) {
      return false;
    }
    if (this->first_seg_dump != other.first_seg_dump) {
      return false;
    }
    return true;
  }
  bool operator!=(const Switch_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Switch_Request_

// alias to use template instance with default allocator
using Switch_Request =
  lx_msgs::srv::Switch_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs


#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__Switch_Response __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__Switch_Response __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Switch_Response_
{
  using Type = Switch_Response_<ContainerAllocator>;

  explicit Switch_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Switch_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    lx_msgs::srv::Switch_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::Switch_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Switch_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::Switch_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__Switch_Response
    std::shared_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__Switch_Response
    std::shared_ptr<lx_msgs::srv::Switch_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Switch_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Switch_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Switch_Response_

// alias to use template instance with default allocator
using Switch_Response =
  lx_msgs::srv::Switch_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs

namespace lx_msgs
{

namespace srv
{

struct Switch
{
  using Request = lx_msgs::srv::Switch_Request;
  using Response = lx_msgs::srv::Switch_Response;
};

}  // namespace srv

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__SWITCH__STRUCT_HPP_
