#ifndef PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP
#define PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP

#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class GetWorksystemTrajectory : public FSM {

public:
  void runState(std::string &current_goalPose_type, bool &wait_for_tool_);
  
}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP
