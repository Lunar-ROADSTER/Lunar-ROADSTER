#include "ortools/linear_solver/linear_solver.h"
#include <cmath> // for math operations, sqrt & floor 
#include <limits> // used for distance, infinity values
#include <algorithm> // checking number of values in vector (i.e. std::count), shuffling vector (std::shuffle)
#include <random> // random number generator
#include <iostream>
#include <vector>

struct Point2D {
    @default(value = 0.0)
    double x; // [m], continuous in global map frame
    @default(value = 0.0)
    double y; // [m], continuous in global map frame
};

struct Pose2D {
    Point2D pt;
    @default(value = 0.0)
    double yaw; // [rad], continuous in global map frame
};

struct TransportNode {
    // a struct which simply defines a points position in continous 3-space
      float x;
      float y;
      float height;
};
  
struct TransportAssignment {
    TransportNode source_node;
    TransportNode sink_node;
    float transport_volume;
};

struct Map{
    size_t height_;    // the vertical number of cells in the map
    size_t width_;     // the horizontal number of cells in the map
    float resolution_; // the resolution of each grid cell 
    std::vector<T> cell_data_; // the actual map data; should have height_ * width_ = cell_data_.size()
}


class myTransportPlanner {
    public:

    

}