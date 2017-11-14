
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Problem {
public:
  static bool isWithinOneSID(string first, string second) {

    // If they are the same length, we only need to check if 1 or 0 swaps are
    // needed.
    if(first.size() == second.size()) {

      bool needsSwap = false;
      for(int i = 0; i < first.size(); i++) {
        if(first[i] != second[i]) {
          if(needsSwap) {
            return false;
          } else {
            needsSwap = true;
          }
        }
      }
      return true; // Both strings are the same, down to at most 1 swap.
    }

    // Otherwise we need to insert or delete. First figure out which string is
    // the longer one so we can do both cases with the same code.
    int sizeDiff = first.size() - second.size();
    if(abs(sizeDiff) == 1) {
      string& larger = (sizeDiff < 0) ? second : first;
      string& smaller = (sizeDiff < 0) ? first : second;

      bool didInsert = false;
      for(int i = 0; i < smaller.size(); i++) {
        // We will simulate an insert by advancing the iterator by 1 for the
        // larger string. So on the first difference read, the iterator on the larger
        // string will skip forward by one. On the second difference, return
        // false; we can't insert twice!
        if(smaller[i] != larger[i + didInsert]) { // Booleans are cast to 0 or 1.
          if(didInsert) {
            // We found multiple differences that could not be corrected by one
            // insert.
            return false; 
          } else {
            didInsert = true;
          }
        }
      }
      return true; // Both strings are the same, down to at most 1 insert.
    } else {
      return false; // The strings differ in length by 2 or more chars.
    }
  }
};

int main(int argc, char** argv) {
  bool result = Problem::isWithinOneSID("string a", "string b");
  std::cout << result << std::endl;

  result = Problem::isWithinOneSID("racecar", "racecara");
  std::cout << result << std::endl;

  result = Problem::isWithinOneSID("not gonna happen", "certainly");
  std::cout << result << std::endl;

  result = Problem::isWithinOneSID("close!", "chose?");
  std::cout << result << std::endl;

  result = Problem::isWithinOneSID("tacocat", "taocat");
  std::cout << result << std::endl;

  result = Problem::isWithinOneSID("", "t");
  std::cout << result << std::endl;
  return 0;
}
