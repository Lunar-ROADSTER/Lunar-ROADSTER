#ifndef BEN__FSM_HPP
#define BEN__FSM_HPP

#include <string>

namespace lr {
namespace ben {

class FSM {

	public:
		enum class State {
			START_MISSION,
			// GENERATE_GLOBAL_WAYPOINTS,
			// NAVIGATE_TO_GLOBAL_WAYPOINT,
			// NAVIGATE_TO_LOCAL_WAYPOINT,
			// PLAN_TOOL_HEIGHT,
			// GRADING_CRATER,
			VALIDATION,
			// CHECK_GOALS_REMAINING,
			END_MISSION,
			STOPPED
		};

		// Constructor
		FSM(){};
		FSM(State start_state_);

		// Destructor
		~FSM();

		// Getters
		State getCurrState() const { return curr_state_; }

		// Setters
		void setCurrState(State curr_state) { curr_state_ = curr_state; }

		// Helpers
		std::string currStateToString();

		// Shared private variables
		protected:
			static State curr_state_;

	private:
  		static State defaultStartState() { return State::START_MISSION; }

};

} // namespace ben
} // namespace lr

#endif // BEN__FSM_HPP