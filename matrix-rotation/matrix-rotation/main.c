//
//  main.c
//  matrix-rotation: rotate the matrix by 90 degrees
//

#include <stdio.h>

void fillMatrix(int rows, int cols, int matrix[rows][cols]) {
    int col, row;

    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            matrix[row][col] = 10 * (row + 1) + (col);
        }
    } 
};

int main(void) {
    void fillMatrix(int rows, int cols, int matrix[rows][cols]);

    int mRows = 0, mCols = 0;
    
    printf("Please enter number of rows: ");
    scanf("%i", &mRows);
    printf("Please enter number of columns: ");
    scanf("%i", &mCols);
    
    int matrix[5][5];

    fillMatrix(mRows, mCols, matrix);

    return 0;
}
