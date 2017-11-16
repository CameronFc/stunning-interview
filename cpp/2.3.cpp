
#include <stdio.h>
#include <iostream>
#include "linkedlist.hpp"

using std::cout;
using std::endl;

using LinkedList::printLL;
using LinkedList::arrayToLL;
using LinkedList::Node;

class Problem {

public:
  static void deleteMiddle(Node* middle) {

    if(middle->next == nullptr || middle == nullptr) {
      throw; 
    }

    middle->id = middle->next->id;
    middle->next = middle->next->next;
  }
};

int main(int argc, char** argv) {
  
  int array[] = {1,2,3,4,4,5,5,2,1,3,4,5,5,6,6,9,5,4,0};
  Node* a = arrayToLL(array, sizeof(array) / sizeof(int));
    
  printLL(a);
  Problem::deleteMiddle(a->next->next);
  printLL(a);

  int array2[] = {1, 2, 3,4,5,6};
  Node* a2 = arrayToLL(array2, sizeof(array2) / sizeof(int));
  printLL(a2);
  Problem::deleteMiddle(a2->next);
  printLL(a2);
  
  return 0;
}
