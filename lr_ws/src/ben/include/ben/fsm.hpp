#ifndef BEN__FSM_HPP
#define BEN__FSM_HPP

#include <string>
#include <stdexcept>

namespace lr {
namespace ben {

class FSM {

	public:
		enum class State {
			START_MISSION,
			GLOBAL_NAV_PLANNER,
			GLOBAL_NAV_CONTROLLER,
			VALIDATION,
			PERCEPTION,
			MANIPULATION_PLANNER,
			MANIPULATION_CONTROLLER,
			END_MISSION,
			STOPPED,
			DEBUG,
			MANUAL_OVERRIDE
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
		State stringToState(const std::string &state_str);

		// Shared private variables
		protected:
			static State curr_state_;

	private:
  		static State defaultStartState() { return State::START_MISSION; }

};

} // namespace ben
} // namespace lr

#endif // BEN__FSM_HPP