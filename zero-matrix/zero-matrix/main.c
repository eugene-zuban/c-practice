//
//  main.c
//  zero-matrix: if an element in an MxN matrix is 0, set its entire row and column to 0.
//

#include <stdio.h>

void fillMatrix(int rows, int cols, int matrix[rows][cols]) {
    int value = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Please enter values for row: %i and col: %i: ", i + 1, j + 1);
            scanf("%i", &value);
   
            if (value) {
                matrix[i][j] = value;
            } else {
                --j;
            }
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    fputs("Your matrix is:\n", stdout);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%5i", matrix[i][j]);
        }
        
        fputs("\n", stdout);
    }
}

int main(void) {
    void fillMatrix(int rows, int cols, int matrix[rows][cols]);
    void printMatrix(int rows, int cols, int matrix[rows][cols]);
    void zeroFill(int rows, int cols, int matrix[rows][cols]);

    int rows = 0, cols = 0;

    printf("Please enter number of rows and columns in a format MxN: ");
    scanf("%ix%i", &rows, &cols);

    if (! rows || ! cols ) {
        fputs("Incorrect number of rows or cols", stdout);

        return 1;
    }

    int matrix[rows][cols];

    fillMatrix(rows, cols, matrix);
    
    printMatrix(rows, cols, matrix);

    return 0;
}
