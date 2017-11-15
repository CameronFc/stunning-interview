
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Problem {
public:
  static string runlengthCompress(const string input) {

    if(input.size() <= 2) {
      return input; // Can't possibly compress a string of this size
    }

    int runs = 0; // number of 'runlengths' in the string
    char current = input[0];
    for(int i = 0; i < input.size(); i++) {
      if(input[i] != current) {
        runs++;
      }
      current = input[i];
    }
    runs++; // Additional run from reading last character

    int bSize = runs * 2;
    if(input.size() <= bSize) {
      return input; // Just return the input string, could not compress.
    }
    string output(bSize, '0');
    
    int oIndex = bSize - 1; // Last element.
    current = input[input.size() - 1];
    int runlength = 0;
    for(int i = input.size() - 1; i >= 0 ; i--) {
      if(current == input[i]) {
        runlength++;
      } else {
        // convert runlength to char, save to spot along with character
        char out = (char)('0' + runlength);
        output[oIndex] = out; 
        output[oIndex - 1] = current;
        oIndex -= 2;
        runlength = 1; // just saw 1 new character
      }
      current = input[i];
    }
    // We have to set the last two characters written(first two characters in
    // the string) when we hit the end of the input string.
    output[1] = (char)('0' + runlength); 
    output[0] = current;

    return output;
  }
};

int main(int argc, char** argv) {
  string result = Problem::runlengthCompress("string a");
  std::cout << result << std::endl;

  result = Problem::runlengthCompress("aabbccdeeeee");
  std::cout << result << std::endl;

  result = Problem::runlengthCompress("aabcccccaaa");
  std::cout << result << std::endl;

  return 0;
}
