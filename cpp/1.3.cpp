
#include <stdio.h>
#include <string>
#include <cstdint>
#include <iostream>
#include <queue>

using std::string;
using std::cout;
using std::endl;
using std::queue;

// There is also another solution using 2 passes - forward pass to count the
// spaces, then a backward pass to swap characters to their proper place.

class Problem {
public:
  static void HTMLify(string& input, int length) {

    queue<int> queuedChars;

    for(int i = 0; i < input.size(); i++) {

      // If we read a space, save it to queue
      if(input[i] == ' ') {
        queuedChars.push('%');
        queuedChars.push('2');
        queuedChars.push('0');
      }

      // If we have nothing to replace in queue, just skip
      if(queuedChars.empty()) {
        continue;
      } else {

        // If we read a non-space character, save it to queue
        if(input[i] != ' ') {
          queuedChars.push(input[i]);
        }

        // Now replace the read character with the next char queued.
        input[i] = queuedChars.front();
        queuedChars.pop();
      }
    }
  }
};

int main(int argc, char** argv) {
  string input = "there are several spaces in this string.            ";
  cout << input << endl;
  Problem::HTMLify(input, input.size());
  cout << input << endl;
  return 0;
}
