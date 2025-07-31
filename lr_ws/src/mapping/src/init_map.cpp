/**
 * @file init_map.cpp
 * @brief Loads a saved pointcloud map from a PCD file and converts it to a ROS2 PointCloud2 message.
 *
 * This utility provides a helper function to load a previously saved global map in `.pcd` format and
 * convert it into a ROS 2 `sensor_msgs::msg::PointCloud2` message. This is primarily used to preload
 * the global elevation map into the mapping node for continuity and map reuse across sessions.
 *
 * The PCD file is expected to be located at:
 * `${MAPPING_SOURCE_DIR}/saved_maps/map.pcd`
 *
 * @version 1.0.0
 * @date 2025-07-27
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Functions:
 * - `getMapFromPCD()`: Loads a PCD file and returns a ROS2-compatible `PointCloud2` message if successful.
 *
 * Returns:
 * - `sensor_msgs::msg::PointCloud2::SharedPtr` containing the loaded map, or `nullptr` if the file doesn't exist or fails to load.
 *
 * Assumptions:
 * - The file path `${MAPPING_SOURCE_DIR}/saved_maps/map.pcd` exists and is readable.
 * - The loaded point cloud is in the `map` frame.
 *
 * Dependencies:
 * - PCL (`pcl::PointCloud`, `pcl::io::loadPCDFile`)
 * - ROS 2 (`sensor_msgs::msg::PointCloud2`, `rclcpp::get_logger`)
 * - STL (`std::filesystem`, `std::string`)
 *
 * @credit Adapted from standard PCL-ROS pipelines and tailored for ROS 2 map initialization.
 */

#include "mapping/init_map.hpp"

#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <memory>
#include <filesystem>
#include <ament_index_cpp/get_package_share_directory.hpp>

namespace lr
{
    namespace mapping
    {

        const sensor_msgs::msg::PointCloud2::SharedPtr getMapFromPCD()
        {
            std::string filename = std::string(MAPPING_SOURCE_DIR) + "/saved_maps/map.pcd";

            // Check if file exists
            if (!std::filesystem::exists(filename))
            {
                RCLCPP_ERROR(rclcpp::get_logger("getMapFromPCD"), "PCD file not found: %s", filename.c_str());
                return nullptr;
            }

            // Load PCD using PCL
            pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
            if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename, *pcl_cloud) == -1)
            {
                RCLCPP_ERROR(rclcpp::get_logger("getMapFromPCD"), "Failed to load PCD file: %s", filename.c_str());
                return nullptr;
            }

            // Convert to ROS2 PointCloud2
            sensor_msgs::msg::PointCloud2::SharedPtr cloud_msg = std::make_shared<sensor_msgs::msg::PointCloud2>();
            pcl::toROSMsg(*pcl_cloud, *cloud_msg);
            cloud_msg->header.frame_id = "map";
            return cloud_msg;
        }

    } // namespace mapping
} // namespace lr