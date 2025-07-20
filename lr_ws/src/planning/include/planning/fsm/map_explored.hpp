#ifndef PLANNING__MAP_EXPLORED_HPP
#define PLANNING__MAP_EXPLORED_HPP

#include <planning/fsm/fsm.hpp>

namespace lr {
namespace planning {

// Inherit from FSM to have access to current state/signal
class MapExplored : public FSM {

public:

  void runState();

private:

}; // class State

} // namespace planning
} // namespace lr

#endif // PLANNING__MAP_EXPLORED_HPP
