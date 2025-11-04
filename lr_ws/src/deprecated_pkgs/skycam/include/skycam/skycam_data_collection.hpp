#ifndef SKYCAM_H
#define SKYCAM_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <sensor_msgs/msg/imu.hpp>
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include <tf2/LinearMath/Quaternion.h>

#include <mutex>
#include <optional>
#include <chrono>
#include <string>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <system_error>
#include <array>
#include <random>
#include <algorithm>

namespace lr{
namespace skycam{
    
class SkycamDataCollectionNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
        rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr prism_pose_sub_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;

        // Publishers
        rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr pose_vis_pub_;

        // Functions
        void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);
        void prismPoseCallback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg);
        void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);
        void timerCallback();

        void ensureOutputDir();
        std::string currentImageBasenameCounter() const;
        std::string currentImageBasenameHash() const;
        void advanceCounter();
        static inline std::array<double,3> quatToRPY(double x, double y, double z, double w);

        // Variables
        double hz_rate_;
        double max_time_diff_sec_{1.0};
        rclcpp::TimerBase::SharedPtr timer_;

        std::mutex data_mutex_;
        sensor_msgs::msg::Image::SharedPtr latest_image_;  // keep most recent image
        geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr latest_prism_pose_; // most recent pose
        sensor_msgs::msg::Imu::SharedPtr latest_imu_; //  most recent IMU
        std::array<double,3> latest_rpy_{0.0, 0.0, 0.0};  // roll, pitch, yaw
        tf2::Quaternion q_baseline_;
        std::array<double,3> latest_rel_rpy_{0.0, 0.0, 0.0};

        rclcpp::Time last_image_time_{0, 0, RCL_SYSTEM_TIME};
        rclcpp::Time last_prism_pose_time_{0, 0, RCL_SYSTEM_TIME};
        rclcpp::Time last_imu_time_{0, 0, RCL_SYSTEM_TIME};

        std::string output_dir_;
        std::string mode_;
        uint64_t image_counter_{1};

        bool have_imu_{false};
        bool zero_on_startup_ = true;
        bool have_baseline_ = false; 

    public:
        // Constructor and destructor
        SkycamDataCollectionNode();
        ~SkycamDataCollectionNode(){};
};  

} // namespace skycam
} // namespace lr
#endif