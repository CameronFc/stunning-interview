
#include <stdio.h>
#include <iostream>

using std::cout;
using std::endl;

namespace LinkedList {
  struct Node {
    int id;
    Node* next;
    
    Node(int id) {
      this->id = id;
      this->next = nullptr;
    }
  };

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
}

