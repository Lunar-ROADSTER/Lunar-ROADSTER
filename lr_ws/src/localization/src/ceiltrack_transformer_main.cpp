#include <memory>
#include <rclcpp/rclcpp.hpp>
#include "localization/ceiltrack_transformer_node.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<lr::ceiltrack::CeiltrackTransformer>());
  rclcpp::shutdown();
  return 0;
}
