//
//  main.c
//  find-nth-to-last: Find Nth to last node in a linked list.
//

#include <stdio.h>
#include <stdlib.h>

#define LIST_END (struct node *) 0

struct node {
    int value;
    struct node *next;
};

struct node *makeList(void);
struct node *findNthToLast(struct node *head, int *nodeIndex, int nSearh);
void printList(struct node *head);

// searching Nth to last using recursion
struct node *findNthToLast(struct node *head, int *nodeIndex, int nSearch) {
    if (head == LIST_END) {
        return LIST_END;
    }

    struct node *item = findNthToLast(head->next, nodeIndex, nSearch);

    *nodeIndex += 1;
    if (*nodeIndex == nSearch) {
        return head;
    }

    return item;
}

void printList(struct node *head) {
    while (head != LIST_END) {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

struct node *makeList(void) {
    int nodes = 0;
    struct node *item, *head = LIST_END, *previous = LIST_END;

    printf("Please enter the number of nodes: ");
    scanf("%d", &nodes);

    while ((nodes--) > 0) {
        item = malloc(sizeof(struct node));

        if (item == NULL) {
            fprintf(stderr, "Error memory allocation\n");
            exit(EXIT_FAILURE);
        }

        printf("Please enter node value: ");
        scanf("%d", &item->value);
        item->next = LIST_END;

        if (head == LIST_END) {
            head = item;
            previous = head;

            continue;
        }
        
        previous->next = item;
        previous = item;
    }

    return head;
}

int main(void) {
    struct node *list, *nthNode;
    int elementToLast = 0, index = 0;
    int *indexNode = &index;

    list = makeList();
    printList(list);

    printf("Enter Nth to last element: ");
    scanf("%d", &elementToLast);

    nthNode = findNthToLast(list, indexNode, elementToLast);
    printf("Nth to last element has value %d \n", nthNode->value);

    return 0;
}
