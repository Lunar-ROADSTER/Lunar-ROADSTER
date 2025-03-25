#ifndef PC_HANDLER_H
#define PC_HANDLER_H

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "std_msgs/msg/float64.hpp"
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_sensor_msgs/tf2_sensor_msgs.hpp>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/crop_box.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/common/transforms.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/passthrough.h>

class ExpFilter{
    public:
        double DECAY_RATE;
        double prev_output;
        int itr = 0;
        ExpFilter(double decay_rate = 0.9)
        {
            this->DECAY_RATE = decay_rate;
            this->prev_output = 0.0;
        }
        double getValue(double input)
        {
            if(itr==0)
            {
                this->prev_output = input;
                itr++;
            }
            else
            {
                this->prev_output = this->DECAY_RATE*this->prev_output + (1-this->DECAY_RATE)*input;
            }
            return this->prev_output;
        }
};

class PointCloudHandler : public rclcpp::Node
{
    private:
        // Variables & pointers -----------------
        const double MAP_DIMENSION = 8.0;
        const double MAP_RESOLUTION = 0.05;
        const bool debug_mode_ = false;
        bool need_ground_height_ = false;
        geometry_msgs::msg::TransformStamped cam2map_transform;
        // Transforms
        std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;
        // Subscribers
        std::thread pointcloud_thread_;
        rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr pointcloud_subscriber_;
        // Publishers
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr transformed_pointcloud_publisher_;
        rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr ground_height_publisher_;
        rclcpp::Publisher<sensor_msgs::msg::PointCloud2>::SharedPtr ground_pointcloud_publisher_;

        ExpFilter exp_height_filter_;

        //
        // --------------------------------------

        // Functions ----------------------------
        /*
        * Set up subscribers and publishers of the node
        * */
        void setupCommunications();

        /*
        *
        * */
        void pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr );

        /*
        *
        * */
        void processPointCloud(const sensor_msgs::msg::PointCloud2::SharedPtr );

    public:
        // Functions
        /*
        * Constructor
        * */
        PointCloudHandler();

        /*
        * Destructor
        * */
        ~PointCloudHandler(){};
};

#endif