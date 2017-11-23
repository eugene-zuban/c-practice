//
//  main.c
//  parens: print all valid combinations of n pairs of parentheses.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEM_ALLOC_ERROR fprintf(stderr, "Memory alloc error\n"); exit(EXIT_FAILURE)
#define EMPTY_NODE (node *) 0

typedef struct list_node {
    char *string;
    struct list_node *next;
} node;

typedef struct linked_list {
    node *head;
    node *tail;
} list;

void addParen(list *parens, int leftRem, int rightRem, char *str, int offset);
char *cloneString(char *str);
void listAdd(list *linkedList, char *str);

char *cloneString(char *str) {
    int offset = 0;

    char *cloned = (char *) calloc(strlen(str) + 1, sizeof(char));
    if (cloned == NULL) {
        MEM_ALLOC_ERROR;
    }

    while (*(str + offset)) {
        *(cloned + offset) = *(str + offset);
        offset++;
    }

    return cloned;
}

void listAdd(list *linkedList, char *str) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        MEM_ALLOC_ERROR;
    }

    newNode->string = str;
    newNode->next = EMPTY_NODE;

    if (linkedList->head == EMPTY_NODE) {
        linkedList->head = newNode;
    } else {
        linkedList->tail->next = newNode;
    }

    linkedList->tail = newNode;
}

list *createList(void) {
    list *newList = (list *) malloc(sizeof(list));
    if (newList == NULL) {
        MEM_ALLOC_ERROR;
    }

    newList->head = EMPTY_NODE;
    newList->tail = EMPTY_NODE;

    return newList;
}

void printList(list *linkedList) {
    node *head = linkedList->head;

    while (head != EMPTY_NODE) {
        printf("%s\n", head->string);
        head = head->next;
    }
}

void addParen(list *parens, int leftRem, int rightRem, char *str, int offset) {
    if (leftRem < 0 || rightRem < leftRem) return;

    if (leftRem == 0 && rightRem == 0) {
        listAdd(parens, cloneString(str));
    } else {
        str[offset] = '(';
        addParen(parens, leftRem - 1, rightRem, str, offset + 1);

        str[offset] = ')';
        addParen(parens, leftRem, rightRem - 1, str, offset + 1);
    }
}

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        fprintf(stderr, "No arguments provided\n");
        exit(EXIT_FAILURE);
    }

    int count = atoi(argv[1]);
    list *listWithPairs = createList();

    char *str = (char *) calloc((count * 2) + 1, sizeof(char));
    if (str == NULL) {
        MEM_ALLOC_ERROR;
    }

    addParen(listWithPairs, count, count, str, 0);
    printList(listWithPairs);

    return 0;
}

