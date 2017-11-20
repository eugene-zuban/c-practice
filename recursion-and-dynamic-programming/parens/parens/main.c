//
//  main.c
//  parens: print all valid combinations of n pairs of parentheses.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    char *string;
    struct list_node *next;
} node;

typedef struct linked_list {
    node *head;
    node *tail;
} list;

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No arguments provided\n");
        exit(EXIT_FAILURE);
    }

    int count = atoi(argv[1]);

    return 0;
}

