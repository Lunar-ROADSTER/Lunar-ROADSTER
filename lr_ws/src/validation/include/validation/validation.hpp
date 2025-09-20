#ifndef VALIDATION_H
#define VALIDATION_H

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_msgs/msg/grid_map.hpp>
#include <grid_map_ros/GridMapRosConverter.hpp>
#include <std_msgs/msg/bool.hpp> 
#include <std_msgs/msg/float64_multi_array.hpp>
#include <atomic>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <limits>

namespace lr{
namespace validation{
    
class ValidationNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr occupancy_sub_;
        rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr publish_local_map_sub_;

        // Publishers
        rclcpp::Publisher<grid_map_msgs::msg::GridMap>::SharedPtr grid_map_pub_;
        rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr elevation_data_pub_;

        // Functions
        void occupancyCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);
        void publishLocalMapCallback(const std_msgs::msg::Bool::SharedPtr msg);

        // Variables
        std::atomic<bool> publish_callback_;

    public:
        // Constructor and destructor
        ValidationNode();
        ~ValidationNode(){};
};  

}
}
#endif