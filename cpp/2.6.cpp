
#include <stdio.h>
#include <iostream>
#include <stack>
#include "linkedlist.hpp"

using std::cout;
using std::endl;
using std::stack;

using LinkedList::printLL;
using LinkedList::arrayToLL;
using LinkedList::Node;

class Problem {

public:
  static bool isPalindrome(Node* start) {

    if(start == nullptr) {
      return false;
    }

    if(start->next == nullptr) {
      return true; // length 1 
    }

    stack<Node*> leftSide;

    Node* walker = start;
    Node* runner = start;
    while(runner->next != nullptr && runner->next->next != nullptr) {
      leftSide.push(walker);
      walker = walker->next;
      runner = runner->next->next;
    }
    if(runner->next != nullptr) {
      leftSide.push(walker); // little hack to fix even-sized LLs.
    }
    // No matter the length of the  original LL, the next node after the walker
    // will be the start of the right hand side of the palindrome.
    // The leftside stack will contain all the nodes on the lefthand side,
    // exluding the exact middle node, if the LL is odd.
    walker = walker->next;
    while(walker != nullptr) {
      Node* left = leftSide.top();
      leftSide.pop();

      if(left->id != walker->id) {
        return false;
      }
      walker = walker->next;
    }

    return true;
  }
};

int main(int argc, char** argv) {
  
  int array[] = {1,2,3,3,2,1};
  Node* a = arrayToLL(array, sizeof(array) / sizeof(int));
  printLL(a);
    
  bool result = Problem::isPalindrome(a);
  cout << result << endl;

  int array2[] = {2,2};
  Node* a2 = arrayToLL(array2, sizeof(array2) / sizeof(int));
  printLL(a2);

  result = Problem::isPalindrome(a2);
  cout << result << endl;
  
  return 0;
}
