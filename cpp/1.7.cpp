
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using std::string;
using std::cout;
using std::endl;

#define N 5

class Matrix {
public:

  int** values;
  const int size;

  Matrix(const int size) : size(size) {
    srand(time(NULL));
    values = new int*[size];
    for(int i = 0; i < size; i++) {
      values[i] = new int[size];
      for(int j = 0; j < size; j++) {
        values[i][j] = rand() % 10;
      }
    }
  }

  void swapCellRing(int row, int column, int oldValue, int recurse) {
    int nextRow = (size - 1) - column;
    int nextCol = row;
    int stored = values[nextRow][nextCol]; // Store forward position
    values[nextRow][nextCol] = oldValue;

    if(recurse) {
      swapCellRing(nextRow, nextCol, stored, --recurse);
    }
  }

  void rotate() {
    for(int row = 0; row < ((size + 1) / 2); row++) {
      int leftBound = row;
      // The right bound starts from the right-hand side, and is less one for
      // each row. To avoid overlapping the triangle we are 'rotating', we
      // subtract one more from the right bound initially.
      int rightBound = (size - 2) - row; 
      while(leftBound <= rightBound) {
        swapCellRing(row, leftBound, values[row][leftBound], 3);
        leftBound++;
      }
    }
  }

  void print() {
    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        cout << values[i][j];
      }
      cout << endl;
    }
    cout << endl;
  }
};

int main(int argc, char** argv) {

  Matrix m(N);
  m.print();
  m.rotate();
  m.print();

  return 0;
}
