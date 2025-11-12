/**
 * @file pc_handler.cpp
 * @brief Processes raw camera point clouds, transforms them to the `base_link` frame, filters noise, crops to a region of interest, and republishes the transformed cloud.
 *
 * This node subscribes to the depth camera's `PointCloud2` topic, applies statistical outlier removal,
 * transforms the point cloud from the camera frame to `base_link` using TF, optionally performs plane
 * segmentation for debugging, crops the cloud to a fixed bounding box, and publishes the processed point cloud.
 * Ground height estimation logic is implemented but currently commented out.
 *
 * @version 1.0.1
 * @date 2025-11-01
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /zed/zed_node/point_cloud/cloud_registered: [sensor_msgs::msg::PointCloud2] Raw depth camera point cloud.
 *
 * Publishers:
 * - /sensing/transformed_pointcloud: [sensor_msgs::msg::PointCloud2] Noise-filtered, cropped, and transformed point cloud in the `base_link` frame.
 * - /sensing/pcl_ground_height: [std_msgs::msg::Float64] Estimated ground height in meters (currently commented out).
 * - /sensing/ground_pointcloud: [sensor_msgs::msg::PointCloud2] Cropped ground points (currently published only in debug mode).
 *
 * Services:
 * - None
 *
 * Parameters:
 * - debug_mode_: [bool] If true, runs plane segmentation to print model coefficients and optionally publishes ground cloud.
 *
 * Notes:
 * - Uses `tf2_ros::Buffer` and `tf2_ros::TransformListener` to retrieve the transform from `camera_depth_optical_frame` to `base_link`.
 * - Applies `pcl::StatisticalOutlierRemoval` to filter noise from the raw point cloud.
 * - Applies transformation using Eigen affine matrices constructed from TF rotation and translation.
 * - Crops cloud using `pcl::CropBox` to keep points within a large bounding volume (-1000 m to +1000 m in X/Y, -20 m to +20 m in Z).
 * - Ground height estimation is implemented but disabled by default; it crops a smaller box and averages Z values.
 * - Publishes processed cloud in `base_link` frame.
 */

#include "sensing/pc_handler.hpp"

PointCloudHandler::PointCloudHandler() : Node("pc_handler_node")
{
    // Setup Communications
    setupCommunications();

    RCLCPP_INFO(this->get_logger(), "Point Cloud Handler initialized");
}

void PointCloudHandler::setupCommunications()
{
    auto qos = rclcpp::SensorDataQoS();

    // Subscribers
    pointcloud_subscriber_ = this->create_subscription<sensor_msgs::msg::PointCloud2>("zed/zed_node/point_cloud/cloud_registered", qos,
                                                                                      std::bind(&PointCloudHandler::processPointCloud, this, std::placeholders::_1));
    // Publishers
    transformed_pointcloud_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("sensing/transformed_pointcloud", qos);
    ground_height_publisher_ = this->create_publisher<std_msgs::msg::Float64>("sensing/pcl_ground_height", qos);
    ground_pointcloud_publisher_ = this->create_publisher<sensor_msgs::msg::PointCloud2>("sensing/ground_pointcloud", qos);

    // Transform Listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock(), tf2::durationFromSec(10));
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);
}

void PointCloudHandler::pointCloudCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
    pointcloud_thread_ = std::thread(std::bind(&PointCloudHandler::processPointCloud, this, msg));

    pointcloud_thread_.detach();
}

void PointCloudHandler::processPointCloud(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
    if (this->cam2map_transform.header.frame_id == "")
    {
        // Lookup the transform from the sensor frame to the target frame
        try
        {
            cam2map_transform = tf_buffer_->lookupTransform("base_link", "zed_camera_link", tf2::TimePointZero, tf2::durationFromSec(1));
            RCLCPP_INFO(this->get_logger(), "Transform found");
        }
        catch (tf2::TransformException &ex)
        {
            RCLCPP_INFO(this->get_logger(), "Waiting for transform... %s", ex.what());
            return;
        }
    }

    // DEBUGGER
    // RCLCPP_INFO(this->get_logger(), "Transform Translation:");
    // RCLCPP_INFO(this->get_logger(), "  x: %.6f", cam2map_transform.transform.translation.x);
    // RCLCPP_INFO(this->get_logger(), "  y: %.6f", cam2map_transform.transform.translation.y);
    // RCLCPP_INFO(this->get_logger(), "  z: %.6f", cam2map_transform.transform.translation.z);

    // RCLCPP_INFO(this->get_logger(), "Transform Rotation (quaternion):");
    // RCLCPP_INFO(this->get_logger(), "  x: %.6f", cam2map_transform.transform.rotation.x);
    // RCLCPP_INFO(this->get_logger(), "  y: %.6f", cam2map_transform.transform.rotation.y);
    // RCLCPP_INFO(this->get_logger(), "  z: %.6f", cam2map_transform.transform.rotation.z);
    // RCLCPP_INFO(this->get_logger(), "  w: %.6f", cam2map_transform.transform.rotation.w);

    // convert x,y,z,w to roll, pitch, yaw
    tf2::Quaternion q(cam2map_transform.transform.rotation.x, cam2map_transform.transform.rotation.y, cam2map_transform.transform.rotation.z, cam2map_transform.transform.rotation.w);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*msg, *cloud);

    // remove noise from the point cloud
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud(cloud);
    sor.setMeanK(50);
    sor.setStddevMulThresh(1.0);
    sor.filter(*cloud_filtered);

    Eigen::Affine3f affine_transform = Eigen::Affine3f::Identity();
    affine_transform.rotate(Eigen::AngleAxisf(yaw, Eigen::Vector3f::UnitZ()));
    affine_transform.rotate(Eigen::AngleAxisf(pitch, Eigen::Vector3f::UnitY()));
    affine_transform.rotate(Eigen::AngleAxisf(roll, Eigen::Vector3f::UnitX()));
    affine_transform.translation() << cam2map_transform.transform.translation.x, cam2map_transform.transform.translation.y, cam2map_transform.transform.translation.z;

    pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud(new pcl::PointCloud<pcl::PointXYZ>());
    pcl::transformPointCloud(*cloud_filtered, *transformed_cloud, affine_transform);

    if (debug_mode_)
    {
        // find the best fit plane
        pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
        pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
        // find coefficients
        pcl::SACSegmentation<pcl::PointXYZ> seg;
        seg.setOptimizeCoefficients(true);
        seg.setModelType(pcl::SACMODEL_PLANE);
        seg.setMethodType(pcl::SAC_RANSAC);
        seg.setDistanceThreshold(0.01);
        seg.setInputCloud(transformed_cloud);
        seg.segment(*inliers, *coefficients);

        RCLCPP_INFO(this->get_logger(), "Model coefficients: %f %f %f %f", coefficients->values[0], coefficients->values[1], coefficients->values[2], coefficients->values[3]);
    }

    // crop the point cloud to the desired region
    pcl::PointCloud<pcl::PointXYZ>::Ptr result_cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::CropBox<pcl::PointXYZ> cropFilter;
    cropFilter.setInputCloud(transformed_cloud);
    cropFilter.setMax(Eigen::Vector4f(1000, 1000, 20.0, 1.0));
    cropFilter.setMin(Eigen::Vector4f(-1000, -1000, -20.0, 1.0));
    cropFilter.filter(*result_cloud);

    // // determine the ground height of a cropped region
    // // crop the point cloud to the desired region
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cropped_cloud_ground (new pcl::PointCloud<pcl::PointXYZ>);
    // pcl::CropBox<pcl::PointXYZ> cropFilterGround;
    // cropFilterGround.setInputCloud(result_cloud);
    // cropFilterGround.setMax(Eigen::Vector4f(1.0, 0.2, 1000, 1.0));
    // cropFilterGround.setMin(Eigen::Vector4f(0.7, -0.2, -1000, 1.0));
    // cropFilterGround.filter(*cropped_cloud_ground);

    // // get average z value of cropped point cloud and publish it
    // double avg_z = 0.0;
    // if (cropped_cloud_ground->points.size() != 0)
    // {
    //     for(size_t i=0; i<cropped_cloud_ground->points.size(); i++){
    //         avg_z += cropped_cloud_ground->points[i].z;
    //     }
    //     avg_z /= cropped_cloud_ground->points.size();
    // }
    // std_msgs::msg::Float64 avg_z_msg;
    // avg_z_msg.data = exp_height_filter_.getValue(avg_z);
    // ground_height_publisher_->publish(avg_z_msg);
    // // publish the pointcloud if debug mode is on
    // if (debug_mode_)
    // {
    //     sensor_msgs::msg::PointCloud2 cropped_cloud_msg;
    //     pcl::toROSMsg(*cropped_cloud_ground, cropped_cloud_msg);
    //     cropped_cloud_msg.header.frame_id = "base_link";
    //     ground_pointcloud_publisher_->publish(cropped_cloud_msg);
    // }

    sensor_msgs::msg::PointCloud2 result_msg;
    pcl::toROSMsg(*result_cloud, result_msg);
    result_msg.header.frame_id = "base_link";
    transformed_pointcloud_publisher_->publish(result_msg);
}