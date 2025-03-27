#ifndef INIT_MAP_H
#define INIT_MAP_H

#include <sensor_msgs/msg/point_cloud2.hpp>
#include <memory>

namespace lr {
namespace mapping {

const sensor_msgs::msg::PointCloud2::SharedPtr getMapFromPCD();

} // mapping namespace
} // lr namespace

#endif 