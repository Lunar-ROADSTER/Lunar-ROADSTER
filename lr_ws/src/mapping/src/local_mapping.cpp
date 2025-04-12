/* Author: Boxiang Fu
 * Publishers:
 * - TODO
 * Services:
 * - TODO
 *
 * - Summary
 * - TODO
 * */


#include "mapping/local_mapping.hpp"

#define GETMAXINDEX(x, y, width) ((y) * (width) + (x))

WorldModel::WorldModel() : Node("local_mapping_node")
{   

    // Setup Communications
    setupCommunications();

    // Setup map
    configureMaps();

    RCLCPP_INFO(this->get_logger(), "Local mapping initialized");
}

// Setup
void WorldModel::setupCommunications(){
    // QoS
    rclcpp::QoS qos(10);
    qos.transient_local();
    qos.reliable(); 
    qos.keep_last(1);

    // Publishers
    local_map_publisher_ = this->create_publisher<nav_msgs::msg::OccupancyGrid>("mapping/local_map", qos);
    filtered_local_map_publisher_ = this->create_publisher<nav_msgs::msg::OccupancyGrid>("mapping/filtered_local_map", qos);

    // Subscribers
    transformed_pcl_subscriber_ = this->create_subscription<sensor_msgs::msg::PointCloud2>("mapping/transformed_pointcloud", 10, 
                                                                                std::bind(&WorldModel::transformedPCLCallback, this, std::placeholders::_1));

    // Transform Listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // Timers
    timer_local_map_ = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&WorldModel::publishLocalMap, this));
}

void WorldModel::configureMaps(){

    // Configuring occupancy grid
    this->local_map_.header.frame_id = "base_link";
    this->local_map_.info.resolution = MAP_RESOLUTION;
    this->local_map_.info.width = MAP_DIMENSION/MAP_RESOLUTION;
    this->local_map_.info.height = MAP_DIMENSION/MAP_RESOLUTION;
    this->local_map_.info.origin.position.x = 0.0;
    this->local_map_.info.origin.position.y = -1.0;

    filtered_local_map_.header.frame_id = "base_link";
    filtered_local_map_.info = local_map_.info;

    // Initialize bayes filter
    for(size_t i = 0; i < local_map_.info.width*local_map_.info.height; i++){
        BayesFilter bf;
        bayes_filter_.push_back(bf);
    }

    // Initialize occupancy grid
    this->local_map_.data.resize(local_map_.info.width*local_map_.info.height);
    this->filtered_local_map_.data.resize(local_map_.info.width*local_map_.info.height);
    for(size_t i = 0; i < this->local_map_.info.width*this->local_map_.info.height; i++){
        this->local_map_.data[i] = 0;
        this->filtered_local_map_.data[i] = 0;
    }
}

void WorldModel::resetMaps(){

    for(size_t i = 0; i < this->local_map_.info.width*this->local_map_.info.height; i++){
        this->local_map_.data[i] = 0;
        this->filtered_local_map_.data[i] = 0;
    }
}


// Pointcloud callback
void WorldModel::transformedPCLCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg){
    auto msg_copy = std::make_shared<sensor_msgs::msg::PointCloud2>(*msg);
    fuse_map_thread_ = std::thread(std::bind(&WorldModel::fuseMap, this, msg_copy));

    // Have to detach thread before it goes out of scope
    fuse_map_thread_.detach();
}

void WorldModel::fuseMap(const sensor_msgs::msg::PointCloud2::SharedPtr msg)  {

    // Reset map
    configureMaps();

    pcl::PointCloud<pcl::PointXYZ>::Ptr cropped_cloud_local_map(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*msg, *cropped_cloud_local_map);

    std::vector<double> elevation_values(local_map_.info.width*local_map_.info.height, 0.0);
    std::vector<double> density_values(local_map_.info.width*local_map_.info.height, 0.0);

    for(size_t i = 0; i < cropped_cloud_local_map->points.size(); i++){
        int col_x =  int(cropped_cloud_local_map->points[i].x / local_map_.info.resolution );
        double offset_y = 1.0;
        int row_y = int((cropped_cloud_local_map->points[i].y + offset_y) / local_map_.info.resolution );

        col_x = std::min(std::max(col_x, 0), int(local_map_.info.width-1));
        row_y = std::min(std::max(row_y, 0), int(local_map_.info.height-1));

        int local_idx = col_x + row_y*local_map_.info.width;
        double elev = cropped_cloud_local_map->points[i].z;
        elevation_values[local_idx] += ELEVATION_SCALE*(elev);
        density_values[local_idx] += 1.0;
    }

    for(size_t i = 0; i < local_map_.info.width*local_map_.info.height; i++){
        if(density_values[i] > 1.0){
            local_map_.data[i] = int(elevation_values[i]/density_values[i]);
            filtered_local_map_.data[i] = int(elevation_values[i]/density_values[i]);
        }
    }
    
    filterMap();
}

void WorldModel::filterMap(){
    double gradient = ELEVATION_SCALE/0.866;
    // use globalmap to update bayes filter and then update filtered global map
    for(size_t i = 0; i < local_map_.info.width*local_map_.info.height; i++){
        if(local_map_.data[i] == 0){
            continue;
        }
        // RCLCPP_INFO(this->get_logger(), "Bayes Filter initialized5");
        if(abs(filtered_local_map_.data[i] - local_map_.data[i]) > gradient){
            bayes_filter_[i].updateCell(local_map_.data[i], 10.0);
            filtered_local_map_.data[i] = int(bayes_filter_[i].getCellElevation());
        }

        // double 
        // update cell of neighbours
        int neighbour_deltas[8] = {-1, 1, -(int)local_map_.info.width, (int)local_map_.info.width, -(int)local_map_.info.width-1, -(int)local_map_.info.width+1, (int)local_map_.info.width-1, (int)local_map_.info.width+1};
        // only 4 neighbours
        // int neighbour_deltas[4] = {-1, 1, -local_map_.info.width, local_map_.info.width};
        for(size_t j=0;j<4;j++){
            size_t neighbour_idx = i+neighbour_deltas[j];
            if(neighbour_idx > local_map_.info.width*local_map_.info.height){
                continue;
            }
            // else if(filtered_local_map_.data[neighbour_idx] == 0){
            //     continue;
            // }   
            if(abs(filtered_local_map_.data[i] - filtered_local_map_.data[neighbour_idx]) <= gradient){
                continue;
            }
            // else if(local_map_.data[i] > local_map_.data[neighbour_idx]){
            else if(filtered_local_map_.data[i] > filtered_local_map_.data[neighbour_idx]){
                bayes_filter_[neighbour_idx].updateCell(filtered_local_map_.data[i] - gradient, 10000.0);
                filtered_local_map_.data[neighbour_idx] = int(bayes_filter_[neighbour_idx].getCellElevation());
            }
            // // // else if(local_map_.data[i] < local_map_.data[neighbour_idx]){
            else if(filtered_local_map_.data[i] < filtered_local_map_.data[neighbour_idx]){
                bayes_filter_[neighbour_idx].updateCell(filtered_local_map_.data[i] + gradient, 10000.0);
                filtered_local_map_.data[neighbour_idx] = int(bayes_filter_[neighbour_idx].getCellElevation());
            }
        }
    }
}


// Map publishers
void WorldModel::publishLocalMap(){
    // local_map_publisher_->publish(local_map_);
    filtered_local_map_publisher_->publish(filtered_local_map_);
}