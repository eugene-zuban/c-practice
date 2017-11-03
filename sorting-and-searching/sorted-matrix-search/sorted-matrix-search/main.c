//
//  main.c
//  sorted-matrix-search: find an element in a given MxN matrix in which each row and column is sorted in ASC order.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// searching by using properties of sorted rows and cols starting from the last row and the first col
bool checkElement(int x, int rows, int cols, int arr[rows][cols]) {
    int col = 0;
    int row = rows - 1;

    // starting from the bottom of the first col and moving up and right
    while (row >= 0 && col < cols) {
        if (x == arr[row][col]) {
            return true;
        }

        if (x < arr[row][col]) {
            row--; // if x is less, move to the row above
        } else {
            col++; // if x is more, move to the next col on the same row
        }
    }

    return false;
}

void arrayPrint(int rows, int cols, int arr[][cols]) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%5i", arr[r][c]);
        }

        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    const int rows = 4;
    const int cols = 4;
    int x = 0;

    int arr[rows][cols] = {
        {10, 15, 20, 40},
        {20, 25, 30, 45},
        {25, 30, 31, 50},
        {30, 40, 45, 55},
    };

    arrayPrint(rows, cols, arr);

    while (true) {
        printf("Please enter eement to find or 999 to exit: ");
        scanf("%i", &x);

        if (x == 999) {
            break;
        }

        printf("Element %i is in the array: %s\n", x, checkElement(x, rows, cols, arr) ? "true" : "false");
    }
    
    return 0;
}
