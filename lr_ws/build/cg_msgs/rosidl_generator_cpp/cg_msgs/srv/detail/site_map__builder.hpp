// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:srv/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__SITE_MAP__BUILDER_HPP_
#define CG_MSGS__SRV__DETAIL__SITE_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/srv/detail/site_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::SiteMap_Request>()
{
  return ::cg_msgs::srv::SiteMap_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace cg_msgs


namespace cg_msgs
{

namespace srv
{

namespace builder
{

class Init_SiteMap_Response_success
{
public:
  explicit Init_SiteMap_Response_success(::cg_msgs::srv::SiteMap_Response & msg)
  : msg_(msg)
  {}
  ::cg_msgs::srv::SiteMap_Response success(::cg_msgs::srv::SiteMap_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::srv::SiteMap_Response msg_;
};

class Init_SiteMap_Response_map_fully_explored
{
public:
  explicit Init_SiteMap_Response_map_fully_explored(::cg_msgs::srv::SiteMap_Response & msg)
  : msg_(msg)
  {}
  Init_SiteMap_Response_success map_fully_explored(::cg_msgs::srv::SiteMap_Response::_map_fully_explored_type arg)
  {
    msg_.map_fully_explored = std::move(arg);
    return Init_SiteMap_Response_success(msg_);
  }

private:
  ::cg_msgs::srv::SiteMap_Response msg_;
};

class Init_SiteMap_Response_site_map
{
public:
  Init_SiteMap_Response_site_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SiteMap_Response_map_fully_explored site_map(::cg_msgs::srv::SiteMap_Response::_site_map_type arg)
  {
    msg_.site_map = std::move(arg);
    return Init_SiteMap_Response_map_fully_explored(msg_);
  }

private:
  ::cg_msgs::srv::SiteMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::SiteMap_Response>()
{
  return cg_msgs::srv::builder::Init_SiteMap_Response_site_map();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__SRV__DETAIL__SITE_MAP__BUILDER_HPP_
