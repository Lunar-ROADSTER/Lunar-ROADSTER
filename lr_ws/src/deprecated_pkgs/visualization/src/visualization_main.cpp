#include "visualization/visualization.hpp"

int main(int argc, char** argv){
	rclcpp::init(argc, argv);

	// Initialize node
	auto node = std::make_shared<lr::viz::ElevationGridMapNode>();

	rclcpp::spin(node);

	rclcpp::shutdown();

	return 0;
}
