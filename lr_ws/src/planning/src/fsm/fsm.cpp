#include <planning/fsm/fsm.hpp>

namespace cg {
namespace planning {

// Initialize default static variables
FSM::StateL1 FSM::curr_state_l1_ = FSM::defaultStartStateL1();
FSM::StateL0 FSM::curr_state_l0_ = FSM::defaultStartStateL0();
FSM::Signal FSM::pre_signal_ = FSM::defaultStartSignal();

FSM::FSM(StateL1 start_state_l1, StateL0 start_state, Signal start_signal) {
  curr_state_l1_ = start_state_l1;
  curr_state_l0_ = start_state;
  pre_signal_ = start_signal;
}

FSM::~FSM(){
  // Reset to default states when being destroyed so new FSM objects start with defaults (e.g. for tests)
  curr_state_l1_ = FSM::defaultStartStateL1();
  curr_state_l0_ = FSM::defaultStartStateL0();
  pre_signal_ = FSM::defaultStartSignal();
}

std::string FSM::currStateL0ToString() {
  switch(curr_state_l0_) {
    case StateL0::READY:
      return "READY";
    case StateL0::UPDATE_MAP:
      return "UPDATE_MAP";
    case StateL0::SITE_WORK_DONE:
      return "SITE_WORK_DONE";
    case StateL0::MAP_EXPLORED:
      return "MAP_EXPLORED";
    case StateL0::PLAN_TRANSPORT:
      return "PLAN_TRANSPORT";
    case StateL0::GET_TRANSPORT_GOALS:
      return "GET_TRANSPORT_GOALS";
    case StateL0::GOALS_REMAINING:
      return "GOALS_REMAINING";
    case StateL0::GET_WORKSYSTEM_TRAJECTORY:
      return "GET_WORKSYSTEM_TRAJECTORY";
    case StateL0::FOLLOWING_TRAJECTORY:
      return "FOLLOWING_TRAJECTORY";
    case StateL0::END_MISSION:
      return "END_MISSION";
    case StateL0::STOPPED:
      return "STOPPED";
    default:
      return "State L0 not recognized!";
  }
}

std::string FSM::currStateL1ToString() {
  switch(curr_state_l1_) {
    case StateL1::EXPLORATION:
      return "EXPLORATION";
    case StateL1::TRANSPORT:
      return "TRANSPORT";
    default:
      return "State L1 not recognized";
  }
}

std::string FSM::preSignalToString()
{
  switch(pre_signal_) {
    case Signal::START:
      return "START";
    case Signal::STOP:
      return "STOP";
    case Signal::YES:
      return "YES";
    case Signal::NO:
      return "NO";
    case Signal::MAP_UPDATED:
      return "MAP_UPDATED";
    case Signal::TRANSPORT_PLANNED:
      return "TRANSPORT_PLANNED";
    case Signal::DRIVE:
      return "DRIVE";
    case Signal::FOLLOW_TRAJECTORY:
      return "FOLLOW_TRAJECTORY";
    case Signal::GOAL_REACHED:
      return "GOAL_REACHED";
    default:
      return "Signal not recognized!";
  }
}

} // planning namespace
} // cg namespace
