/**
 * @file update_map.cpp
 * @brief Manages map update checks and FSM state transitions.
 *
 * This module checks if the map is updated: if not, it stops; if yes, it skips to transport goals in debug mode.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - map_updated [const bool]: Whether the map has been updated.
 * - traj_debug [const bool]: Flag for trajectory debugging mode.
 *
 * Methods:
 * - runState(): Verifies map status and updates FSM states; outputs: None (void), with side effects on signals and states.
 *
 * @credit John Harrington, Team CraterGrader.
 */

#include <planning/fsm/update_map.hpp>
#include <iostream> // DEBUG

namespace lr {
  namespace planning {
  
    void UpdateMap::runState(const bool map_updated, const bool traj_debug)
    {
      std::cout << "UPDATE_MAP" << std::endl;
  
      // Don't move to next state if map is not updated
      if (!map_updated) {
        return;
      }
  
      // Skip directly to state for trajectory debugging
      if (traj_debug) {
        pre_signal_ = Signal::DRIVE;
        curr_state_l0_ = StateL0::GOALS_REMAINING;
        curr_state_l1_ = StateL1::TRANSPORT;
        return;
      }
  
      // Update shared current state and the precursing signal
      pre_signal_ = Signal::MAP_UPDATED;
      curr_state_l0_ = StateL0::SITE_WORK_DONE;
    }
  
  } // planning namespace
  } // lr namespace
  