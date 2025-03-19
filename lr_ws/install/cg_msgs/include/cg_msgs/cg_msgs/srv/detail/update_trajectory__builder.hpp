// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:srv/UpdateTrajectory.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__BUILDER_HPP_
#define CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/srv/detail/update_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace srv
{

namespace builder
{

class Init_UpdateTrajectory_Request_trajectory
{
public:
  Init_UpdateTrajectory_Request_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::srv::UpdateTrajectory_Request trajectory(::cg_msgs::srv::UpdateTrajectory_Request::_trajectory_type arg)
  {
    msg_.trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::srv::UpdateTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::UpdateTrajectory_Request>()
{
  return cg_msgs::srv::builder::Init_UpdateTrajectory_Request_trajectory();
}

}  // namespace cg_msgs


namespace cg_msgs
{

namespace srv
{

namespace builder
{

class Init_UpdateTrajectory_Response_updated_trajectory
{
public:
  Init_UpdateTrajectory_Response_updated_trajectory()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::srv::UpdateTrajectory_Response updated_trajectory(::cg_msgs::srv::UpdateTrajectory_Response::_updated_trajectory_type arg)
  {
    msg_.updated_trajectory = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::srv::UpdateTrajectory_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::UpdateTrajectory_Response>()
{
  return cg_msgs::srv::builder::Init_UpdateTrajectory_Response_updated_trajectory();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__SRV__DETAIL__UPDATE_TRAJECTORY__BUILDER_HPP_
