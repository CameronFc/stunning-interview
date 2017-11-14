
#include <stdio.h>
#include <string>
#include <cstdint>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Problem {
public:
  static bool isPalindromePermutation(string input) {

    int charCount[128] = {0};

    for(int i = 0; i < input.size(); i++) {

      char currentChar = input[i];
      
      if(currentChar == ' ') {
        continue; // Question does not consider spaces to be important.
      }
      // Count the number of each distinct character.
      // Map upper case letters to lower case ones, as in the question.
      // Don't change other characters like !,@,# etc.
      char lowerCasedChar = ((currentChar >= 'A' && currentChar <= 'Z')) ? (currentChar + ('a' - 'A')) : currentChar;
      charCount[(int)lowerCasedChar]++;
    }

    // In a palindrome, at most 1 character can appear exaclty once in the string.
    bool parsedCenterChar = false; 
    for(int i = 0; i < 128; i++) {
      if(charCount[i] % 2 == 1) {
        if(parsedCenterChar) {
          return false;
        } else {
          parsedCenterChar = true;
        }
      }
    }

    return true;
  }

};

int main(int argc, char** argv) {
  bool result = Problem::isPalindromePermutation("string a");
  std::cout << result << std::endl;

  result = Problem::isPalindromePermutation("tacoTAc");
  std::cout << result << std::endl;

  result = Problem::isPalindromePermutation("Tact Coa");
  std::cout << result << std::endl;
  return 0;
}
