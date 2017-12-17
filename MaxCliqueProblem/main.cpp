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
#include "MaxCliqueProblemSolver.hpp"

int main(int argc, const char * argv[]) {
  Graph g(3);
  g.AddEdge(1, 2, 15);
  g.AddEdge(1, 3, 10);
  g.AddEdge(2, 3, 5);
  g.PrintVertices();
  g.PrintAdjacencyList();
  auto k = g.GetNumberVetricesDegreeMoreX(1);
  std::cout << k << std::endl;
  auto m = g.GetVerticesDegreeMoreX(1);
  for (const auto &each: m) {
    std::cout << each.GetNumber() << " " << each.GetDegree() <<std::endl;
  }
  if (g.IsClique(m)) {
    std::cout << "YES! \n";
  } else {
    std::cout << "NO! \n";
  }
  return 0;
}

