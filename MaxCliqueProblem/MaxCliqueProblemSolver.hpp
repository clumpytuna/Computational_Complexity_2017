//
//  MaxCliqueProblemSolver.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#ifndef MaxCliqueProblemSolver_hpp
#define MaxCliqueProblemSolver_hpp

#include <iostream>
#include <set>
#include "Graph.hpp"
#include "Subsetter.hpp"
#include "Vertex.hpp"

class MaxCliqueSolver {
public:
  MaxCliqueSolver(Graph graph)
      : graph_(graph),
        left_border_max_clique_size_(0),
        right_border_max_clique_size_(graph_.GetMaxDegree()),
        max_clique_size_(0){}
  ~MaxCliqueSolver() {};
  
  size_t FindClique();
  void SetGraph(Graph graph);
  
private:
  bool Select(size_t cliqueSize);
  size_t GetNextPretenderSize();
  Graph graph_;
  std::vector<Vertex> current_vertex_set_;
  std::set<Vertex> current_max_clique_;
  std::set<Vertex> max_clique_;
  size_t max_clique_size_;
  size_t left_border_max_clique_size_;
  size_t right_border_max_clique_size_;
  size_t num_vertices_degree_more_x_;
};

size_t MaxCliqueSolver::GetNextPretenderSize() {
  return (left_border_max_clique_size_ + right_border_max_clique_size_) / 2;
}

size_t MaxCliqueSolver::FindClique() {
  size_t pretender_size = GetNextPretenderSize();
  while (true) {
    num_vertices_degree_more_x_ = graph_.GetNumberVetricesDegreeMoreX(pretender_size);
    current_vertex_set_ = graph_.GetVerticesDegreeMoreX(pretender_size);
    if (num_vertices_degree_more_x_ > pretender_size) {
      if (Select(pretender_size + 1)) {
        max_clique_size_ = pretender_size + 1;
        max_clique_ = current_max_clique_;
        left_border_max_clique_size_ = pretender_size + 1;
      } else {
        right_border_max_clique_size_ = pretender_size - 1;
      }
    } else {
      right_border_max_clique_size_ = pretender_size - 1;
    }
  
    if ( left_border_max_clique_size_ <= right_border_max_clique_size_) {
      pretender_size = GetNextPretenderSize();
    } else {
      return max_clique_size_;
    }
  }

}

bool MaxCliqueSolver::Select(size_t cliqueSize) {
  std::set<Vertex> pretender_clique;
  Subsetter subsetter(current_vertex_set_, cliqueSize);
  while (subsetter.GetNextSubset(pretender_clique)) {
    if (graph_.IsClique(pretender_clique)) {
      current_max_clique_ = pretender_clique;
      return true;
    }
  }
  return false;
}

void MaxCliqueSolver::SetGraph(Graph graph) {
  graph_ = graph;
}


#endif /* MaxCliqueProblemSolver_h */
