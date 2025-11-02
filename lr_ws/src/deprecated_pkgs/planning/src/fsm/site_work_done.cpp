/**
 * @file site_work_done.cpp
 * @brief Processes the site work done state, evaluating completion and triggering FSM transitions.
 *
 * This module checks if site work is complete, originally designed to compare current and design height maps against a threshold to determine similarity, 
 * but currently operates in debug mode with hardcoded state updates. 
 *
 * Core elements:
 *   - runState(): Performs site work checks and updates FSM states accordingly.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - None in the active runState() implementation, but the commented section references intended parameters like 
 *   current_height_map (const lr::mapping::Map<float>&), design_height_map (const lr::mapping::Map<float>&), and topology_equality_threshold (float); 
 *   it relies on internal FSM variables such as pre_signal_ and curr_state_l0_.
 *
 * Methods:
 * - runState(): Executes debug logic to set pre_signal_ to Signal::NO and curr_state_l0_ to StateL0::MAP_EXPLORED; outputs: None (void), with side effects that influence FSM progression.
 *
 * @credit John Harrington, Team CraterGrader.
 */

#include <planning/fsm/site_work_done.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

// void SiteWorkDone::runState(const lr::mapping::Map<float> &current_height_map, const lr::mapping::Map<float> &design_height_map, float topology_equality_threshold) {
void SiteWorkDone::runState() {  
  std::cout << "SITE_WORK_DONE" << std::endl;

  // bool within_thresh = lr::mapping::mapSimilarityWithinThreshold(
  //   current_height_map.getCellData(), 
  //   design_height_map.getCellData(), 
  //   topology_equality_threshold);

  // // Update shared current state and the precursing signal
  // // TODO: also check amount of the map that has been explored?
  // if (within_thresh) {
  //   pre_signal_ = Signal::YES;
  //   curr_state_l0_ = StateL0::END_MISSION;
  // } else {
  // pre_signal_ = Signal::NO;
  // curr_state_l0_ = StateL0::MAP_EXPLORED;
  // }
  pre_signal_ = Signal::NO; // DEBUG
  curr_state_l0_ = StateL0::MAP_EXPLORED; // DEBUG
}

} // planning namespace
} // lr namespace
