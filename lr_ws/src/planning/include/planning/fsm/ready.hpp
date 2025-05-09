#ifndef PLANNING__READY_HPP
#define PLANNING__READY_HPP

#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class Ready : public FSM {

public:
  void runState();

}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__READY_HPP
