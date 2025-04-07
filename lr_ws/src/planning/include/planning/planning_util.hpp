#ifndef PLANNING__PLANNING_UTIL_HPP
#define PLANNING__PLANNING_UTIL_HPP

#include <cmath> // sqrt, fmod
#include <Eigen/Dense> // matrix multiplication
#include <Eigen/Geometry> // homogenous transforms
#include <cg_msgs/msg/point2_d.hpp>
#include <cg_msgs/msg/pose2_d.hpp>
#include <cg_msgs/msg/trajectory.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <limits>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/utils.h>
#include <fstream>
#include <filesystem>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include <iostream>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <memory>
#include <pcl/io/pcd_io.h>
#include <pcl_conversions/pcl_conversions.h>
#include "nav_msgs/msg/occupancy_grid.hpp"

namespace cg {
namespace planning {

// Functions
cg_msgs::msg::Point2D create_point2d(const double& x, const double& y);
cg_msgs::msg::Pose2D create_pose2d(const double& x, const double& y, const double &yaw);

void generateZeroMapCsv(size_t height, size_t width, float resolution);
void generateElevationMapCsv(size_t height, size_t width, float resolution);
const sensor_msgs::msg::PointCloud2::SharedPtr getMapFromPCD();
void saveElevationMapToCsv1D(const std::vector<double>& global_map, size_t width, size_t height, float resolution, const std::string& full_filepath);
void saveElevationMapToCsv2D(const std::vector<double>& global_map, size_t width, size_t height, float resolution, const std::string& full_filepath);

} // planning namespace
} // cg namespace

#endif // PLANNING__COMMON_HPP
