/**
 * @file skycam_data_collection.cpp
 * @brief Collects synchronized FLIR camera images and total station prism poses for training or evaluation datasets.
 *
 * This node subscribes to raw camera images and prism pose measurements, caches the most recent of each, and
 * periodically (at `hz_rate`) saves synchronized samples into the specified output directory. For each valid sample,
 * the node stores:
 *   1. An image file saved as an incremented sequence (0001.jpg, 0002.jpg, ...).
 *   2. The image filename appended to either `train_files.txt` or `eval_files.txt` depending on the selected mode.
 *   3. The prism pose (x, y, z) and the corresponding image/pose timestamps appended to `{mode}_labels.txt`.
 *
 * Samples are only saved if both an image and prism pose are available, and if their timestamps differ by less than
 * `max_time_diff_sec` seconds. Otherwise, the timer callback skips saving that frame.
 *
 * @version 1.0.0
 * @date 2025-09-20
 *
 * Maintainer: Boxiang (William) Fu  
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /flir_camera/image_raw : [sensor_msgs::msg::Image] Raw FLIR camera frames used as visual input.
 * - /total_station_prism   : [geometry_msgs::msg::PoseWithCovarianceStamped] Raw prism pose measurements in map frame.
 *
 * Publishers:
 * - None
 *
 * Parameters:
 * - hz_rate: [double] Frequency of the timer callback for saving samples (default: 10.0 Hz).
 * - output_dir: [string] Base directory where images and label files are stored (default: "/home").
 * - max_time_diff_sec: [double] Maximum allowable time difference (seconds) between image and pose (default: 1.0).
 * - mode: [string] Dataset mode; determines file naming (`train_*` or `eval_*`) (default: "train").
 *
 * Features:
 * - Ensures the output directory exists before saving.
 * - Sequentially names images with zero-padded counters.
 * - Appends dataset file lists and label files incrementally.
 * - Skips saving when no data is available or if image/pose timestamps are out of sync.
 */


#include "skycam/skycam_data_collection.hpp"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgcodecs.hpp>
#include <tf2/LinearMath/Matrix3x3.h>

using namespace std::chrono_literals;
 
namespace lr {
namespace skycam {

SkycamDataCollectionNode::SkycamDataCollectionNode() : Node("skycam_data_collection_node")
{
    // Parameters
    this->declare_parameter<double>("hz_rate", 10.0);
    hz_rate_ = this->get_parameter("hz_rate").as_double();

    this->declare_parameter<std::string>("output_dir", "/home");
    output_dir_ = this->get_parameter("output_dir").as_string();
    ensureOutputDir();

    this->declare_parameter<double>("max_time_diff_sec", 1.0);
    max_time_diff_sec_ = this->get_parameter("max_time_diff_sec").as_double();

    this->declare_parameter<std::string>("mode", "train");
    mode_ = this->get_parameter("mode").as_string();

    this->declare_parameter<bool>("zero_on_startup", true);
    zero_on_startup_ = this->get_parameter("zero_on_startup").as_bool();

    // Subscribers
    image_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/flir_camera/image_raw",
        rclcpp::SensorDataQoS(),
        std::bind(&SkycamDataCollectionNode::imageCallback, this, std::placeholders::_1));
  
    prism_pose_sub_ = this->create_subscription<geometry_msgs::msg::PoseWithCovarianceStamped>(
        "/total_station_prism",
        10,
        std::bind(&SkycamDataCollectionNode::prismPoseCallback, this, std::placeholders::_1));
    
    imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>(
        "/vectornav/imu",
        rclcpp::SensorDataQoS(),
        std::bind(&SkycamDataCollectionNode::imuCallback, this, std::placeholders::_1));

    // Publishers
    pose_vis_pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("/skycam/data_collection_pose", 10);
    
    // Save most recent collected data
    timer_ = this->create_wall_timer(
        std::chrono::duration<double>(1.0 / hz_rate_),
        std::bind(&SkycamDataCollectionNode::timerCallback, this));

    RCLCPP_INFO(
        this->get_logger(),
        "Skycam data collection node initialized with collection Hz rate: %.2f Hz\n"
        "Output directory: %s",
        hz_rate_,
        output_dir_.c_str());
}


void SkycamDataCollectionNode::ensureOutputDir()
{
    std::error_code ec;
    if (!std::filesystem::exists(output_dir_, ec))
    {
        std::filesystem::create_directories(output_dir_, ec);
        if (ec)
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to create output dir %s: %s",
                         output_dir_.c_str(), ec.message().c_str());
        }
    }
}


std::string SkycamDataCollectionNode::currentImageBasenameCounter() const
{
    std::ostringstream ss;
    ss << std::setw(4) << std::setfill('0') << image_counter_ << ".jpg";
    return ss.str();
}


std::string SkycamDataCollectionNode::currentImageBasenameHash() const
{
    static const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    static thread_local std::mt19937 rg{std::random_device{}()};
    static thread_local std::uniform_int_distribution<std::size_t> pick(0, sizeof(charset) - 2);

    std::string s;
    s.reserve(15);
    for (int i = 0; i < 15; i++) {
        s.push_back(charset[pick(rg)]);
    }
    return s + ".jpg";
}


void SkycamDataCollectionNode::advanceCounter()
{
    ++image_counter_;
}


void SkycamDataCollectionNode::imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(data_mutex_);
    latest_image_ = msg;
    last_image_time_ = this->get_clock()->now();
    // last_image_time_ = msg->header.stamp;
}


void SkycamDataCollectionNode::prismPoseCallback(const geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(data_mutex_);
    latest_prism_pose_ = msg;
    last_prism_pose_time_ = this->get_clock()->now();
    // last_prism_pose_time_ = msg->header.stamp;
}


void SkycamDataCollectionNode::imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg)
{
    std::lock_guard<std::mutex> lock(data_mutex_);
    latest_imu_ = msg;
    last_imu_time_ = this->get_clock()->now();
    // last_imu_time_ = msg->header.stamp;

    const auto &qmsg = msg->orientation;
    if (qmsg.w == 0.0 && qmsg.x == 0.0 && qmsg.y == 0.0 && qmsg.z == 0.0) {
        have_imu_ = false;
        return;
    }

    tf2::Quaternion q_cur(qmsg.x, qmsg.y, qmsg.z, qmsg.w);

    // Capture baseline once at startup
    if (zero_on_startup_ && !have_baseline_) {
        q_baseline_ = q_cur;
        have_baseline_ = true;
        RCLCPP_INFO(this->get_logger(), "Captured IMU baseline orientation.");
    }

    if (!have_baseline_) {
        have_imu_ = false;
        return;
    }

    // Compute relative quaternion
    tf2::Quaternion q_rel = q_baseline_.inverse() * q_cur;
    double r_rel, p_rel, y_rel;
    tf2::Matrix3x3(q_rel).getRPY(r_rel, p_rel, y_rel);
    latest_rel_rpy_ = {r_rel, p_rel, y_rel};
    have_imu_ = true;
}


void SkycamDataCollectionNode::timerCallback()
{
    sensor_msgs::msg::Image::SharedPtr image_msg;
    geometry_msgs::msg::PoseWithCovarianceStamped::SharedPtr pose_msg;
    std::array<double,3> rpy_copy{0.0, 0.0, 0.0};
    bool have_imu_copy = false;
    rclcpp::Time img_t, pose_t;

    // Guard against race conditions
    {
        std::lock_guard<std::mutex> lock(data_mutex_);
        image_msg = latest_image_;
        pose_msg  = latest_prism_pose_;
        img_t     = last_image_time_;
        pose_t    = last_prism_pose_time_;
        rpy_copy = latest_rel_rpy_;
        have_imu_copy = have_imu_;
    }

    if (!image_msg) {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                            "timerCallback: no image yet. Skipping save.");
        return;
    }
    if (!pose_msg) {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                            "timerCallback: no prism pose yet. Skipping save.");
        return;
    }

    rclcpp::Duration delta = (img_t > pose_t) ? (img_t - pose_t) : (pose_t - img_t);
    auto max_diff_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<double>(max_time_diff_sec_)).count();
    if (delta.nanoseconds() > max_diff_ns) {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 2000,
                             "timerCallback: image/pose are out of sync by %.3f s. Skipping save.",
                             static_cast<double>(delta.nanoseconds()) * 1e-9);
        return;
    }

    const std::string basename = currentImageBasenameHash();
    const std::filesystem::path image_path  = std::filesystem::path(output_dir_) / basename;
    const std::filesystem::path files_list  = std::filesystem::path(output_dir_) / (mode_ + "_files.txt");
    const std::filesystem::path labels_list = std::filesystem::path(output_dir_) / (mode_ + "_labels.txt");

    // Save image
    try
    {
        cv_bridge::CvImageConstPtr cv_ptr = cv_bridge::toCvShare(image_msg, "bgr8");
        if (!cv::imwrite(image_path.string(), cv_ptr->image))
        {
            RCLCPP_ERROR(this->get_logger(), "Failed to write image: %s", image_path.c_str());
            return;
        }
    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "Exception writing image: %s", e.what());
        return;
    }

    // Save to {train, eval}_files.txt
    try
    {
        std::ofstream ofs(files_list, std::ios::app);
        ofs << basename << "\n";
        ofs.flush();
    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to append %s: %s", files_list.c_str(), e.what());
    }

    // Save to {train, eval}_labels.txt
    try
    {
        const auto &p = pose_msg->pose.pose.position;
        const int64_t img_ns = img_t.nanoseconds();
        const int64_t pose_ns = pose_t.nanoseconds();

        double roll = std::numeric_limits<double>::quiet_NaN();
        double pitch = std::numeric_limits<double>::quiet_NaN();
        double yaw = std::numeric_limits<double>::quiet_NaN();
        if (have_imu_copy) {
            roll = rpy_copy[0];
            pitch = rpy_copy[1];
            yaw = rpy_copy[2];
        }

        std::ofstream ofs(labels_list, std::ios::app);
        ofs << std::fixed << std::setprecision(6)
            << p.x << " " << p.y << " " << p.z << " "
            << img_ns << " " << pose_ns << " "
            << roll << " " << pitch << " " << yaw << "\n";
        ofs.flush();

        // Publish to topic for debugging
        geometry_msgs::msg::PoseWithCovarianceStamped vis;
        vis.header.stamp = this->get_clock()->now();
        vis.header.frame_id = pose_msg->header.frame_id;
        vis.pose.pose.position = p;

        if (have_imu_copy) {
            tf2::Quaternion q; q.setRPY(rpy_copy[0], rpy_copy[1], rpy_copy[2]);
            vis.pose.pose.orientation.x = q.x();
            vis.pose.pose.orientation.y = q.y();
            vis.pose.pose.orientation.z = q.z();
            vis.pose.pose.orientation.w = q.w();
        } else {
            vis.pose.pose.orientation.x = 0.0;
            vis.pose.pose.orientation.y = 0.0;
            vis.pose.pose.orientation.z = 0.0;
            vis.pose.pose.orientation.w = 1.0;
        }

        pose_vis_pub_->publish(vis);

    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to append %s: %s", labels_list.c_str(), e.what());
    }

    advanceCounter();

    RCLCPP_INFO(this->get_logger(), "Saved %s", image_path.c_str());
}


inline std::array<double,3>SkycamDataCollectionNode::quatToRPY(double x, double y, double z, double w)
{
    tf2::Quaternion q;
    q.setX(x); q.setY(y); q.setZ(z); q.setW(w);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    return {roll, pitch, yaw};
}

} // namespace skycam
} // namespace lr