#ifndef PLANNING__SITE_WORK_DONE_HPP
#define PLANNING__SITE_WORK_DONE_HPP

#include <planning/fsm/fsm.hpp>
// #include <mapping/map.hpp>
// #include <mapping/map_util.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class SiteWorkDone : public FSM {

public:
  // void runState(const cg::mapping::Map<float> &current_height_map, const cg::mapping::Map<float> &design_height_map, float topology_equality_threshold);
  void runState();

}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__SITE_WORK_DONE_HPP
