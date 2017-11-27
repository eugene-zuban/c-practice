//
//  main.c
//  eight-queens: print all the ways of arrangings 8 queens on an 8x8 chessboard.
//  That none of the queens shares the same row, column, or diagonal.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define GRID_SIZE 8
#define EMPTY_WAY (way *) 0

// a node for ways_list linked list structure
typedef struct way_node {
    int *columns;
    struct way_node *next;
} way;

// a linked list wrapper for holding all the ways of queens arrangements
typedef struct ways_list {
    way *head;
    way *tail;
} ways;

// clone the columns array
int *cloneColumns(int *columns) {
    int *cloned = (int *) calloc(sizeof(int), GRID_SIZE);
    if (cloned == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        cloned[i] = columns[i];
    }

    return cloned;
}

// add a new way to the ways list
void copyColumnsToList(ways *list, int *columns) {
    way *newWay = (way *) malloc(sizeof(way));
    if (newWay == NULL) {
        exit(EXIT_FAILURE);
    }

    newWay->columns = cloneColumns(columns);
    newWay->next = EMPTY_WAY;
    if (list->head == EMPTY_WAY) {
        list->head = newWay;
    } else {
        newWay = list->tail;
    }

    list->tail = newWay;
}

// Checking if the requested position is "safe" for putting the queen in
bool isQueenAllowed(int rowToPut, int colToPut, int *columns) {
    for (int rowBefore = 0; rowBefore < rowToPut; rowBefore++) {
        int colBefore = columns[rowBefore];

        /* check that the column is free to put a queen in */
        if (colBefore == colToPut) {
            return false;
        }

        /* Check a diagonal */
        int colsDiff = abs(colToPut - colBefore);
        int rowsDiff = rowToPut - rowBefore;

        if (colsDiff == rowsDiff) {
            return false;
        }
    }

    return true;
}

// recursively fill the grid with all possible combinations
void putQueen(int *columns, int row, ways *listOfWays) {
    if (row == GRID_SIZE) { // add the current combination to the list of ways/combinations
        copyColumnsToList(listOfWays, columns);
    } else {
        for (int col = 0; col < GRID_SIZE; col++) {
            if (isQueenAllowed(row, col, columns)) {
                columns[row] = col;
                putQueen(columns, row + 1, listOfWays);
            }
        }
    }
}

void printWays(ways *list) {
    way *head = list->head;
    while (head != EMPTY_WAY) {
        for (int row = 0; row < GRID_SIZE; row++) {
            for (int col = 0; col < GRID_SIZE; col++) {
                printf(" %c ", head->columns[row] == col ? 'Q' : '-');
            }

            printf("\n");
        }

        printf("\n");
        head = head->next;
    }
}

int main(int argc, const char * argv[]) {
    int *columns = (int *) calloc(sizeof(int), GRID_SIZE);
    ways *listOfWays = (ways *) calloc(sizeof(ways), 1);

    if (columns == NULL || listOfWays == NULL) {
        exit(EXIT_FAILURE);
    }

    listOfWays->head = EMPTY_WAY;
    listOfWays->tail = EMPTY_WAY;

    putQueen(columns, 0, listOfWays);
    printWays(listOfWays);

    return 0;
}
