#ifndef PRISM_TRANSFORMER_NODE_HPP
#define PRISM_TRANSFORMER_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <geometry_msgs/msg/transform_stamped.h>
#include <sensor_msgs/msg/imu.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/convert.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/buffer.h>
#include "lr_msgs/action/calibrate_imu.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "lr_msgs/msg/rover_command.hpp"
#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <math.h>
#include <tf2/utils.h>

namespace lr {
namespace total_station_rtls {

class TSPrismTransformer : public rclcpp::Node {

public:
    TSPrismTransformer();
    using CalibrateImu = lr_msgs::action::CalibrateImu;
    using GoalHandleCalibrateImu = rclcpp_action::ServerGoalHandle<CalibrateImu>;

private:

    /* Publishers and Subscribers */
    rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr transformed_ts_prism_pub_;
    rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr ts_prism_subscription_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscription_;
    rclcpp::TimerBase::SharedPtr tf_timer_{nullptr};

    /* Callbacks */
    void ts_prism_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr prism_msg);
    void imu_callback(const sensor_msgs::msg::Imu::SharedPtr imu_msg);
    bool tf_update(std::string toFrameRel, std::string fromFrameRel, geometry_msgs::msg::TransformStamped &transform);
    void tf_Callback();

    /* Transforms */
    std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
    std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    bool got_tf{false};
    std::shared_ptr<tf2_ros::TransformBroadcaster> transform_broadcaster_; // Add this line to broadcast transforms -- New code

    // TODO turn these into ROS parameters
    std::string prism_frame = "total_station_prism";
    std::string base_link_frame = "base_link";
    std::string map_frame = "map";

    geometry_msgs::msg::PoseWithCovarianceStamped updated_pose_;
    sensor_msgs::msg::Imu imu_last;
    geometry_msgs::msg::TransformStamped ts_prism_transformStamped;
    geometry_msgs::msg::TransformStamped local_ts_prism_transform;
    geometry_msgs::msg::TransformStamped base_link_transform;
    bool got_imu{false};
    bool got_bearing_{false};

    double yaw_offset_;
    bool calibration_complete_;
    rclcpp_action::Server<CalibrateImu>::SharedPtr calibrate_imu_action_server_;

    double addAngles(double a1, double a2);
    double calculateAverageAngle(const std::vector<double>& angles);
    void append_TS_IMU_Data(std::vector<std::pair<geometry_msgs::msg::Point, double>> & TS_IMU_Data, int itr);

    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const CalibrateImu::Goal> goal);
    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleCalibrateImu> goal_handle);

    void handle_accepted(const std::shared_ptr<GoalHandleCalibrateImu> goal_handle);
    void executeCalibrateIMU(const std::shared_ptr<GoalHandleCalibrateImu> goal_handle);    

};


}  // namespace total_station_rtls
}  // namespace lr

#endif  // PRISM_TRANSFORMER_NODE_HPP
