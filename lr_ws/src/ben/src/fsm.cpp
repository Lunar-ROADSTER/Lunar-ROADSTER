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
		// case State::GENERATE_GLOBAL_WAYPOINTS:
		// 	return "GENERATE_GLOBAL_WAYPOINTS";
		// case State::NAVIGATE_TO_GLOBAL_WAYPOINT:
		// 	return "NAVIGATE_TO_GLOBAL_WAYPOINT";
		// case State::NAVIGATE_TO_LOCAL_WAYPOINT:
		// 	return "NAVIGATE_TO_LOCAL_WAYPOINT";
		// case State::PLAN_TOOL_HEIGHT:
		// 	return "PLAN_TOOL_HEIGHT";
		// case State::GRADING_CRATER:
		// 	return "GRADING_CRATER";
		case State::VALIDATION:
			return "VALIDATION";
		// case State::CHECK_GOALS_REMAINING:
		// 	return "CHECK_GOALS_REMAINING";
		case State::END_MISSION:
			return "END_MISSION";
		case State::STOPPED:
			return "STOPPED";
		default:
			return "State not recognized!";
	}
}

} // namespace ben
} // namespace lr
