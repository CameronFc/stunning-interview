
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;
using std::cout;
using std::endl;

class Problem {
  
public:
  static bool isSubstring(string smaller, string larger) {
    return true; // STUB
  }

  static bool isRotation(string first, string second) {

    if(first.size() != second.size()) {
      return false;
    }

    string doubled = first + first;

    if(isSubstring(second, doubled)) {
      return true;
    } else {
      return false;
    }
  }

};

int main(int argc, char** argv) {
  bool result = Problem::isRotation("waterbottle", "erbottlewat");
  cout << result << endl;
  return 0;
}
