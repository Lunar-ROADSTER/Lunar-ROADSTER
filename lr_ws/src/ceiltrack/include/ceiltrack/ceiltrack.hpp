#ifndef CEILTRACK_H
#define CEILTRACK_H

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/bool.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "geometry_msgs/msg/pose2_d.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include "visualization_msgs/msg/image_marker.hpp"
#include "ceiltrack/fisheye.hpp"

#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/matx.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgcodecs/legacy/constants_c.h>

#include <cstdint>
#include <utility>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <atomic>
#include <mutex>


namespace lr{
namespace ceiltrack{

class CeiltrackNode : public rclcpp::Node
{
    private:
        // Subscribers
        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr img_sub_;
        rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr set_home_sub_;
        rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;

        // Publishers
        rclcpp::Publisher<geometry_msgs::msg::Pose2D>::SharedPtr pose_camera_pub_;
        rclcpp::Publisher<geometry_msgs::msg::PoseWithCovarianceStamped>::SharedPtr pose_world_pub_;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_marker_pub_;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr deoriented_image_pub_;

        // Functions
        void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);
        void setHomeCallback(const std_msgs::msg::Bool::SharedPtr msg);
        void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg);

        // Variables
        FisheyeLens lens_;
        bool tracker_ready_;

        // Parameters
        double cam_tilt_rad_;
        double xgrid_m_;
        double ygrid_m_;
        double xgrid_;
        double ygrid_;
        double ceil_height_;
        int threshold_;
        int niter_;
        bool publish_grid_;

        int width_;
        int height_;
        double center_limit_;
        double ceil_limit_;

        double home_x_;
        double home_y_;
        double home_theta_;
        double home_x_init_;
        double home_y_init_;
        double home_theta_init_;
        std::atomic<bool> have_home_ref_{false};

        float* uvmap_{nullptr};
        int uvmaplen_{0};
        uint16_t* mask_rle_{nullptr};
        int mask_rlelen_{0};

        float xytheta_[3] = {0.f, 0.f, 0.f};

        // IMU orientation
        std::mutex imu_mutex_;
        bool have_imu_{false};
        tf2::Quaternion imu_q_;

        // Camera distortion model
        cv::Matx33d K_; // Intrinsic matrix
        cv::Vec4d D_; // Distortion coefficients
        bool cv_model_ready_{false};
        cv::Mat deoriented_img_;

        // Helper functions
        struct RLEMask;

        inline float moddist(float x, float q, float ooq);
    
        bool ceiltrackInit(const FisheyeLens& lens, float cam_tilt_rad);

        float ceiltrackUpdate(const uint8_t* img, uint8_t thresh,
                            float xgrid, float ygrid,
                            float* xytheta, int niter);

        void ceiltrackGetMatchedGrid(const FisheyeLens& lens, const float* xytheta,
                                    float xgrid, float ygrid,
                                    std::vector<std::pair<float,float>>& out);

        void ceiltrackShutdown();

        inline static double wrapAngle(double a) {
            return std::atan2(std::sin(a), std::cos(a));
        }

        void deorientImage(const sensor_msgs::msg::Image::SharedPtr msg);

    public:
        // Constructor and destructor
        CeiltrackNode();
        ~CeiltrackNode() override { ceiltrackShutdown(); }
};  

} // namespace ceiltrack
} // namespace lr
#endif