// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cg_msgs:msg/SiteMap.idl
// generated code does not contain a copyright notice

#ifndef CG_MSGS__MSG__DETAIL__SITE_MAP__BUILDER_HPP_
#define CG_MSGS__MSG__DETAIL__SITE_MAP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cg_msgs/msg/detail/site_map__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cg_msgs
{

namespace msg
{

namespace builder
{

class Init_SiteMap_height_map
{
public:
  Init_SiteMap_height_map()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cg_msgs::msg::SiteMap height_map(::cg_msgs::msg::SiteMap::_height_map_type arg)
  {
    msg_.height_map = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cg_msgs::msg::SiteMap msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cg_msgs::msg::SiteMap>()
{
  return cg_msgs::msg::builder::Init_SiteMap_height_map();
}

}  // namespace cg_msgs

#endif  // CG_MSGS__MSG__DETAIL__SITE_MAP__BUILDER_HPP_
