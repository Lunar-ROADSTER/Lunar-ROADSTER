#ifndef PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP
#define PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP

#include <planning/fsm/fsm.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class GetWorksystemTrajectory : public FSM {

public:
  void runState(std::string &current_goalPose_type, bool &wait_for_tool_);
  
}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__GET_WORKSYSTEM_TRAJECTORY_HPP
