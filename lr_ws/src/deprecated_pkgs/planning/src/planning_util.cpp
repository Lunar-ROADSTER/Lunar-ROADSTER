/**
 * @file planning_util.cpp
 * @brief Offers utility functions for map generation, loading (including PointCloud2 from PCD files), and saving in planning operations.
 *
 * This module provides tools for creating zero height and elevation maps from PCD files, loading maps as PointCloud2 messages, and saving them 
 * as CSV files in the /saved_maps directory (e.g., zeros_height_map.csv, elevation_map_1d.csv, elevation_map_2d.csv). 
 * It handles geometric data processing, including map initialization and file I/O for planning tasks.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Methods:
 * - generateZeroMapCsv(): Creates a zero height map CSV in /saved_maps/zeros_height_map.csv.
 * - generateElevationMapCsv(): Generates and saves elevation maps from PCD files to /saved_maps/elevation_map_1d.csv and /saved_maps/elevation_map_2d.csv.
 * - getMapFromPCD(): Loads a map from a PCD file in /saved_maps/map.pcd and converts it to a sensor_msgs::msg::PointCloud2 message.
 * - saveElevationMapToCsv1D(): Saves a 1D elevation map to a CSV file.
 * - saveElevationMapToCsv2D(): Saves a 2D elevation map to a CSV file.
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * @credit John Harrington, Team CraterGrader. Implemented from ROS2 file handling and planning utilities from the project's codebase.
 */
 
#include "planning/planning_util.hpp"

namespace lr {
namespace planning {

void generateZeroMapCsv(size_t height, size_t width, float resolution) {

  // Target directory and fixed filename
  std::string full_filepath = std::string(PLANNING_SOURCE_DIR) + "/saved_maps" + "/zeros_height_map.csv";

  // Create and open the file
  std::ofstream file(full_filepath);
  if (!file.is_open()) {
    RCLCPP_ERROR(rclcpp::get_logger("generateZeroMapCsv"), "Failed to create file: %s", full_filepath.c_str());
    return;
  }

  file << height << "\n";
  file << width << "\n";
  file << resolution << "\n";

  for (size_t i = 0; i < width * height; ++i) {
    file << "0\n";
  }

  file.close();
  RCLCPP_INFO(rclcpp::get_logger("generateZeroMapCsv"), "Height map saved to file: %s", full_filepath.c_str());
}


void generateElevationMapCsv(size_t height, size_t width, float resolution) {

  RCLCPP_INFO(rclcpp::get_logger("generateElevationMapCsv"), "Loading map...");
  auto map_msg = getMapFromPCD();
  if (!map_msg) {
    RCLCPP_ERROR(rclcpp::get_logger("generateElevationMapCsv"), "Map preload failed");
    return;
  }

  RCLCPP_INFO(rclcpp::get_logger("generateElevationMapCsv"), "Map preload successful");

  pcl::PointCloud<pcl::PointXYZ>::Ptr map(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromROSMsg(*map_msg, *map);

  std::vector<double> elevation_values(width*height, 0.0);
  std::vector<double> density_values(width*height, 0.0);
  std::vector<double> global_map(width*height, 0.0);

  for(size_t i = 0; i < map->points.size(); i++){
      int col_x =  int(map->points[i].x / resolution);
      int row_y =  int(map->points[i].y / resolution);

      col_x = std::min(std::max(col_x, 0), int(width-1));
      row_y = std::min(std::max(row_y, 0), int(height-1));

      int global_idx = col_x + row_y*width;
      double elev = map->points[i].z;
      elevation_values[global_idx] += elev;
      density_values[global_idx] += 1.0;
  }

  for(size_t i = 0; i < width*height; i++){
    if(density_values[i] > 1.0){
      global_map[i] = elevation_values[i]/density_values[i];
    }
  }

  // Save to CSV file
  std::string full_filepath_1d = std::string(PLANNING_SOURCE_DIR) + "/saved_maps" + "/elevation_map_1d.csv";
  saveElevationMapToCsv1D(global_map, width, height, resolution, full_filepath_1d);

  std::string full_filepath_2d = std::string(PLANNING_SOURCE_DIR) + "/saved_maps" + "/elevation_map_2d.csv";
  saveElevationMapToCsv2D(global_map, width, height, resolution, full_filepath_2d);
}

const sensor_msgs::msg::PointCloud2::SharedPtr getMapFromPCD() {
  std::string filename = std::string(PLANNING_SOURCE_DIR) + "/saved_maps/map.pcd";

  // Check if file exists
  if (!std::filesystem::exists(filename)) {
      RCLCPP_ERROR(rclcpp::get_logger("getMapFromPCD"), "PCD file not found: %s", filename.c_str());
      return nullptr;
  }

  // Load PCD using PCL
  pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_cloud(new pcl::PointCloud<pcl::PointXYZ>);
  if (pcl::io::loadPCDFile<pcl::PointXYZ>(filename, *pcl_cloud) == -1) {
      RCLCPP_ERROR(rclcpp::get_logger("getMapFromPCD"), "Failed to load PCD file: %s", filename.c_str());
      return nullptr;
  }

  // Convert to ROS2 PointCloud2
  sensor_msgs::msg::PointCloud2::SharedPtr cloud_msg = std::make_shared<sensor_msgs::msg::PointCloud2>();
  pcl::toROSMsg(*pcl_cloud, *cloud_msg);
  cloud_msg->header.frame_id = "map";
  return cloud_msg;
}

void saveElevationMapToCsv1D(const std::vector<double>& global_map, size_t width, size_t height, float resolution, const std::string& full_filepath) {

  std::ofstream file(full_filepath);

  if (!file.is_open()) {
    RCLCPP_ERROR(rclcpp::get_logger("saveElevationMapToCsv1D"), "Failed to create file: %s", full_filepath.c_str());
    return;
  }

  // Write metadata as column
  file << height << "\n";
  file << width << "\n";
  file << resolution << "\n";

  // Write map data
  for (size_t i = 0; i < width * height; ++i) {
    file << global_map[i] << "\n";
  }

  file.close();
  RCLCPP_INFO(rclcpp::get_logger("saveElevationMapToCsv1D"), "Height map saved to file: %s", full_filepath.c_str());
}

void saveElevationMapToCsv2D(const std::vector<double>& global_map, size_t width, size_t height, float resolution, const std::string& full_filepath) {

  std::ofstream file(full_filepath);

  if (!file.is_open()) {
    RCLCPP_ERROR(rclcpp::get_logger("saveElevationMapToCsv2D"), "Failed to create file: %s", full_filepath.c_str());
    return;
  }

  // Write metadata as column
  file << height << "\n";
  file << width << "\n";
  file << resolution << "\n";

  // Write map data
  for (size_t i = 0; i < height; ++i) {
    for (size_t j = 0; j < width; ++j) {
      size_t idx = i * width + j;
      file << global_map[idx];
      if (j < width - 1) file << ",";
    }
    file << "\n";
  }

  file.close();
  RCLCPP_INFO(rclcpp::get_logger("saveElevationMapToCsv2D"), "2D height map saved to file: %s", full_filepath.c_str());
}

} // planning namespace
} // lr namespace
