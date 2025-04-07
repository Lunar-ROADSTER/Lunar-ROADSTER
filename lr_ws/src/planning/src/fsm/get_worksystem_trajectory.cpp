#include <planning/fsm/get_worksystem_trajectory.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

// void GetWorksystemTrajectory::runState(const bool worksystem_enabled, bool &updated_trajectory, bool &calculated_trajectory)
void GetWorksystemTrajectory::runState()
{
  std::cout << "GET_WORKSYSTEM_TRAJECTORY" << std::endl;

  // if (worksystem_enabled && updated_trajectory) {
  //   // Reset state flags for next trajectory iteration, if sent and enabled correctly
  //   updated_trajectory = false;
  //   calculated_trajectory = false;

  //   // Update shared current state and the precursing signal if trajectory was sent and worksystem is now enabled
  //   pre_signal_ = Signal::FOLLOW_TRAJECTORY;
  //   curr_state_l0_ = StateL0::FOLLOWING_TRAJECTORY;
  // }

  pre_signal_ = Signal::FOLLOW_TRAJECTORY;
  curr_state_l0_ = StateL0::FOLLOWING_TRAJECTORY;
}

} // planning namespace
} // cg namespace
