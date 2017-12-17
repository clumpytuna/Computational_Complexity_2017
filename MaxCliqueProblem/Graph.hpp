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
  Graph(Graph const& graph);
  ~Graph();
  void AddEdge(int from, int to, double data);
  void AddEdge(Edge edge);
  std::vector<std::vector<Edge>> GetAdjList() const;
  size_t GetDegree(size_t vertex_index) const;
  double GetEdgesLong(int from, int to) const;
  size_t GetEdgesNum() const;
  size_t GetMaxDegree() const;
  size_t GetNumberVetricesDegreeMoreX(size_t x) const;
  std::vector<Vertex> GetVertices() const;
  std::vector<Vertex> GetVerticesDegreeMoreX(size_t x) const;
  size_t GetVetricesNum() const;
  void PrintAdjacencyList() const;
  void PrintVertices() const;
private:
  std::vector <std::vector <Edge>> adjacency_list_;
  size_t max_degree_ = 0;
  size_t number_of_edges_ = 0;
  const size_t number_of_vertices_ = 0;
  std::vector <Vertex> vertices_;
};

Graph::Graph(long number_of_vertices)
    : adjacency_list_(number_of_vertices + 1),
      number_of_vertices_(number_of_vertices) {
  for (size_t i = 0; i < number_of_vertices + 1; ++i) {
    vertices_.push_back(Vertex(i));
  }
}

Graph::Graph(Graph const& graph)
    : number_of_vertices_(graph.GetVetricesNum()),
      number_of_edges_(graph.GetEdgesNum()),
      max_degree_(graph.GetMaxDegree()),
      adjacency_list_(graph.GetVetricesNum() + 1),
      vertices_(graph.GetVertices()){
    std::copy(&(graph.GetAdjList())[0][0], &(graph.GetAdjList())[0][0] +
              (number_of_vertices_ + 1) * (number_of_vertices_ + 1), &adjacency_list_[0][0]);
}

Graph::~Graph() {}

std::vector<Vertex> Graph::GetVertices() const {
  return vertices_;
}

std::vector<std::vector<Edge>> Graph::GetAdjList() const {
  return adjacency_list_;
}

void Graph::PrintVertices() const {
  for (const auto &vertex: vertices_) {
    if (vertex.GetNumber() == 0) {
      continue;
    }
    std::cout <<"Vertex number: " << vertex.GetNumber() << " Vertex degree: " << vertex.GetDegree()<< std::endl;
  }
}

size_t Graph::GetNumberVetricesDegreeMoreX(size_t x) const {
  auto counter = 0;
  for (const auto &vertex: vertices_) {    
    if (vertex.GetDegree() >= x && vertex.GetNumber() != 0) {
      ++counter;
    }
  }
  return counter;
}


std::vector<Vertex> Graph::GetVerticesDegreeMoreX(size_t x) const {
  std::vector<Vertex> vertices;
  for (const auto &vertex: vertices_) {
    if (vertex.GetDegree() >= x && vertex.GetNumber() != 0) {
      vertices.push_back(vertex);
    }
  }
  return vertices;
}

size_t Graph::GetMaxDegree() const {
  return max_degree_;
}
size_t Graph::GetDegree(size_t vertex_index) const {
  return vertices_[vertex_index].GetDegree();
}

double Graph::GetEdgesLong(int from, int to) const {
  for (int i = 0; i < adjacency_list_[from].size(); ++i){
    if (adjacency_list_[from][i].GetTo() == to){
      return adjacency_list_[from][i].GetData();
    }
  }
  return 0;
}

void Graph::PrintAdjacencyList() const {
  for (int i = 1; i < number_of_vertices_ + 1; ++i){
    for (int j = 0; j <adjacency_list_[i].size(); ++j){
      std::cout << adjacency_list_[i][j].GetFrom() <<" "<<adjacency_list_[i][j].GetTo() <<" "<<adjacency_list_[i][j].GetData();
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}


void Graph::AddEdge(Edge edge) {
  adjacency_list_[edge.GetFrom()].push_back(edge);
  adjacency_list_[edge.GetTo()].push_back(edge.GetReverse());
  number_of_edges_ += 2;
  
  vertices_[edge.GetFrom()].DegreeInc();
  vertices_[edge.GetTo()].DegreeInc();
  
  if (vertices_[edge.GetFrom()].GetDegree() > max_degree_ ||
      vertices_[edge.GetTo()].GetDegree() > max_degree_) {
    max_degree_ = std::max(vertices_[edge.GetFrom()].GetDegree(),
                          vertices_[edge.GetTo()].GetDegree());
  }
}

void Graph::AddEdge(int from, int to, double data) {
  AddEdge(Edge(from, to, data));
}

size_t Graph::GetVetricesNum() const {
  return number_of_vertices_;
}

size_t Graph::GetEdgesNum() const {
  return number_of_edges_;
}

#endif /* Graph_hpp */
