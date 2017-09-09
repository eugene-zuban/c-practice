//
//  main.c
//  zero-matrix: if an element in an MxN matrix is 0, set its entire row and column to 0.
//

#include <stdio.h>
#include <stdbool.h>

void fillMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("matrix[%i][%i]: ", i, j);
            scanf("%i", &matrix[i][j]);
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

    fputs("\n", stdout);
}

void zeroMatrix(int rows, int cols, int matrix[rows][cols]) {
    bool firstRowHasZero = false, firstColumnHasZero = false;
    void nullifyRow(int rows, int cols, int index, int matrix[rows][cols]);
    void nullifyColumn(int rows, int cols, int index, int matrix[rows][cols]);

    // search for a 0 in the first row
    for (int i = 0; i < cols; ++i) {
        if (matrix[0][i] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    // search for a 0 in the first column
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            firstColumnHasZero = true;
        }
    }
    
    // search for zeros, skipping first row and column
    // using first row and column for marking cols and rows with zero(s).
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // scan first row for searching zero marks and fill related rows with zeros
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            nullifyRow(rows, cols, i, matrix);
        }
    }

    // scan first column for searching zero marks and fill related columns with zeros
    for (int i = 1; i < cols; ++i) {
        if (matrix[0][i] == 0) {
            nullifyColumn(rows, cols, i, matrix);
        }
    }

    if (firstRowHasZero) {
        nullifyRow(rows, cols, 0, matrix);
    }

    if (firstColumnHasZero) {
        nullifyColumn(rows, cols, 0, matrix);
    }
}

void nullifyRow(int rows, int cols, int index, int matrix[rows][cols]) {
    for (int i = 0; i < cols; ++i) {
        matrix[index][i] = 0;
    }
}

void nullifyColumn(int rows, int cols, int index, int matrix[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        matrix[i][index] = 0;
    }
}

int main(void) {
    void fillMatrix(int rows, int cols, int matrix[rows][cols]);
    void printMatrix(int rows, int cols, int matrix[rows][cols]);
    void zeroMatrix(int rows, int cols, int matrix[rows][cols]);

    int rows = 0, cols = 0;

    printf("Please enter number of rows and columns MxN: ");
    scanf("%ix%i", &rows, &cols);

    if (! rows || ! cols ) {
        fputs("Incorrect number of rows or cols", stdout);

        return 1;
    }

    int matrix[rows][cols];

    fillMatrix(rows, cols, matrix); 
    printMatrix(rows, cols, matrix);

    zeroMatrix(rows, cols, matrix);
    printMatrix(rows, cols, matrix);

    return 0;
}
