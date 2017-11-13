
#ifndef STACK_ITEM_H
#define STACK_ITEM_H

#include "colors.hpp"

struct StackItem {
  int value;
  int previous; // index in array of previous item we placed on stack
  Color color;
  
  StackItem(int val) {
    value = val;
    previous = -1;
  }
  // Convenience
  StackItem() {
    StackItem(0);
  }
};

#endif
