// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from lx_msgs:action/CalibrateImu.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__ACTION__DETAIL__CALIBRATE_IMU__STRUCT_HPP_
#define LX_MSGS__ACTION__DETAIL__CALIBRATE_IMU__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_Goal __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_Goal __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_Goal_
{
  using Type = CalibrateImu_Goal_<ContainerAllocator>;

  explicit CalibrateImu_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dont_move_rover = false;
      this->time = 0ll;
    }
  }

  explicit CalibrateImu_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dont_move_rover = false;
      this->time = 0ll;
    }
  }

  // field types and members
  using _dont_move_rover_type =
    bool;
  _dont_move_rover_type dont_move_rover;
  using _time_type =
    int64_t;
  _time_type time;

  // setters for named parameter idiom
  Type & set__dont_move_rover(
    const bool & _arg)
  {
    this->dont_move_rover = _arg;
    return *this;
  }
  Type & set__time(
    const int64_t & _arg)
  {
    this->time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_Goal
    std::shared_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_Goal
    std::shared_ptr<lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_Goal_ & other) const
  {
    if (this->dont_move_rover != other.dont_move_rover) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_Goal_

// alias to use template instance with default allocator
using CalibrateImu_Goal =
  lx_msgs::action::CalibrateImu_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs


#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_Result __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_Result __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_Result_
{
  using Type = CalibrateImu_Result_<ContainerAllocator>;

  explicit CalibrateImu_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit CalibrateImu_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    lx_msgs::action::CalibrateImu_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_Result
    std::shared_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_Result
    std::shared_ptr<lx_msgs::action::CalibrateImu_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_Result_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_Result_

// alias to use template instance with default allocator
using CalibrateImu_Result =
  lx_msgs::action::CalibrateImu_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs


#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_Feedback __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_Feedback_
{
  using Type = CalibrateImu_Feedback_<ContainerAllocator>;

  explicit CalibrateImu_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit CalibrateImu_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_Feedback
    std::shared_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_Feedback
    std::shared_ptr<lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_Feedback_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_Feedback_

// alias to use template instance with default allocator
using CalibrateImu_Feedback =
  lx_msgs::action::CalibrateImu_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "lx_msgs/action/detail/calibrate_imu__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Request __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_SendGoal_Request_
{
  using Type = CalibrateImu_SendGoal_Request_<ContainerAllocator>;

  explicit CalibrateImu_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit CalibrateImu_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const lx_msgs::action::CalibrateImu_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Request
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Request
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_SendGoal_Request_

// alias to use template instance with default allocator
using CalibrateImu_SendGoal_Request =
  lx_msgs::action::CalibrateImu_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Response __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_SendGoal_Response_
{
  using Type = CalibrateImu_SendGoal_Response_<ContainerAllocator>;

  explicit CalibrateImu_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit CalibrateImu_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Response
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_SendGoal_Response
    std::shared_ptr<lx_msgs::action::CalibrateImu_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_SendGoal_Response_

// alias to use template instance with default allocator
using CalibrateImu_SendGoal_Response =
  lx_msgs::action::CalibrateImu_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs

namespace lx_msgs
{

namespace action
{

struct CalibrateImu_SendGoal
{
  using Request = lx_msgs::action::CalibrateImu_SendGoal_Request;
  using Response = lx_msgs::action::CalibrateImu_SendGoal_Response;
};

}  // namespace action

}  // namespace lx_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Request __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_GetResult_Request_
{
  using Type = CalibrateImu_GetResult_Request_<ContainerAllocator>;

  explicit CalibrateImu_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit CalibrateImu_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Request
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Request
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_GetResult_Request_

// alias to use template instance with default allocator
using CalibrateImu_GetResult_Request =
  lx_msgs::action::CalibrateImu_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "lx_msgs/action/detail/calibrate_imu__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Response __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_GetResult_Response_
{
  using Type = CalibrateImu_GetResult_Response_<ContainerAllocator>;

  explicit CalibrateImu_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit CalibrateImu_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    lx_msgs::action::CalibrateImu_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const lx_msgs::action::CalibrateImu_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Response
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_GetResult_Response
    std::shared_ptr<lx_msgs::action::CalibrateImu_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_GetResult_Response_

// alias to use template instance with default allocator
using CalibrateImu_GetResult_Response =
  lx_msgs::action::CalibrateImu_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs

namespace lx_msgs
{

namespace action
{

struct CalibrateImu_GetResult
{
  using Request = lx_msgs::action::CalibrateImu_GetResult_Request;
  using Response = lx_msgs::action::CalibrateImu_GetResult_Response;
};

}  // namespace action

}  // namespace lx_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "lx_msgs/action/detail/calibrate_imu__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__lx_msgs__action__CalibrateImu_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__lx_msgs__action__CalibrateImu_FeedbackMessage __declspec(deprecated)
#endif

namespace lx_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct CalibrateImu_FeedbackMessage_
{
  using Type = CalibrateImu_FeedbackMessage_<ContainerAllocator>;

  explicit CalibrateImu_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit CalibrateImu_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const lx_msgs::action::CalibrateImu_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_FeedbackMessage
    std::shared_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__lx_msgs__action__CalibrateImu_FeedbackMessage
    std::shared_ptr<lx_msgs::action::CalibrateImu_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CalibrateImu_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const CalibrateImu_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CalibrateImu_FeedbackMessage_

// alias to use template instance with default allocator
using CalibrateImu_FeedbackMessage =
  lx_msgs::action::CalibrateImu_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace lx_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace lx_msgs
{

namespace action
{

struct CalibrateImu
{
  /// The goal message defined in the action definition.
  using Goal = lx_msgs::action::CalibrateImu_Goal;
  /// The result message defined in the action definition.
  using Result = lx_msgs::action::CalibrateImu_Result;
  /// The feedback message defined in the action definition.
  using Feedback = lx_msgs::action::CalibrateImu_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = lx_msgs::action::CalibrateImu_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = lx_msgs::action::CalibrateImu_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = lx_msgs::action::CalibrateImu_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct CalibrateImu CalibrateImu;

}  // namespace action

}  // namespace lx_msgs

#endif  // LX_MSGS__ACTION__DETAIL__CALIBRATE_IMU__STRUCT_HPP_
