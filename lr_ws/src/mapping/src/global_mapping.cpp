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
    initFuse = true;

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

    // Subscribers
    transformed_pcl_subscriber_ = this->create_subscription<sensor_msgs::msg::PointCloud2>("mapping/transformed_pointcloud", 10, 
                                                                                std::bind(&WorldModel::transformedPCLCallback, this, std::placeholders::_1));

    // Transform Listener
    tf_buffer_ = std::make_shared<tf2_ros::Buffer>(this->get_clock());
    tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

    // Timers
    timer_global_map_ = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&WorldModel::publishGlobalMap, this));
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
    if (initFuse) {
        pcl::fromROSMsg(*msg, *cropped_cloud_local_map);
    }
    else {
        try
        {
            cropped_cloud_local_map = transformMap(msg);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return;
        }
    }

    std::vector<double> elevation_values(global_map_.info.width*global_map_.info.height, 0.0);
    std::vector<double> density_values(global_map_.info.width*global_map_.info.height, 0.0);

    for(size_t i = 0; i < cropped_cloud_local_map->points.size(); i++){
        int col_x = int(cropped_cloud_local_map->points[i].x / global_map_.info.resolution );
        int row_y = int(cropped_cloud_local_map->points[i].y / global_map_.info.resolution );

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

    if (initFuse) {
        initFuse = false;
        RCLCPP_INFO(this->get_logger(), "Initial elevation map fuse successful");
        saveGlobalMapCSV();
    }
}

void WorldModel::saveGlobalMapCSV() {
    std::string csv_filename = std::string(MAPPING_SOURCE_DIR) + "/saved_maps/filtered_global_map.csv";
    std::ofstream csv_file(csv_filename);

    if (csv_file.is_open()) {
        // Save the filtered global map
        // for (size_t y = 0; y < filtered_global_map_.info.height; ++y) {
        //     for (size_t x = 0; x < filtered_global_map_.info.width; ++x) {
        //         size_t idx = x + y * filtered_global_map_.info.width;
        //         csv_file << static_cast<int>(filtered_global_map_.data[idx]);
        //         if (x < filtered_global_map_.info.width - 1) {
        //             csv_file << ",";
        //         }
        //     }
        //     csv_file << "\n";
        // }

        // Save the unfiltered global map
        for (size_t y = 0; y < global_map_.info.height; ++y) {
            for (size_t x = 0; x < global_map_.info.width; ++x) {
                size_t idx = x + y * global_map_.info.width;
                csv_file << static_cast<int>(global_map_.data[idx]);
                if (x < global_map_.info.width - 1) {
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

pcl::PointCloud<pcl::PointXYZ>::Ptr WorldModel::transformMap(const sensor_msgs::msg::PointCloud2::SharedPtr msg)  {
    
    geometry_msgs::msg::TransformStamped base2map_transform;
    try
    {
      base2map_transform = tf_buffer_->lookupTransform("map","base_link",tf2::TimePointZero, tf2::durationFromSec(10));
    }
    catch (tf2::TransformException& ex)
    {
        RCLCPP_WARN(this->get_logger(), "Failed to lookup transform: %s", ex.what());

        return nullptr;
    }

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*msg, *cloud);

    // convert x,y,z,w to roll, pitch, yaw
    tf2::Quaternion q(base2map_transform.transform.rotation.x, base2map_transform.transform.rotation.y, base2map_transform.transform.rotation.z, base2map_transform.transform.rotation.w);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    // RCLCPP_INFO(this->get_logger(), "roll: %f, pitch: %f, yaw: %f", roll, pitch, yaw);

    Eigen::Affine3f afine_transform = Eigen::Affine3f::Identity();
    afine_transform.translation() << base2map_transform.transform.translation.x, base2map_transform.transform.translation.y, base2map_transform.transform.translation.z;
    afine_transform.rotate(Eigen::AngleAxisf(yaw, Eigen::Vector3f::UnitZ()));
    afine_transform.rotate(Eigen::AngleAxisf(pitch, Eigen::Vector3f::UnitY()));
    afine_transform.rotate(Eigen::AngleAxisf(roll, Eigen::Vector3f::UnitX()));

    pcl::PointCloud<pcl::PointXYZ>::Ptr transformed_cloud (new pcl::PointCloud<pcl::PointXYZ> ());
    pcl::transformPointCloud(*cloud, *transformed_cloud, afine_transform);

    return transformed_cloud;
}

void WorldModel::filterMap(){
    double gradient = ELEVATION_SCALE/0.866;
    // use globalmap to update bayes filter and then update filtered global map
    for(size_t i = 0; i < global_map_.info.width*global_map_.info.height; i++){
        if(global_map_.data[i] == 0){
            continue;
        }
        // RCLCPP_INFO(this->get_logger(), "Bayes Filter initialized");
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