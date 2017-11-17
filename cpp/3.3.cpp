
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using std::stack;
using std::cout;
using std::endl;

#define N 5 // Stack threshold

class SetOfStacks {

  const int threshold;

  stack<stack<int>*> StackOfStacks;

  void pushNewStack() {
    stack<int>* s = new stack<int>;
    StackOfStacks.push(s);
  }

  public:

  void pop() {
    if(StackOfStacks.empty()) {
      throw;
    }

    if(!StackOfStacks.top()->empty()) {
      StackOfStacks.top()->pop();

      // If the top stack is now empty, remove it.
      if(StackOfStacks.top()->empty()) {
        StackOfStacks.pop();
      }
    } 
  }

  int top() {
    if(StackOfStacks.empty()) {
      throw;
    }

    return StackOfStacks.top()->top();
  }

  void push(int value) {
    if(StackOfStacks.empty()) {
      pushNewStack();
    }

    stack<int>* topStack = StackOfStacks.top();
    if(topStack->size() == threshold) {
      pushNewStack();
      topStack = StackOfStacks.top();
    }

    topStack->push(value);
  }

  bool empty() {
    return StackOfStacks.empty();
  }

  SetOfStacks(int threshold) : threshold(threshold){ }
};


int main(int argc, char** argv) {

  SetOfStacks megaStack(N);
  for(int i = 0; i < 27; i++) {
    megaStack.push(6);
  }

  while(!megaStack.empty()) {
    //cout << "Hello." << endl;
    cout << megaStack.top() << " ";
    megaStack.pop();
  }
  cout << endl;

  return 0;
}
