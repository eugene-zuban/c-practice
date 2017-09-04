//
//  main.c
//  matrix-rotation: rotate the matrix by 90 degrees
//

#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int n, int matrix[n][n]) {
    int col, row;

    for (row = 0; row < n; ++row) {
        for (col = 0; col < n; ++col) {
            matrix[row][col] = 10 * (row + 1) + (col + 1);
        }
    } 
};

void rotateMatrix(int n, int matrix[n][n]) {
    int layers = n / 2;

    for (int layer = 0; layer < layers; layer++) {
        int first = layer;
        int last = n -1 - layer;

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

void printMatrix(int n, int matrix[n][n]) {
    int row, col;

    for (row = 0; row < n; ++row) {
        for (col = 0; col < n; ++col) {
            printf("%5i", matrix[row][col]);
        }

        printf("\n");
    }
};

int main(void) {
    void fillMatrix(int n, int matrix[n][n]);
    void printMatrix(int n, int matrix[n][n]);

    int n = 0;
    
    printf("Please enter matrix's dimension: ");
    scanf("%d", &n);

    int matrix[n][n];

    fillMatrix(n, matrix);
    printMatrix(n, matrix);

    printf("\n");

    rotateMatrix(n, matrix);
    printMatrix(n, matrix);

    return 0;
}
