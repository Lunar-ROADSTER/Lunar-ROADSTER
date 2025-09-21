#ifndef SKYCAM_H
#define SKYCAM_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"

#include <mutex>
#include <optional>
#include <chrono>
#include <string>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <system_error>

namespace lr{
namespace skycam{
    
class SkycamDataCollectionNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_sub_;
        rclcpp::Subscription<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr prism_pose_sub_;

        // Publishers

        // Functions
        void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);
        void prismPoseCallback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg);
        void timerCallback();

        void ensureOutputDir();
        std::string currentImageBasename() const;
        void advanceCounter();

        // Variables
        double hz_rate_;
        double max_time_diff_sec_{1.0};
        rclcpp::TimerBase::SharedPtr timer_;

        std::mutex data_mutex_;
        sensor_msgs::msg::Image::SharedPtr latest_image_;  // keep most recent image
        geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr latest_prism_pose_; // most recent pose
        rclcpp::Time last_image_time_{0, 0, RCL_SYSTEM_TIME};
        rclcpp::Time last_prism_pose_time_{0, 0, RCL_SYSTEM_TIME};

        std::string output_dir_;
        std::string mode_;
        uint64_t image_counter_{1};

    public:
        // Constructor and destructor
        SkycamDataCollectionNode();
        ~SkycamDataCollectionNode(){};
};  

} // namespace skycam
} // namespace lr
#endif