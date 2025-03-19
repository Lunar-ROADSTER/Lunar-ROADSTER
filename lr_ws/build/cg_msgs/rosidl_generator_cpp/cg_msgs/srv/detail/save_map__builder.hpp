// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:srv/SaveMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__SRV__DETAIL__SAVE_MAP__BUILDER_HPP_
#define CG_MSGS__SRV__DETAIL__SAVE_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/srv/detail/save_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace srv
{

namespace builder
{

class Init_SaveMap_Request_filepath
{
public:
  Init_SaveMap_Request_filepath()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::srv::SaveMap_Request filepath(::cg_msgs::srv::SaveMap_Request::_filepath_type arg)
  {
    msg_.filepath = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::srv::SaveMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::SaveMap_Request>()
{
  return cg_msgs::srv::builder::Init_SaveMap_Request_filepath();
}

}  // namespace cg_msgs


namespace cg_msgs
{

namespace srv
{

namespace builder
{

class Init_SaveMap_Response_map_saved
{
public:
  Init_SaveMap_Response_map_saved()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::srv::SaveMap_Response map_saved(::cg_msgs::srv::SaveMap_Response::_map_saved_type arg)
  {
    msg_.map_saved = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::srv::SaveMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::srv::SaveMap_Response>()
{
  return cg_msgs::srv::builder::Init_SaveMap_Response_map_saved();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__SRV__DETAIL__SAVE_MAP__BUILDER_HPP_
