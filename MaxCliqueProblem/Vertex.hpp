//
//  Vertex.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include "Edge.hpp"
class Vertex {
public:
  Vertex() : degree_(0) {}
  
  Vertex(size_t number) : number_(number), degree_(0) {}
  
  Vertex(Vertex const& vertex)
      : number_(vertex.GetNumber()),
        degree_(vertex.GetDegree()) {}
  
  ~Vertex() {}
  
  bool operator < (Vertex other) const {
    return number_ < other.GetNumber();
  }

  void DegreeInc() {
    degree_ += 1;
  }
  
  void DegreeDec() {
    degree_ -= 1;
  }
  
  size_t GetDegree() const {
    return degree_;
  }
  
  size_t GetNumber() const {
    return number_;
  }
  
private:
  size_t degree_;
  size_t number_;
};

#endif /* Vertex_hpp */
