#ifndef PERCEPTION__COMMON_HPP
#define PERCEPTION__COMMON_HPP

#include <rclcpp/rclcpp.hpp>
#include <cmath> // sqrt, fmod
#include <Eigen/Dense> // matrix multiplication
#include <Eigen/Geometry> // homogenous transforms
#include <lr_msgs/msg/point2_d.hpp>
#include <lr_msgs/msg/pose2_d.hpp>
#include <lr_msgs/msg/trajectory.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <limits>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/utils.h>

namespace lr {
namespace perception {

// Functions
lr_msgs::msg::Point2D create_point2d(const double& x, const double& y);
lr_msgs::msg::Pose2D create_pose2d(const double& x, const double& y, const double &yaw);

float euclidean_distance(const lr_msgs::msg::Point2D& pt1, const lr_msgs::msg::Point2D& pt2);

float rad2deg(float rad);
float deg2rad(float deg);

// float angle_difference(const float angle_1, const float angle_2);

lr_msgs::msg::Point2D transformPointGlobalToLocal(
    const lr_msgs::msg::Point2D &global_pt,
    const lr_msgs::msg::Pose2D &local_frame);

lr_msgs::msg::Point2D transformPoint(
  const lr_msgs::msg::Point2D &source_pt, 
  const lr_msgs::msg::Pose2D &pose);

lr_msgs::msg::Pose2D transformPose(
  const lr_msgs::msg::Pose2D &source_pose, 
  const lr_msgs::msg::Pose2D &transforming_pose);

// Find smallest difference between two angles, all units in radians
double smallest_angle_difference_signed(double angle1, double angle2);

// Checks if trajectory_end_pose is within distance threshold of goal_pose
bool samePoseWithinThresh(
    const lr_msgs::msg::Pose2D &pose1, const lr_msgs::msg::Pose2D &pose2,
    const float thresh_pos, const double thresh_head);

// checks what the new closest index should be on a trajectory based on localization
int getClosestTrajIndex(const lr_msgs::msg::Trajectory &target_trajectory, const nav_msgs::msg::Odometry &current_state, int prev_traj_idx);

} // perception namespace
} // lr namespace

#endif // PERCEPTION__COMMON_HPP
