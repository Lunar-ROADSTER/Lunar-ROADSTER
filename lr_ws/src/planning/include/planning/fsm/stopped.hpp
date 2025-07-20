#ifndef PLANNING__STOPPED_HPP
#define PLANNING__STOPPED_HPP

#include <planning/fsm/fsm.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class Stopped : public FSM {

public:
  void runState();

}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__STOPPED_HPP
