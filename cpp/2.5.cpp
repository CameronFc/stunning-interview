
#include <stdio.h>

struct Node {
  int value;
  Node* next;
  
  Node(int val) {
    value = val;
    next = nullptr;
  }
};

void sumLists(Node* lla, Node* llb, Node* out, int carry) {
  // STOP if we don't have any more digits to sum.
  if(lla == nullptr && llb == nullptr) {
    return;
  }
  // Assume the linked digit lists are currently null pointers. (the list has ended).
  // If there are still more digits in the list, use them.
  Node* llaNext = nullptr;
  int da = 0;
  if(lla != nullptr) {
    da = lla->value;
    llaNext = lla->next; // Gibs Swift optional unwrapping plz
  }
  
  int db = 0;
  Node* llbNext = nullptr;
  if(llb != nullptr) {
    db = llb->value;
    llbNext = llb->next;
  }
  
  int digitSum = da + db + carry;
  out->value = digitSum % 10; 
  carry = ((digitSum >= 10) ? 1 : 0); // Calculate carry for next iteration
  
  if(llaNext == nullptr && llbNext == nullptr && carry == 0) {
    return; // Don't add trailing 0s.
  } else {
    out->next = new Node(0); 
  }
  
  sumLists(llaNext, llbNext, out->next, carry);
}


int main(int argc, char** argv) {
  
  Node* a = new Node(7);
  a->next = new Node(1);
  a->next->next = new Node(6);
    
  Node* b = new Node(5);
  b->next = new Node(9);
  b->next->next = new Node(2);

  Node* sum = new Node(0);
  
  sumLists(a,b,sum,0);
  
  while(sum != nullptr) {
    printf("%d\n", sum->value);
    sum = sum->next;
  }
  
  return 0;
}
