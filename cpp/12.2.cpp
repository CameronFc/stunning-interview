
// Question 12.2 Solution (C++)

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>

void reverse(char* cstring) {
  printf("%s\n", cstring);
  const int size = strlen(cstring); // strlen includes length without null terminator.
  for(int i = 0; i < size / 2; i++) {
    int k = size - 1 - i; // Other swappee.
    // Swap in-place
    cstring[i] = cstring[i] ^ cstring[k];
    cstring[k] = cstring[i] ^ cstring[k];
    cstring[i] = cstring[i] ^ cstring[k];
  }
  printf("%s\n", cstring);
}

int main(int argc, char** argv) {
  std::string str = "Hello. and goodbye!";
  reverse((char* )str.c_str());
  return 0;
}
