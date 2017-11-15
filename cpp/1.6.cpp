
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

    // Determine size of output string beforehand.
    // The alternative is preallocating a string that is larger than needs be.
    int bSize = 0; 
    int runlength = 0;
    for(int i = 1; i <= input.size(); i++) {
      runlength++;
      if(i == input.size() || input[i] != input[i - 1]) {
        bSize += 1 + (std::to_string(runlength)).size(); 
        runlength = 0;
      }
    }

    if(input.size() <= bSize) {
      return input; // Just return the input string, could not compress.
    }
    string output(bSize, '0'); // Create an empty string of size bSize
    
    int oIndex = 0;
    runlength = 0;
    for(int i = 1; i <= input.size(); i++) {
      runlength++;
      if(i == input.size() || input[i] != input[i - 1]) {
        output[oIndex++] = input[i - 1]; 
        // Convert each digit in the runlength to a character, and append it to 
        // the output.
        string intString = std::to_string(runlength);
        for(int j = 0; j < intString.size(); j++) {
          output[oIndex++] = intString[j]; 
        }
        runlength = 0; 
      }
    }
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

  result = Problem::runlengthCompress("aaabbbbbbbbbbbbcccccccccccccdeee");
  std::cout << result << std::endl;
  return 0;
}
