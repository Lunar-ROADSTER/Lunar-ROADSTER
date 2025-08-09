/**
 * @file init_map.cpp
 * @brief Loads a saved PCD map file and returns it as a ROS 2 PointCloud2 message.
 *
 * This utility function reads a `.pcd` file containing a point cloud from a predefined path within
 * the package source directory. If the file exists and is successfully loaded, it is converted to
 * a ROS 2 `sensor_msgs::msg::PointCloud2` message with the `map` frame ID and returned as a shared pointer.
 *
 * @version 1.0.0
 * @date 2025-08-09
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - None
 *
 * Publishers:
 * - None
 *
 * Services:
 * - None
 *
 * Parameters:
 * - MAPPING_SOURCE_DIR: [string] Base directory for locating the saved PCD map.
 *
 * Notes:
 * - Expected file path: `<MAPPING_SOURCE_DIR>/saved_maps/map.pcd`.
 * - Returns `nullptr` if the file does not exist or fails to load.
 * - Loads the PCD file using PCL and converts it to a `PointCloud2` message.
 * - Sets `header.frame_id` to `"map"`.
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