//
//  main.c
//  matrix-rotation: rotate the matrix by 90 degrees
//

#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int rows, int cols, int matrix[rows][cols]) {
    int col, row;

    for (row = 0; row < rows; ++row) {
        for (col = 0; col < cols; ++col) {
            matrix[row][col] = 10 * (row + 1) + (col + 1);
        }
    } 
};

void rotateMatrix(int rows, int cols, int matrix[rows][cols]) {
    int layers = rows / 2;

    for (int layer = 0; layer <= layers; layer++) {
        int first = layer;
        int last = cols - layers;

        for (int i = first; i < last; i++) {
            int offset = last - i;

            // save top
            int top = matrix[first][i];

            // left -> top
            matrix[first][i] = matrix[offset][first];

            // bottom -> left
            matrix[offset][first] = matrix[last][offset];

            // right -> bottom
            matrix[last][offset] = matrix[i][last];

            // top -> right
            matrix[i][last] = top;
        }
    }
}

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

    int nRows = 0, nCols = 0;
    
    printf("Please enter number of rows: ");
    scanf("%d", &nRows);
    printf("Please enter number of columns: ");
    scanf("%d", &nCols);

    int matrix[nRows][nCols];

    fillMatrix(nRows, nCols, matrix);
    printMatrix(nRows, nCols, matrix);

    printf("\n");

    rotateMatrix(nRows, nCols, matrix);
    printMatrix(nRows, nCols, matrix);

    return 0;
}
