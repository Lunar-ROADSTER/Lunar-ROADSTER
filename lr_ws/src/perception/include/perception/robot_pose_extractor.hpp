#ifndef PERCEPTION__POSE_EXTRACTOR_HPP
#define PERCEPTION__POSE_EXTRACTOR_HPP

#include <planning/common.hpp>
#include <planning/goal_planner.hpp>
#include <mapping/map.hpp>
#include <vector>
#include <string>

// ROS 2 + TF includes
#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/msg/pose_stamped.hpp>

// Project headers
#include <planning/common.hpp>
#include <planning/goal_planner.hpp>
#include <mapping/map.hpp>

// Messages
#include <lr_msgs/msg/pose2_d.hpp>

namespace lr
{
namespace perception
{

class PoseExtractor : public GoalPlanner{

    public: 
        PoseExtractor(){};

        void makeGoalsfromCraterGeometry(
            std::vector<lr_msgs::msg::Pose2D> &goalPoses, 
            std::vector<std::string> &goalPose_types, 
            std::vector<float> &craterCentroid, float &craterDiameter);

        geometry_msgs::msg::PoseStamped getRoverPose(
            const std::string &target_frame = "map",
            const std::string &rover_frame = "base_link");

    private:
        
        float manipulation_offset_ = 0.1; //metres
        float last_pose_offset_ = 0.5; //metres
        float backblading_multipler_ = 1.5; //multiplier for manipulation distance during backblading
        float boundary_min_ = 0.4;
        float boundary_max_ = 4.6;
        float boundary_increment_ = 0.01;
        // TF2 members for querying transforms
        tf2_ros::Buffer tf_buffer_;
        tf2_ros::TransformListener tf_listener_;

        // We hold a weak reference to the node clock (to construct buffer correctly)
        rclcpp::Clock::SharedPtr clock_;
};

}
}