#include <planning/fsm/get_worksystem_trajectory.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

void GetWorksystemTrajectory::runState(std::string &current_goalPose_type, bool &wait_for_tool_)
{
  std::cout << "GET_WORKSYSTEM_TRAJECTORY" << std::endl;

  std::cout << "current_goalPose_type = " << current_goalPose_type << std::endl;

  if (!wait_for_tool_) {
    pre_signal_ = Signal::FOLLOW_TRAJECTORY;
    curr_state_l0_ = StateL0::FOLLOWING_TRAJECTORY;
  }
}

} // planning namespace
} // cg namespace
