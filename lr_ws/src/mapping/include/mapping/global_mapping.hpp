#ifndef GLOBAL_MAPPING_H
#define GLOBAL_MAPPING_H

#include "rclcpp/rclcpp.hpp"
#include "bayes_filter.hpp"
#include "init_map.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/common/transforms.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <tf2_ros/buffer.h>
#include <tf2_sensor_msgs/tf2_sensor_msgs.hpp>
#include <thread>
#include <vector>

class WorldModel : public rclcpp::Node
{
    private:
        // Variables & pointers -----------------
        bool initFuse;
        const double MAP_DIMENSION = 7.0;
        const double MAP_RESOLUTION = 0.05;
        const double ELEVATION_SCALE = 400;
        nav_msgs::msg::OccupancyGrid global_map_, 
                                     filtered_global_map_;

        // Bayes Filter
        std::vector<BayesFilter> bayes_filter_;
        // Transforms
        std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
        std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

        // Subscribers
        std::thread fuse_map_thread_;
        rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr transformed_pcl_subscriber_;
        // Publishers
        rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr global_map_publisher_;
        rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr filtered_global_map_publisher_;

        // Wall Timer
        rclcpp::TimerBase::SharedPtr timer_global_map_;

        // --------------------------------------

        // Functions ----------------------------
        /*
        * Set up subscribers and publishers of the node
        * */
        void setupCommunications();

        /*
        *
        * */

        pcl::PointCloud<pcl::PointXYZ>::Ptr transformMap(const sensor_msgs::msg::PointCloud2::SharedPtr);

        /*
        *
        */
        void configureMaps();

        /*
        *
        * */
        void transformedPCLCallback(const sensor_msgs::msg::PointCloud2::SharedPtr );

        /*
        *
        * */

        void fuseMap(const sensor_msgs::msg::PointCloud2::SharedPtr );

        /*
        *
        * */

        void filterMap();
        /*
        *
        */

        void publishGlobalMap();
        /*
        *
        */

        void saveGlobalMapCSV();

    public:
        // Functions
        /*
        * Constructor
        * */
        WorldModel();

        /*
        * Destructor
        * */
        ~WorldModel(){};
};  

#endif