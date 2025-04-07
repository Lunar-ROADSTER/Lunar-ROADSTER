
#include <lr_planning/myTransportPlanner.h>


size_t myTransportPlanner::ij_to_index(size_t i, size_t j, size_t width) const {
    return (j + (i * width));
}

Point2D create_point2d(const double& x, const double& y) {
    Point2D pt;
    pt.x = x;
    pt.y = y;
    return pt;
  }
  
Pose2D create_pose2d(const double& x, const double& y, const double& yaw) {
    Pose2D pose;
    pose.pt = create_point2d(x, y);
  
    // Normalize yaw within 0,2*M_PI for distance thresholding and debugging
    float norm_yaw = std::fmod(yaw, 2.0*M_PI);
    if (norm_yaw < 0.0f) norm_yaw += 2.0*M_PI;
  
    pose.yaw = norm_yaw;
    return pose;
  }
  
float euclidean_distance(const Point2D& pt1, const Point2D& pt2) {
    return std::sqrt((pt2.x - pt1.x) * (pt2.x - pt1.x) + (pt2.y - pt1.y) * (pt2.y - pt1.y));
  }
  
  // float angle_difference(const float angle_1, const float angle_2) {
  //   float angle_difference = std::fmod((angle_1 - angle_2) + M_PI, 2.0*M_PI) - M_PI;
  //   return angle_difference;
  // }
  
  float rad2deg(float rad) {
    return 180 * (rad / M_PI);
  }
  
  float deg2rad(float deg) {
    return M_PI * (deg / 180);
  }



// TODO: need to port the mapping stuff or write equivalent code 

void myTransportPlanner::init_nodes(std::vector<TransportNode> &source_nodes, std::vector<TransportNode> &sink_nodes, float &vol_source, float &vol_sink, Map &current_height_map, Map<float> &design_height_map, const std::vector<int> &seen_map)
{

  // Loop through height map and assign points to either source or sink
  size_t num_cells = current_height_map.getHeight() * current_height_map.getWidth();
  for (size_t i = 0; i < num_cells; i++)
  {
    // Put associated coordinates and height with each index into a node
    Point2D pt = current_height_map.indexToContinuousCoords(i);
    float cell_height = current_height_map.getDataAtIdx(i);
    TransportNode node;

    // Skip cell if not seen
    if (seen_map[i] == 0) continue;

    // Positive height becomes a source; positive volume in +z
    if (cell_height > (design_height_map.getDataAtIdx(i) + source_threshold_z_))
    {
      node.x = pt.x;
      node.y = pt.y;
      node.height = cell_height;

      vol_source += node.height;
      source_nodes.push_back(node);
    }
    // Negative height becomes a sink; for solver the sinks also must have positive volume, defined as positive in -z
    else if (cell_height < (design_height_map.getDataAtIdx(i) - sink_threshold_z_))
    {
      node.x = pt.x;
      node.y = pt.y;
      node.height = -cell_height;

      vol_sink += node.height;
      sink_nodes.push_back(node);
    }
  }
}


void TransportPlanner::calculate_distances(std::vector<float> &distances_between_nodes, const std::vector<TransportNode> &source_nodes, const std::vector<TransportNode> &sink_nodes)
{
  // source then sink loop makes vector row major order
  for (size_t i = 0; i < source_nodes.size(); i++)
  {
    for (size_t j = 0; j < sink_nodes.size(); j++)
    {
      // Calculate distance between points
      Point2D source_pt = create_point2d(source_nodes[i].x, source_nodes[i].y);
      Point2D sink_pt = create_point2d(sink_nodes[j].x, sink_nodes[j].y);
      float distance = euclidean_distance(source_pt, sink_pt);
      distances_between_nodes.push_back(distance);
    }
  }
}

/**
 * @brief Helper to solve optimization problem for finding transport plan and the non-zero transport assignments.
 * 
 * Additional notes:
 * - This method also updates new_transport_assignments with the non-zero source-to-sink transports from the optimization solution.
 * - The source and sink volumes are used to calculate the binary decision variable.
 * 
 * @param new_transport_assignments Container of transport assignments to be populated; will be cleared before population
 * @param source_nodes Filled container of source nodes
 * @param sink_nodes Filled container of sink nodes
 * @param distances_between_nodes Filled container of distance values, expected with row-major order
 * @param vol_source Sum of all source volume
 * @param vol_sink Sum of all sink volume
 * @param verbose Optional flag for displaying log info
 * @return float Optimization objective value
 */
using namespace operations_research;
float TransportPlanner::solveForTransportAssignments(std::vector<TransportAssignment> &new_transport_assignments, const std::vector<TransportNode> &source_nodes, const std::vector<TransportNode> &sink_nodes, const std::vector<float> &distances_between_nodes, const float vol_source, const float vol_sink, const float thresh_max_assignment_distance, bool verbose = false)
{
  // Declare the solver.
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  std::unique_ptr<MPSolver> solver(MPSolver::CreateSolver("GLOP"));
  const double infinity = solver->infinity();

  // Create the variables.
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  size_t n_policy = source_nodes.size();
  size_t m_policy = sink_nodes.size();
  size_t num_cells_policy = n_policy * m_policy;

  // Create row-major vector to represent the NxM transport matrix
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  std::vector<MPVariable *> transport_plan;
  std::vector<std::string> varNames;
  for (size_t t = 0; t < num_cells_policy; t++)
  {
    std::string numVarName = 't' + std::to_string(t);
    varNames.push_back(numVarName);
    transport_plan.push_back(solver->MakeNumVar(0.0, infinity, numVarName));
  }

  // Define the objective.
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  MPObjective *const objective = solver->MutableObjective();
  for (size_t t = 0; t < num_cells_policy; t++)
  {
    objective->SetCoefficient(transport_plan.at(t), distances_between_nodes.at(t));
  }
  objective->SetMinimization();

  // Define the constraints.
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  float M = std::max(vol_sink, vol_source);

  // Set binary decision variable online using input volumes
  int b;
  if (vol_sink > vol_source)
  {
    b = 0;
  }
  else
  {
    b = 1;
  }

  // constraint on all transports in transport plan lower bound sink max
  std::vector<MPConstraint *> constraints_sink_lb;
  for (size_t j = 0; j < m_policy; j++)
  {
    // create a constraint for each sink
    constraints_sink_lb.push_back(solver->MakeRowConstraint(-infinity, sink_nodes.at(j).height));
    for (size_t i = 0; i < n_policy; i++)
    {
      // this should capture all of the transport colmns
      size_t index = ij_to_index(i, j, m_policy);
      constraints_sink_lb.at(j)->SetCoefficient(transport_plan.at(index), 1);
    }
  }

  // constraint on all transports in transport plan lower bound source max
  std::vector<MPConstraint *> constraints_source_lb;
  for (size_t i = 0; i < n_policy; i++)
  {
    // create a constraint for each sink
    constraints_source_lb.push_back(solver->MakeRowConstraint(-infinity, source_nodes.at(i).height));
    for (size_t j = 0; j < m_policy; j++)
    {
      // want all the rows
      size_t index = ij_to_index(i, j, m_policy);
      constraints_source_lb.at(i)->SetCoefficient(transport_plan.at(index), 1);
    }
  }

  // mixted integer constraint sink
  std::vector<MPConstraint *> constraints_sink_milp;
  for (size_t j = 0; j < m_policy; j++)
  {
    // create a constraint for each sink
    constraints_sink_milp.push_back(solver->MakeRowConstraint((sink_nodes.at(j).height - (M * (1 - b))), infinity));
    for (size_t i = 0; i < n_policy; i++)
    {
      size_t index = ij_to_index(i, j, m_policy);
      constraints_sink_milp.at(j)->SetCoefficient(transport_plan.at(index), 1);
    }
  }

  // constraint on all transports in transport plan lower bound source max
  std::vector<MPConstraint *> constraints_source_milp;
  for (size_t i = 0; i < n_policy; i++)
  {
    // create a constraint for each sink
    constraints_source_milp.push_back(solver->MakeRowConstraint(source_nodes.at(i).height - (M * b), infinity));
    for (size_t j = 0; j < m_policy; j++)
    {
      size_t index = ij_to_index(i, j, m_policy);
      constraints_source_milp.at(i)->SetCoefficient(transport_plan.at(index), 1);
    }
  }

  // Solve the problem.
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  solver->Solve();

  // Extract the results.
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Transport assignments from optimization variables
  new_transport_assignments.clear(); // Make sure assignments start as empty set
  for (size_t i = 0; i < n_policy; i++)
  {
    for (size_t j = 0; j < m_policy; j++)
    {
      size_t index = ij_to_index(i, j, m_policy);
      float transport_volume = transport_plan.at(index)->solution_value();
      // All non-zero transports that are close enough should be added as assignments
      Point2D source_pt = create_point2d(source_nodes[i].x, source_nodes[i].y);
      Point2D sink_pt = create_point2d(sink_nodes[j].x, sink_nodes[j].y);
      if ((transport_volume > 0) && (cg::planning::euclidean_distance(source_pt, sink_pt) <= thresh_max_assignment_distance))
      {
        TransportAssignment new_assignment = {.source_node = source_nodes[i], .sink_node = sink_nodes[j], .transport_volume = transport_volume};
        new_transport_assignments.push_back(new_assignment);
      }
    }
  }
  
  // Filter assignments to final set for planner to use
  filterAssignments(new_transport_assignments);

  // update unvisited assignments, set all to true
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  unvisited_assignments_.clear(); // clear all previous unvisited_assignments 
  unvisited_assignments_.resize(new_transport_assignments.size(), true); // update to correct size of transport plan, setting all true because they are unvisited

  // Display log info
  if (verbose) {
    LOG(INFO) << "Number of variables = " << solver->NumVariables();
    LOG(INFO) << "Number of constraints = " << solver->NumConstraints();
    LOG(INFO) << "Solution:" << std::endl;
    LOG(INFO) << "Objective value = " << objective->Value();
    for (size_t t = 0; t < num_cells_policy; t++)
    {
      LOG(INFO) << varNames.at(t) << ": " << transport_plan.at(t)->solution_value();
    }
  }

  // Return the objective value
  return objective->Value();
}

void TransportPlanner::filterAssignments(std::vector<TransportAssignment> &new_transport_assignments) {

  std::vector<TransportAssignment> filtered_transport_assignments;

  // Initialize boolean mask to false
  std::vector<bool> keep_assignment(new_transport_assignments.size(), false);

  for (size_t i=0; i < new_transport_assignments.size(); ++i) {

    // bool keep_assignment = true;
    std::vector<Pose2D> assignment_goal_poses;
    makeGoalsFromAssignment(new_transport_assignments, i, assignment_goal_poses);
    Pose2D assignment_source_pose = assignment_goal_poses[0];
    bool no_similar_poses = true;
    for (size_t j=0; j < i; ++j) {
      
      std::vector<Pose2D> check_assignment_goal_poses;
      makeGoalsFromAssignment(new_transport_assignments, j, check_assignment_goal_poses);
      Pose2D check_assignment_source_pose = check_assignment_goal_poses[0];

      // Skip transport that is too close
      if (cg::planning::samePoseWithinThresh(assignment_source_pose, check_assignment_source_pose, thresh_filter_assignment_pos_, thresh_filter_assignment_head_) && keep_assignment[j]) {
        no_similar_poses = false;
        break;
      }
    }

    if (no_similar_poses) {
      keep_assignment[i] = true;
    }

  }

  // Keep assignments
  for (size_t i = 0; i < new_transport_assignments.size(); ++i) {
    if (keep_assignment[i]) {
      filtered_transport_assignments.push_back(new_transport_assignments[i]);
    }
  }
  new_transport_assignments = filtered_transport_assignments;
}

/**
 * @brief Primary method to plan optimal transport of volume from source nodes to sink nodes
 * 
 * Assumptions:
 * - Current and design height maps have same dimensions and resolution
 * - Height maps and threshold have same units
 * 
 * @param current_height_map The current height map that should be modified by the robot
 * @param design_height_map The desired final height map
 * @return float The optimization objective value
 */
float TransportPlanner::planTransport(const cg::mapping::Map<float> &current_height_map, const cg::mapping::Map<float> &design_height_map, const std::vector<int> &seen_map, const float thresh_max_assignment_distance)
{
  // ---------------------------------------------------
  // Initialize nodes and volume sums
  std::vector<TransportNode> source_nodes;
  std::vector<TransportNode> sink_nodes;
  float vol_source = 0.0f;
  float vol_sink = 0.0f;
  init_nodes(source_nodes, sink_nodes, vol_source, vol_sink, current_height_map, design_height_map, seen_map);

  // ---------------------------------------------------
  // Calculate distances between nodes
  std::vector<float> distances_between_nodes;
  calculate_distances(distances_between_nodes, source_nodes, sink_nodes);

  // ---------------------------------------------------
  // Solve the transport optimization problem
  std::vector<TransportAssignment> new_transport_assignments;
  float objective_value = solveForTransportAssignments(new_transport_assignments, source_nodes, sink_nodes, distances_between_nodes, vol_source, vol_sink, thresh_max_assignment_distance);

  // Update current transport assignments
  transport_assignments_ = new_transport_assignments;
  return objective_value;
}

/**
 * @brief Toy problem to verify optimization implementation; solution should match write-up derivation and Python prototype
 * 
 * Additional notes:
 * - Adjust the verbose variable in the method to toggle printing more detailed log/solution info
 *
 * @return float The optimization objective value
 */
float TransportPlanner::solveToyProblem() {
  // ---------------------------------------------------
  // Initialize nodes and volume sums manually
  TransportNode y1 = {.x = -1, .y = -3.5, .height = 0.3};
  TransportNode y2 = {.x = -1.5, .y = 1.8, .height = 0.4};
  TransportNode y3 = {.x = 2.5, .y = 1.5, .height = 0.3};
  std::vector<TransportNode> source_nodes{y1, y2, y3};
  // n source nodes = 3

  TransportNode x1 = {.x = -2, .y = -3, .height = 0.4};
  TransportNode x2 = {.x = -1, .y = 2, .height = 0.1};
  TransportNode x3 = {.x = 2, .y = 1, .height = 0.3};
  TransportNode x4 = {.x = 3, .y = 1, .height = 0.2};
  std::vector<TransportNode> sink_nodes{x1, x2, x3, x4};
  // m sink nodes = 4

  // Sum volumes manually
  float vol_source = 0.0f;
  float vol_sink = 0.0f;
  for (TransportNode node : source_nodes) {
    vol_source += node.height;
  }
  for (TransportNode node : sink_nodes) {
    vol_sink += node.height;
  }

  // ---------------------------------------------------
  // Calculate distances between nodes
  std::vector<float> distances_between_nodes;
  calculate_distances(distances_between_nodes, source_nodes, sink_nodes);

  // ---------------------------------------------------
  // Solve the transport optimization problem
  std::vector<TransportAssignment> new_transport_assignments;
  bool verbose = false;
  float objective_value = solveForTransportAssignments(new_transport_assignments, source_nodes, sink_nodes, distances_between_nodes, vol_source, vol_sink, verbose);

  return objective_value;
}
