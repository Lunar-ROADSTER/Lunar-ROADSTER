/**
 * @file ceiltrack_node.cpp
 * @brief Ceiling-grid localization using a fisheye camera.
 *
 * Estimates ceiling-aligned (u, v, theta) pose by detecting light patterns in a fisheye image.
 * Selects bright pixels, and optimizes grid alignment via a closed-form Levenberg–Marquardt
 * update. Publishes both image-plane and metric poses.
 *
 * @version 1.0.2
 * @date 2025-11-01
 * 
 * Maintainer: Boxiang (William) Fu  
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Subscribers:
 * - /fisheye_camera/image_raw : [sensor_msgs::msg::Image] Input fisheye camera image stream.
 * - /ceiltrack/set_home : [lr_msgs::msg::Pose2D] Resets pose to home.
 *
 * Publishers:
 * - /ceiling_pose : [geometry_msgs::msg::Pose2D] Pose in image-plane units.
 * - /ceiling_pose_with_covariance : [geometry_msgs::msg::PoseWithCovarianceStamped] Pose in world coordinates.
 * - /ceiling_image_marker : [sensor_msgs::msg::Image] Debug image with grid overlay.
 *
 * Parameters:
 * - cam_tilt_rad : [double] Camera tilt angle from vertical (radians).
 * - xgrid_m : [double] Grid spacing in x (meters).
 * - ygrid_m : [double] Grid spacing in y (meters).
 * - ceil_height : [double] Ceiling height (meters).
 * - threshold : [int] Brightness threshold.
 * - niter : [int] Number of iterations for optimization.
 * - publish_grid_marker : [bool] Whether to publish grid marker.
 * - lens.width : [int] Fisheye image width (pixels).
 * - lens.height : [int] Fisheye image height (pixels).
 * - lens.center_limit : [double] Center limit (pixels).
 * - lens.cell_limit : [double] Cell limit (pixels).
 * - lens.fx : [double] Fisheye focal length x (pixels).
 * - lens.fy : [double] Fisheye focal length y (pixels).
 * - lens.cx : [double] Fisheye principal point x (pixels).
 * - lens.cy : [double] Fisheye principal point y (pixels).
 * - lens.k1 : [double] Fisheye radial distortion coefficient.
 * - home.x : [double] Home position x estimated by fisheye alignment (meters).
 * - home.y : [double] Home position y estimated by fisheye alignment (meters).
 * - home.theta : [double] Home orientation estimated by fisheye alignment (radians).
 * - home.x_init : [double] Initial global home position x (meters).
 * - home.y_init : [double] Initial global home position y (meters).
 * - home.theta_init : [double] Initial global home orientation (radians).
 *
 * Notes:
 * - Requires camera output "yuv422_yuy2".
 * - ceil_height is in meters; xgrid and ygrid are in unitless grid meters / height.
 * 
 * @credit Andy Sloane from https://www.a1k0n.net/2021/01/22/indoor-localization.html
 */


#include "ceiltrack/ceiltrack.hpp"
 
namespace lr {
namespace ceiltrack {

CeiltrackNode::CeiltrackNode() : Node("ceiltrack_node")
{
    // Parameters
    this->declare_parameter<double>("cam_tilt_rad", 0.0);
    cam_tilt_rad_ = this->get_parameter("cam_tilt_rad").as_double();

    this->declare_parameter<double>("ceil_height", 2.5);
    ceil_height_ = this->get_parameter("ceil_height").as_double();

    this->declare_parameter<double>("xgrid_m", 0.25);
    xgrid_m_ = this->get_parameter("xgrid_m").as_double();
    xgrid_ = xgrid_m_ / ceil_height_;

    this->declare_parameter<double>("ygrid_m", 0.25);
    ygrid_m_ = this->get_parameter("ygrid_m").as_double();
    ygrid_ = ygrid_m_ / ceil_height_;

    this->declare_parameter<int>("threshold", 233);
    threshold_ = this->get_parameter("threshold").as_int();

    this->declare_parameter<int>("niter", 5);
    niter_ = this->get_parameter("niter").as_int();

    this->declare_parameter<bool>("publish_grid_marker", false);
    publish_grid_ = this->get_parameter("publish_grid_marker").as_bool();

    this->declare_parameter<int>("lens.width", 640);
    width_ = this->get_parameter("lens.width").as_int();

    this->declare_parameter<int>("lens.height", 480);
    height_ = this->get_parameter("lens.height").as_int();

    this->declare_parameter<double>("lens.center_limit", 64.0);
    center_limit_ = this->get_parameter("lens.center_limit").as_double();

    this->declare_parameter<double>("lens.cell_limit", 9.0);
    ceil_limit_ = this->get_parameter("lens.cell_limit").as_double();

    this->declare_parameter<double>("lens.fx", 239.22139424050349);
    const double fx = this->get_parameter("lens.fx").as_double();

    this->declare_parameter<double>("lens.fy", 239.18055604379532);
    const double fy = this->get_parameter("lens.fy").as_double();

    this->declare_parameter<double>("lens.cx", 327.24047691408475);
    const double cx = this->get_parameter("lens.cx").as_double();

    this->declare_parameter<double>("lens.cy", 230.38304598028427);
    const double cy = this->get_parameter("lens.cy").as_double();

    this->declare_parameter<double>("lens.k1", 0.0);
    const double k1 = this->get_parameter("lens.k1").as_double();

    this->declare_parameter<double>("home.x", 0.0);
    home_x_ = this->get_parameter("home.x").as_double();

    this->declare_parameter<double>("home.x_init", 0.0);
    home_x_init_ = this->get_parameter("home.x_init").as_double();

    this->declare_parameter<double>("home.y", 0.0);
    home_y_ = this->get_parameter("home.y").as_double();

    this->declare_parameter<double>("home.y_init", 0.0);
    home_y_init_ = this->get_parameter("home.y_init").as_double();

    this->declare_parameter<double>("home.theta", 0.0);
    home_theta_ = this->get_parameter("home.theta").as_double();

    this->declare_parameter<double>("home.theta_init", 0.0);
    home_theta_init_ = this->get_parameter("home.theta_init").as_double();

    // Fisheye calibration
    lens_.SetCalibration(static_cast<float>(fx), static_cast<float>(fy),
                        static_cast<float>(cx), static_cast<float>(cy),
                        static_cast<float>(k1));
    RCLCPP_INFO(this->get_logger(), "Fisheye lens: fx=%.2f, fy=%.2f, cx=%.2f, cy=%.2f, k1=%.6f",
                lens_.fx, lens_.fy, lens_.cx, lens_.cy, lens_.k1);
    
    // Publishers
    pose_camera_pub_ = this->create_publisher<geometry_msgs::msg::Pose2D>("ceiling_pose", 10);
    pose_world_pub_ = this->create_publisher<geometry_msgs::msg::PoseWithCovarianceStamped>("ceiling_pose_with_covariance", 10);
    image_marker_pub_ = this->create_publisher<sensor_msgs::msg::Image>("ceiling_image_marker", 10);

    // Subscribers
    img_sub_ = this->create_subscription<sensor_msgs::msg::Image>(
        "/fisheye_camera/image_raw", rclcpp::SensorDataQoS(),
        std::bind(&CeiltrackNode::imageCallback, this, std::placeholders::_1)
    );
    set_home_sub_ = this->create_subscription<lr_msgs::msg::Pose2D>(
        "/ceiltrack/set_home", 10,
        std::bind(&CeiltrackNode::setHomeCallback, this, std::placeholders::_1));

    // Initialization
    tracker_ready_ = ceiltrackInit(lens_, static_cast<float>(cam_tilt_rad_));

    if (tracker_ready_) {
        RCLCPP_INFO(this->get_logger(), "CeiltrackNode initialized.");
    } else {
        RCLCPP_ERROR(this->get_logger(), "Ceiltrack tracker init failed.");
    }
}


struct CeiltrackNode::RLEMask
{
    int run = 0;
    bool zero = true;
    std::vector<uint16_t> out;
    inline void AddZero()
    {
        if (zero)
        {
            ++run;
        }
        else
        {
            out.push_back(run);
            run = 1;
            zero = true;
        }
    }
    inline void AddOne()
    {
        if (zero)
        {
            out.push_back(run);
            run = 1;
            zero = false;
        }
        else
        {
            ++run;
        }
    }
};


inline float CeiltrackNode::moddist(float x, float q, float ooq)
{
    const float xoq = x * ooq;
    return q * (xoq - ((int)(xoq + 1024.5f)) + 1024.f);
}


bool CeiltrackNode::ceiltrackInit(const FisheyeLens &lens, float cam_tilt_rad)
{
    ceiltrackShutdown();

    float *pts = lens.GenUndistortedPts(width_, height_);
    if (!pts)
        return false;

    const float S = std::sin(cam_tilt_rad);
    const float C = std::cos(cam_tilt_rad);

    RLEMask mask;
    std::vector<float> uvpts;
    uvpts.reserve(static_cast<size_t>(width_ * height_));

    int idx = 0;
    for (int j = 0; j < height_; ++j)
    {
        for (int i = 0; i < width_; ++i)
        {
            float px = pts[idx++];
            float py = pts[idx++];
            float pz = pts[idx++];

            if (pz != 1 || (px * px + py * py) > center_limit_)
            {
                mask.AddZero();
                continue;
            }

            float Rx = C * px + S * pz;
            float Ry = py;
            float Rz = -S * px + C * pz;

            Rx /= std::fabs(Rz);
            Ry /= std::fabs(Rz);

            if ((Rx * Rx + Ry * Ry) > ceil_limit_)
            {
                mask.AddZero();
                continue;
            }

            mask.AddOne();
            uvpts.push_back(Rx);
            uvpts.push_back(Ry);
        }
    }

    uvmaplen_ = static_cast<int>(uvpts.size());
    uvmap_ = new float[uvmaplen_];
    std::memcpy(uvmap_, uvpts.data(), static_cast<size_t>(uvmaplen_) * sizeof(float));

    mask_rlelen_ = static_cast<int>(mask.out.size());
    mask_rle_ = new uint16_t[mask_rlelen_];
    std::memcpy(mask_rle_, mask.out.data(), static_cast<size_t>(mask_rlelen_) * sizeof(uint16_t));

    // DEBUG
    RCLCPP_INFO(this->get_logger(), "Mask Size: %d runs, UV map size: %d points",
                mask_rlelen_, uvmaplen_ / 2);
    RCLCPP_INFO(this->get_logger(), "Mask Starts: %d, %d, %d, %d, %d",
                mask_rle_[0], mask_rle_[1], mask_rle_[2], mask_rle_[3], mask_rle_[4]);
    RCLCPP_INFO(this->get_logger(), "UV Points Starts: %.4f, %.4f, %.4f, %.4f, %.4f, %.4f",
                uvmap_[0], uvmap_[1], uvmap_[2], uvmap_[3], uvmap_[4], uvmap_[5]);

    delete[] pts;
    return true;
}


float CeiltrackNode::ceiltrackUpdate(const uint8_t *img, uint8_t thresh,
                                     float xgrid, float ygrid,
                                     float *xytheta, int niter)
{
    if (!uvmap_ || !mask_rle_)
        return 0.0f;

    const float ooxg = 1.0f / xgrid;
    const float ooyg = 1.0f / ygrid;

    static std::vector<float> xybuf;
    xybuf.clear();
    xybuf.reserve(static_cast<size_t>(uvmaplen_));

    int rleptr = 0;
    int uvptr = 0;

    const uint8_t *p = img;
    while (rleptr < mask_rlelen_)
    {
        p += mask_rle_[rleptr++];
        int n = mask_rle_[rleptr++];
        while (n--)
        {
            if ((*p++) > thresh)
            {
                xybuf.push_back(uvmap_[uvptr]);
                xybuf.push_back(uvmap_[uvptr + 1]);
            }
            uvptr += 2;
        }
    }

    // DEBUG
    // RCLCPP_INFO(this->get_logger(), "CeiltrackUpdate: matched %zu points",
    //             xybuf.size() / 2);

    float cost = 0.0f;

    for (int iter = 0; iter < niter; ++iter)
    {
        float u = xytheta[0], v = xytheta[1], theta = xytheta[2];
        float S = std::sin(theta), C = std::cos(theta);

        cost = 0.0f;
        float R = 0.0f, S2 = 0.0f, S3 = 0.0f, Sdx = 0.0f, Sdy = 0.0f, SdRxy = 0.0f;

        // Equation from https://github.com/a1k0n/cycloid/blob/master/src/localization/ceiltrack/ceiltrack.cc#L462-L556
        for (size_t i = 0; i + 1 < xybuf.size(); i += 2)
        {
            const float x = xybuf[i];
            const float y = xybuf[i + 1];
            const float Rx = x * C + y * S;
            const float Ry = -x * S + y * C;

            R += x * x + y * y;
            S2 -= Ry;
            S3 += Rx;

            const float dx = moddist(Rx - u, xgrid, ooxg);
            const float dy = moddist(Ry - v, ygrid, ooyg);

            cost += dx * dx + dy * dy;
            Sdx += dx;
            Sdy += dy;
            SdRxy += -dx * Ry + dy * Rx;
        }

        const float lambda = 1.0f;
        const float N = static_cast<float>(xybuf.size()) / 2.0f;

        // Closed form Levenberg-Marquardt update
        const float x0 = S3 * Sdy;
        const float x1 = N + lambda;
        const float x2 = SdRxy * x1;
        const float x3 = -x1 * (R + lambda);
        const float x4 = S3 * S3 + x3;
        const float x5 = S2 * S2;
        const float x6 = 1.0f / (x4 + x5);
        const float x7 = x6 / x1;
        const float x8 = S2 * Sdx;

        xytheta[0] -= x7 * (S2 * (x0 - x2) - Sdx * x4);
        xytheta[1] -= x7 * (-S3 * x2 + S3 * x8 - Sdy * (x3 + x5));
        xytheta[2] -= x6 * (-x0 + x2 - x8);

        // DEBUG
        // RCLCPP_INFO(this->get_logger(), "CeilTrack iter %d: cost %.6f  xyt = [%.6f, %.6f, %.6f], used=%zu",
        //             iter, 0.5f * cost, xytheta[0], xytheta[1], xytheta[2], xybuf.size() / 2);
    }

    return 0.5f * cost;
}


void CeiltrackNode::ceiltrackGetMatchedGrid(const FisheyeLens &lens, const float *xytheta,
                                            float xgrid, float ygrid,
                                            std::vector<std::pair<float, float>> &out)
{
    out.clear();
    out.reserve(31 * 31);

    const float S = std::sin(-xytheta[2]);
    const float C = std::cos(-xytheta[2]);
    const float St = std::sin(-static_cast<float>(cam_tilt_rad_));
    const float Ct = std::cos(-static_cast<float>(cam_tilt_rad_));

    for (int i = -15; i <= 15; ++i)
    {
        const float u = i * xgrid + xytheta[0];
        for (int j = -15; j <= 15; ++j)
        {
            const float v = j * ygrid + xytheta[1];

            // Rotate by theta in image-plane
            const float Ru = u * C + v * S;
            const float Rv = -u * S + v * C;

            // 3D rotate by cam tilt around y
            const float z = -St * Ru + Ct;
            const float x = (Ct * Ru + St) / z;
            const float y = Rv / z;

            if (z > 0.0f)
            {
                float uu, vv;
                lens.DistortPoint(x, y, 1.0f, &uu, &vv);
                out.emplace_back(uu, vv);
            }
        }
    }
}


void CeiltrackNode::ceiltrackShutdown()
{
    delete[] uvmap_;
    uvmap_ = nullptr;
    uvmaplen_ = 0;

    delete[] mask_rle_;
    mask_rle_ = nullptr;
    mask_rlelen_ = 0;
}


void CeiltrackNode::imageCallback(const sensor_msgs::msg::Image::SharedPtr msg)
{
    if (!tracker_ready_)
        return;

    // DEBUG
    // RCLCPP_INFO(this->get_logger(), "Received image: %ux%u, encoding=%s",
    //              msg->width, msg->height, msg->encoding.c_str());

    const bool is_yuy2 = (msg->encoding == "yuv422_yuy2");
    if (!is_yuy2)   
    {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 3000,
                             "Expected yuv422_yuy2 image; got '%s'.", msg->encoding.c_str());
        return;
    }

    if (msg->width != 640 || msg->height != 480)
    {
        RCLCPP_WARN_THROTTLE(this->get_logger(), *this->get_clock(), 3000,
                             "Expected 640x480 image; got %ux%u.", msg->width, msg->height);
        return;
    }

    const uint8_t *data = nullptr;
    std::vector<uint8_t> ybuf;

    // Convert YUY2 (Y0 U Y1 V) to mono8 by extracting Y bytes
    ybuf.resize(msg->width * msg->height);
    for (uint32_t r = 0; r < msg->height; ++r)
    {
        const uint8_t *row = msg->data.data() + r * msg->step;
        uint8_t *out = ybuf.data() + r * msg->width;
        for (uint32_t c = 0; c < msg->width; ++c)
        {
            out[c] = row[2 * c];
        }
    }
    data = ybuf.data();

    const float cost = ceiltrackUpdate(
        data,
        static_cast<uint8_t>(std::clamp(threshold_, 0, 255)),
        static_cast<float>(xgrid_),
        static_cast<float>(ygrid_),
        xytheta_,
        niter_);

    const double u_abs = static_cast<double>(xytheta_[0]);
    const double v_abs = static_cast<double>(xytheta_[1]);
    const double th_cam_abs = static_cast<double>(xytheta_[2]);
    const double yaw_abs = -th_cam_abs;
    const double X_abs = -u_abs * ceil_height_;
    const double Y_abs = -v_abs * ceil_height_;

    double X_rel = X_abs;
    double Y_rel = Y_abs;
    double yaw_rel = yaw_abs;

    if (have_home_ref_.load())
    {
        X_rel = X_abs - home_x_ + home_x_init_;
        Y_rel = Y_abs - home_y_ + home_y_init_;
        yaw_rel = wrapAngle(yaw_abs - home_theta_);
    }

    const double u_rel = -X_rel / ceil_height_;
    const double v_rel = -Y_rel / ceil_height_;
    const double th_cam_rel = -yaw_rel;

    // Publish camera coordinate frame pose
    geometry_msgs::msg::Pose2D p_camera;
    p_camera.x = u_rel;
    p_camera.y = v_rel;
    p_camera.theta = th_cam_rel;
    pose_camera_pub_->publish(p_camera);

    // Publish world coordinate frame pose
    geometry_msgs::msg::PoseWithCovarianceStamped p_world;
    p_world.header = msg->header;
    p_world.header.frame_id = "map";
    p_world.pose.pose.position.x = X_rel;
    p_world.pose.pose.position.y = Y_rel;
    p_world.pose.pose.position.z = 0.0;

    tf2::Quaternion q;
    q.setRPY(0.0, 0.0, yaw_rel);
    p_world.pose.pose.orientation = tf2::toMsg(q);

    for (double &c : p_world.pose.covariance)
        c = 0.0;
    pose_world_pub_->publish(p_world);

    // Publish image overlay with grid points
    if (publish_grid_)
    {
        std::vector<std::pair<float, float>> uv;
        uv.reserve(31 * 31);
        ceiltrackGetMatchedGrid(lens_, xytheta_,
                                static_cast<float>(xgrid_), static_cast<float>(ygrid_), uv);

        const int W = static_cast<int>(msg->width);
        const int H = static_cast<int>(msg->height);

        auto put_pixel = [&](int x, int y, uint8_t val)
        {
            if (x >= 0 && x < W && y >= 0 && y < H)
            {
                ybuf[y * W + x] = val;
            }
        };

        for (const auto &pt : uv)
        {
            const int u = static_cast<int>(std::lround(pt.first));
            const int v = static_cast<int>(std::lround(pt.second));
            // 3x3 white dot
            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    put_pixel(u + dx, v + dy, 255);
                }
            }
        }

        sensor_msgs::msg::Image img_marker;
        img_marker.header = msg->header;
        img_marker.height = msg->height;
        img_marker.width = msg->width;
        img_marker.encoding = "mono8";
        img_marker.is_bigendian = 0;
        img_marker.step = msg->width;
        img_marker.data = ybuf;

        image_marker_pub_->publish(img_marker);
    }

    // DEBUG
    RCLCPP_INFO(this->get_logger(),
                "cost=%.6f, camera pose(u=%.4f, v=%.4f, th=%.4f), world pose(X=%.4f, Y=%.4f, yaw=%.4f)",
                cost,
                u_rel, v_rel, th_cam_rel,
                X_rel, Y_rel, yaw_rel);
}


void CeiltrackNode::setHomeCallback(const lr_msgs::msg::Pose2D::SharedPtr msg)
{
    // Store current pose
    const double X_now = -static_cast<double>(xytheta_[0]) * ceil_height_;
    const double Y_now = -static_cast<double>(xytheta_[1]) * ceil_height_;
    const double yaw_now = -static_cast<double>(xytheta_[2]);

    home_x_ = X_now;
    home_y_ = Y_now;
    home_theta_ = yaw_now;

    // Store initial home pose (should ideally come from total station or fixed reference point)
    const double X_home  = msg->pt.x;
    const double Y_home  = msg->pt.y;
    const double yaw_home = msg->yaw;

    home_x_init_ = X_home;
    home_y_init_ = Y_home;
    home_theta_init_ = yaw_home;

    have_home_ref_.store(true);
    RCLCPP_INFO(
        this->get_logger(),
        "Initial home set to (X=%.4f, Y=%.4f, yaw=%.4f rad); current pose set (X=%.4f, Y=%.4f, yaw=%.4f rad)",
        home_x_init_, home_y_init_, home_theta_init_,
        home_x_, home_y_, home_theta_);
}


} // namespace ceiltrack
} // namespace lr