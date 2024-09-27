#include <stdio.h>

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
  int firstRowZero = 0, firstColZero = 0;

  // Step 1: Determine if the first row or first column needs to be zeroed
  for (int i = 0; i < matrixSize; i++) {
    if (matrix[i][0] == 0) {
      firstColZero = 1;
    }
  }
  for (int j = 0; j < matrixColSize[0]; j++) {
    if (matrix[0][j] == 0) {
      firstRowZero = 1;
    }
  }

  // Step 2: Use first row and first column as markers
  for (int i = 1; i < matrixSize; i++) {
    for (int j = 1; j < matrixColSize[0]; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  // Step 3: Zero the marked rows and columns
  for (int i = 1; i < matrixSize; i++) {
    if (matrix[i][0] == 0) {
      for (int j = 1; j < matrixColSize[0]; j++) {
        matrix[i][j] = 0;
      }
    }
  }
  for (int j = 1; j < matrixColSize[0]; j++) {
    if (matrix[0][j] == 0) {
      for (int i = 1; i < matrixSize; i++) {
        matrix[i][j] = 0;
      }
    }
  }

  // Step 4: Zero the first row and first column if needed
  if (firstColZero) {
    for (int i = 0; i < matrixSize; i++) {
      matrix[i][0] = 0;
    }
  }
  if (firstRowZero) {
    for (int j = 0; j < matrixColSize[0]; j++) {
      matrix[0][j] = 0;
    }
  }
}

int main() {
  // Example usage:
  int matrix[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  int* mat[3];
  for (int i = 0; i < 3; i++) {
    mat[i] = matrix[i];
  }
  int cols = 3;
  setZeroes(mat, 3, &cols);

  // Output the result
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  return 0;
}
