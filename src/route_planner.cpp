#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    start_node = &m_Model.FindClosestNode(start_x, start_y);
    end_node = &m_Model.FindClosestNode(end_x, end_y);   
}


float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
    return node->distance(*end_node);
}


void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
  current_node->FindNeighbors();
  for (auto neighbor: current_node->neighbors) {
    neighbor->parent = current_node;
    neighbor->h_value = CalculateHValue(neighbor);
    neighbor->g_value = current_node->g_value+current_node->distance(*neighbor);
    neighbor->visited = true;
    open_list.push_back(neighbor);
  }

}


bool RoutePlanner::Compare(RouteModel::Node *node_1, RouteModel::Node *node_2) {
    return (node_1->g_value+node_1->h_value <= node_2->g_value+node_2->h_value);
  }

RouteModel::Node *RoutePlanner::NextNode() {
  std::stable_sort(open_list.begin(), open_list.end(), Compare);
  RouteModel::Node* best_node = open_list[0];
  open_list.erase(open_list.begin());
  return best_node;
}


std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
    // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;

    // TODO: Implement your solution here.
  
    while (current_node != start_node) {
      path_found.push_back(*current_node);
      distance += current_node->distance(*(current_node->parent));
      current_node = current_node->parent;
    }
    path_found.push_back(*start_node);
    std::reverse(path_found.begin(), path_found.end());

    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;

}


void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;

    // TODO: Implement your solution here.
    current_node = start_node;
    start_node->visited = true;
  
    while (current_node != end_node) {
      AddNeighbors(current_node);
      current_node = NextNode();
    }
    m_Model.path = ConstructFinalPath(current_node);
}