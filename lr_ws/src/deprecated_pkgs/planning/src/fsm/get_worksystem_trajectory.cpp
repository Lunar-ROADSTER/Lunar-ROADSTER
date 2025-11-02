/**
  * @file get_worksystem_trajectory.cpp
  * @brief Manages the retrieval of worksystem trajectories in the FSM for planning module.
  *
  * This component handles the logic for obtaining and transitioning based on worksystem trajectories, ensuring seamless state changes when conditions are met.
  * It focuses on checking tool status and updating FSM states accordingly.
  *
  * Key operations include:
  *   - runState(): Processes trajectory data and signals state shifts.
  *
  * @version 1.0.0
  * @date 2025-07-19
  *
  * Maintainer: Boxiang (William) Fu
  * Team: Lunar ROADSTER  
  * Team Members: Ankit Aggarwal, Deepam Ameria, Bhaswanth Ayapilla, Simson D’Souza, Boxiang (William) Fu
  *
  * Inputs:
  * - current_goalPose_type [std::string&]: The type of the current goal pose.
  * - wait_for_tool_ [bool&]: Flag indicating whether to wait for a tool.
  *
  * Methods:
  * - runState(): Executes trajectory logic; outputs: None (void), with side effects on FSM states.
  *
  * @credit John Harrington, Team CraterGrader.
  */
  
#include <planning/fsm/get_worksystem_trajectory.hpp>
#include <iostream> // DEBUG

namespace lr {
namespace planning {

void GetWorksystemTrajectory::runState(std::string &current_goalPose_type, bool &wait_for_tool_)
{
  std::cout << "GET_WORKSYSTEM_TRAJECTORY" << std::endl;

  std::cout << "current_goalPose_type = " << current_goalPose_type << std::endl;

  if (!wait_for_tool_) {
    pre_signal_ = Signal::FOLLOW_TRAJECTORY;
    curr_state_l0_ = StateL0::FOLLOWING_TRAJECTORY;
  }
}

} // planning namespace
} // lr namespace
