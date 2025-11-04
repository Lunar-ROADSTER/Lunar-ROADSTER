#ifndef PLANNING__END_MISSION_HPP
#define PLANNING__END_MISSION_HPP

#include <planning/fsm/fsm.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class EndMission : public FSM {

public:
  void runState();

}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__END_MISSION_HPP
