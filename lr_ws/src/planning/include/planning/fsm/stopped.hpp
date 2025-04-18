#ifndef PLANNING__STOPPED_HPP
#define PLANNING__STOPPED_HPP

#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class Stopped : public FSM {

public:
  void runState();

}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__STOPPED_HPP
