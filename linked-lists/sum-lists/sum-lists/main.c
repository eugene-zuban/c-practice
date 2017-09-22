//
//  main.c
//  sum-lists: sum two linked lists represent integer numbers.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_END (node *) 0

typedef struct node {
    int data;
    struct node *next;
} node;

node *makeList(void);
void printList(node *list);
node *addItems(node *item1, node *item2, node *previosResult);

node *addItems(node *item1, node *item2, node *previousResult) {
    bool isFirstItem = false;
    
    if (item1 == LIST_END && item2 == LIST_END) {
        return LIST_END;
    }

    if (previousResult == LIST_END) {
        previousResult = (node *) malloc(sizeof(node));
        previousResult->data = 0;
        isFirstItem = true;
    }

    node *currentResult = (node *) malloc(sizeof(node));
    currentResult->data = 0;

    currentResult->next = addItems(item1->next, item2->next, currentResult);
    int sum = currentResult->data + item1->data + item2->data;
    currentResult->data = sum % 10;
    previousResult->data = sum / 10;

    if (isFirstItem && previousResult->data) {
        previousResult->next = currentResult;

        return previousResult;
    }

    return currentResult;
}

node *makeList(void) {
    node *head = LIST_END, *previous = LIST_END;
    int totalNodes = 0, value = 0;

    printf("Please enter number of nodes: ");
    scanf("%d", &totalNodes);

    for (int i = 0; i < totalNodes; i++) {
        node *item = (node *) malloc(sizeof(node));
        if (item == NULL) {
            printf("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        printf("Node %d: ", i + 1);
        scanf("%d", &value);
        item->data = value;
        item->next = LIST_END;

        if (head == LIST_END) {
            head = item;
        } else {
            previous->next = item;  
        }

        previous = item;
    }

    return head;
}

void printList(node *head) {
    printf("List values: ");

    while (head != LIST_END) {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main(void) {
    node *list1 = LIST_END, *list2 = LIST_END;

    list1 = makeList();
    list2 = makeList();

    printList(list1);
    printList(list2);

    printList(addItems(list1, list2, LIST_END));

    return 0;
}
