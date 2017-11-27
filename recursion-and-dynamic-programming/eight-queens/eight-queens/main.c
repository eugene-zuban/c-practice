//
//  main.c
//  eight-queens: print all the ways of arrangings 8 queens on an 8x8 chess board.
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

// a linked list wrapper for holding all the ways of queens arrangings
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

int main(int argc, const char * argv[]) {
    return 0;
}
