#include <planning/fsm/get_transport_goals.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

  void GetTransportGoals::runState()
  {
    std::cout << "GET_TRANSPORT_GOALS" << std::endl;

    // Update shared current state and the precursing signal
    pre_signal_ = Signal::DRIVE;
    curr_state_l0_ = StateL0::GOALS_REMAINING;
  }

} // planning namespace
} // cg namespace
