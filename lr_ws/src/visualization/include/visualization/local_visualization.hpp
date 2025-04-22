#ifndef LOCAL_ELEVATION_GRID_MAP_H
#define LOCAL_ELEVATION_GRID_MAP_H

#include <rclcpp/rclcpp.hpp>
#include <nav_msgs/msg/occupancy_grid.hpp>
#include <grid_map_ros/grid_map_ros.hpp>
#include <grid_map_msgs/msg/grid_map.hpp>
#include <grid_map_ros/GridMapRosConverter.hpp>
#include <std_msgs/msg/bool.hpp> 
#include <atomic>

class ElevationGridMapNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr occupancy_sub_;
        rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr publish_local_map_sub_;

        // Publishers
        rclcpp::Publisher<grid_map_msgs::msg::GridMap>::SharedPtr grid_map_pub_;

        // Functions
        void occupancyCallback(const nav_msgs::msg::OccupancyGrid::SharedPtr msg);
        void publishLocalMapCallback(const std_msgs::msg::Bool::SharedPtr msg);

        // Variables
        std::atomic<bool> publish_callback_;

    public:
        // Constructor and destructor
        ElevationGridMapNode();
        ~ElevationGridMapNode(){};
};  

#endif