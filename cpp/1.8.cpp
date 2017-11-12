
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <map>

#define N 5
#define M N

#define RED     "\033[31m"
#define RESET   "\033[0m"

using std::vector;
using std::map;

class Problem {
  
  int matrix[N][M];
  vector<int> unmarkedRows;
  map<int, bool> columnsToMark;
  // Fills a portion (prefix) of a row with zeros.
  void markRowPrefix(int x, int y) {
    for(int i = 0; i < y; i++) {
      matrix[x][i] = 0;
    }
  }
  
  void randomizeMatrix() {
    srand(time(NULL));
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        matrix[i][j] = rand() % 10;   
      }
    }
  }
  
  void printMatrix() {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        if(matrix[i][j] == 0) {
          std::cout << RED << matrix[i][j] << " ";
        } else {
          std::cout << RESET << matrix[i][j] << " ";
        }
      }
      printf("\n");
    }
  }
  
  public:
  Problem() {
    
    randomizeMatrix();
    printMatrix();
    // Walk through each row fully. Mark any row with a zero in it.
    for(int i = 0; i < N; i++) {
      bool rowIsMarked = false;
      for(int j = 0; j < M; j++) {
        if(matrix[i][j] == 0) {
          // Mark the row if we have not already.
          if(!rowIsMarked) {
            markRowPrefix(i, j);
            rowIsMarked = true; 
          }
          // Take note that we need to mark this column too!
          columnsToMark[j] = true;
        }
        // Finish cell marking.
        if(rowIsMarked) {
          matrix[i][j] = 0;
        }
      }
      // If we have an unmarked row, we need to check later if it contains
      // any marked columns.
      if(!rowIsMarked) {
        unmarkedRows.push_back(i);
      }
    }
    printf("AFTER:\n");
    // Now that the rows are marked, onto the columns.
    for(map<int,bool>::iterator iter = columnsToMark.begin(); iter != columnsToMark.end(); iter++) {
      for(vector<int>::iterator viter = unmarkedRows.begin(); viter != unmarkedRows.end(); viter++) {
        matrix[*viter][iter->first] = 0;
      }
    }
    printMatrix();
  }
  
};

int main(int argc, char** argv) {
  Problem p; 
  return 0;
}
