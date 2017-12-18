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
        marker_(vertices.size(), 0), continue_(true) {
  }
  
  bool GetNextSubset(std::set<Vertex>& vertices) {
    std::set<Vertex> desired_set;
    while (std::count(marker_.begin(), marker_.end(), 1) != cardinality_) {
      if (!continue_) {
        return false;
      }
      continue_ = Increment();
    }
    
    for (size_t index = 0; index < marker_.size(); ++index) {
      if (marker_[index] == 1) {
        desired_set.insert(vertices_[index]);
      }
    }
    vertices.swap(desired_set);
    continue_ = Increment();
    return true;
  }
  
  void PrintMarker() {
    for (const auto &each: marker_) {
      std::cout << each << " ";
    }
    std::cout << std::endl;
  }
  
public:
  bool Increment() {
    auto index = 0;
    while (marker_[index] != 0 && index < marker_.size()) {
      marker_[index] = 0;
      ++index;
    }
    if (index >= marker_.size()) {
      return false;
    }
    
    if (marker_[index] == 0) {
      marker_[index] = 1;
      return true;
    }
    return true;
  }
  bool continue_;
  std::vector<size_t> marker_;
  std::vector<Vertex> vertices_;
  size_t cardinality_;
};
#endif /* Subsetter_hpp */
