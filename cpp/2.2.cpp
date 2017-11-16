
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

class Problem {


public:
  static Node* lastKNodes(Node* inputNode, int k) {

    if(inputNode == nullptr) {
      return nullptr;
    }

    int position = 1;

    Node* runner = inputNode;
    while(runner->next != nullptr && position < k) {
      runner = runner->next;
      position++;
    }
    if(position < k) {
      return inputNode; // If there are < k elements, just return the first node.
    }
    //Runner is now k nodes into the LL. Walk it forward with the slow pointer.
    Node* walker = inputNode;
    while(runner->next != nullptr) {
      runner = runner->next;
      walker = walker->next;
    }

    return walker;
  }

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
};

int main(int argc, char** argv) {
  

  int array[] = {1,2,3,4,4,5,5,2,1,3,4,5,5,6,6,9,5,4,0};
  Node* a = Problem::arrayToLL(array, sizeof(array) / sizeof(int));
    
  Problem::printLL(a);
  int k = 5;
  Node* uniqueLL = Problem::lastKNodes(a, k);
  Problem::printLL(uniqueLL);

  int array2[] = {1, 2, 3,4,5,6};
  Node* a2 = Problem::arrayToLL(array2, sizeof(array2) / sizeof(int));
  Problem::printLL(a2);
  k = 3;
  uniqueLL = Problem::lastKNodes(a2, k);
  Problem::printLL(uniqueLL);
  
  return 0;
}
