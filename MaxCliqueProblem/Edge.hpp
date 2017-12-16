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
  Edge(int from, int to, double data) : from(from), to(to), data(data) {}
  ~Edge(){};
  int from;
  int to;
  double data;
  Edge *GetReverse();
  const bool operator<(const Edge& rv) const {
    return this->data < rv.data;
  }
};

Edge *Edge::GetReverse()
{
  return new Edge(this->to, this->from, this->data);
}

#endif /* Edge_hpp */
