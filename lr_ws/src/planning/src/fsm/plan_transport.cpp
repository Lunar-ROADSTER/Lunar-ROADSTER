/**
 * @file plan_transport.cpp
 * @brief Orchestrates transport planning operations within the FSM framework.
 *
 * This component facilitates the planning of transport routes by processing height maps, seen areas, and distance thresholds to generate goal types, ultimately triggering FSM state updates for continued mission execution.
 * It integrates external planner logic to evaluate and optimize transport paths, handling scenarios where assignments are made based on predefined criteria.
 *
 * Key elements:
 *   - runState(): Executes the transport planning algorithm and manages subsequent state transitions.
 *
 * @version 1.0.0
 * @date 2025-07-19
 *
 * Maintainer: Boxiang (William) Fu
 * Team: Lunar ROADSTER  
 * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
 *
 * Inputs:
 * - transport_planner [lr::planning::TransportPlanner&]: Reference to the transport planner for executing planning logic.
 * - current_height_map [const lr::mapping::Map<float>&]: The current map of height values used in planning.
 * - design_height_map [const lr::mapping::Map<float>&]: The target design map for height comparisons.
 * - seen_map [const std::vector<int>&]: Vector representing areas that have been explored or seen.
 * - thresh_max_assignment_distance [const float]: Threshold value for maximum allowable distance in assignments.
 * - goalPose_types [std::vector<std::string>&]: Vector of strings for the types of goal poses generated or updated.
 *
 * Methods:
 * - runState(): Performs transport planning and updates FSM signals/states; outputs: None (void), but returns an objective value internally and modifies inputs by reference (e.g., updates goalPose_types and sets pre_signal_ and curr_state_l0_).
 *
 * @credit John Harrington, Team CraterGrader.
 */

#include <planning/fsm/plan_transport.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

  void PlanTransport::runState(lr::planning::TransportPlanner &transport_planner, const lr::mapping::Map<float> &current_height_map, const lr::mapping::Map<float> &design_height_map, const std::vector<int> &seen_map, const float thresh_max_assignment_distance, std::vector<std::string> &goalPose_types)
  {
    std::cout << "PLAN_TRANSPORT" << std::endl;

    float objective_value = transport_planner.planTransport(current_height_map, design_height_map, seen_map, thresh_max_assignment_distance, goalPose_types);
    std::cout << "    obj value: " << objective_value << std::endl;
    // Update shared current state and the precursing signal
    pre_signal_ = Signal::TRANSPORT_PLANNED;
    curr_state_l0_ = StateL0::GET_TRANSPORT_GOALS;
  }

} // planning namespace
} // lr namespace
