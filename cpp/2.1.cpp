
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

struct Node {
  int id;
  Node* next;
  
  Node(int id) {
    this->id = id;
    this->next = nullptr;
  }
};


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
  static void printLL(Node* ll){
    while(ll != nullptr) {
      cout << ll->id << " ";
      ll = ll->next;
    }
    cout << endl;
  }

  static Node* arrayToLL(int* input, int size) {

    if(size == 0) {
      return nullptr;
    }
    Node* temp = new Node(input[0]);
    Node* output = temp;
    for(int i = 1; i < size; i++) {
      temp->next = new Node(input[i]);
      temp = temp->next;
    }
    return output;
  }

  static Node* removeDuplicates(Node* inputNode) {
    return removeDuplicates(inputNode, nullptr, nullptr);
  }
};

int main(int argc, char** argv) {
  

  int array[] = {1,2,3,4,4,5,5,2,1,3,4,5,5,6,6,9,5,4,0};
  Node* a = Problem::arrayToLL(array, sizeof(array) / sizeof(int));
    
  Problem::printLL(a);
  Node* uniqueLL = Problem::removeDuplicates(a);
  Problem::printLL(uniqueLL);
  
  return 0;
}
