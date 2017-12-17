//
//  Edge.h
//  MaxCliqueProblem
//
//  Created by Clumpy Tuna on 17.12.2017.
//  Copyright © 2017 Clumpy Tuna. All rights reserved.
//


#ifndef Edge_hpp
#define Edge_hpp
class Edge
{
public:
  Edge(size_t from, size_t to, double data)
      : from_(from), to_(to), data_(data) {}
  
  Edge(Edge const& edge)
      : from_(edge.GetFrom()),
        to_(edge.GetTo()),
        data_(edge.GetData()){}
  
  ~Edge(){}
  
  size_t GetFrom() const {
    return from_;
  }
  
  size_t GetTo() const {
    return to_;
  }
  
  double GetData() const {
    return data_;
  }
  
  Edge GetReverse() {
    return Edge(this->to_, this->from_, this->data_);
  }
  
  const bool operator < (const Edge& other) const {
    return this->data_ < other.data_;
  }
private:
  size_t from_;
  size_t to_;
  double data_;
};


#endif /* Edge_hpp */
