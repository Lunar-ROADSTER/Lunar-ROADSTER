#ifndef PLANNING__PLAN_TRANSPORT_HPP
#define PLANNING__PLAN_TRANSPORT_HPP

#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Inherit from FSM to have access to current state/signal
class PlanTransport : public FSM {

public:
  void runState();

}; // class State

} // namespace planning
} // namespace cg

#endif // PLANNING__PLAN_TRANSPORT_HPP
