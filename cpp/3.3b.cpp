
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::cout;
using std::endl;
using std::vector;

#define N 5 // Threshold of stacks

class SetOfStacks {

  const int threshold;

  vector<stack<int>*> VectorOfStacks;

  void pushNewStack() {
    stack<int>* s = new stack<int>;
    VectorOfStacks.push_back(s);
  }

  public:

  void pop() {
    if(VectorOfStacks.empty()) {
      throw;
    }

    if(!VectorOfStacks.back()->empty()) {
      VectorOfStacks.back()->pop();

      // If the top stack is now empty, remove it.
      if(VectorOfStacks.back()->empty()) {
        VectorOfStacks.pop_back();
      }
    } 
  }

  // Follow-up : We will re-arrange the Stack of Stacks if removing an element
  // with this method would give rise to an empty stack.

  // Strategy: we use a vector of stacks instead. We need to use a non-stack
  // data structure is we want the OPTIONAL behavior where popping the last
  // element in a substack deletes the substack.
  void popAt(int index) {

    // This will throw an exception if trying to access an out-of-bounds stack.
    stack<int>* subStack = VectorOfStacks.at(index);

    if(subStack->empty()) {
      throw; // This should never happen! We try to actively delete empty stacks.
    }

    subStack->pop();

    // Delete the substack from our vector if it's now empty.
    if(subStack->empty()) {
      delete subStack; // Was allocated dynamically!
      VectorOfStacks.erase(VectorOfStacks.begin() + index);
    }
  }

  int top() {
    if(VectorOfStacks.empty()) {
      throw;
    }

    return VectorOfStacks.back()->top();
  }

  void push(int value) {
    if(VectorOfStacks.empty()) {
      pushNewStack();
    }

    stack<int>* topStack = VectorOfStacks.back();
    if(topStack->size() == threshold) {
      pushNewStack();
      topStack = VectorOfStacks.back();
    }

    topStack->push(value);
  }

  bool empty() {
    return VectorOfStacks.empty();
  }

  SetOfStacks(int threshold) : threshold(threshold){ }
};


int main(int argc, char** argv) {

  SetOfStacks megaStack(N);
  for(int i = 0; i < 25; i++) {
    megaStack.push(i / 5);
  }

  // Delete the whole third stack
  megaStack.popAt(3);
  megaStack.popAt(3);
  megaStack.popAt(3);
  megaStack.popAt(3);
  megaStack.popAt(3);
  // The vector of stacks self-adjusted. This now deletes the top element from 
  // the original 4th stack.
  megaStack.popAt(3);

  // Print in reverse order, destroy all stacks
  while(!megaStack.empty()) {
    //cout << "Hello." << endl;
    cout << megaStack.top() << " ";
    megaStack.pop();
  }
  cout << endl;

  return 0;
}
