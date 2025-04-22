#include "visualization/visualization.hpp"

ElevationGridMapNode::ElevationGridMapNode() : Node("visualization_node")
{   

    occupancy_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
        "/mapping/filtered_global_map", 10,
        std::bind(&ElevationGridMapNode::occupancyCallback, this, std::placeholders::_1));

    grid_map_pub_ = this->create_publisher<grid_map_msgs::msg::GridMap>("/grid_map", 100);
    
    RCLCPP_INFO(this->get_logger(), "Visualization wrapper initialized");
}


void ElevationGridMapNode::occupancyCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{
  const int width = msg->info.width;
  const int height = msg->info.height;
  const double resolution = msg->info.resolution;

  grid_map::GridMap map({"elevation"});
  map.setFrameId(msg->header.frame_id);
  map.setGeometry(grid_map::Length(width * resolution, height * resolution),
                  resolution,
                  grid_map::Position(msg->info.origin.position.x + width * resolution / 2.0,
                                     msg->info.origin.position.y + height * resolution / 2.0));

  map["elevation"].setConstant(0.0);

  for (int y = 0; y < height; ++y)
  {
    for (int x = 0; x < width; ++x)
    {
      int idx = x + y * width;
      int flipped_x = width - 1 - x;
      int flipped_y = height - 1 - y;
  
      int8_t val = msg->data[idx];
  
      if (val >= 0)
      {
        float elevation_m = static_cast<float>(val) / 100.0;
        map.at("elevation", grid_map::Index(flipped_x, flipped_y)) = elevation_m;
      }
    }
  }

  auto message_ptr = grid_map::GridMapRosConverter::toMessage(map);
  grid_map_pub_->publish(*message_ptr);
}