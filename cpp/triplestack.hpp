
#include "stackitem.hpp"
#include <stack>

class SubStack;

class TripleStack {
public:

  int size;

  SubStack* a;
  SubStack* b;
  SubStack* c;

  // The array specified in the problem.
  StackItem* stackItemArray;
  std::stack<int> spaceStack;

  TripleStack(int);

  void print();
};

