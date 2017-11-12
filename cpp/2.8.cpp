
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>

#define RED     "\033[31m"
#define NORMAL   "\033[0m"

#define N 100 // Max size of node value (integer)
#define LIST_LENGTH 50

using std::cout;
using std::endl;

struct Node {
  int value;
  Node* next;
  
  Node(int val) {
    value = val;
    next = nullptr;
  }
};

class Problem {

public:

  Node* corruptList = nullptr; // Start of corrupt Linked list
  Node* marker = nullptr;
  unsigned int stepCounter;

  // Create a corrupt linked list with a loop.
  // Length is the total number of unique nodes.
  Node* makeLoopedLL(int length) {
    Node* temp = new Node(rand() % N);
    Node* nodeArray[length];
    nodeArray[0] = temp;
    for(int i = 1; i < length; i++) {
      temp->next = new Node(rand() % N);
      temp = temp->next;
      nodeArray[i] = temp;
    }
    int loopIntersection = rand() % (length); // ANY node can be the first intersection
    nodeArray[length - 1]->next = nodeArray[loopIntersection]; // Close the loop

    // Just for fun, print the list and loop.
    for(int i = 0; i < length; i++) {
      if(i < loopIntersection) {
        cout << NORMAL << nodeArray[i]->value;
      } else {
        cout << RED << nodeArray[i]->value;
      }
      if(i != length - 1) {
        cout << NORMAL << "->";
      }
    }
    cout << NORMAL << endl;

    return nodeArray[0];
  }

  // Returns a 'random' node in the loop.
  Node* getLoopNode(Node* lla) {
    stepCounter = 0;
    while(lla != nullptr) {
      //printf("%p\n", lla);
      lla = lla->next;

      // If we have visited a place we were at before (i.e in the loop), we are
      // done.
      if(lla == marker) {
        return marker;
      }

      // Bit magic; detects if stepCounter is power of 2.
      if((stepCounter & (stepCounter - 1)) == 0) {
        // Replace the marker at increasingly further distances.
        marker = lla;
      }
      
      stepCounter++;
    }
    return nullptr; // There was no loop in the linked list! 
  }

  // Find length of list from ll until marker
  int getLength(Node* ll) {
    int length = 0;
    while(ll != marker) {
      ll=ll->next;
      length++;
    }
    return length;
  }
  
  // Reprised solution from question 2.7; modified slightly
  Node* lengthLLCollide(Node* lla, Node* llb) {

    int lengthA = getLength(lla);
    int lengthB = getLength(llb);

    int cutAmount = lengthA - lengthB;
    if(cutAmount < 0) {
      // llb has more elements. cut from its start.
      int cutCount = 0;
      while(cutCount < -cutAmount) {
        llb = llb->next;
        cutCount++;
      }

    } else if(cutAmount > 0) {
      int cutCount = 0;
      while(cutCount < cutAmount) {
        lla = lla->next;
        cutCount++;
      }
    }

    // Now the linked lists are the same length. All we have to do know is check
    // if the nodes are the same!
    while(true) {
      if(lla == llb) {
        return lla;
      }
      lla = lla->next;
      llb = llb->next;
    }
    throw;
  }

  Problem() {
    srand(time(NULL));
    corruptList = makeLoopedLL(LIST_LENGTH);
    Node* loopNode = getLoopNode(corruptList);
    printf("The discovered loop node is: %d\n", loopNode->value);
    Node* collision = lengthLLCollide(corruptList, loopNode->next);
    printf("The loop start has value: %d\n", collision->value);
  }

};

int main(int argc, char** argv) {
  Problem p;
  return 0;
}
