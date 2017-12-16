//
//  Edge.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#ifndef Edge_h
#define Edge_h

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
  return 0;
}

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}

#endif /* Edge_h */
