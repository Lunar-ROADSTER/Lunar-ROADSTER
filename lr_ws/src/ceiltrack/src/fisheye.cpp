#include "ceiltrack/fisheye.hpp"

namespace lr {
namespace ceiltrack {

    static inline float solvetheta(float thetad, float k1)
    {
        float theta = thetad;
        theta += (theta * (k1 * theta * theta + 1) - thetad) /
                 (-3 * k1 * theta * theta - 1);
        theta += (theta * (k1 * theta * theta + 1) - thetad) /
                 (-3 * k1 * theta * theta - 1);
        return theta;
    }

    void FisheyeLens::SetCalibration(float fx_, float fy_, float cx_, float cy_, float k1_)
    {
        fx = fx_;
        fy = fy_;
        cx = cx_;
        cy = cy_;
        k1 = k1_;
    }

    float *FisheyeLens::GenUndistortedPts(int w, int h) const
    {
        float *buf = new float[w * h * 3];
        int idx = 0;
        for (int j = 0; j < h; j++)
        {
            float v = (j - cy) / fy;
            for (int i = 0; i < w; i++)
            {
                float u = (i - cx) / fx;
                float r = std::sqrt(u * u + v * v);
                float a = u / r;
                float b = v / r;
                float theta = solvetheta(r, k1);
                float t = 1.0f / std::tan(M_PI_2 - theta);
                float at = std::fabs(t);
                buf[idx++] = a * at;
                buf[idx++] = b * at;
                buf[idx++] = std::signbit(t) ? -1.0f : 1.0f;
            }
        }
        return buf;
    }

    void FisheyeLens::DistortPoint(float x, float y, float z, float *u, float *v) const
    {
        float r = std::sqrt(x * x + y * y);
        float theta = std::atan2(r, z);
        float dist = theta * (1 + k1 * theta * theta) / r;
        *u = fx * dist * x + cx;
        *v = fy * dist * y + cy;
    }

} // namespace ceiltrack
} // namespace lr