#ifndef PLANNING__UPDATE_MAP_HPP
#define PLANNING__UPDATE_MAP_HPP

#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class UpdateMap : public FSM {

public:
  void runState(const bool map_updated, const bool traj_debug);
  
}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__UPDATE_MAP_HPP
