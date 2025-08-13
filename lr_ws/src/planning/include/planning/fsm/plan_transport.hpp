#ifndef PLANNING__PLAN_TRANSPORT_HPP
#define PLANNING__PLAN_TRANSPORT_HPP

#include <planning/fsm/fsm.hpp>
#include <planning/transport_planner.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class PlanTransport : public FSM {

  public:
  void runState(lr::planning::TransportPlanner &transport_planner, const lr::mapping::Map<float> &current_height_map, const lr::mapping::Map<float> &design_height_map, const std::vector<int> &seen_map, const float thresh_max_assignment_distance, std::vector<std::string> &goalPose_types); // Main function to run current state; optionally modifies signal and state for transition

}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__PLAN_TRANSPORT_HPP
