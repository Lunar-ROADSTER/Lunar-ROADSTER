#pragma once 

#include<chrono>
#include <rclcpp/rclcpp.hpp>
#include <cg_msgs/msg/slip.hpp>
#include <cg_msgs/msg/actuator_state.hpp>
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <cmath> // std::abs
#include <algorithm> // std::max
#include <list> // moving average filter
#include "localization/kalman_filter_linear.hpp"

#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2/LinearMath/Quaternion.h>


namespace cg {
namespace slip {

class SlipEstimateNode : public rclcpp::Node {

public:
  SlipEstimateNode();

private: 
  /* Publishers and Subscribers */
  rclcpp::Publisher<cg_msgs::msg::Slip>::SharedPtr slip_pub_;
  rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr uwb_avg_sub_;
  rclcpp::Subscription<cg_msgs::msg::ActuatorState>::SharedPtr act_sub_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscription_;

  rclcpp::TimerBase::SharedPtr timer_; // For looping publish

  /* Message data */
  cg_msgs::msg::Slip slip_msg_;

  /* Parameters */
  float vel_wheels_ = 0.0; // Wheel velocity averaged between front and back, as reported from actuator state
  float curr_slip_ = 0.0;
  float nonzero_slip_thresh_wheel_ms_;
  float nonzero_slip_thresh_vehicle_ms_;
  float slip_latch_thresh_ms_;
  float slip_velocity_latch_release_ms_;

  int slip_window_size_ = 10;
  std::list<float> slip_window_;
  float slip_avg_ = 0.0;

  int vel_kf_window_size_ = 10;
  std::list<float> vel_kf_window_;
  float vel_kf_avg_ = 0.0;

  bool slip_latch_ = false;

  // Kalman filter for velocity estimation
  int kf_n_ = 4; // Number of states
  int kf_m_ = 2;            // Number of measurements
  double kf_dt_ = 0.05; // Time step in seconds: in theory, this should align with rate of prediction calls but might not in practice due to modeling error
  float vel_kf_ = 0.;       // Estimated velocity from Kalman Filter

  float Qx_;
  float Qxdot_;
  float Qax_;
  float Qy_;
  float Qydot_;
  float Qay_;
  // float Rx_;
  float Rxdot_;
  float Rax_;
  // float Ry_;
  float Rydot_;
  float Ray_;
  float Px_;
  float Pxdot_;
  float Pax_;
  float Py_;
  float Pydot_;
  float Pay_;

  Eigen::VectorXd z_;
  Eigen::VectorXd xhat_;
  Eigen::VectorXd x0_;

  cg::localization::KalmanFilterLinear kf_vel_;

  /* Callbacks */
  void actStateCallback(const cg_msgs::msg::ActuatorState::SharedPtr msg);
  void timerCallback(); // For looping publish
  void uwbAvgCallback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg);
  void imuAvgCallback(const sensor_msgs::msg::Imu::SharedPtr imu_msg);

  /* Helpers */
  // Update list of values for moving average, modify the list being passed as an argument
  float updateMovingAverage(std::list<float> &list, const float &new_val, const int &window_size);


  /* New code*/
  std::shared_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
  geometry_msgs::msg::Quaternion latest_imu_orientation_;
  bool got_imu_data_ = false;
  geometry_msgs::msg::TransformStamped imuTransformStamped;
  std::string base_link_frame = "base_link";
  std::string map_frame = "map";


}; // class SlipEstimateNode

} // namespace slip
} // namespace cg
