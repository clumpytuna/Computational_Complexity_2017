//
//  main.cpp
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#include <iostream>
#include "Graph.hpp"
#include "Vertex.hpp"

class MaxCliqueSolver {
public:
  size_t FindClique(Graph &graph);

private:
  Graph graph_;
};

size_t MaxCliqueSolver::FindClique(Graph &graph) {
  auto m = graph.GetMaxDegree();
  auto lb = 0;
  auto ub = m;
  std::vector<size_t> clique;
  std::vector<size_t> iclique;
  auto mid = (lb + ub) / 2;
  auto k = graph.GetNumberVetricesDegreeMoreX(mid);
  auto s = graph.GetVerticesDegreeMoreX(mid);
  if (k > mid) {
    
  }
  
  
  return 0;
}

int main(int argc, const char * argv[]) {
  Graph g(10);
  g.AddEdge(1, 2, 15);
  g.PrintVertices();
  auto k = g.GetNumberVetricesDegreeMoreX(1);
  std::cout << k << std::endl;
  
  auto m = g.GetVerticesDegreeMoreX(1);
  for (const auto &each: m) {
    std::cout << each.GetNumber() << " " << each.GetDegree() <<std::endl;
  }
  
  return 0;
}

