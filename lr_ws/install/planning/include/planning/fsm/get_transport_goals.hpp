#ifndef PLANNING__GET_TRANSPORT_GOALS_HPP
#define PLANNING__GET_TRANSPORT_GOALS_HPP

#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class GetTransportGoals : public FSM {

public:
  void runState();
}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__GET_TRANSPORT_GOALS_HPP
