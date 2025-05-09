#ifndef PLANNING__TRANSPORT_PLANNER_HPP
#define PLANNING__TRANSPORT_PLANNER_HPP

#include <planning/common.hpp>
#include <planning/goal_planner.hpp>
#include <mapping/map.hpp>
#include "ortools/linear_solver/linear_solver.h"
#include <cmath> // for math operations, sqrt & floor 
#include <limits> // used for distance, infinity values
#include <algorithm> // checking number of values in vector (i.e. std::count), shuffling vector (std::shuffle)
#include <random> // random number generator
#include <string>



namespace cg {
namespace planning {

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

class TransportPlanner : public GoalPlanner {

public:
  // Constructor()
  TransportPlanner(){};

  // Computations()
  float planTransport(const cg::mapping::Map<float> &current_height_map, const cg::mapping::Map<float> &design_height_map, const std::vector<int> &seen_map, const float thresh_max_assignment_distance, std::vector<std::string> &goalPoses_types);
  std::vector<cg_msgs::msg::Pose2D> getGoalPose(const cg_msgs::msg::Pose2D &agent_pose, const cg::mapping::Map<float> &map, std::vector<std::string> &goalPose_types);
  std::vector<cg_msgs::msg::Pose2D> getUnvisitedGoalPoses(std::vector<std::string> &goalPose_types);
  void getGoalPoseType(std::vector<std::string> &goalPose_types);
  void makeGoalsFromAssignment(const std::vector<TransportAssignment> &transport_assignments, const size_t assignment_idx, std::vector<cg_msgs::msg::Pose2D> &goalPoses, std::vector<std::string> &goalPose_types);

  float solveToyProblem(); // For implementation verification purposes only

  // Helpers()
  size_t ij_to_index(size_t x, size_t y, size_t width) const;
  void init_nodes(std::vector<TransportNode> &source_nodes, std::vector<TransportNode> &sink_nodes, float &vol_source, float &vol_sink, const cg::mapping::Map<float> &current_height_map, const cg::mapping::Map<float> &design_height_map, const std::vector<int> &seen_map);
  void calculate_distances(std::vector<float> &distances_between_nodes, const std::vector<TransportNode> &source_nodes, const std::vector<TransportNode> &sink_nodes);
  float solveForTransportAssignments(std::vector<TransportAssignment> &new_transport_assignments, const std::vector<TransportNode> &source_nodes, const std::vector<TransportNode> &sink_nodes, const std::vector<float> &distances_between_nodes, const float vol_source, const float vol_sink, const float thresh_max_assignment_distance, std::vector<std::string> &goalPose_types , bool verbose);
  void filterAssignments(std::vector<TransportAssignment> &new_transport_assignments, std::vector<std::string> &goalPose_types);

  // Getters()
  std::vector<TransportAssignment> getTransportAssignments() const {return transport_assignments_;};

  // Setters()
  void setLastPoseOffset(double last_pose_offset){last_pose_offset_ = last_pose_offset;};
  void setSourcePoseOffset(double source_pose_offset) { source_pose_offset_ = source_pose_offset; };
  void setSourceThresholdZ(float source_threshold_z) { source_threshold_z_ = source_threshold_z; };
  void setSinkThresholdZ(float sink_threshold_z) { sink_threshold_z_ = sink_threshold_z; };
  void setBoundaryMin(float boundary_min) { boundary_min_ = boundary_min; };
  void setBoundaryMax(float boundary_max) { boundary_max_ = boundary_max; };
  void setThreshFilterAssignmentPos(float thresh_filter_assignment_pos) { thresh_filter_assignment_pos_ = thresh_filter_assignment_pos; };
  void setThreshFilterAssignmentHead(double thresh_filter_assignment_head) { thresh_filter_assignment_head_ = thresh_filter_assignment_head; };

private: 
  // Attributes
  std::vector<TransportAssignment> transport_assignments_; // Assignments for transporting volume from a source to a sink (i.e. the non-zero transports)
  std::vector<bool> unvisited_assignments_; // each index corresponds to a TransportAssignment in transport_assignments. true = unvisited, false = visited
  double last_pose_offset_ = 1.0; // Offset for how far back to make final pose rearward of the first source node
  double source_pose_offset_ = 1.0; // Offset for how far back to make final pose rearward of the original source node; positive is further from crater rim, negative is closer to crater valley

  float sink_threshold_z_ = 0.03;
  float source_threshold_z_ = 0.03;
  float boundary_min_ = 0.4;
  float boundary_max_ = 4.6;
  float boundary_increment_ = 0.01;

  float thresh_filter_assignment_pos_ = 0.0;
  double thresh_filter_assignment_head_ = 6.28;
};

} // namespace planning
} // namespace cg

#endif // PLANNING__TRANSPORT_PLANNER_HPP
