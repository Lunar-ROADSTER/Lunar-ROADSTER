// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:srv/PclGroundHeight.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__BUILDER_HPP_
#define LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/srv/detail/pcl_ground_height__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_PclGroundHeight_Request_need_height
{
public:
  Init_PclGroundHeight_Request_need_height()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::PclGroundHeight_Request need_height(::lx_msgs::srv::PclGroundHeight_Request::_need_height_type arg)
  {
    msg_.need_height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::PclGroundHeight_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::PclGroundHeight_Request>()
{
  return lx_msgs::srv::builder::Init_PclGroundHeight_Request_need_height();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_PclGroundHeight_Response_success
{
public:
  Init_PclGroundHeight_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::PclGroundHeight_Response success(::lx_msgs::srv::PclGroundHeight_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::PclGroundHeight_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::PclGroundHeight_Response>()
{
  return lx_msgs::srv::builder::Init_PclGroundHeight_Response_success();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__PCL_GROUND_HEIGHT__BUILDER_HPP_
