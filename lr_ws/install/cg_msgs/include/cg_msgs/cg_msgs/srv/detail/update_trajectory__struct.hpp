// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cg_msgs:srv/UpdateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__STRUCT_HPP_
#define CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'trajectory'
#include "cg_msgs/msg/detail/trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cg_msgs__srv__UpdateTrajectory_Request __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__srv__UpdateTrajectory_Request __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UpdateTrajectory_Request_
{
  using Type = UpdateTrajectory_Request_<ContainerAllocator>;

  explicit UpdateTrajectory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_init)
  {
    (void)_init;
  }

  explicit UpdateTrajectory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : trajectory(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _trajectory_type =
    cg_msgs::msg::Trajectory_<ContainerAllocator>;
  _trajectory_type trajectory;

  // setters for named parameter idiom
  Type & set__trajectory(
    const cg_msgs::msg::Trajectory_<ContainerAllocator> & _arg)
  {
    this->trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__srv__UpdateTrajectory_Request
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__srv__UpdateTrajectory_Request
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpdateTrajectory_Request_ & other) const
  {
    if (this->trajectory != other.trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpdateTrajectory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpdateTrajectory_Request_

// alias to use template instance with default allocator
using UpdateTrajectory_Request =
  cg_msgs::srv::UpdateTrajectory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cg_msgs


#ifndef _WIN32
# define DEPRECATED__cg_msgs__srv__UpdateTrajectory_Response __attribute__((deprecated))
#else
# define DEPRECATED__cg_msgs__srv__UpdateTrajectory_Response __declspec(deprecated)
#endif

namespace cg_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct UpdateTrajectory_Response_
{
  using Type = UpdateTrajectory_Response_<ContainerAllocator>;

  explicit UpdateTrajectory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->updated_trajectory = false;
    }
  }

  explicit UpdateTrajectory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->updated_trajectory = false;
    }
  }

  // field types and members
  using _updated_trajectory_type =
    bool;
  _updated_trajectory_type updated_trajectory;

  // setters for named parameter idiom
  Type & set__updated_trajectory(
    const bool & _arg)
  {
    this->updated_trajectory = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cg_msgs__srv__UpdateTrajectory_Response
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cg_msgs__srv__UpdateTrajectory_Response
    std::shared_ptr<cg_msgs::srv::UpdateTrajectory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpdateTrajectory_Response_ & other) const
  {
    if (this->updated_trajectory != other.updated_trajectory) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpdateTrajectory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpdateTrajectory_Response_

// alias to use template instance with default allocator
using UpdateTrajectory_Response =
  cg_msgs::srv::UpdateTrajectory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace cg_msgs

namespace cg_msgs
{

namespace srv
{

struct UpdateTrajectory
{
  using Request = cg_msgs::srv::UpdateTrajectory_Request;
  using Response = cg_msgs::srv::UpdateTrajectory_Response;
};

}  // namespace srv

}  // namespace cg_msgs

#endif  // CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__STRUCT_HPP_
