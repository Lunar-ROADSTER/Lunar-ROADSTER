#include <planning/fsm/map_explored.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

void MapExplored::runState() {
  std::cout << "MAP_EXPLORED" << std::endl;
  
  pre_signal_ = Signal::YES;
  curr_state_l0_ = StateL0::PLAN_TRANSPORT;
  curr_state_l1_ = StateL1::TRANSPORT;
}

} // planning namespace
} // cg namespace
