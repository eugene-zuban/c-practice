//
//  main.c
//  remove-duplicates Remove Duplicates from a linked list.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIST_END (struct node *) 0

struct node {
    char value;
    struct node *next;
};

bool nodeValuesMap[52] = {}; // "hash" table for storing flags of characters from the linked list.

struct node *makeList(void);
void printList(struct node *head);

struct node *makeList(void) {
    int nodes = 0;
    struct node *listHead = LIST_END, *previousNode = LIST_END, *newNode;
    char value;

    printf("Please enter number of nodes: ");
    scanf("%i", &nodes);

    for (int i = 0; i < nodes; ++i) {
        printf("Please enter node value: ");
        scanf("%1s", &value);

        newNode = (struct node *) malloc(sizeof(struct node));
        if (newNode == NULL) {
            fprintf(stderr, "Error allocation memory\n");
            exit(EXIT_FAILURE);
        }

        newNode->value = value;
        newNode->next = LIST_END;

        // link nodes to make a linked list
        if (listHead == LIST_END) {
            listHead = newNode;
            previousNode = listHead;
        } else {
            previousNode->next = newNode;
            previousNode = newNode;
        }
    }

    return listHead;
}

void printList(struct node *listNode) {
    while (listNode != LIST_END) {
        printf("%c ", listNode->value);
        listNode = listNode->next;
    }
    
    printf("\n");
}

int main(void) {
    struct node *listHead = makeList();
    printList(listHead);

    return 0;
}
