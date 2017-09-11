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
void removeDuplicates(struct node *head);
bool isValueSetOnMap(char value); 
void setValueOnMap(char value); 
int getValueCode(char value);

// check nodeValuesMap for provided value's flag
bool isValueSetOnMap(char value) {
    int code = getValueCode(value);

    if (code < 0) { // remove only alphabetical duplicates
        return false;
    }

    return nodeValuesMap[code];
}

// set provided value's flag to true
void setValueOnMap(char value) {
    int code = getValueCode(value);

    if (code >= 0) { // for simplicity works only with a-z && A-Z chars
        nodeValuesMap[code] = true;
    }
}

// convert an alphabet char into integer code where a is 0, or return -1 for non alphabetic chars
int getValueCode(char value) {
    if (value >= 'a' && value <= 'z') {
        return value - 'a';
    }

    if (value >= 'A' && value <= 'Z') {
        return value - 'A';
    }

    return -1;
}

// make a linked list
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
            fprintf(stderr, "Error allocating memory\n");
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

// remove duplicates using hash table for checking if each value from the list is unique.
void removeDuplicates(struct node *listNode) {
    struct node *previousNode = LIST_END;

    while (listNode != LIST_END) {
        if (isValueSetOnMap(listNode->value)) {
            previousNode->next = listNode->next;
            free(listNode);
            listNode = previousNode->next;
        } else {
            setValueOnMap(listNode->value);
            previousNode = listNode;
            listNode = listNode->next;
        }
    }
}

int main(void) {
    struct node *listHead = makeList();
    printList(listHead);

    removeDuplicates(listHead);
    printList(listHead);

    return 0;
}
