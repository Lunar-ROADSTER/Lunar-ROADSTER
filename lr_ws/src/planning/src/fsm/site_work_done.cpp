#include <planning/fsm/site_work_done.hpp>
#include <iostream> // DEBUG

namespace cg {
namespace planning {

// void SiteWorkDone::runState(const cg::mapping::Map<float> &current_height_map, const cg::mapping::Map<float> &design_height_map, float topology_equality_threshold) {
void SiteWorkDone::runState() {  
  std::cout << "SITE_WORK_DONE" << std::endl;

  // bool within_thresh = cg::mapping::mapSimilarityWithinThreshold(
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
} // cg namespace
