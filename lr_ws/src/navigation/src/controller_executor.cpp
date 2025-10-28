#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_stamped.hpp>
#include <nav_msgs/msg/path.hpp>

#include <rclcpp_action/rclcpp_action.hpp>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/buffer.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include "tf2/time.h"

#include "lr_msgs/srv/plan_path.hpp"
#include "lr_msgs/action/follow_path.hpp"
using FollowPath = lr_msgs::action::FollowPath;

#include <mutex>
#include <chrono>
#include <functional>

class ControllerExecutor : public rclcpp::Node
{
public:
    ControllerExecutor()
        : Node("controller_executor")
    {
        declare_parameter<std::string>("planner_service_name", "/global_astar_planner/plan_path");
        declare_parameter<std::string>("controller_action_name", "follow_path");
        declare_parameter<std::string>("global_frame", "map");
        declare_parameter<bool>("smooth", true);

        planner_service_name_ = get_parameter("planner_service_name").as_string();
        controller_action_name_ = get_parameter("controller_action_name").as_string();
        global_frame_ = get_parameter("global_frame").as_string();
        smooth_ = get_parameter("smooth").as_bool();

        RCLCPP_INFO(get_logger(), "Planner service: %s", planner_service_name_.c_str());
        RCLCPP_INFO(get_logger(), "Controller action: %s", controller_action_name_.c_str());
        RCLCPP_INFO(get_logger(), "Global frame: %s | smooth=%s", global_frame_.c_str(), smooth_ ? "true" : "false");

        tf_buffer_ = std::make_shared<tf2_ros::Buffer>(get_clock());
        tf_listener_ = std::make_shared<tf2_ros::TransformListener>(*tf_buffer_);

        planner_client_ = create_client<lr_msgs::srv::PlanPath>(planner_service_name_);
        controller_ac_ = rclcpp_action::create_client<FollowPath>(this, controller_action_name_);

        goal_sub_ = create_subscription<geometry_msgs::msg::PoseStamped>(
            "/goal_pose", 10,
            std::bind(&ControllerExecutor::goalCallback, this, std::placeholders::_1));
    }

private:
    std::string planner_service_name_;
    std::string controller_action_name_;
    std::string global_frame_;
    bool smooth_;

    tf2_ros::Buffer::SharedPtr tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    rclcpp::Client<lr_msgs::srv::PlanPath>::SharedPtr planner_client_;
    rclcpp_action::Client<FollowPath>::SharedPtr controller_ac_;
    rclcpp::Subscription<geometry_msgs::msg::PoseStamped>::SharedPtr goal_sub_;

    std::mutex action_mtx_;
    rclcpp_action::ClientGoalHandle<FollowPath>::SharedPtr active_handle_;

    bool transformGoalToMap(const geometry_msgs::msg::PoseStamped &in, geometry_msgs::msg::PoseStamped &out)
    {
        try
        {
            if (in.header.frame_id.empty() || in.header.frame_id == global_frame_)
            {
                out = in;
                out.header.frame_id = global_frame_;
                return true;
            }
            out = tf_buffer_->transform(in, global_frame_, tf2::durationFromSec(0.3));
            return true;
        }
        catch (const tf2::TransformException &ex)
        {
            RCLCPP_ERROR(get_logger(), "Transform goal %s -> %s failed: %s",
                         in.header.frame_id.c_str(), global_frame_.c_str(), ex.what());
            return false;
        }
    }

    bool callPlanner(const geometry_msgs::msg::PoseStamped &goal_in_map, nav_msgs::msg::Path &path_out)
    {
        if (!planner_client_->wait_for_service(std::chrono::seconds(2)))
        {
            RCLCPP_ERROR(get_logger(), "Planning service %s not available.", planner_service_name_.c_str());
            return false;
        }

        auto req = std::make_shared<lr_msgs::srv::PlanPath::Request>();
        req->goal = goal_in_map;
        req->smooth = smooth_;

        auto fut = planner_client_->async_send_request(req);
        auto status = fut.wait_for(std::chrono::seconds(10));
        if (status != std::future_status::ready)
        {
            RCLCPP_ERROR(get_logger(), "Planning timed out.");
            return false;
        }

        auto resp = fut.get();
        if (!resp->success)
        {
            RCLCPP_WARN(get_logger(), "Planning failed: %s", resp->message.c_str());
            return false;
        }
        if (resp->path.poses.empty())
        {
            RCLCPP_WARN(get_logger(), "Planner returned an empty path.");
            return false;
        }

        path_out = resp->path;
        RCLCPP_INFO(get_logger(), "Got path with %zu poses.", path_out.poses.size());
        return true;
    }

    void sendPathToController(const nav_msgs::msg::Path &path)
    {
        if (!controller_ac_->wait_for_action_server(std::chrono::seconds(2)))
        {
            RCLCPP_ERROR(get_logger(), "Controller action server '%s' not available.", controller_action_name_.c_str());
            return;
        }

        {
            std::lock_guard<std::mutex> lk(action_mtx_);
            if (active_handle_)
            {
                RCLCPP_WARN(get_logger(), "Canceling previous controller goal.");
                controller_ac_->async_cancel_goal(active_handle_);
                active_handle_.reset();
            }
        }

        FollowPath::Goal goal_msg;
        goal_msg.path = path;

        rclcpp_action::Client<FollowPath>::SendGoalOptions opts;

        opts.goal_response_callback =
            [this](rclcpp_action::ClientGoalHandle<FollowPath>::SharedPtr handle)
        {
            if (!handle)
            {
                RCLCPP_ERROR(get_logger(), "Controller rejected the goal.");
                return;
            }
            {
                std::lock_guard<std::mutex> lk(action_mtx_);
                active_handle_ = handle;
            }
            RCLCPP_INFO(get_logger(), "Controller accepted the goal.");
        };

        opts.feedback_callback =
            [this](rclcpp_action::ClientGoalHandle<FollowPath>::SharedPtr,
                   const std::shared_ptr<const FollowPath::Feedback> fb)
        {
            RCLCPP_INFO(get_logger(), "Controller feedback: distance_to_goal=%.2f", fb->distance_to_goal);
        };

        opts.result_callback =
            [this](const rclcpp_action::ClientGoalHandle<FollowPath>::WrappedResult &result)
        {
            switch (result.code)
            {
            case rclcpp_action::ResultCode::SUCCEEDED:
                RCLCPP_INFO(get_logger(), "Controller SUCCEEDED.");
                break;
            case rclcpp_action::ResultCode::ABORTED:
                RCLCPP_WARN(get_logger(), "Controller ABORTED.");
                break;
            case rclcpp_action::ResultCode::CANCELED:
                RCLCPP_WARN(get_logger(), "Controller CANCELED.");
                break;
            default:
                RCLCPP_ERROR(get_logger(), "Controller: unknown result code.");
                break;
            }
            std::lock_guard<std::mutex> lk(action_mtx_);
            active_handle_.reset();
        };

        controller_ac_->async_send_goal(goal_msg, opts);
    }

    void goalCallback(const geometry_msgs::msg::PoseStamped::SharedPtr msg)
    {
        geometry_msgs::msg::PoseStamped goal_map;
        if (!transformGoalToMap(*msg, goal_map))
        {
            return;
        }

        goal_map.header.frame_id = global_frame_;
        if (goal_map.header.stamp.nanosec == 0 && goal_map.header.stamp.sec == 0)
        {
            goal_map.header.stamp = now();
        }

        nav_msgs::msg::Path plan;
        if (!callPlanner(goal_map, plan))
        {
            RCLCPP_ERROR(get_logger(), "Planning failed; not sending to controller.");
            return;
        }

        sendPathToController(plan);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ControllerExecutor>());
    rclcpp::shutdown();
    return 0;
}
