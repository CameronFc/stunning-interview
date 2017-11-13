
#include "triplestack.hpp"
#include "substack.hpp"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "colors.hpp"
#include <iostream>

TripleStack::TripleStack(int size) {
  srand(time(NULL));

  stackItemArray = new StackItem[size];
  this->size = size;
  // Space stack is initially full, holds every array index
  for(int i = 0; i < size; i++) {
    spaceStack.push(i);
    stackItemArray[i].color = Color::NORMAL;
  }

  a = new SubStack(this, Color::RED);
  b = new SubStack(this, Color::YELLOW);
  c = new SubStack(this, Color::GREEN);
}

void TripleStack::print() {
  for(int i = 0; i < size; i++) {
    switch (stackItemArray[i].color) {
      case Color::RED:
        std::cout << "\033[31m" << "[" <<  stackItemArray[i].value << "]";
        break;
      case Color::YELLOW:
        std::cout << "\033[35m" << "[" <<  stackItemArray[i].value << "]";
        break;
      case Color::GREEN:
        std::cout << "\033[32m" << "[" <<  stackItemArray[i].value << "]";
        break;
      default:
        std::cout << "\033[0m" << "[" <<  stackItemArray[i].value << "]";
    }
  }
  std::cout << "\033[0m" << std::endl;
}
