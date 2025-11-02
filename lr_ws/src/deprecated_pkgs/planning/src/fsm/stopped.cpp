/**
 * @file stopped.cpp
 * @brief Manages the stopped state in the planning FSM.
 *
 * This module updates signals to halt operations and maintain the stopped state.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs: None
 *
 * Methods: runState(): Sets stopped signal and state; outputs: None (void), with side effects on FSM variables.
 *
 * @credit John Harrington, Team CraterGrader.
 */

#include <planning/fsm/stopped.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

void Stopped::runState() {
  std::cout << "STOPPED" << std::endl;

  // Update shared current state and the precursing signal
  pre_signal_ = Signal::STOP;
  curr_state_l0_ = StateL0::STOPPED;
}

} // planning namespace
} // lr namespace
