/**
 * @file imu_base_link_conversion_node.cpp
 * @brief Converts IMU data from `imu_link` to `base_link` using TF and republishes the rotated signals.
 *
 * This node subscribes to IMU messages in the `imu_link` frame, resolves the transform to `base_link`
 * via TF, and applies only the rotational component to the IMU signals: angular velocity, linear
 * acceleration, and orientation. The transformed IMU is published in the `base_link` frame on a
 * ~20 Hz timer (50 ms). Covariances are currently forwarded unchanged from the input.
 *
 * @version 1.0.0
 * @date 2025-08-09
 *
 * Maintainer: Bhaswanth Ayapilla, Ankit Aggarwal, Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /vectornav/imu: [sensor_msgs::msg::Imu] Incoming IMU data in the `imu_link` frame (SensorDataQoS).
 *
 * Publishers:
 * - /imu/data/base_link: [sensor_msgs::msg::Imu] IMU data rotated into the `base_link` frame.
 *
 * Services:
 * - None
 *
 * Parameters:
 * - None (uses hardcoded frame names: "base_link" and "imu_link")
 *
 * @credit Inspired by standard tf2-based IMU frame conversion patterns in ROS 2.
 *
 * Notes:
 * - Translation in the transform is ignored; only rotation is applied to IMU signals.
 * - Orientation, angular velocity, and linear acceleration are rotated using Eigen.
 * - Covariance matrices are currently copied directly from the input IMU message.
 * - TF lookup between frames is performed once during node startup; assumes static transform.
 * - Processing is driven by a fixed 50 ms timer (~20 Hz).
 */

#include <tf2/transform_datatypes.h>
#include <tf2_ros/buffer_interface.h>
#include "imu/imu_base_link_conversion_node.hpp"

namespace lr
{
  namespace imu
  {

    ImuBaseLinkConversionNode::ImuBaseLinkConversionNode() : Node("imu_base_link_conversion_node")
    {
      // Initialize publishers and subscribers
      base_link_imu_pub_ = this->create_publisher<sensor_msgs::msg::Imu>(
          "/imu/data/base_link", 1);
      imu_link_imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
          "/vectornav/imu", rclcpp::SensorDataQoS(), std::bind(&ImuBaseLinkConversionNode::imuLinkImuCallback, this, std::placeholders::_1));
      timer_ = this->create_wall_timer(
          std::chrono::milliseconds(50),
          std::bind(&ImuBaseLinkConversionNode::timerCallback, this));
      tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
      std::shared_ptr<tf2_ros::TransformListener> tf_listener = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

      std::string target_frame = "base_link";
      std::string source_frame = "imu_link";
      while (rclcpp::ok())
      {
        try
        {
          base_link_imu_link_tf_ = tf_buffer_->lookupTransform(
              target_frame, source_frame, tf2::TimePointZero);
          break;
        }
        catch (tf2::TransformException &ex)
        {
          RCLCPP_WARN(
              this->get_logger(), "Could not lookupTransform with target %s, source %s: %s",
              target_frame.c_str(), source_frame.c_str(), ex.what());
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
      }
    }

    void ImuBaseLinkConversionNode::imuLinkImuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
    {
      imu_link_msg_ = *msg;
    }

    void ImuBaseLinkConversionNode::timerCallback()
    {
      try
      {
        sensor_msgs::msg::Imu base_link_msg;
        doTransform(imu_link_msg_, base_link_msg, base_link_imu_link_tf_);
        base_link_imu_pub_->publish(base_link_msg);
      }
      catch (tf2::TransformException &ex)
      {
        RCLCPP_WARN(
            this->get_logger(), "Could not transform Imu msg with error: %s", ex.what());
      }
    }

    void ImuBaseLinkConversionNode::doTransform(
        const sensor_msgs::msg::Imu &imu_in,
        sensor_msgs::msg::Imu &imu_out,
        const geometry_msgs::msg::TransformStamped &t_in) const
    {
      imu_out.header = t_in.header;
      imu_out.header.frame_id = "base_link";
      imu_out.header.stamp = imu_in.header.stamp;

      // Discard translation, only use orientation for IMU transform
      Eigen::Quaternion<double> r(
          t_in.transform.rotation.w,
          t_in.transform.rotation.x,
          t_in.transform.rotation.y,
          t_in.transform.rotation.z);
      Eigen::Transform<double, 3, Eigen::Affine> t(r);

      Eigen::Vector3d vel = t * Eigen::Vector3d(
                                    imu_in.angular_velocity.x,
                                    imu_in.angular_velocity.y,
                                    imu_in.angular_velocity.z);
      imu_out.angular_velocity.x = vel.x();
      imu_out.angular_velocity.y = vel.y();
      imu_out.angular_velocity.z = vel.z();

      imu_out.angular_velocity_covariance = imu_in.angular_velocity_covariance;

      Eigen::Vector3d acc = t * Eigen::Vector3d(
                                    imu_in.linear_acceleration.x,
                                    imu_in.linear_acceleration.y,
                                    imu_in.linear_acceleration.z);
      imu_out.linear_acceleration.x = acc.x();
      imu_out.linear_acceleration.y = acc.y();
      imu_out.linear_acceleration.z = acc.z();

      imu_out.linear_acceleration_covariance = imu_in.linear_acceleration_covariance;

      Eigen::Quaternion<double> orientation = r * Eigen::Quaternion<double>(imu_in.orientation.w, imu_in.orientation.x, imu_in.orientation.y, imu_in.orientation.z) * r.inverse();

      imu_out.orientation.w = orientation.w();
      imu_out.orientation.x = orientation.x();
      imu_out.orientation.y = orientation.y();
      imu_out.orientation.z = orientation.z();

      imu_out.orientation_covariance = imu_in.orientation_covariance;
    }

    void ImuBaseLinkConversionNode::transformCovariance(
        const std::array<double, 9> &in,
        std::array<double, 9> &out,
        const Eigen::Quaternion<double> &r) const
    {
      Eigen::Map<const Eigen::Matrix<double, 3, 3, Eigen::RowMajor>> cov_in(in.data());
      Eigen::Map<Eigen::Matrix<double, 3, 3, Eigen::RowMajor>> cov_out(out.data());
      cov_out = r * cov_in * r.inverse();
    }

  } // namespace imu
} // namespace lr
