// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:srv/RequestRoverService.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__BUILDER_HPP_
#define LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/srv/detail/request_rover_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_RequestRoverService_Request_excavation_zone_coordinates
{
public:
  explicit Init_RequestRoverService_Request_excavation_zone_coordinates(::lx_msgs::srv::RequestRoverService_Request & msg)
  : msg_(msg)
  {}
  ::lx_msgs::srv::RequestRoverService_Request excavation_zone_coordinates(::lx_msgs::srv::RequestRoverService_Request::_excavation_zone_coordinates_type arg)
  {
    msg_.excavation_zone_coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::RequestRoverService_Request msg_;
};

class Init_RequestRoverService_Request_restricted_zone_coordinates
{
public:
  explicit Init_RequestRoverService_Request_restricted_zone_coordinates(::lx_msgs::srv::RequestRoverService_Request & msg)
  : msg_(msg)
  {}
  Init_RequestRoverService_Request_excavation_zone_coordinates restricted_zone_coordinates(::lx_msgs::srv::RequestRoverService_Request::_restricted_zone_coordinates_type arg)
  {
    msg_.restricted_zone_coordinates = std::move(arg);
    return Init_RequestRoverService_Request_excavation_zone_coordinates(msg_);
  }

private:
  ::lx_msgs::srv::RequestRoverService_Request msg_;
};

class Init_RequestRoverService_Request_berm
{
public:
  Init_RequestRoverService_Request_berm()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RequestRoverService_Request_restricted_zone_coordinates berm(::lx_msgs::srv::RequestRoverService_Request::_berm_type arg)
  {
    msg_.berm = std::move(arg);
    return Init_RequestRoverService_Request_restricted_zone_coordinates(msg_);
  }

private:
  ::lx_msgs::srv::RequestRoverService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::RequestRoverService_Request>()
{
  return lx_msgs::srv::builder::Init_RequestRoverService_Request_berm();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_RequestRoverService_Response_success
{
public:
  Init_RequestRoverService_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::RequestRoverService_Response success(::lx_msgs::srv::RequestRoverService_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::RequestRoverService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::RequestRoverService_Response>()
{
  return lx_msgs::srv::builder::Init_RequestRoverService_Response_success();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__REQUEST_ROVER_SERVICE__BUILDER_HPP_
