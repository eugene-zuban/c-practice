//
//  main.c
//  paint-fill: given an MxN array represents a screen with pixels of different colors, a point, and a color.
//  Fill all the surrounding area untill the color changes the original color. "Paint fill" function analogy.
//

#include <stdio.h>

enum colors {Red, Green, Blue};

char *getColorFromEnum(enum colors color) {
    switch (color) {
        case Red:
            return "Red";
            break;
        case Green:
            return "Green";
            break;
        case Blue:
            return "Blue";
            break;
    }

    return "No color";
}

void arrayPrint(int rows, int cols, enum colors arr[][cols]) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%-8s", getColorFromEnum(arr[row][col]));
        }

        printf("\n");
    }
}

void paintFill(int rows, int cols, enum colors arr[][cols], enum colors originalColor, enum colors newColor, int row, int col) {
    if (row < 0 || col < 0 || row >= rows || col >= cols) {
        return;
    }

    if (arr[row][col] != originalColor) {
        return;
    }

    arr[row][col] = newColor;

    // move up
    paintFill(rows, cols, arr, originalColor, newColor, row - 1, col);
    
    // move down
    paintFill(rows, cols, arr, originalColor, newColor, row + 1, col);

    // move left
    paintFill(rows, cols, arr, originalColor, newColor, row, col - 1);

    // move right
    paintFill(rows, cols, arr, originalColor, newColor, row, col + 1);
}

int main(void) {
    // create an array with colors
    const int rows = 5, cols = 5;

    enum colors arr[rows][cols] = {
        {Blue, Blue, Blue, Green, Blue},
        {Green, Blue, Green, Green, Green},
        {Blue, Blue, Green, Blue, Blue},
        {Blue, Green, Green, Blue, Blue},
        {Green, Green, Green, Green, Blue},
    };

    printf("Original screen (matrix):\n");
    arrayPrint(rows, cols, arr);

    printf("\nChanging Blue to Red:\n");
    paintFill(rows, cols, arr, Blue, Red, 1, 1);
    arrayPrint(rows, cols, arr);

    return 0;
}
