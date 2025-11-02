/**
 * @file map_explored.cpp
 * @brief Manages transitions after map exploration in the planning FSM.
 *
 * This script coordinates the post-exploration phase, ensuring the system advances to transport planning by updating relevant signals and states upon completion.
 * It streamlines the FSM flow by checking exploration status and initiating the next operational phase.
 *
 * Core functionality:
 *   - runState(): Triggers state changes for subsequent planning steps.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - None directly in runState(), but relies on internal FSM variables like pre_signal_, curr_state_l0_, and curr_state_l1_.
 *
 * Methods:
 * - runState(): Handles state transitions; outputs: None (void), with side effects on FSM signals and states.
 *
 * @credit John Harrington, Team CraterGrader.
 */
 
#include <planning/fsm/map_explored.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

void MapExplored::runState() {
  std::cout << "MAP_EXPLORED" << std::endl;
  
  pre_signal_ = Signal::YES;
  curr_state_l0_ = StateL0::PLAN_TRANSPORT;
  curr_state_l1_ = StateL1::TRANSPORT;
}

} // planning namespace
} // lr namespace
