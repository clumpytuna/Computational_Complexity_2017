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
#include "Vertex.hpp"

class MaxCliqueSolver {
public:
  MaxCliqueSolver(Graph graph): graph_(graph) {}
  ~MaxCliqueSolver();
  size_t FindClique();
  void SetGraph(Graph graph);
  bool IsClique(std::set<Vertex> vertices);
  
private:
  Graph graph_;
  
};
bool MaxCliqueSolver::IsClique(std::set<Vertex> vertices) {
  for (const auto& vertex: vertices) {
    auto counter = 0;
    for (const auto &edge: graph_.adjacency_list_[vertex.GetNumber()]) {
        if (vertices.find(edge.GetFrom()) != vertices.end()) {
          counter += 1;
        }
      }
    if (counter != vertices.size() - 1) {
      return false;
    }
  }
  return true;
}

size_t MaxCliqueSolver::FindClique() {
  auto m = graph_.GetMaxDegree();
  auto lb = 0;
  auto ub = m;
  std::vector<size_t> clique;
  std::vector<size_t> iclique;
  auto mid = (lb + ub) / 2;
  auto k = graph_.GetNumberVetricesDegreeMoreX(mid);
  auto s = graph_.GetVerticesDegreeMoreX(mid);
  if (k > mid) {
    
  }
  
  
  return 0;
}

void MaxCliqueSolver::SetGraph(Graph graph) {
  graph_ = graph;
}


#endif /* MaxCliqueProblemSolver_h */