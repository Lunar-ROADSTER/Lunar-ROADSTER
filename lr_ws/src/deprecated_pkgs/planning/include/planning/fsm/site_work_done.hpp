#ifndef PLANNING__SITE_WORK_DONE_HPP
#define PLANNING__SITE_WORK_DONE_HPP

#include <planning/fsm/fsm.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class SiteWorkDone : public FSM {

public:
  // void runState(const lr::mapping::Map<float> &current_height_map, const lr::mapping::Map<float> &design_height_map, float topology_equality_threshold);
  void runState();

}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__SITE_WORK_DONE_HPP
