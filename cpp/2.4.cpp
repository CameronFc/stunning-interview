
#include <stdio.h>
#include <iostream>
#include "linkedlist.hpp"

using std::cout;
using std::endl;

using LinkedList::printLL;
using LinkedList::arrayToLL;
using LinkedList::Node;

// Todo: clean up with more concise node cutting?
class Problem {

public:
  static Node* partition(Node* start, int pivot) {

    if(start == nullptr || start->next == nullptr) {
      return start;// Can't do anything with LL of size <= 1
    }
    
    int listDepth = 0;
    Node* end = start;
    while(end->next != nullptr) {
      end = end->next;
      listDepth++;
    }

    // add a dummy element, prestart, to the start of the linked list to make 
    // cutting simpler
    Node* preStart = new Node(0);
    preStart->next = start;
    Node* walker = preStart;
    // ..->walker->nodeToCut->..
    int currentDepth = 0;
    while(currentDepth++ < listDepth) {
      Node* nodeToCut = walker->next;
      if(nodeToCut->next == nullptr) {
        // We are at the end of the LL and can't do any more cutting. Return the
        // first Node(possibly changed from start)
        return preStart->next;
      }
      if(nodeToCut->id >= pivot) {

        // cut the node...
        walker->next = nodeToCut->next;
        nodeToCut->next = nullptr;
        // and paste to end.
        end->next = nodeToCut;
        // finally update the end pointer.
        end = nodeToCut;
      } else {
        // if we did not cut a node, advance.
        walker = walker->next;
      }
    }
    return preStart->next;
  }
};

int main(int argc, char** argv) {
  
  int array[] = {1,2,3,4,4,5,5,2,1,3,4,5,5,6,6,9,5,4,0};
  Node* a = arrayToLL(array, sizeof(array) / sizeof(int));
    
  printLL(a);
  a = Problem::partition(a, 0);
  printLL(a);

  int array2[] = {4,5,6,1,2,3};
  Node* a2 = arrayToLL(array2, sizeof(array2) / sizeof(int));
  printLL(a2);
  a2 = Problem::partition(a2, 6);
  printLL(a2);
  
  return 0;
}
