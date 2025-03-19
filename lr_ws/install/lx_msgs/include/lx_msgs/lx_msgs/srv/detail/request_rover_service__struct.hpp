// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:srv/RequestRoverService.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__STRUCT_HPP_
#define LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'berm'
#include "lx_msgs/msg/detail/berm_config__struct.hpp"
// Member 'restricted_zone_coordinates'
// Member 'excavation_zone_coordinates'
#include "geometry_msgs/msg/detail/point_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__RequestRoverService_Request __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__RequestRoverService_Request __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestRoverService_Request_
{
  using Type = RequestRoverService_Request_<ContainerAllocator>;

  explicit RequestRoverService_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : berm(_init)
  {
    (void)_init;
  }

  explicit RequestRoverService_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : berm(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _berm_type =
    lx_msgs::msg::BermConfig_<ContainerAllocator>;
  _berm_type berm;
  using _restricted_zone_coordinates_type =
    std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>>;
  _restricted_zone_coordinates_type restricted_zone_coordinates;
  using _excavation_zone_coordinates_type =
    std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>>;
  _excavation_zone_coordinates_type excavation_zone_coordinates;

  // setters for named parameter idiom
  Type & set__berm(
    const lx_msgs::msg::BermConfig_<ContainerAllocator> & _arg)
  {
    this->berm = _arg;
    return *this;
  }
  Type & set__restricted_zone_coordinates(
    const std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>> & _arg)
  {
    this->restricted_zone_coordinates = _arg;
    return *this;
  }
  Type & set__excavation_zone_coordinates(
    const std::vector<geometry_msgs::msg::PointStamped_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::PointStamped_<ContainerAllocator>>> & _arg)
  {
    this->excavation_zone_coordinates = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__RequestRoverService_Request
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__RequestRoverService_Request
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestRoverService_Request_ & other) const
  {
    if (this->berm != other.berm) {
      return false;
    }
    if (this->restricted_zone_coordinates != other.restricted_zone_coordinates) {
      return false;
    }
    if (this->excavation_zone_coordinates != other.excavation_zone_coordinates) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestRoverService_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestRoverService_Request_

// alias to use template instance with default allocator
using RequestRoverService_Request =
  lx_msgs::srv::RequestRoverService_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs


#ifndef _WIN32
# define DEPRECATED__lx_msgs__srv__RequestRoverService_Response __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__srv__RequestRoverService_Response __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestRoverService_Response_
{
  using Type = RequestRoverService_Response_<ContainerAllocator>;

  explicit RequestRoverService_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit RequestRoverService_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__srv__RequestRoverService_Response
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__srv__RequestRoverService_Response
    std::shared_ptr<lx_msgs::srv::RequestRoverService_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestRoverService_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestRoverService_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestRoverService_Response_

// alias to use template instance with default allocator
using RequestRoverService_Response =
  lx_msgs::srv::RequestRoverService_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace lx_msgs

namespace lx_msgs
{

namespace srv
{

struct RequestRoverService
{
  using Request = lx_msgs::srv::RequestRoverService_Request;
  using Response = lx_msgs::srv::RequestRoverService_Response;
};

}  // namespace srv

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__STRUCT_HPP_
