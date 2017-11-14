
#include <stdio.h>
#include <string>
#include <cstdint>
#include <iostream>

using std::string;

class Problem {
public:
  static bool isUnique(string s) {

    char charsUsed[32] = {}; // 1 bit for each character. Init to \0

    for(int i = 0; i < s.size(); i++) {
      uint8_t k = s[i] >> 3;
      uint8_t charBit = (1 << (s[i] % 8));
      if((charsUsed[k] & charBit) > 0) {
        return false;
      } else {
        charsUsed[k] = charsUsed[k] ^ charBit;
      }
    }
    
    return true;
  }

};

int main(int argc, char** argv) {
  bool result = Problem::isUnique("Am Uniqe!");
  std::cout << result << std::endl;

  result = Problem::isUnique("Not unique");
  std::cout << result << std::endl;
  return 0;
}
