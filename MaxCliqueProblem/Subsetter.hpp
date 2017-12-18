//
//  Subsetter.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 18.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#ifndef Subsetter_hpp
#define Subsetter_hpp

#include "Graph.hpp"
#include "Vertex.hpp"

class Subsetter {
public:
  Subsetter(std::vector<Vertex>& vertices, size_t cardinality)
      : vertices_(vertices), cardinality_(cardinality),
        marker(vertices.size(), 0), continue_(true) {
  }
  
  bool GetNextSubset(std::set<Vertex>& vertices) {
    std::set<Vertex> desired_set;
    while (std::count(marker.begin(), marker.end(), 1) != cardinality_) {
      if (!continue_) {
        return false;
      }
      continue_ = Increment();
    }
    
    for (size_t index = 0; index < marker.size(); ++index) {
      if (marker[index] == 1) {
        desired_set.insert(vertices_[index]);
      }
    }
    vertices.swap(desired_set);
    continue_ = Increment();
    return true;
  }
  
  void PrintMarker() {
    for (const auto &each: marker) {
      std::cout << each << " ";
    }
    std::cout << std::endl;
  }
  
public:
  bool Increment() {
    auto index = 0;
    while (marker[index] != 0 && index < marker.size()) {
      marker[index] = 0;
      ++index;
    }
    if (index >= marker.size()) {
      return false;
    }
    
    if (marker[index] == 0) {
      marker[index] = 1;
      return true;
    }
    return true;
  }
  bool continue_;
  std::vector<size_t> marker;
  std::vector<Vertex> vertices_;
  size_t cardinality_;
};
#endif /* Subsetter_hpp */
