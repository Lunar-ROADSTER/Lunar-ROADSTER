#ifndef PERCEPTION__POSE_EXTRACTOR_HPP
#define PERCEPTION__POSE_EXTRACTOR_HPP

#include <perception/common.hpp>
#include <vector>
#include <string>

// ROS 2 + TF includes
#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/msg/pose_stamped.hpp>



// Messages
#include <lr_msgs/msg/pose2_d.hpp>

namespace lr
{
namespace perception
{

class PoseExtractor{

    public: 
        explicit PoseExtractor(const rclcpp::Node::SharedPtr &node);

        void makeGoalsfromCraterGeometry(
            std::vector<lr_msgs::msg::Pose2D> &goalPoses, 
            std::vector<std::string> &goalPose_types, 
            std::vector<double> &craterCentroid, double &craterDiameter);

        geometry_msgs::msg::PoseStamped getRoverPose(
            const std::string &target_frame = "map",
            const std::string &rover_frame = "base_link");

    private:
        
        float manipulation_offset_ = 0.1;
        float last_pose_offset_ = 0.5;
        float backblading_multipler_ = 1.5;
        float boundary_min_ = 0.4;
        float boundary_max_ = 4.6;
        float boundary_increment_ = 0.01;
        float robot_half_length_ = 0.5;
        float source_pose_offset_x_ = 0.0;
        float source_pose_offset_y_ = 0.0;
        float sink_pose_offset_x_ = 0.2;
        float sink_pose_offset_y_ = 0.3;
        float source_backblade_pose_offset_x_ = 0.7;
        float source_backblade_pose_offset_y_ = 0.0;
        float sink_backblade_pose_offset_x_ = 0.0;
        float sink_backblade_pose_offset_y_ = 0.0;

        // TF2 members for querying transforms
        tf2_ros::Buffer tf_buffer_;
        tf2_ros::TransformListener tf_listener_;

        // We hold a weak reference to the node clock (to construct buffer correctly)
        rclcpp::Clock::SharedPtr clock_;
};

}
}

#endif