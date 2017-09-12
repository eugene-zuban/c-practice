//
//  main.c
//  find-nth-to-last: Find Nth to last node in a linked list.
//

#include <stdio.h>

struct node {
    int value;
    struct node *next;
}

#define LIST_END = (struct node *) 0;

struct node *makeList(void), *findNthTOLast(struct node *head, int *nodeIndex, int nSearh);
void printList(struct node *head);

struct node *findNthToLast(struct node *head, int *nodeIndex, int nSearch) {
    if (head == LIST_END) {
        return LIST_END;
    }

    struct node *item = findNthToLast(head->next, nodeIndex, nSearch);

    *nodeIndex = *nodeIndex + 1;
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
    struct node *item, *head = END_LIST, *previous = END_LIST;

    printf("Please enter the number of nodes: ");
    scanf("%d", &nodes);

    while (nodes-- > 0) {
        item = malloc(sizeof(struct node));

        if (item == NULL) {
            fprintf(stderr, "Error memory allocation\n");
            exit(EXIT_FAILURE);
        }

        printf("Please enter node value: ");
        scanf("%d", item->value);
    }
}

int main(void) {
    return 0;
}
