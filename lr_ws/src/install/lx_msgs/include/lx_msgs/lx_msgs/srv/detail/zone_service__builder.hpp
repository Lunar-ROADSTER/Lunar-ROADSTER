// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from lx_msgs:srv/ZoneService.idl
// generated code does not contain a copyright notice

#ifndef LX_MSGS__SRV__DETAIL__ZONE_SERVICE__BUILDER_HPP_
#define LX_MSGS__SRV__DETAIL__ZONE_SERVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "lx_msgs/srv/detail/zone_service__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_ZoneService_Request_zone_coordinates
{
public:
  explicit Init_ZoneService_Request_zone_coordinates(::lx_msgs::srv::ZoneService_Request & msg)
  : msg_(msg)
  {}
  ::lx_msgs::srv::ZoneService_Request zone_coordinates(::lx_msgs::srv::ZoneService_Request::_zone_coordinates_type arg)
  {
    msg_.zone_coordinates = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::ZoneService_Request msg_;
};

class Init_ZoneService_Request_zone_type
{
public:
  Init_ZoneService_Request_zone_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ZoneService_Request_zone_coordinates zone_type(::lx_msgs::srv::ZoneService_Request::_zone_type_type arg)
  {
    msg_.zone_type = std::move(arg);
    return Init_ZoneService_Request_zone_coordinates(msg_);
  }

private:
  ::lx_msgs::srv::ZoneService_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::ZoneService_Request>()
{
  return lx_msgs::srv::builder::Init_ZoneService_Request_zone_type();
}

}  // namespace lx_msgs


namespace lx_msgs
{

namespace srv
{

namespace builder
{

class Init_ZoneService_Response_success
{
public:
  Init_ZoneService_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::lx_msgs::srv::ZoneService_Response success(::lx_msgs::srv::ZoneService_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::lx_msgs::srv::ZoneService_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::lx_msgs::srv::ZoneService_Response>()
{
  return lx_msgs::srv::builder::Init_ZoneService_Response_success();
}

}  // namespace lx_msgs

#endif  // LX_MSGS__SRV__DETAIL__ZONE_SERVICE__BUILDER_HPP_
