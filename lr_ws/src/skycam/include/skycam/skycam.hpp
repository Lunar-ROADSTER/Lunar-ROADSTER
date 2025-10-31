#ifndef SKYCAM_H
#define SKYCAM_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "geometry_msgs/msg/point_stamped.hpp"
#include <geometry_msgs/msg/pose_with_covariance_stamped.hpp>
#include <string>
#include <torch/script.h>

namespace lr{
namespace skycam{
    
class SkycamNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr sub_image_;

        // Publishers
        rclcpp::Publisher<geometry_msgs::msg::PointStamped>::SharedPtr pub_point_;
        rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr pub_pose_;

        // Functions
        void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);

        // Variables
        std::string model_path_;
        int image_size_{224};
        int channels_{3};
        std::string device_str_{"cpu"};
        torch::Device device_{torch::kCPU};

        // Model
        torch::jit::script::Module module_;

    public:
        // Constructor and destructor
        SkycamNode();
        ~SkycamNode(){};
};  

} // namespace skycam
} // namespace lr
#endif