/**
 * @file global_mapping.cpp
 * @brief Builds and maintains a global elevation occupancy map from pointcloud data using recursive Bayesian updates.
 *
 * This node constructs a 2D global elevation map by discretizing transformed pointcloud data into a grid,
 * applying a moving average elevation update per cell, and filtering discontinuities using a scalar BayesFilter.
 * It supports loading a saved map from a PCD file, fusing new data in real-time, and exporting the filtered map to CSV.
 *
 * The output map is published periodically as a ROS 2 `OccupancyGrid` aligned to the `map` frame.
 *
 * @version 1.0.1
 * @date 2025-07-27
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - (internal callback only): PointCloud2 loaded from PCD or passed externally to `transformedPCLCallback()`.
 *
 * Publishers:
 * - /mapping/global_map: [nav_msgs::msg::OccupancyGrid] Raw elevation map (currently commented out).
 * - /mapping/filtered_global_map: [nav_msgs::msg::OccupancyGrid] Filtered elevation map smoothed with BayesFilter.
 *
 * TF Usage:
 * - The map assumes a static frame `map`, and incoming clouds are expected to be aligned with it.
 * - TF listener initialized but not used actively in this file.
 *
 * Processing Pipeline:
 * - `configureMaps()`: Initializes the grid size, metadata, and per-cell Bayes filters. Optionally preloads map from PCD.
 * - `transformedPCLCallback()`: Spawns a thread to process incoming (or preloaded) pointcloud data.
 * - `fuseMap()`: Discretizes cloud into grid cells, computes average elevation, and writes to raw and filtered maps.
 * - `filterMap()`: Applies localized smoothing based on gradient threshold using BayesFilter updates.
 * - `publishGlobalMap()`: Publishes the filtered map to ROS 2 at 10-second intervals.
 * - `saveGlobalMapCSV()`: Saves the filtered map to a CSV file under `mapping_util/filtered_global_map.csv`.
 *
 * Parameters and Constants:
 * - `MAP_RESOLUTION`: Grid resolution in meters per cell.
 * - `MAP_DIMENSION`: Map width and height (square), in meters.
 * - `ELEVATION_SCALE`: Scale factor converting z-elevation to grid values.
 * - `MAPPING_SOURCE_DIR`: Used to locate saved map files or store CSV.
 *
 * Elevation Fusion Model:
 * - If cell density > 1, average elevation is computed and written.
 * - Discontinuities exceeding a gradient threshold (`ELEVATION_SCALE / 0.866`) are smoothed via neighbor propagation.
 *
 * BayesFilter Update (per cell):
 *   \f[
 *   K_t = \frac{\sigma^2_{\text{prior}}}{\sigma^2_{\text{prior}} + \sigma^2_{\text{meas}}}, \quad
 *   \hat{z}_t = \hat{z}_{t-1} + K_t(z_t - \hat{z}_{t-1})
 *   \f]
 *
 * Assumptions:
 * - The input cloud is aligned with the `map` frame.
 * - No runtime pointcloud subscriber — all clouds passed directly or loaded from disk.
 *
 * @credit Custom implementation based on grid mapping and terrain elevation filtering in planetary robotics.
 */

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
void WorldModel::setupCommunications()
{
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

void WorldModel::configureMaps()
{
    // Configuring occupancy grid

    this->global_map_.header.frame_id = "map";
    this->global_map_.info.resolution = MAP_RESOLUTION;
    this->global_map_.info.width = MAP_DIMENSION / MAP_RESOLUTION;
    this->global_map_.info.height = MAP_DIMENSION / MAP_RESOLUTION;
    this->global_map_.info.origin.position.x = -0.15;
    this->global_map_.info.origin.position.y = 0.0;

    filtered_global_map_.header.frame_id = "map";
    filtered_global_map_.info = global_map_.info;

    // Initialize bayes filter
    for (size_t i = 0; i < global_map_.info.width * global_map_.info.height; i++)
    {
        BayesFilter bf;
        bayes_filter_.push_back(bf);
    }

    // Initialize occupancy grid
    this->global_map_.data.resize(global_map_.info.width * global_map_.info.height);
    this->filtered_global_map_.data.resize(global_map_.info.width * global_map_.info.height);
    for (size_t i = 0; i < this->global_map_.info.width * this->global_map_.info.height; i++)
    {
        this->global_map_.data[i] = 0;
        this->filtered_global_map_.data[i] = 0;
    }

    // Preload saved map if it exists
    RCLCPP_INFO(this->get_logger(), "Loading map...");
    auto map_msg = lr::mapping::getMapFromPCD();
    RCLCPP_INFO(this->get_logger(), "Map loaded");
    if (map_msg)
    {
        transformedPCLCallback(map_msg);
        RCLCPP_INFO(this->get_logger(), "Map preload successful");
    }
    else
    {
        RCLCPP_ERROR(this->get_logger(), "Map preload failed");
    }
}

// Pointcloud callback
void WorldModel::transformedPCLCallback(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{
    auto msg_copy = std::make_shared<sensor_msgs::msg::PointCloud2>(*msg);
    fuse_map_thread_ = std::thread(std::bind(&WorldModel::fuseMap, this, msg_copy));

    // Have to detach thread before it goes out of scope
    fuse_map_thread_.detach();
}

void WorldModel::fuseMap(const sensor_msgs::msg::PointCloud2::SharedPtr msg)
{

    pcl::PointCloud<pcl::PointXYZ>::Ptr cropped_cloud_local_map(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::fromROSMsg(*msg, *cropped_cloud_local_map);

    std::vector<double> elevation_values(global_map_.info.width * global_map_.info.height, 0.0);
    std::vector<double> density_values(global_map_.info.width * global_map_.info.height, 0.0);

    for (size_t i = 0; i < cropped_cloud_local_map->points.size(); i++)
    {
        int col_x = int(cropped_cloud_local_map->points[i].x / global_map_.info.resolution);
        int row_y = int(cropped_cloud_local_map->points[i].y / global_map_.info.resolution);

        col_x = std::min(std::max(col_x, 0), int(global_map_.info.width - 1));
        row_y = std::min(std::max(row_y, 0), int(global_map_.info.height - 1));

        int global_idx = col_x + row_y * global_map_.info.width;
        double elev = cropped_cloud_local_map->points[i].z;
        elevation_values[global_idx] += ELEVATION_SCALE * (elev);
        density_values[global_idx] += 1.0;
    }

    for (size_t i = 0; i < global_map_.info.width * global_map_.info.height; i++)
    {
        if (density_values[i] > 1.0)
        {
            global_map_.data[i] = int(elevation_values[i] / density_values[i]);
            filtered_global_map_.data[i] = int(elevation_values[i] / density_values[i]);
        }
    }

    filterMap();
}

void WorldModel::saveGlobalMapCSV()
{
    std::string csv_filename = std::string(MAPPING_SOURCE_DIR) + "/mapping_util/filtered_global_map.csv";
    std::ofstream csv_file(csv_filename);

    if (csv_file.is_open())
    {
        for (size_t y = 0; y < filtered_global_map_.info.height; ++y)
        {
            for (size_t x = 0; x < filtered_global_map_.info.width; ++x)
            {
                size_t idx = x + y * filtered_global_map_.info.width;
                csv_file << static_cast<int>(filtered_global_map_.data[idx]);
                if (x < filtered_global_map_.info.width - 1)
                {
                    csv_file << ",";
                }
            }
            csv_file << "\n";
        }
        csv_file.close();
        RCLCPP_INFO(this->get_logger(), "Filtered elevation map saved to %s", csv_filename.c_str());
    }
    else
    {
        RCLCPP_WARN(this->get_logger(), "Failed to open file for CSV export");
    }
}

void WorldModel::filterMap()
{
    double gradient = ELEVATION_SCALE / 0.866;
    // use globalmap to update bayes filter and then update filtered global map
    for (size_t i = 0; i < global_map_.info.width * global_map_.info.height; i++)
    {
        if (global_map_.data[i] == 0)
        {
            continue;
        }
        // RCLCPP_INFO(this->get_logger(), "Bayes Filter initialized5");
        if (abs(filtered_global_map_.data[i] - global_map_.data[i]) > gradient)
        {
            bayes_filter_[i].updateCell(global_map_.data[i], 10.0);
            filtered_global_map_.data[i] = int(bayes_filter_[i].getCellElevation());
        }

        // double
        // update cell of neighbours
        int neighbour_deltas[8] = {-1, 1, -(int)global_map_.info.width, (int)global_map_.info.width, -(int)global_map_.info.width - 1, -(int)global_map_.info.width + 1, (int)global_map_.info.width - 1, (int)global_map_.info.width + 1};
        // only 4 neighbours
        // int neighbour_deltas[4] = {-1, 1, -global_map_.info.width, global_map_.info.width};
        for (size_t j = 0; j < 4; j++)
        {
            size_t neighbour_idx = i + neighbour_deltas[j];
            if (neighbour_idx > global_map_.info.width * global_map_.info.height)
            {
                continue;
            }
            // else if(filtered_global_map_.data[neighbour_idx] == 0){
            //     continue;
            // }
            if (abs(filtered_global_map_.data[i] - filtered_global_map_.data[neighbour_idx]) <= gradient)
            {
                continue;
            }
            // else if(global_map_.data[i] > global_map_.data[neighbour_idx]){
            else if (filtered_global_map_.data[i] > filtered_global_map_.data[neighbour_idx])
            {
                bayes_filter_[neighbour_idx].updateCell(filtered_global_map_.data[i] - gradient, 10000.0);
                filtered_global_map_.data[neighbour_idx] = int(bayes_filter_[neighbour_idx].getCellElevation());
            }
            // // // else if(global_map_.data[i] < global_map_.data[neighbour_idx]){
            else if (filtered_global_map_.data[i] < filtered_global_map_.data[neighbour_idx])
            {
                bayes_filter_[neighbour_idx].updateCell(filtered_global_map_.data[i] + gradient, 10000.0);
                filtered_global_map_.data[neighbour_idx] = int(bayes_filter_[neighbour_idx].getCellElevation());
            }
        }
    }
}

// Map publishers
void WorldModel::publishGlobalMap()
{
    // global_map_publisher_->publish(global_map_);
    filtered_global_map_publisher_->publish(filtered_global_map_);
}