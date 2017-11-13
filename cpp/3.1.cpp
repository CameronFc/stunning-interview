
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "triplestack.hpp"
#include "substack.hpp"


#define N 100 // Size of array

int main(int argc, char** argv) {
  TripleStack p(N);

  for(int i = 0; i < 80; i++) {
    p.a->push(rand() % 100);
  }
  for(int i = 0; i < 10; i++) {
    p.b->push(rand() % 100);
  }
  for(int i = 0; i < 10; i++) {
    p.c->push(rand() % 100);
  }

  p.print();

  for(int i = 0; i < 10; i++) {
    p.c->pop();
  }
  for(int i = 0; i < 10; i++) {
    p.b->pop();
  }
  for(int i = 0; i < 10; i++) {
    p.a->pop();
  }
  for(int i = 0; i < 10; i++) {
    p.c->push(rand() % 100);
  }

  p.print();

  for(int i = 0; i < 10; i++) {
    p.b->push(rand() % 100);
  }
  for(int i = 0; i < 5; i++) {
    p.c->pop();
  }
  for(int i = 0; i < 10; i++) {
    p.a->push(rand() % 100);
  }

  p.print();

  
  return 0;
}
