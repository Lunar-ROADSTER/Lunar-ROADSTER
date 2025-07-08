/**
 * @file slip_estimate_node.cpp
 * @brief Estimates wheel slip in real-time by comparing encoder-based and IMU-based velocity estimates using a Kalman filter.
 *
 * This node computes slip as the difference between commanded wheel velocity and estimated vehicle velocity derived
 * from IMU acceleration and encoder measurements using a 6-state Kalman filter. It latches slip detection if slip exceeds
 * thresholds, and releases it once the robot starts moving above threshold velocities.
 *
 * A TF transform is also broadcasted from the map to the base_link frame based on IMU orientation and Kalman-filtered velocity.
 *
 * @version 1.0.0
 * @date 2025-07-07
 *
 * Maintainer: Bhaswanth Ayapilla, Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /actuator/state: [lr_msgs::msg::ActuatorState] Provides wheel velocity from actuators.
 * - /imu/data/base_link: [sensor_msgs::msg::Imu] Provides linear acceleration and orientation of the robot.
 *
 * Publishers:
 * - /slip_estimate: [lr_msgs::msg::Slip] Slip estimate and supporting state information for debugging.
 * - TF: [geometry_msgs::msg::TransformStamped] Estimated transform from map to base_link using filtered velocity and IMU orientation.
 *
 * Parameters:
 * - Qx, Qxdot, Qy, Qydot, Qax, Qay: Process noise covariances
 * - Rxdot, Rydot, Rax, Ray: Measurement noise covariances
 * - Px, Pxdot, Py, Pydot, Pax, Pay: Initial estimation uncertainties
 * - kf_dt: Kalman filter timestep
 * - vel_kf_window_size: Moving average window size for velocity estimate
 * - slip_window_size: Moving average window size for slip estimate
 * - nonzero_slip_thresh_wheel_ms, nonzero_slip_thresh_vehicle_ms: Thresholds to activate slip calculation
 * - slip_latch_thresh_ms, slip_velocity_latch_release_ms: Latching thresholds for slip condition
 *
 * Kalman Filter:
 * - State vector: `[x, ẋ, y, ẏ, aₓ, aᵧ]`
 * - Measurement vector: `[ẋ_enc, ẏ_enc, aₓ_imu, aᵧ_imu]`
 * - Dynamics: Constant acceleration model in 2D (x, y)
 *
 * @credit Adapted from standard vehicle state estimation and slip detection methods in planetary mobility literature.
 */

#include "localization/slip_estimate_node.hpp"

namespace lr {
namespace slip {

SlipEstimateNode::SlipEstimateNode() : Node("slip_estimate_node") {
  
  // Initialize publishers and subscribers
  slip_pub_ = this->create_publisher<lr_msgs::msg::Slip>(
    "/slip_estimate", 1
  );

  act_sub_ = this->create_subscription<lr_msgs::msg::ActuatorState>(
      "/actuator/state", 1, std::bind(&SlipEstimateNode::actStateCallback, this, std::placeholders::_1));

  imu_subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
    "/imu/data/base_link", 10, std::bind(&SlipEstimateNode::imuAvgCallback, this, std::placeholders::_1));

  // Timer callback
  timer_ = this->create_wall_timer(
      std::chrono::milliseconds(100),
      std::bind(&SlipEstimateNode::timerCallback, this));

  // Tf Broadcaster
  tf_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

  // Load parameters
  this->declare_parameter<float>("Qx", 10.0);
  this->get_parameter("Qx", Qx_);
  this->declare_parameter<float>("Qxdot", 10.0);
  this->get_parameter("Qxdot", Qxdot_);
  this->declare_parameter<float>("Qax", 10.0);
  this->get_parameter("Qax", Qax_);
  this->declare_parameter<float>("Qy", 10.0);
  this->get_parameter("Qy", Qy_);
  this->declare_parameter<float>("Qydot", 10.0);
  this->get_parameter("Qydot", Qydot_);
  this->declare_parameter<float>("Qay", 10.0);
  this->get_parameter("Qay", Qay_);
  // this->declare_parameter<float>("Rx", 10.0);
  // this->get_parameter("Rx", Rx_);
  this->declare_parameter<float>("Rxdot", 10.0);
  this->get_parameter("Rxdot", Rxdot_);
  this->declare_parameter<float>("Rax", 10.0);
  this->get_parameter("Rax", Rax_);
  // this->declare_parameter<float>("Ry", 10.0);
  // this->get_parameter("Ry", Ry_);
  this->declare_parameter<float>("Rydot", 10.0);
  this->get_parameter("Rydot", Rydot_);
  this->declare_parameter<float>("Ray", 10.0);
  this->get_parameter("Ray", Ray_);
  this->declare_parameter<float>("Px", 10.0);
  this->get_parameter("Px", Px_);
  this->declare_parameter<float>("Pxdot", 10.0);
  this->get_parameter("Pxdot", Pxdot_);
  this->declare_parameter<float>("Pax", 10.0);
  this->get_parameter("Pax", Pax_);
  this->declare_parameter<float>("Py", 10.0);
  this->get_parameter("Py", Py_);
  this->declare_parameter<float>("Pydot", 10.0);
  this->get_parameter("Pydot", Pydot_);
  this->declare_parameter<float>("Pay", 10.0);
  this->get_parameter("Pay", Pay_);
  this->declare_parameter<double>("kf_dt", 0.05);
  this->get_parameter("kf_dt", kf_dt_);

  this->declare_parameter<int>("vel_kf_window_size", 10);
  this->get_parameter("vel_kf_window_size", vel_kf_window_size_);

  this->declare_parameter<float>("nonzero_slip_thresh_wheel_ms", 0.1);
  this->get_parameter("nonzero_slip_thresh_wheel_ms", nonzero_slip_thresh_wheel_ms_);
  this->declare_parameter<float>("nonzero_slip_thresh_vehicle_ms_", 0.07);
  this->get_parameter("nonzero_slip_thresh_vehicle_ms_", nonzero_slip_thresh_vehicle_ms_);

  this->declare_parameter<float>("slip_latch_thresh_ms", 0.8);
  this->get_parameter("slip_latch_thresh_ms", slip_latch_thresh_ms_);
  this->declare_parameter<float>("slip_velocity_latch_release_ms", 0.06);
  this->get_parameter("slip_velocity_latch_release_ms", slip_velocity_latch_release_ms_);

  this->declare_parameter<int>("slip_window_size", 10);
  this->get_parameter("slip_window_size", slip_window_size_);

  // Kalman Filter for velocity estimation
  // Discrete LTI projectile motion, measuring position only, constant velocity kinematics
  Eigen::MatrixXd A_(6, 6); // System dynamics matrix
  Eigen::MatrixXd H_(4, 6); // Measurement observation matrix
  Eigen::MatrixXd Q_(6, 6); // Process noise covariance
  Eigen::MatrixXd R_(4, 4); // Measurement noise covariance
  Eigen::MatrixXd P_(6, 6); // Estimate error covariance

  Eigen::VectorXd x0_(6);

  // state vector x0 = [x; xdot; y; ydot; ax; ay]
  A_ << 1, kf_dt_, 0,   0, 0.5 * pow(kf_dt_,2), 0,
        0,   1,    0,   0, kf_dt_, 0,
        0,   0,    1, kf_dt_, 0, 0.5 * pow(kf_dt_,2),
        0,   0,    0,   1, 0, kf_dt_,
        0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 1;
        
  H_ << 0, 1, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0,
        0, 0, 0, 0, 1, 0,
        0, 0, 0, 0, 0, 1;

  // Process uncertainty
  Q_ << Qx_, .0, .0, .0, .0, .0,
        .0, Qxdot_, .0, .0, .0, .0,
        .0, .0, Qy_, .0, .0, .0,
        .0, .0, .0, Qydot_, .0, .0,
        .0, .0, .0, .0, Qax_, .0,
        .0, .0, .0, .0, .0, Qay_;

  // Measurement uncertainty
  R_ << Rxdot_, .0, .0, .0,
        .0, Rydot_, .0, .0,
        .0, .0, Rax_, .0,
        .0, .0, .0, Ray_;

  // Initially give high uncertainty to unestimated states
  P_ << Px_, .0, .0, .0, .0, .0,
        .0, Pxdot_, 0, .0, .0, .0, 
        .0, 0, Py_, .0, .0, .0,
        .0, 0, .0, Pydot_, .0, .0,
        .0, .0, .0, .0, Pax_, .0,
        .0, .0, .0, .0, .0, Pay_;

  // Construct the filter using initializer list with temp object
  lr::localization::KalmanFilterLinear kf_vel_tmp_(A_, H_, Q_, R_, P_);
  kf_vel_ = kf_vel_tmp_; // Assign temp object to the actual object that is declared in node header

  // Best guess of initial states
  x0_ << 0, 0, 0, 0, 0, 0; // [x; xdot; y; ydot; ax; ay]
  kf_vel_.init(x0_);
}

void SlipEstimateNode::timerCallback()
{
  // Calculate slip estimate if wheels are moving fast enough, and vehicle is moving too slow
  if (vel_wheels_ > nonzero_slip_thresh_wheel_ms_ && vel_kf_avg_ < nonzero_slip_thresh_vehicle_ms_)
  {
    // Expect 0 for no slip, 1 for 100% slip, clamp at zero so no negative slip (only using magnitudes)
    curr_slip_ = std::max(static_cast<float>(0.0), (vel_wheels_ - vel_kf_avg_) / vel_wheels_);
  }
  else
  {
    curr_slip_ = static_cast<float>(0.0);
  }

  // Use moving average to smooth slip estimate
  slip_avg_ = updateMovingAverage(slip_window_, curr_slip_, slip_window_size_);

  // Evaluate slip latch conditions
  if (!slip_latch_)
  {
    // Activate latch if average slip is above a threshold, and vehicle speed is below a threshold
    if (slip_avg_ > slip_latch_thresh_ms_)
    {
      slip_latch_ = true;
    }
  }
  else
  {
    // Only release latch if both velocity estimates agree that we are driving above a threshold
    if (vel_kf_avg_ > slip_velocity_latch_release_ms_ && vel_wheels_ > slip_velocity_latch_release_ms_)
    {
      slip_latch_ = false;
    }
  }

  // Publish the message; some extra values included to assist testing
  slip_msg_.slip = curr_slip_;
  slip_msg_.slip_avg = slip_avg_;
  slip_msg_.slip_latch = slip_latch_;
  slip_msg_.vel = vel_kf_;
  slip_msg_.vel_avg = vel_kf_avg_;
  slip_msg_.header.stamp = this->get_clock()->now();
  slip_pub_->publish(slip_msg_);


  /* Publish transforms -- New code*/

  if(!got_imu_data_) return;

  // Broadcast the estimated transform
  static double x = 0, y = 0;
  double yaw = tf2::getYaw(latest_imu_orientation_);
  x += vel_kf_ * kf_dt_ * cos(yaw);
  y += vel_kf_ * kf_dt_ * sin(yaw);

  
  imuTransformStamped.header.stamp = this->get_clock()->now();
  imuTransformStamped.header.frame_id = map_frame;  // Reference frame
  imuTransformStamped.child_frame_id = base_link_frame;  // Estimated robot frame

  imuTransformStamped.transform.translation.x = x;
  imuTransformStamped.transform.translation.y = y;
  imuTransformStamped.transform.translation.z = 0.0;

  // Use IMU orientation
  imuTransformStamped.transform.rotation = latest_imu_orientation_;

  tf_broadcaster_->sendTransform(imuTransformStamped);

}


void SlipEstimateNode::actStateCallback(const lr_msgs::msg::ActuatorState::SharedPtr msg)
{
  // Get current magnitude of wheel velocity
  vel_wheels_ = std::abs(msg->wheel_velocity);
}


void SlipEstimateNode::imuAvgCallback(const sensor_msgs::msg::Imu::SharedPtr imu_msg)
{
  // Store latest IMU orientation -- New code
  latest_imu_orientation_ = imu_msg->orientation;
  got_imu_data_ = true;

  // Extract linear accelerations from IMU
  double measured_ax = imu_msg->linear_acceleration.x;
  double measured_ay = imu_msg->linear_acceleration.y;

  // Extract velocities from encoders
  double measured_xdot = vel_wheels_;
  double measured_ydot = 0;

  Eigen::VectorXd z_(4);
  z_ << measured_xdot, measured_ydot, measured_ax, measured_ay;

  kf_vel_.predict();
  kf_vel_.update(z_);

  // Extract estimate of velocity magnitude
  Eigen::VectorXd xhat_(6);
  xhat_ = kf_vel_.state(); // [x; xdot; y; ydot; ax; ay]
  vel_kf_ = sqrt(pow(xhat_(1), 2.0) + pow(xhat_(3), 2.0));

  // Update moving average
  vel_kf_avg_ = updateMovingAverage(vel_kf_window_, vel_kf_, vel_kf_window_size_);
}

float SlipEstimateNode::updateMovingAverage(std::list<float> &list, const float &new_val, const int &window_size)
{
  // Build up the filter
  list.push_front(new_val);
  if (static_cast<int>(list.size()) > window_size)
  {
    list.pop_back(); // remove oldest value
  }

  // Update the filter
  return std::accumulate(list.begin(), list.end(), 0.0) / list.size();
}

} // namespace odom
} // namespace lr
