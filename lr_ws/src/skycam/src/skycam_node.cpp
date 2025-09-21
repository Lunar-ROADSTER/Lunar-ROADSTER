/**
 * @file skycam_node.cpp
 * @brief Runs a TorchScript SkyCam model to infer 3D position (x, y, z) from FLIR images and publishes results.
 *
 * This node subscribes to raw FLIR camera images, preprocesses them (resize + color conversion),
 * forwards them through a TorchScript (LibTorch) regression model, and publishes:
 *   1) /skycam/point : geometry_msgs::msg::PointStamped — inferred (x, y, z)
 *   2) /skycam/pose  : geometry_msgs::msg::PoseWithCovarianceStamped — same position with identity orientation
 *
 * The node is CPU-only (no CUDA) and will ignore device parameters requesting GPU. Orientation is not estimated by
 * the model; /skycam/pose publishes an identity quaternion (w=1) and zero covariance by default.
 *
 * @version 1.0.0
 * @date 2025-09-21
 *
 * Maintainer: Boxiang (William) Fu  
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /flir_camera/image_raw : [sensor_msgs::msg::Image] Raw FLIR camera frames used as input to the network.
 *
 * Publishers:
 * - /skycam/point : [geometry_msgs::msg::PointStamped] Regressed (x, y, z) in the incoming image header frame.
 * - /skycam/pose  : [geometry_msgs::msg::PoseWithCovarianceStamped] Same position, identity orientation, zero covariance.
 *
 * Parameters:
 * - model_path : [string] Filesystem path to TorchScript model (default: "skycam_convnet_ts.pt").
 * - image_size : [int]    Square size (pixels) to which images are resized before inference (default: 224).
 * - channels   : [int]    Number of input channels (1 = grayscale, 3 = RGB) expected by the model (default: 3).
 * - device     : [string] Requested device ("cpu" or "cuda"); this node forces CPU and warns if "cuda" is set (default: "cpu").
 *
 * Features:
 * - Robust image handling with cv_bridge (supports BGR8 and RGB8; converts as needed).
 * - Normalizes images to [0, 1] and arranges tensors as [1, C, H, W] before inference.
 * - Publishes both point and pose messages using the original image header (timestamp/frame_id).
 */


#include "skycam/skycam.hpp"
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <stdexcept>
 
namespace lr {
namespace skycam {

SkycamNode::SkycamNode() : Node("skycam_node")
{
    // Parameters
    this->declare_parameter<std::string>("model_path", "skycam_convnet_ts.pt");
    model_path_ = this->get_parameter("model_path").as_string();

    this->declare_parameter<int>("image_size", 224);
    image_size_ = this->get_parameter("image_size").as_int();

    this->declare_parameter<int>("channels", 3);
    channels_ = this->get_parameter("channels").as_int();

    this->declare_parameter<std::string>("device", "cpu");
    device_str_ = this->get_parameter("device").as_string();

    // Find device
    device_ = torch::Device(torch::kCPU);
    if (device_str_ != "cpu") {
        RCLCPP_WARN(this->get_logger(),
                    "This node is CPU-only. Ignoring device:=%s and using CPU.",
                    device_str_.c_str());
    }

    // Load model
    try
    {
        module_ = torch::jit::load(model_path_);
        module_.to(device_);
        module_.eval();
        RCLCPP_INFO(this->get_logger(), "Loaded TorchScript model: %s", model_path_.c_str());
    }
    catch (const c10::Error &e)
    {
        RCLCPP_FATAL(this->get_logger(), "Failed to load TorchScript model at '%s': %s",
                        model_path_.c_str(), e.what());
        throw;
    }

    // Publishers
    pub_point_ = this->create_publisher<geometry_msgs::msg::PointStamped>("/skycam/point", 10);
    pub_pose_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("/skycam/pose", 10);

    // Subscriber
    sub_image_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/flir_camera/image_raw",
        rclcpp::SensorDataQoS(),
        std::bind(&SkycamNode::imageCallback, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(),
                "SkycamNode ready. model=%s size=%dx%d channels=%d device=%s",
                model_path_.c_str(), image_size_, image_size_, channels_, device_str_.c_str());
}


void SkycamNode::imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
{
    // Convert ROS Image to cv::Mat
    cv_bridge::CvImageConstPtr cv_ptr;
    try
    {
        if (msg->encoding == sensor_msgs::image_encodings::BGR8)
        {
            cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::BGR8);
        }
        else if (msg->encoding == sensor_msgs::image_encodings::RGB8)
        {
            cv_ptr = cv_bridge::toCvShare(msg, sensor_msgs::image_encodings::RGB8);
        }
        else
        {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
        }
    }
    catch (const cv_bridge::Exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
        return;
    }

    cv::Mat img_bgr = cv_ptr->image;
    if (img_bgr.empty())
    {
        RCLCPP_WARN(this->get_logger(), "Empty image frame, skipping.");
        return;
    }

    // Resize to model input size
    cv::Mat img_resized;
    cv::resize(img_bgr, img_resized, cv::Size(image_size_, image_size_), 0, 0, cv::INTER_LINEAR);

    // Prepare tensor [1,C,H,W], normalized to [0,1]
    torch::Tensor input_tensor;
    if (channels_ == 1)
    {
        cv::Mat gray;
        if (cv_ptr->encoding == sensor_msgs::image_encodings::MONO8)
        {
            gray = img_resized;
        }
        else
        {
            cv::cvtColor(img_resized, gray, cv::COLOR_BGR2GRAY);
        }
        gray.convertTo(gray, CV_32FC1, 1.0 / 255.0);
        input_tensor = torch::from_blob(gray.data, {1, 1, image_size_, image_size_}, torch::kFloat32).clone();
    }
    else
    {
        cv::Mat rgb;
        if (cv_ptr->encoding == sensor_msgs::image_encodings::RGB8)
        {
            rgb = img_resized;
        }
        else
        {
            cv::cvtColor(img_resized, rgb, cv::COLOR_BGR2RGB);
        }
        rgb.convertTo(rgb, CV_32FC3, 1.0 / 255.0);
        torch::Tensor tmp = torch::from_blob(rgb.data, {1, image_size_, image_size_, 3}, torch::kFloat32).clone();
        input_tensor = tmp.permute({0, 3, 1, 2}); // [1,H,W,3] to [1,3,H,W]
    }

    input_tensor = input_tensor.to(device_);

    // Inference
    torch::NoGradGuard no_grad;
    at::Tensor output;
    try
    {
        output = module_.forward({input_tensor}).toTensor();
    }
    catch (const c10::Error &e)
    {
        RCLCPP_ERROR(this->get_logger(), "Inference error: %s", e.what());
        return;
    }

    // Extract prediction
    output = output.to(torch::kCPU);
    auto xyz = output.accessor<float, 2>();
    double x = static_cast<double>(xyz[0][0]);
    double y = static_cast<double>(xyz[0][1]);
    double z = static_cast<double>(xyz[0][2]);

    // Publish PointStamped
    geometry_msgs::msg::PointStamped point_msg;
    point_msg.header = msg->header;
    point_msg.point.x = x;
    point_msg.point.y = y;
    point_msg.point.z = z;
    pub_point_->publish(point_msg);

    // Publish PoseWithCovarianceStamped
    geometry_msgs::msg::PoseWithCovarianceStamped pose_msg;
    pose_msg.header = msg->header;
    pose_msg.pose.pose.position.x = x;
    pose_msg.pose.pose.position.y = y;
    pose_msg.pose.pose.position.z = z;

    // Skycam will not provide orientation information
    pose_msg.pose.pose.orientation.x = 0.0;
    pose_msg.pose.pose.orientation.y = 0.0;
    pose_msg.pose.pose.orientation.z = 0.0;
    pose_msg.pose.pose.orientation.w = 1.0;
    pose_msg.pose.covariance.fill(0.0);

    pub_pose_->publish(pose_msg);

    RCLCPP_INFO(this->get_logger(), "Pred XYZ = [%.3f, %.3f, %.3f]", x, y, z);
}

} // namespace skycam
} // namespace lr