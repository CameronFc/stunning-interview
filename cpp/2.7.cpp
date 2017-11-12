
#include <stdio.h>

struct Node {
  int value;
  Node* next;
  
  Node(int val) {
    value = val;
    next = nullptr;
  }
};

struct State {
  Node* collision;

  State() {
    collision = nullptr;
  }
};


void recurseLLCollide(Node& lla, Node& llb, State& state) {

  bool recurse = false;

  Node* llaNext = &lla;
  if(lla.next != nullptr) {
    llaNext = lla.next;
    recurse = true;
  }

  Node* llbNext = &llb;
  if(llb.next != nullptr) {
    llbNext = llb.next;
    recurse = true;
  }

  if(recurse) {
    recurseLLCollide(*llaNext, *llbNext, state);
  }

  // By this point, we are at the end of the linked lists.
  printf("LLA address: %p\n", &lla);
  printf("LLB address: %p\n", &llb);
  if(&lla == &llb) {
    printf("The references are the same!\n");
    state.collision = &lla;
  }
}


int main(int argc, char** argv) {
  
  Node* a = new Node(7);
  a->next = new Node(1);
  a->next->next = new Node(6);
    
  Node* b = new Node(5);
  //b->next = a->next;

  State state;
  
  recurseLLCollide(*a,*b,state);
  
  printf("The collision is: %p\n", state.collision);
  
  return 0;
}
