/**
 * @file local_visualization.cpp
 * @brief Converts occupancy grid data to a grid map for terrain visualization and publishes statistical terrain metrics.
 *
 * This node subscribes to a local occupancy grid and a boolean trigger flag. When triggered, it converts the occupancy data
 * into a GridMap with elevation values, computes the mean elevation, root mean square error (RMSE), and the maximum slope 
 * of the terrain. The elevation values are assumed to be encoded in the occupancy grid as integer centimeters (0–100).
 *
 * Key terrain metrics are published for downstream modules like terrain adaptation, locomotion control, and diagnostic monitoring.
 * The node publishes both a full `grid_map_msgs::msg::GridMap` and a summary `std_msgs::msg::Float64MultiArray` message.
 *  
 * @version 1.0.0
 * @date 2025-07-07
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /mapping/filtered_local_map: [nav_msgs::msg::OccupancyGrid] The filtered local terrain map with elevation encoded in grid cells.
 * - /publish_local_map: [std_msgs::msg::Bool] Boolean flag that controls when the node should process and publish the grid map.
 *
 * Publishers:
 * - /local_grid_map: [grid_map_msgs::msg::GridMap] The constructed grid map with elevation values.
 * - /mean_rmse_slope: [std_msgs::msg::Float64MultiArray] Contains [mean_elevation_cm, rmse_cm, max_slope_deg].
 *
 * Services:
 * - None
 */

#include "visualization/local_visualization.hpp"

namespace lr{
namespace localviz{
ElevationGridMapNode::ElevationGridMapNode() : Node("local_visualization_node")
{   

    occupancy_sub_ = this->create_subscription<nav_msgs::msg::OccupancyGrid>(
        "/mapping/filtered_local_map", 10,
        std::bind(&ElevationGridMapNode::occupancyCallback, this, std::placeholders::_1));

    publish_local_map_sub_ = this->create_subscription<std_msgs::msg::Bool>(
        "/publish_local_map", 10,
        std::bind(&ElevationGridMapNode::publishLocalMapCallback, this, std::placeholders::_1));

    grid_map_pub_ = this->create_publisher<grid_map_msgs::msg::GridMap>("/local_grid_map", 100);

    elevation_data_pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/mean_rmse_slope", 10);

    RCLCPP_INFO(this->get_logger(), "Local visualization wrapper initialized");
}


void ElevationGridMapNode::occupancyCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg)
{

  bool publish_grid_map = publish_callback_.exchange(false);
  if (!publish_grid_map) {
    return;
  }
  
  // Convert map from OccupancyGrid format to GridMap format
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

  // Calculate maximum gradient in local map
  double max_gradient = 0.0;
  for (int y = 1; y < height - 1; ++y)
  {
    for (int x = 1; x < width - 1; ++x)
    {
      grid_map::Index idx(x, y);
  
      // Get neighbors for central difference
      // float z_center = map.at("elevation", idx);
      float z_left   = map.at("elevation", grid_map::Index(x - 1, y));
      float z_right  = map.at("elevation", grid_map::Index(x + 1, y));
      float z_down   = map.at("elevation", grid_map::Index(x, y - 1));
      float z_up     = map.at("elevation", grid_map::Index(x, y + 1));
  
      // Central differences
      float dz_dx = (z_right - z_left) / (2.0 * resolution);
      float dz_dy = (z_up - z_down) / (2.0 * resolution);
  
      float gradient = std::sqrt(dz_dx * dz_dx + dz_dy * dz_dy);
  
      if (gradient > max_gradient)
        max_gradient = gradient;
    }
  }

  // Convert max gradient to degrees
  double slope_deg = std::atan(max_gradient) * 180.0 / M_PI;

  // Calculate mean elevation
  double elevation_sum = 0.0;
  int valid_cell_count = 0;

  for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it)
  {
    float elevation = map.at("elevation", *it);
    if (!std::isnan(elevation))
    {
      elevation_sum += elevation;
      valid_cell_count++;
    }
  }

  double mean_elevation = 0.0;
  if (valid_cell_count > 0)
    mean_elevation = elevation_sum / valid_cell_count;

  // Calculate RMSE from mean
  double sum_squared_error = 0.0;

  for (grid_map::GridMapIterator it(map); !it.isPastEnd(); ++it)
  {
    float elevation = map.at("elevation", *it);
    if (!std::isnan(elevation))
    {
      double error = elevation - mean_elevation;
      sum_squared_error += error * error;
    }
  }

  double rmse = 0.0;
  if (valid_cell_count > 0)
    rmse = std::sqrt(sum_squared_error / valid_cell_count);

  // Change to cm
  mean_elevation = mean_elevation * 100.0;
  rmse = rmse * 100.0;

  RCLCPP_INFO(this->get_logger(), "Mean elevation: %.2f cm", mean_elevation);
  RCLCPP_INFO(this->get_logger(), "Elevation RMSE: %.2f cm", rmse);
  RCLCPP_INFO(this->get_logger(), "Maximum slope angle: %.2f degrees", slope_deg);

  std_msgs::msg::Float64MultiArray elevation_msg;
  elevation_msg.data = {mean_elevation, rmse, slope_deg};
  elevation_data_pub_->publish(elevation_msg);
}

void ElevationGridMapNode::publishLocalMapCallback(const std_msgs::msg::Bool::SharedPtr msg) {

  publish_callback_ = msg->data;
}
}
}