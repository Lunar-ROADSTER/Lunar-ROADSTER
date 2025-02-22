#ifndef IMU__IMU_BASE_LINK_CONVERSION_NODE_HPP
#define IMU__IMU_BASE_LINK_CONVERSION_NODE_HPP

#include <Eigen/Eigen>
#include <Eigen/Geometry>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_ros/transform_listener.h>

namespace cg {
namespace imu {

class ImuBaseLinkConversionNode : public rclcpp::Node {

public:
  ImuBaseLinkConversionNode();

private:
  /* Publishers and Subscribers */
  rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr base_link_imu_pub_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_link_imu_sub_;
  rclcpp::TimerBase::SharedPtr timer_;
  std::unique_ptr<tf2_ros::Buffer> tf_buffer_;

  /* Callbacks */
  void imuLinkImuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);
  void timerCallback();

  /* Transform helper functions */
  // Most of this copied from http://docs.ros.org/en/noetic/api/imu_transformer/html/tf2__sensor__msgs_8h_source.html
  void doTransform(
    const sensor_msgs::msg::Imu &imu_in,
    sensor_msgs::msg::Imu &imu_out,
    const geometry_msgs::msg::TransformStamped &t_in
  ) const;
  void transformCovariance(
    const std::array<double, 9> &in,
    std::array<double, 9> &out,
    const Eigen::Quaternion<double> &r
  ) const;

  sensor_msgs::msg::Imu imu_link_msg_;
  geometry_msgs::msg::TransformStamped base_link_imu_link_tf_;
};


}  // namespace imu
}  // namespace cg

#endif  // IMU__IMU_BASE_LINK_CONVERSION_NODE_HPP
