//
//  main.c
//  coins: given an infinite number of coins 25, 10, 5, and 1 cents.
//  Compute the number of ways representing n cents.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int makeChange(int amount, const int denomsCount, const int denoms[], int index, int **map) {
    if (map[amount][index] > 0) { // get cached value
        return map[amount][index];
    }

    if (index >= denomsCount - 1) { // base case when only one denom is remained
        return 1;
    }

    int ways = 0;
    int denomAmount = denoms[index];
    for (int i = 0; i * denomAmount <= amount; i++) {
        int amountRemaining = amount - i * denomAmount;
        ways += makeChange(amountRemaining, denomsCount, denoms, index + 1, map);
    }

    map[amount][index] = ways; // save the ways value into the cache

    return ways;
}

// create a map[][] array of pointers
int **makeMap(int rows, int cols) {
    int **map = (int **) malloc(sizeof(int *) * rows);
    if (map == NULL) exit(EXIT_FAILURE);
    
    for (int i = 0; i < rows; i++) {
        map[i] = (int *) calloc(sizeof(int), cols);
        
        if (map[i] == NULL) exit(EXIT_FAILURE);
    }

    return map;
}

// free map pointers
void cleanMap(int **map, int rows) {
    for (int row = 0; row < rows; row++) {
        free(map[row]);
    }

    free(map);
}

int main(void) {
    int amount = 0;
    const int denomsCount = 4;
    const int denoms[] = {25, 10, 5, 1};

    while(true) {
        printf("Please enter the amount or -9999 for exit: ");
        scanf("%i", &amount);
        if (amount == -9999) break;

        int **map = makeMap(amount + 1, denomsCount);
        printf("%i\n", makeChange(amount, denomsCount, denoms, 0, map));
        cleanMap(map, amount + 1);
    }

    return 0;
}

