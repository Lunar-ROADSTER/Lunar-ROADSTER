#include "localization/ts_prism_transformer.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

namespace cg
{
  namespace total_station_rtls
  {

    TSPrismTransformer::TSPrismTransformer() : Node("ts_prism_transformer")
    {

      /* Publishers and Subscribers */
      ts_prism_subscription_ = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
          "/total_station_prism", 10, std::bind(&TSPrismTransformer::ts_prism_callback, this, _1));

      imu_subscription_ = this->create_subscription<sensor_msgs::msg::Imu>(
          "/imu/data/base_link", 10, std::bind(&TSPrismTransformer::imu_callback, this, _1));

      transformed_ts_prism_pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>(
          "/transformed_total_station_prism", 1);
      
      int pub_freq{10};
      tf_timer_ = this->create_wall_timer(
          std::chrono::milliseconds(1000 / pub_freq),
          std::bind(&TSPrismTransformer::tf_Callback, this));

      // Tf listeners
      tf_buffer_ = std::make_unique<tf2_ros::Buffer>(this->get_clock());
      transform_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

      // Tf broadcaster
      transform_broadcaster_ = std::make_shared<tf2_ros::TransformBroadcaster>(this);

      // Setup IMU calibration action server
      yaw_offset_ = 0.0;
      calibration_complete_ = false;
      calibrate_imu_action_server_ = rclcpp_action::create_server<CalibrateImu>(
          this,
          "ts_prism_transformer/calibrate_imu",
          std::bind(&TSPrismTransformer::handle_goal, this, _1, _2),
          std::bind(&TSPrismTransformer::handle_cancel, this, _1),
          std::bind(&TSPrismTransformer::handle_accepted, this, _1));

    }

    double TSPrismTransformer::addAngles(double a1, double a2)
    {
      double sum = a1 + a2;

      if(sum > M_PI)
        sum -= 2.0 * M_PI;
      else if(sum < -M_PI)
        sum += 2.0 * M_PI;
      
      return sum;
    }

    double TSPrismTransformer::calculateAverageAngle(const std::vector<double>& angles)
    {
      double sumX = 0.0, sumY = 0.0;
      for (const auto& angle : angles) {
        sumX += cos(angle);
        sumY += sin(angle);
      }
      double averageRadians = atan2(sumY, sumX);

      return addAngles(averageRadians, 0);
    }

    void TSPrismTransformer::append_TS_IMU_Data(std::vector<std::pair<geometry_msgs::msg::Point, double>> & TS_IMU_Data, int itr)
    {
      (void) itr;
      // Use the latest TS prism position and current IMU yaw
      tf2::Quaternion imu_q(
        imu_last.orientation.x,
        imu_last.orientation.y,
        imu_last.orientation.z,
        imu_last.orientation.w);
      double imu_yaw = tf2::getYaw(imu_q);
      TS_IMU_Data.push_back(std::make_pair(updated_pose_.pose.pose.position, imu_yaw));
    }

    void TSPrismTransformer::ts_prism_callback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr prism_msg)
    {
      updated_pose_ = *prism_msg;
      if (got_imu)
      {
        // Obtain roll/pitch/yaw from IMU in quaternion forms
        tf2::Quaternion imu_q(
          imu_last.orientation.x,
          imu_last.orientation.y,
          imu_last.orientation.z,
          imu_last.orientation.w);

        // Convert quaternions to roll/pitch/yaw
        tf2::Matrix3x3 imu_m(imu_q);
        double imu_roll, imu_pitch, imu_yaw;
        imu_m.getRPY(imu_roll, imu_pitch, imu_yaw);

        // Compute 3DOF orientation from map to base_link, based on raw IMU and bearing measurements
        tf2::Quaternion map_to_base_link_q;
        map_to_base_link_q.setRPY(imu_roll, imu_pitch, imu_yaw);

        if(calibration_complete_)
        {
          double calibrated_yaw = addAngles(imu_yaw, yaw_offset_);
          map_to_base_link_q.setRPY(imu_roll, imu_pitch, calibrated_yaw);
        }

        Eigen::Quaternion<double> map_to_base_link_rotation(
          map_to_base_link_q.w(),
          map_to_base_link_q.x(),
          map_to_base_link_q.y(),
          map_to_base_link_q.z()
        );

        // TODO parametrize this hard-coded translation
        // Get static TS prism to base_link translation from transform/parameters
        Eigen::Vector3d ts_prism_to_base_link_translation(
          // ts_prism_transformStamped.transform.translation.x,
          // ts_prism_transformStamped.transform.translation.y,
          // ts_prism_transformStamped.transform.translation.z
          -0.20033, -0.020133, -0.75628
        );

        // Rotate translation such that it is axis aligned with base_link
        Eigen::Vector3d rotated_ts_prism_to_base_link_translation = map_to_base_link_rotation * ts_prism_to_base_link_translation;

        // Get position of TS prism in map frame, from raw TS measurement
        Eigen::Vector3d map_to_ts_prism_translation(
          updated_pose_.pose.pose.position.x,
          updated_pose_.pose.pose.position.y,
          updated_pose_.pose.pose.position.z
        );

        // Get position of base_link in map frame by translating position of TS prism
        Eigen::Vector3d map_to_base_link_translation = map_to_ts_prism_translation + rotated_ts_prism_to_base_link_translation;
        updated_pose_.pose.pose.position.x = map_to_base_link_translation.x();
        updated_pose_.pose.pose.position.y = map_to_base_link_translation.y();
        updated_pose_.pose.pose.position.z = map_to_base_link_translation.z();
        updated_pose_.pose.pose.orientation.w = map_to_base_link_rotation.w();
        updated_pose_.pose.pose.orientation.x = map_to_base_link_rotation.x();
        updated_pose_.pose.pose.orientation.y = map_to_base_link_rotation.y();
        updated_pose_.pose.pose.orientation.z = map_to_base_link_rotation.z();

        transformed_ts_prism_pub_->publish(updated_pose_);

      } else {
        std::cout << "No imu received\n";
      }
    }

    void TSPrismTransformer::imu_callback(const sensor_msgs::msg::Imu::SharedPtr imu_msg)
    {
      imu_last = *imu_msg;
      got_imu = true;
    }

    // Update tf transforms
    // TODO investigate if tf_Callback and tf_Update are still needed
    void TSPrismTransformer::tf_Callback()
    {

      // Get Translation between base_link and prism in base_link_frame
      bool got_tf1 = tf_update(prism_frame, base_link_frame, ts_prism_transformStamped);

      // Get Orientation between map and base_link in map_frame
      bool got_tf2 = tf_update(map_frame, base_link_frame, base_link_transform);
      got_tf = got_tf1 && got_tf2;
    }

    // Update given tf transform
    bool TSPrismTransformer::tf_update(std::string toFrameRel, std::string fromFrameRel, geometry_msgs::msg::TransformStamped &transform)
    {
      try
      {
        transform = tf_buffer_->lookupTransform(
            toFrameRel, fromFrameRel,
            tf2::TimePointZero);
        return true;
      }
      catch (tf2::TransformException &ex)
      {
        RCLCPP_INFO(
            this->get_logger(), "Could not transform %s to %s: %s",
            toFrameRel.c_str(), fromFrameRel.c_str(), ex.what());
        return false;
      }
    }

    rclcpp_action::GoalResponse TSPrismTransformer::handle_goal(
        const rclcpp_action::GoalUUID & uuid,
        std::shared_ptr<const CalibrateImu::Goal> goal)
    {
      RCLCPP_INFO(this->get_logger(), "Received calibrate IMU request");
      (void)uuid;
      (void)goal;
      return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse TSPrismTransformer::handle_cancel(
        const std::shared_ptr<GoalHandleCalibrateImu> goal_handle)
    {
      RCLCPP_INFO(this->get_logger(), "Received request to cancel calibrate IMU action");
      (void)goal_handle;
      return rclcpp_action::CancelResponse::ACCEPT;
    }

    void TSPrismTransformer::handle_accepted(
        const std::shared_ptr<GoalHandleCalibrateImu> goal_handle)
    {
      std::thread{std::bind(&TSPrismTransformer::executeCalibrateIMU, this, std::placeholders::_1), goal_handle}.detach();
    }

    void TSPrismTransformer::executeCalibrateIMU(
        const std::shared_ptr<GoalHandleCalibrateImu> goal_handle)
    {
      RCLCPP_INFO(this->get_logger(), "Executing calibrate IMU action");
      const auto goal = goal_handle->get_goal();
      auto feedback = std::make_shared<CalibrateImu::Feedback>();
      auto result = std::make_shared<CalibrateImu::Result>();

      double calibrate_duration = (goal->time > 0) ? goal->time : 6.5;
      std::vector<std::pair<geometry_msgs::msg::Point, double>> TS_IMU_Data;
      auto start_time = this->get_clock()->now();
      rclcpp::Rate loop_rate(1);

      while(rclcpp::ok() && !goal_handle->is_canceling())
      {
        auto current_time = this->get_clock()->now();
        if((current_time - start_time).seconds() >= calibrate_duration)
        {
          RCLCPP_INFO(this->get_logger(), "Calibration period complete");
          break;
        }
        append_TS_IMU_Data(TS_IMU_Data, 0);
        loop_rate.sleep();
      }

      if(goal_handle->is_canceling() || !rclcpp::ok())
      {
        RCLCPP_INFO(this->get_logger(), "Calibrate IMU action cancelled");
        result->success = false;
        goal_handle->abort(result);
        return;
      }

      if(TS_IMU_Data.size() < 2)
      {
        RCLCPP_INFO(this->get_logger(), "Not enough data recorded, aborting calibration");
        result->success = false;
        goal_handle->abort(result);
        return;
      }

      std::vector<double> yaw_offsets;
      for(size_t i = 0; i < TS_IMU_Data.size() - 1; i++)
      {
        double angle_diff = addAngles(TS_IMU_Data[i+1].second, -TS_IMU_Data[i].second);
        if (fabs(angle_diff) > 20.0 * M_PI / 180.0)
        {
          continue;
        }
        double avg_imu_yaw = addAngles((TS_IMU_Data[i].second + TS_IMU_Data[i+1].second) / 2.0, 0);
        double ts_bearing = atan2(TS_IMU_Data[i+1].first.y - TS_IMU_Data[i].first.y,
                                  TS_IMU_Data[i+1].first.x - TS_IMU_Data[i].first.x);
        double yaw_offset = addAngles(ts_bearing, -avg_imu_yaw);
        yaw_offsets.push_back(yaw_offset);
      }

      if(yaw_offsets.empty())
      {
        RCLCPP_INFO(this->get_logger(), "No valid yaw offsets calculated, calibration failed");
        result->success = false;
        goal_handle->abort(result);
        return;
      }

      double new_yaw_offset = calculateAverageAngle(yaw_offsets);
      yaw_offset_ = new_yaw_offset;
      calibration_complete_ = true;
      RCLCPP_INFO(this->get_logger(), "Calibration complete, new yaw offset: %f", yaw_offset_);
      result->success = true;
      goal_handle->succeed(result);
    }

  } // namespace total_station_rtls
} // namespace cg
