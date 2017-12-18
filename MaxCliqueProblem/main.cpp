//
//  main.cpp
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Graph.hpp"
#include "Vertex.hpp"
#include "MaxCliqueProblemSolver.hpp"

int main(int argc, const char * argv[]) {
  Graph g(5);
  
  g.AddEdge(1, 2, 1);
  g.AddEdge(1, 3, 1);
  g.AddEdge(1, 4, 1);
  g.AddEdge(1, 5, 1);

  
  g.AddEdge(2, 3, 1);
  g.AddEdge(2, 4, 1);
  g.AddEdge(2, 5, 1);

  
  g.AddEdge(3, 4, 1);
  g.AddEdge(3, 5, 1);

  
  g.AddEdge(4, 5, 1);

  
  //g.PrintVertices();
  //g.PrintAdjacencyList();
  
  MaxCliqueSolver Solver(g);
  std::cout <<"Размер максимальной клики: " << Solver.FindClique() << " " <<std::endl;
}


