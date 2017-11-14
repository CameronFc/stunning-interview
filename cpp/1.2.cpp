
#include <stdio.h>
#include <string>
#include <cstdint>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Problem {
public:
  static bool isPermutation(string s, string t) {

    int charCountS[256] = {0};
    int charCountT[256] = {0};

    for(int i = 0; i < s.size(); i++) {
      charCountS[(int)s[i]]++;
    }

    for(int i = 0; i < t.size(); i++) {
      charCountT[(int)t[i]]++;
    }

    for(int i = 0; i < 256; i++) {
      if(charCountS[i] != charCountT[i]) {
        return false;
      }
    }

    return true;
  }

};

int main(int argc, char** argv) {
  bool result = Problem::isPermutation("string a", "string b");
  std::cout << result << std::endl;

  result = Problem::isPermutation("tacocat", "catocat");
  std::cout << result << std::endl;
  return 0;
}
