//
//  Graph.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include "Edge.hpp"
#include "Vertex.hpp"
#include <vector>
#include <iostream>

class Graph {
public:
  Graph(long number_of_vertices);
  ~Graph();
  void AddEdge(int from, int to, double data);
  void AddEdge(Edge *edge);
  std::vector<Vertex> GetVerticesDegreeMoreX(size_t x) const;
  double GetEdgesLong(int from, int to) const;
  size_t GetDegree(size_t vertex_index) const;
  size_t GetMaxDegree() const;
  long GetSize() const;
  void PrintAdjacencyList() const;
private:
  long size = 0;
  std::vector <std::vector <Edge*>> adjacency_list;
  std::vector <Vertex> vertices_;
  void edgesDelete();
  long number_of_vertices = 0;
  size_t max_degree = 0;
};


std::vector<Vertex> Graph::GetVerticesDegreeMoreX(size_t x) const {
  std::vector<Vertex> vertices;
  for (const auto &vertex: vertices) {
    if (vertex.GetDegree() >= x) {
      vertices.push_back(vertex);
    }
  }
  return vertices;
}

size_t Graph::GetMaxDegree() const {
  return max_degree;
}
size_t Graph::GetDegree(size_t vertex_index) const {
  return vertices_[vertex_index].GetDegree();
}

double Graph::GetEdgesLong(int from, int to) const {
  for (int i = 0; i < adjacency_list[from].size(); ++i){
    if (adjacency_list[from][i]->to == to){
      return adjacency_list[from][i]->data;
    }
  }
  return 0;
}

Graph::Graph(long number_of_vertices)
    : adjacency_list(number_of_vertices + 1),
      size(number_of_vertices),
      vertices_(number_of_vertices + 1) {
        
      }

Graph::~Graph() {
  edgesDelete();
}

void Graph::PrintAdjacencyList() const {
  for (int i = 1; i < size + 1; ++i){
    for (int j = 0; j <adjacency_list[i].size(); ++j){
      std::cout << adjacency_list[i][j]->from <<" "<<adjacency_list[i][j]->to <<" "<<adjacency_list[i][j]->data;
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}

void Graph::edgesDelete() {
  for (int i = 1; i < size + 1; ++i) {
    for (int j = 0; j <adjacency_list[i].size(); ++j) {
      if (adjacency_list[i][j] != NULL) {
        delete adjacency_list[i][j];
      }
    }
    adjacency_list[i].clear();
  }
}

void Graph::AddEdge(Edge *edge) {
  adjacency_list[edge->from].push_back(edge);
  adjacency_list[edge->to].push_back(edge->GetReverse());
  vertices_[edge->from].DegreeInc();
  vertices_[edge->to].DegreeInc();
  
  if (vertices_[edge->from].GetDegree() > max_degree ||
      vertices_[edge->to].GetDegree() > max_degree) {
    max_degree = std::max(vertices_[edge->from].GetDegree(),
                          vertices_[edge->to].GetDegree());
  }
}

void Graph::AddEdge(int from, int to, double data) {
  AddEdge(new Edge(from, to, data));
}

long Graph::GetSize() const {
  return size;
}


#endif /* Graph_hpp */
