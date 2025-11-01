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

FSM::State FSM::stringToState(const std::string &state_str) {
	if (state_str == "START_MISSION") {
		return State::START_MISSION;
	} else if (state_str == "GLOBAL_NAV_PLANNER") {
		return State::GLOBAL_NAV_PLANNER;
	} else if (state_str == "GLOBAL_NAV_CONTROLLER") {
		return State::GLOBAL_NAV_CONTROLLER;
	} else if (state_str == "VALIDATION") {
		return State::VALIDATION;
	} else if (state_str == "PERCEPTION") {
		return State::PERCEPTION;
	} else if (state_str == "MANIPULATION_PLANNER") {
		return State::MANIPULATION_PLANNER;
	} else if (state_str == "MANIPULATION_CONTROLLER") {
		return State::MANIPULATION_CONTROLLER;
	} else if (state_str == "END_MISSION") {
		return State::END_MISSION;
	} else if (state_str == "STOPPED") {
		return State::STOPPED;
	} else if (state_str == "DEBUG") {
		return State::DEBUG;
	} else {
		return State::DEBUG; // Default to DEBUG for unrecognized strings
	}
}

} // namespace ben
} // namespace lr
