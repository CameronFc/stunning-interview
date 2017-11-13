
#include "substack.hpp"
#include "stackitem.hpp"
#include "triplestack.hpp"

void SubStack::push(int value) {
  // Check if we have free space available
  if(parent->spaceStack.empty()) {
    return; // No space to push into!
  }
  int emptySpot = parent->spaceStack.top();
  parent->spaceStack.pop();
  
  // Create a new stack item, make sure to record the index of the previous
  // stack item
  StackItem newItem(value);
  newItem.previous = top;
  newItem.color = color;

  // Now put the new item in the empty spot.
  parent->stackItemArray[emptySpot] = newItem;
  top = emptySpot;
}

void SubStack::pop() {
  // Tell the spaceStack it has a new spot free
  parent->spaceStack.push(top);
  parent->stackItemArray[top].color = Color::NORMAL; // Reset color for drawing
  top = parent->stackItemArray[top].previous;
}

int SubStack::peek() {
  return parent->stackItemArray[top].value;
}

bool SubStack::isEmpty() {
  return (top == -1);
}

SubStack::SubStack(TripleStack* p, Color c) {
  parent = p;
  color = c;
  top = -1;
}
