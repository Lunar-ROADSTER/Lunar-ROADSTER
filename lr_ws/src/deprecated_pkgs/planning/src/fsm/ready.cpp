/**
 * @file ready.cpp
 * @brief Handles the initial ready state, transitioning to map update in the planning FSM.
 *
 * This module serves as the entry point for FSM operations, where it signals the start of the mission and shifts to the UPDATE_MAP state to ensure the map is current before proceeding. Drawing from FSM details, UPDATE_MAP checks for map updates and manages state progression, making this step crucial for accurate mission initialization.
 * It focuses on setting up signals and states to kick off the process, preventing progression until map data is handled.
 *
 * Core features:
 *   - runState(): Sets the initial signal and transitions to UPDATE_MAP.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - None directly in runState(), but depends on internal FSM variables such as pre_signal_ and curr_state_l0_, which link to broader FSM logic like UPDATE_MAP.
 *
 * Methods:
 * - runState(): Initiates state transition to UPDATE_MAP; outputs: None (void), with side effects that set pre_signal_ to START and update curr_state_l0_ to trigger map-related operations.
 *
 * @credit John Harrington, Team CraterGrader.
 */
 
#include <planning/fsm/ready.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

void Ready::runState() {
  std::cout << "READY" << std::endl;

  // Update shared current state and the precursing signal
  pre_signal_ = Signal::START;
  curr_state_l0_ = StateL0::UPDATE_MAP;
}

} // planning namespace
} // lr namespace
