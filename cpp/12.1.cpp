
// Question 12.1 solution. (C++)

#include <iostream>
#include <stdio.h>

#define INPUT_FILE "input_file.txt"
#define SIZE 100
#define BLOCK_SIZE 1000 // The maximum number of characters we expect to load
// into a string from a line (including newline char)
#define K 3 // Prints Kth last lines

int main(int argc, char** argv) {

  char fileBuffer[SIZE];
  // Last line in a file should end in a newline according to POSIX
  sprintf(fileBuffer, "%s", "Line 1\nLine 2 Hello by the way. Hello once more! \nLine 3\nLine 4\nLine 5\n");
  
  // We are going to read the string in BLOCK_SIZE characters at a time
  char buffer[BLOCK_SIZE];
  
  int numLines = 0;
  
  //FILE* fp = fopen(INPUT_FILE, "r"); // We are not going to read a file in this solution, because we don't have access to the filesystem on an online REPL!
  FILE* fp = fmemopen(fileBuffer, SIZE, "r");
  if(fp == NULL) {
    printf("Could not open file: %s\n", INPUT_FILE);
    return 0;
  } else {
    // Unsafe, fgets does not check if the buffer is big enough!
    while(fgets(buffer, BLOCK_SIZE, fp) != NULL) { // fgets returns NULL on eof
      numLines++;
      printf("%s", buffer);
    }
    numLines--; // The above code will read one more line than there are in the file.

    printf("\n");

    rewind(fp);
    int currentLine = 1;// To match the semantics of the question, the lines will start numbered from 1
    while(fgets(buffer, BLOCK_SIZE, fp) != NULL) {
      if(numLines - currentLine < K) {
        printf("%s", buffer);
      }
      currentLine++; 
    } 
  }
  
  return 0;
}
