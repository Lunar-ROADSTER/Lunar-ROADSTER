#ifndef PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP
#define PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP

#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class GetWorksystemTrajectory : public FSM {

public:
  // void runState(const bool worksystem_enabled, bool &updated_trajectory, bool &calculated_trajectory);
  void runState();
  
}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP
