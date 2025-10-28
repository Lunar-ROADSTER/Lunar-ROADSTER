#pragma once

#include <cmath>

namespace lr {
namespace ceiltrack {

class FisheyeLens {

public:
    void SetCalibration(float fx, float fy, float cx, float cy, float k1);
    float* GenUndistortedPts(int w, int h) const;
    void DistortPoint(float x, float y, float z, float* u, float* v) const;
    float fx{}, fy{}, cx{}, cy{}, k1{};


private:
};

} // namespace ceiltrack
} // namespace lr