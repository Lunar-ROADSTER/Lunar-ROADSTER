#ifndef ELEVATION_GRID_MAP_H
#define ELEVATION_GRID_MAP_H

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_msgs/msg/grid_map.hpp>
#include <grid_map_ros/GridMapRosConverter.hpp>

namespace lr{
namespace viz{
class ElevationGridMapNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr occupancy_sub_;

        // Publishers
        rclcpp::Publisher<grid_map_msgs::msg::GridMap>::SharedPtr grid_map_pub_;

        // Functions
        void occupancyCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);

    public:
        // Constructor and destructor
        ElevationGridMapNode();
        ~ElevationGridMapNode(){};
};  
}
}
#endif