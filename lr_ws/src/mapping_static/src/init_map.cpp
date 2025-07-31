/**
 * @file init_map.cpp
 * @brief Utility for loading a previously saved pointcloud map (PCD) and converting it to ROS 2 PointCloud2 format.
 *
 * This utility provides a single function `getMapFromPCD()` that loads a `.pcd` file from disk, converts it into a
 * ROS 2 `sensor_msgs::msg::PointCloud2` message, and returns a shared pointer to it. This function is typically used
 * by mapping nodes to preload previously saved global elevation maps into memory for fusion or reuse.
 *
 * The file is expected at:
 * \code
 * ${MAPPING_SOURCE_DIR}/saved_maps/map.pcd
 * \endcode
 *
 * @version 1.0.0
 * @date 2025-07-27
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Function:
 * - `getMapFromPCD()`: Loads a pointcloud from a `.pcd` file and returns a ROS 2 message if successful.
 *
 * Returns:
 * - `sensor_msgs::msg::PointCloud2::SharedPtr` if the file exists and loads successfully.
 * - `nullptr` if the file is missing or PCL fails to parse the contents.
 *
 * Dependencies:
 * - `pcl::io::loadPCDFile`: Loads the point cloud from disk.
 * - `pcl::toROSMsg`: Converts PCL point cloud to ROS 2 message format.
 * - `std::filesystem`: Checks file existence.
 * - `rclcpp::get_logger`: Used for error reporting.
 *
 * Assumptions:
 * - The pointcloud is aligned with the `map` frame.
 * - File is located using `MAPPING_SOURCE_DIR`.
 *
 * @credit Based on standard PCL-to-ROS pipelines adapted for persistent map reuse.
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