/**
 * @file perception_call_tester.cpp
 * @brief Test node that listens for crater detections and triggers PoseExtract
 *        service calls to generate approach/goal poses for Lunar ROADSTER.
 *
 * This node subscribes to the output of the crater detection module
 * (`lr_msgs::msg::CraterStamped`) and, for every received crater message,
 * sends a request to the `perception::srv::PoseExtract` service
 * ("generate_crater_goals"). The service computes rover goal poses based on the
 * crater centroid and diameter, returning a set of 2D poses and their
 * associated semantic types (e.g., ENTRY, EXIT, ALIGNMENT).
 *
 * The node stores the returned poses and prints them in a formatted manner
 * for verification and debugging. It also prevents multiple simultaneous
 * service calls by enforcing an in-flight request flag.
 *
 * @version 1.0.0
 * @date 2025-12-02
 *
 * Maintainer: Ankit Aggarwal, Deepam Ameria
 * Contributors: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla,
 *               Simson D’Souza, Boxiang (William) Fu  
 * Team: Lunar ROADSTER
 *
 * ------------------------------------------------------------------------------
 * SUBSCRIBERS
 * ------------------------------------------------------------------------------
 * - /crater_detection/crater
 *     Type: lr_msgs::msg::CraterStamped  
 *     Final crater centroid + diameter after detection and filtering.
 *     Used as input to generate rover goal poses.
 *
 * ------------------------------------------------------------------------------
 * SERVICE CLIENTS
 * ------------------------------------------------------------------------------
 * - generate_crater_goals
 *     Type: perception::srv::PoseExtract  
 *     Computes goal poses based on crater geometry.
 *     Called asynchronously every time a crater message is received.
 *
 * ------------------------------------------------------------------------------
 * PARAMETERS / INTERNAL STATE
 * ------------------------------------------------------------------------------
 * - pending_request_ (bool)
 *     Tracks whether a PoseExtract request is currently in flight.
 *     Prevents multiple overlapping service calls.
 *
 * - goalPoses (std::vector<lr_msgs::msg::Pose2D>)
 *     Goal poses returned from the service.
 *
 * - goalPosesTypes (std::vector<std::string>)
 *     Semantic type labels returned with each pose.
 *
 * ------------------------------------------------------------------------------
 * FEATURES
 * ------------------------------------------------------------------------------
 * - Waits for crater detections and triggers pose generation automatically.
 * - Avoids duplicate service requests using a request-in-flight guard.
 * - Pretty-prints crater information and resulting goal poses.
 * - Gracefully handles service availability issues.
 *
 * ------------------------------------------------------------------------------
 * WORKFLOW
 * ------------------------------------------------------------------------------
 * 1. Node starts and waits for incoming crater detections.
 * 2. On crater callback:
 *        - Checks service availability.
 *        - Sends asynchronous PoseExtract request.
 *        - Passes crater dimensions as service input.
 * 3. On service response:
 *        - Stores returned poses + types.
 *        - Prints all results to the ROS2 logger.
 * 4. Ready for next crater message.
 *
 * ------------------------------------------------------------------------------
 * NOTES
 * ------------------------------------------------------------------------------
 * - Designed as a lightweight integration tester for crater → pose generation.
 * - Useful for verifying correctness of perception and planning handoff.
 * - Does not publish or drive the rover — only tests perception-service logic.
 *
 */

#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

#include <rclcpp/rclcpp.hpp>
#include <lr_msgs/msg/crater_stamped.hpp>
#include <lr_msgs/msg/pose2_d.hpp>
#include <lr_msgs/srv/pose_extract.hpp>

using namespace std::chrono_literals;

class PerceptionCallTester : public rclcpp::Node
{
public:
  PerceptionCallTester()
  : rclcpp::Node("perception_call_tester"),
    pose_client_(this->create_client<perception::srv::PoseExtract>("generate_crater_goals")),
    pending_request_(false)
  {
    crater_sub_ = this->create_subscription<lr_msgs::msg::CraterStamped>(
      "/crater_detection/crater", rclcpp::QoS(10).transient_local(),
      std::bind(&PerceptionCallTester::craterCallback, this, std::placeholders::_1));

    RCLCPP_INFO(get_logger(), "Waiting for crater detections on /crater_detection/crater");
  }

  std::vector<lr_msgs::msg::Pose2D> goalPoses;
  std::vector<std::string> goalPosesTypes;

private:
  void craterCallback(const lr_msgs::msg::CraterStamped::SharedPtr msg)
  {
    if (pending_request_) {
      RCLCPP_WARN(get_logger(), "Ignoring crater message while service request is in flight");
      return;
    }

    if (!pose_client_->wait_for_service(2s)) {
      RCLCPP_ERROR(get_logger(), "Pose extract service unavailable (generate_crater_goals)");
      return;
    }

    auto request = std::make_shared<perception::srv::PoseExtract::Request>();
    request->centroid = msg->point;
    request->diameter = static_cast<float>(msg->diameter);

    pending_request_ = true;
    pose_client_->async_send_request(
      request,
      std::bind(
        &PerceptionCallTester::handleResponse, this,
        std::placeholders::_1, msg));
  }

  void handleResponse(
    rclcpp::Client<perception::srv::PoseExtract>::SharedFuture future,
    const lr_msgs::msg::CraterStamped::SharedPtr &crater_msg)
  {
    pending_request_ = false;

    const auto response = future.get();
    goalPoses = response->goal_poses;
    goalPosesTypes = response->goal_types;

    if (!response->success) {
      RCLCPP_ERROR(get_logger(), "Pose extraction failed: %s", response->message.c_str());
      return;
    }

    printResults(*crater_msg, response->message);
  }

  void printResults(
    const lr_msgs::msg::CraterStamped &crater_msg,
    const std::string &service_message)
  {
    std::ostringstream header;
    header << std::fixed << std::setprecision(3)
           << "Crater @ (" << crater_msg.point.x << ", "
           << crater_msg.point.y << ", " << crater_msg.point.z
           << "), diameter " << crater_msg.diameter << " m";
    RCLCPP_INFO(get_logger(), "%s", header.str().c_str());
    RCLCPP_INFO(get_logger(), "Service message: %s", service_message.c_str());

    for (size_t i = 0; i < goalPoses.size(); ++i) {
      const auto &pose = goalPoses[i];
      const auto type = (i < goalPosesTypes.size()) ? goalPosesTypes[i] : "unknown";

      std::ostringstream line;
      line << std::fixed << std::setprecision(3)
           << "  [" << i << "] type=" << type
           << " x=" << pose.pt.x
           << " y=" << pose.pt.y
           << " yaw=" << pose.yaw;
      RCLCPP_INFO(get_logger(), "%s", line.str().c_str());
    }
  }

  rclcpp::Subscription<lr_msgs::msg::CraterStamped>::SharedPtr crater_sub_;
  rclcpp::Client<perception::srv::PoseExtract>::SharedPtr pose_client_;
  bool pending_request_;
};

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PerceptionCallTester>());
  rclcpp::shutdown();
  return 0;
}
