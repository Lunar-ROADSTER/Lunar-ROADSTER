#include <ben/fsm.hpp>

namespace lr {
namespace ben {

// Initialize FSM
FSM::State FSM::curr_state_ = FSM::defaultStartState();

FSM::FSM(State start_state_)
{
	curr_state_ = start_state_;
}

FSM::~FSM()
{
	curr_state_ = FSM::defaultStartState();
}

// Helper to convert current state to string
std::string FSM::currStateToString() {
	switch(curr_state_) {
		case State::START_MISSION:
			return "START_MISSION";
		case State::GLOBAL_NAV_PLANNER:
			return "GLOBAL_NAV_PLANNER";
		case State::GLOBAL_NAV_CONTROLLER:
			return "GLOBAL_NAV_CONTROLLER";
		case State::VALIDATION:
			return "VALIDATION";
		case State::PERCEPTION:
			return "PERCEPTION";
		case State::MANIPULATION_PLANNER:
			return "MANIPULATION_PLANNER";
		case State::MANIPULATION_CONTROLLER:
			return "MANIPULATION_CONTROLLER";
		case State::END_MISSION:
			return "END_MISSION";
		case State::STOPPED:
			return "STOPPED";
		case State::DEBUG:
			return "DEBUG";
		default:
			return "State not recognized!";
	}
}

} // namespace ben
} // namespace lr
