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
};

size_t MaxCliqueSolver::FindClique(Graph &graph) {
  auto m = graph.GetMaxDegree();
  auto lb = 0;
  auto ub = m;
  size_t s;
  std::vector<size_t> clique;
  std::vector<size_t> iclique;
  auto mid = (lb + ub) / 2;
  
  return 0;
}

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}

