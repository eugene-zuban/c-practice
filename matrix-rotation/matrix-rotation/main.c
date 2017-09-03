//
//  main.c
//  matrix-rotation: rotate the matrix by 90 degrees
//

#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int rows, int cols, int matrixx[rows][cols]) {
    int col, row;

    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            matrixx[row][col] = 10 * (col + 1) + (row + 1);
        }
    } 
};

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    int row, col;

    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            printf("%5i", matrix[row][col]);
        }

        printf("\n");
    }
};

int main(void) {
    void fillMatrix(int rows, int cols, int matrix[rows][cols]);
    void printMatrix(int rows, int cols, int matrix[rows][cols]);

    int mRows = 0, mCols = 0;
    
    printf("Please enter number of rows: ");
    scanf("%d", &mRows);
    printf("Please enter number of columns: ");
    scanf("%d", &mCols);

    int matrix[mCols][mRows];

    fillMatrix(mRows, mCols, matrix);
    
    printMatrix(mRows, mCols, matrix);

    return 0;
}
