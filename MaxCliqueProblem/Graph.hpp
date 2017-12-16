//
//  Graph.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include "Edge.hpp"
#include "Vertex.hpp"
#include <vector>
#include <iostream>
class Graph
{
public:
  Graph(long number_of_vertex);
  ~Graph();
  void AddEdge(int from, int to, double data);
  void AddEdge(Edge *edge);
  long GetSize() const;
  double GetEdgesLong(int from, int to) const;
  size_t GetDegree(int from, int to) const;
  size_t GetMaxDegree() const;
  void PrintAdjacencyList();
private:
  long size = 0;
  std::vector <std::vector <Edge*>> adjacency_list;
  void edgesDelete();
  long number_of_vertex = 0;
  size_t max_degree = 0;
};


size_t Graph::GetMaxDegree() const {
  return max_degree;
}
size_t Graph::GetDegree(int from, int to) const {
  return 0; //degree_matrix[from][to];
}

double Graph::GetEdgesLong(int from, int to) const
{
  for (int i = 0; i < adjacency_list[from].size(); ++i){
    if (adjacency_list[from][i]->to == to){
      return adjacency_list[from][i]->data;
    }
  }
  return 0;
}

Graph::Graph(long number_of_vertex)
{
  adjacency_list.resize(number_of_vertex + 1);
  size = number_of_vertex;
}



Graph::~Graph()
{
  edgesDelete();
}

void Graph::PrintAdjacencyList()
{
  for (int i = 1; i < size + 1; ++i){
    for (int j = 0; j <adjacency_list[i].size(); ++j){
      std::cout << adjacency_list[i][j]->from <<" "<<adjacency_list[i][j]->to <<" "<<adjacency_list[i][j]->data;
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

void Graph::edgesDelete()
{
  for (int i = 1; i < size + 1; ++i){
    for (int j = 0; j <adjacency_list[i].size(); ++j){
      if (adjacency_list[i][j] != NULL){
        delete adjacency_list[i][j];
      }
    }
    adjacency_list[i].clear();
  }
}

void Graph::AddEdge(Edge *edge)
{
  adjacency_list[edge->from].push_back(edge);
  adjacency_list[edge->to].push_back(edge->GetReverse());
  
}

void Graph::AddEdge(int from, int to, double data)
{
  AddEdge(new Edge(from, to, data));
}

long Graph::GetSize() const
{
  return size;
}


#endif /* Graph_h */
