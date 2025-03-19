#ifndef IMU_TF_PUBLISHER_HPP
#define IMU_TF_PUBLISHER_HPP

#include "rclcpp/rclcpp.hpp"
#include <sensor_msgs/msg/imu.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <visualization_msgs/msg/marker.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2/convert.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/transform_broadcaster.h>
#include <tf2_ros/buffer.h>
#include <math.h>

namespace cg {

namespace imu_rlts {

class ImuTfPublisher : public rclcpp::Node {

public:
    ImuTfPublisher();

private:

    /* Publishers and Subscribers */
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscription_;
    rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;

    /* Transforms */
    // std::shared_ptr<tf2_ros::TransformListener> transform_listener_{nullptr};
    // std::unique_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
    bool got_tf{false};

    std::string base_link_frame = "base_link";
    std::string map_frame = "map";
    std::string imu_frame = "imu_link";

    /* Callbacks */
    void imuCallback(const sensor_msgs::msg::Imu::SharedPtr imu_msg);
    void publishImuMarker(const sensor_msgs::msg::Imu::SharedPtr msg);

    visualization_msgs::msg::Marker marker;

};


} // namespace imu_rlts
} // namespace cg

#endif // IMU_TF_PUBLISHER_HPP