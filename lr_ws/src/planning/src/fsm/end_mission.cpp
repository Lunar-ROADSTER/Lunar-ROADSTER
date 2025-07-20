/**
 * @file end_mission.cpp
 * @brief End Mission state implementation for finite state machine in planning module.
 *
 * This module implements the End Mission state, which signals the end of the mission by updating the current state and preceding signal.
 * It sets the system to a stopped condition.
 *
 * The implementation uses a simple state update mechanism:
 *   - runState(): Updates the preceding signal to STOP and sets the current state to STOPPED.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - None directly in runState(), but relies on internal state variables like pre_signal_ and curr_state_l0_.
 *
 * Methods:
 * - runState(): Executes the end mission logic to update states.
 *
 * @credit John Harrington, Team CraterGrader.
 */
 
#include <planning/fsm/end_mission.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

void EndMission::runState() {
  std::cout << "END_MISSION" << std::endl;

  // Update shared current state and the precursing signal
  pre_signal_ = Signal::STOP;
  curr_state_l0_ = StateL0::STOPPED;
}

} // planning namespace
} // lr namespace
