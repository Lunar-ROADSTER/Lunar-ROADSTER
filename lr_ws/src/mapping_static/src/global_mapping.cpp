/* Author: Boxiang Fu
 * Publishers:
 * - TODO
 * Services:
 * - TODO
 *
 * - Summary
 * - TODO
 * */


#include "mapping/global_mapping.hpp"

#define GETMAXINDEX(x, y, width) ((y) * (width) + (x))

WorldModel::WorldModel() : Node("global_mapping_node")
{   

    // Setup Communications
    setupCommunications();

    // Setup Maps
    configureMaps();

    RCLCPP_INFO(this->get_logger(), "Global mapping initialized");
}

// Setup
void WorldModel::setupCommunications(){
    // QoS
    rclcpp::QoS qos(10);
    qos.transient_local();
    qos.reliable(); 
    qos.keep_last(1);

    // Publishers
    global_map_publisher_ = this->create_publisher<nav_msgs::msg::OccupancyGrid>("mapping/global_map", qos);
    filtered_global_map_publisher_ = this->create_publisher<nav_msgs::msg::OccupancyGrid>("mapping/filtered_global_map", qos);

    // Transform Listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // Timers
    timer_global_map_ = this->create_wall_timer(std::chrono::milliseconds(10000), std::bind(&WorldModel::publishGlobalMap, this));
}

void WorldModel::configureMaps(){
    // Configuring occupancy grid

    this->global_map_.header.frame_id = "map";
    this->global_map_.info.resolution = MAP_RESOLUTION;
    this->global_map_.info.width = MAP_DIMENSION/MAP_RESOLUTION;
    this->global_map_.info.height = MAP_DIMENSION/MAP_RESOLUTION;
    this->global_map_.info.origin.position.x = 0.0;
    this->global_map_.info.origin.position.y = 0.0;

    filtered_global_map_.header.frame_id = "map";
    filtered_global_map_.info = global_map_.info;

    // Initialize bayes filter
    for(size_t i = 0; i < global_map_.info.width*global_map_.info.height; i++){
        BayesFilter bf;
        bayes_filter_.push_back(bf);
    }

    // Initialize occupancy grid
    this->global_map_.data.resize(global_map_.info.width*global_map_.info.height);
    this->filtered_global_map_.data.resize(global_map_.info.width*global_map_.info.height);
    for(size_t i = 0; i < this->global_map_.info.width*this->global_map_.info.height; i++){
        this->global_map_.data[i] = 0;
        this->filtered_global_map_.data[i] = 0;
    }

    // Preload saved map if it exists
    RCLCPP_INFO(this->get_logger(), "Loading map...");
    auto map_msg = lr::mapping::getMapFromPCD();
    RCLCPP_INFO(this->get_logger(), "Map loaded");
    if (map_msg) {
        transformedPCLCallback(map_msg);
        RCLCPP_INFO(this->get_logger(), "Map preload successful");
    } else {
        RCLCPP_ERROR(this->get_logger(), "Map preload failed");
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

    pcl::PointCloud<pcl::PointXYZ>::Ptr cropped_cloud_local_map(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*msg, *cropped_cloud_local_map);

    std::vector<double> elevation_values(global_map_.info.width*global_map_.info.height, 0.0);
    std::vector<double> density_values(global_map_.info.width*global_map_.info.height, 0.0);

    for(size_t i = 0; i < cropped_cloud_local_map->points.size(); i++){
        int col_x =  int(cropped_cloud_local_map->points[i].x / global_map_.info.resolution );
        int row_y =  int(cropped_cloud_local_map->points[i].y / global_map_.info.resolution );

        col_x = std::min(std::max(col_x, 0), int(global_map_.info.width-1));
        row_y = std::min(std::max(row_y, 0), int(global_map_.info.height-1));

        int global_idx = col_x + row_y*global_map_.info.width;
        double elev = cropped_cloud_local_map->points[i].z;
        elevation_values[global_idx] += ELEVATION_SCALE*(elev);
        density_values[global_idx] += 1.0;
    }

    for(size_t i = 0; i < global_map_.info.width*global_map_.info.height; i++){
        if(density_values[i] > 1.0){
            global_map_.data[i] = int(elevation_values[i]/density_values[i]);
            filtered_global_map_.data[i] = int(elevation_values[i]/density_values[i]);
        }
    }
    
    filterMap();
}

void WorldModel::saveGlobalMapCSV() {
    std::string csv_filename = std::string(MAPPING_SOURCE_DIR) + "/mapping_util/filtered_global_map.csv";
    std::ofstream csv_file(csv_filename);

    if (csv_file.is_open()) {
        for (size_t y = 0; y < filtered_global_map_.info.height; ++y) {
            for (size_t x = 0; x < filtered_global_map_.info.width; ++x) {
                size_t idx = x + y * filtered_global_map_.info.width;
                csv_file << static_cast<int>(filtered_global_map_.data[idx]);
                if (x < filtered_global_map_.info.width - 1) {
                    csv_file << ",";
                }
            }
            csv_file << "\n";
        }
        csv_file.close();
        RCLCPP_INFO(this->get_logger(), "Filtered elevation map saved to %s", csv_filename.c_str());
    } else {
        RCLCPP_WARN(this->get_logger(), "Failed to open file for CSV export");
    }
}

void WorldModel::filterMap(){
    double gradient = ELEVATION_SCALE/0.866;
    // use globalmap to update bayes filter and then update filtered global map
    for(size_t i = 0; i < global_map_.info.width*global_map_.info.height; i++){
        if(global_map_.data[i] == 0){
            continue;
        }
        // RCLCPP_INFO(this->get_logger(), "Bayes Filter initialized5");
        if(abs(filtered_global_map_.data[i] - global_map_.data[i]) > gradient){
            bayes_filter_[i].updateCell(global_map_.data[i], 10.0);
            filtered_global_map_.data[i] = int(bayes_filter_[i].getCellElevation());
        }

        // double 
        // update cell of neighbours
        int neighbour_deltas[8] = {-1, 1, -(int)global_map_.info.width, (int)global_map_.info.width, -(int)global_map_.info.width-1, -(int)global_map_.info.width+1, (int)global_map_.info.width-1, (int)global_map_.info.width+1};
        // only 4 neighbours
        // int neighbour_deltas[4] = {-1, 1, -global_map_.info.width, global_map_.info.width};
        for(size_t j=0;j<4;j++){
            size_t neighbour_idx = i+neighbour_deltas[j];
            if(neighbour_idx > global_map_.info.width*global_map_.info.height){
                continue;
            }
            // else if(filtered_global_map_.data[neighbour_idx] == 0){
            //     continue;
            // }   
            if(abs(filtered_global_map_.data[i] - filtered_global_map_.data[neighbour_idx]) <= gradient){
                continue;
            }
            // else if(global_map_.data[i] > global_map_.data[neighbour_idx]){
            else if(filtered_global_map_.data[i] > filtered_global_map_.data[neighbour_idx]){
                bayes_filter_[neighbour_idx].updateCell(filtered_global_map_.data[i] - gradient, 10000.0);
                filtered_global_map_.data[neighbour_idx] = int(bayes_filter_[neighbour_idx].getCellElevation());
            }
            // // // else if(global_map_.data[i] < global_map_.data[neighbour_idx]){
            else if(filtered_global_map_.data[i] < filtered_global_map_.data[neighbour_idx]){
                bayes_filter_[neighbour_idx].updateCell(filtered_global_map_.data[i] + gradient, 10000.0);
                filtered_global_map_.data[neighbour_idx] = int(bayes_filter_[neighbour_idx].getCellElevation());
            }
        }
    }
}


// Map publishers
void WorldModel::publishGlobalMap(){
    // global_map_publisher_->publish(global_map_);
    filtered_global_map_publisher_->publish(filtered_global_map_);
}