
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using std::string;
using std::cout;
using std::endl;

#define N 3

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

  void swapCells90(int row, int column) {
    int temp = values[row][column];
    values[row][column] = values[(size - 1) - column][row];
    values[(size - 1) - column][row] = temp;
  }

  void rotate() {
    // Create 4 identical 'triangles' cut into the square matrix. Swap them to
    // achieve rotation.
    for(int side = 0; side < 3; side++) {
      for(int row = 0; row < ((size + 1) / 2); row++) {
        int leftBound = row;
        // The right bound starts from the right-hand side, and is less one for
        // each row. To avoid overlapping the triangle we are 'rotating', we
        // subtract one more from the right bound initially.
        int rightBound = (size - 2) - row; 
        while(leftBound <= rightBound) {

          // Swap coordinates from an orientation (side) to absolute within the
          // matrix;
          int adjRow = row;
          int adjCol = leftBound;
          for(int i = 0; i < side; i++) {
            int temp = adjRow;
            adjRow = (size - 1) - adjCol;
            adjCol = temp;
          }
          swapCells90(adjRow,adjCol);

          leftBound++;
        }
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
