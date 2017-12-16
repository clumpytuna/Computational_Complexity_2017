//
//  Vertex.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

#include "Edge.hpp"
class Vertex {
public:
  Vertex(size_t number) : number_(number), degree(0) {
  };
  void DegreeInc() {
    degree += 1;
  }
  void DegreeDec() {
    degree -= 1;
  }
  size_t GetDegree() const {
    return degree;
  }
private:
  size_t number_;
  size_t degree;
};

#endif /* Vertex_h */
