#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/pose_array.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <cmath>
#include <vector>

class CraterCentroidsPublisher : public rclcpp::Node
{
public:
    CraterCentroidsPublisher() : Node("crater_centroids_publisher")
    {
        pub_ = create_publisher<geometry_msgs::msg::PoseArray>("/crater_centroids", 1);
        timer_ = create_wall_timer(std::chrono::seconds(1),
                                   std::bind(&CraterCentroidsPublisher::publishCentroids, this));
        RCLCPP_INFO(get_logger(), "Crater Centroids Publisher started.");
    }

private:
    void publishCentroids()
    {
        const int W = 800, H = 800;      
        const double res = 0.05;        
        const double cx_px = W / 2.0;
        const double cy_px = H / 2.0;

        const double a = 270.0;         
        const double b = 210.0;

        std::vector<double> crater_rs   = {42, 28, 35, 30, 22, 40, 26, 34};
        std::vector<double> angles_deg  = {200, 235, 270, 315, 20, 60, 100, 150};

        geometry_msgs::msg::PoseArray arr;
        arr.header.stamp = now();
        arr.header.frame_id = "map";

        for (size_t i = 0; i < crater_rs.size(); ++i)
        {
            double theta = angles_deg[i] * M_PI / 180.0;
            double x_px = cx_px + a * std::cos(theta);
            double y_px = cy_px + b * std::sin(theta);

            double x = x_px * res;
            double y = (H - y_px) * res;

            geometry_msgs::msg::Pose p;
            p.position.x = x;
            p.position.y = y;
            p.position.z = 0.0;
            arr.poses.push_back(p);
        }

        {
            double a_extra = a + 70.0;
            double b_extra = b - 10.0;
            double theta = 10.0 * M_PI / 180.0;
            double x_px = cx_px + a_extra * std::cos(theta);
            double y_px = cy_px + b_extra * std::sin(theta);
            double x = x_px * res;
            double y = (H - y_px) * res;
            geometry_msgs::msg::Pose p;
            p.position.x = x;
            p.position.y = y;
            p.position.z = 0.0;
            arr.poses.push_back(p);
        }

        pub_->publish(arr);
    }

    rclcpp::Publisher<geometry_msgs::msg::PoseArray>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CraterCentroidsPublisher>());
    rclcpp::shutdown();
    return 0;
}
