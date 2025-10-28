#include "navigation/global_planner_controller_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors/multi_threaded_executor.hpp"
#include <memory> 

/**
 * @brief Main entry point for the global_planner_controller node.
 * @param argc
 * @param argv
 * @return 0 on successful execution.
 */
int main(int argc, char * argv[])
{
    // Initialize ROS2
    rclcpp::init(argc, argv);

    rclcpp::NodeOptions options;

    auto node = std::make_shared<lr_global_planner_controller::GlobalPlannerController>(options);

    // Use a MultiThreadedExecutor
    // This allows the action server to handle new goals or cancellations
    // in a separate thread while the main controller timer is running.
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);

    RCLCPP_INFO(node->get_logger(), "Starting GlobalPlannerController node with MultiThreadedExecutor.");
    
    executor.spin();

    rclcpp::shutdown();
    
    return 0;
}
