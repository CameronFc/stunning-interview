
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <limits.h>

using std::stack;

class MinStack {

  public:
  stack<int*> minStack;
  stack<int> normalStack;

  void pop() {
    if(minStack.top() == &(normalStack.top())) {
      minStack.pop();
    }
    normalStack.pop();
  }

  void push(int value) {
    normalStack.push(value);
    if(value <= *(minStack.top())) {
      minStack.push(&(normalStack.top()));
    }
  }

  MinStack() {
    int* max = new int(INT_MAX);
    minStack.push(max);
  }
};


int main(int argc, char** argv) {
  MinStack m;
  m.push(8);
  m.push(5);
  m.push(5);
  m.push(5);
  m.push(3);
  m.push(2);

  m.pop();
  m.pop();
  m.pop();
  m.pop();
  m.pop();

  printf("The min is: %d\n", *(m.minStack.top()));

  return 0;
}
