
/*
 * Problem: Given two sorted integer arrays of lengths M and N, find their 
 * combined median. Can you do this in O(log(N + M)) time?
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10
#define M 10

int main() {

  int half = (N + M) / 2;

  int currentSeparatorIndex = 0;

  int* arrayA = malloc(sizeof(int*) * N);
  int* arrayB = malloc(sizeof(int*) * M);

  for(int i = 0; i < N; i++) {
    arrayA[i] = i;
  }
  for(int i = 0; i < M; i++) {
    arrayB[i] = i + 6;
    printf("%d\n", arrayB[i]);
  }

  
}

