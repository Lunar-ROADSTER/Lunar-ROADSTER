#include "skycam/skycam_data_collection.hpp"

int main(int argc, char** argv){
	rclcpp::init(argc, argv);

	// Initialize node
	auto node = std::make_shared<lr::skycam::SkycamDataCollectionNode>();

	rclcpp::spin(node);

	rclcpp::shutdown();

	return 0;
}
