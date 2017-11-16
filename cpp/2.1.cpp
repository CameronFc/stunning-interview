
#include "linkedlist.hpp"
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

using LinkedList::printLL;
using LinkedList::arrayToLL;
using LinkedList::Node;

// Strategy for follow-up : make a new linked list. (delete old if desired.)
// iterate over old LL - if the current Node does not exist in the new LL, add
// it.
class Problem {

  static bool valueExistsIn(Node* ll, int id) {
    if(ll == nullptr) {
      return false;
    }
    if(ll->id == id) {
      return true;
    } else {
      return valueExistsIn(ll->next, id);
    }
  }

  static Node* removeDuplicates(Node* inputNode, Node* startOutput, Node* endOutput) {

    if(inputNode == nullptr) {
      return startOutput; // Empty in, empty out
    }

    if(startOutput == nullptr) {
      startOutput = new Node(inputNode->id);
      endOutput = startOutput;
    }

    if(!valueExistsIn(startOutput, inputNode->id)) {
      endOutput->next = new Node(inputNode->id);
      endOutput = endOutput->next;
    }

    return removeDuplicates(inputNode->next, startOutput, endOutput);
  }

public:
  static Node* removeDuplicates(Node* inputNode) {
    return removeDuplicates(inputNode, nullptr, nullptr);
  }
};

int main(int argc, char** argv) {
  
  int array[] = {1,2,3,4,4,5,5,2,1,3,4,5,5,6,6,9,5,4,0};
  Node* a = arrayToLL(array, sizeof(array) / sizeof(int));
    
  printLL(a);
  Node* uniqueLL = Problem::removeDuplicates(a);
  printLL(uniqueLL);
  
  return 0;
}
