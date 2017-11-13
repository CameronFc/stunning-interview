
#ifndef SUBSTACK_H
#define SUBSTACK_H 

#include "colors.hpp"

class TripleStack;

class SubStack {
  int top;
  TripleStack* parent;
  Color color;

  public:
  void push(int);

  void pop();

  int peek();

  bool isEmpty();

  SubStack(TripleStack*, Color);
};

#endif
