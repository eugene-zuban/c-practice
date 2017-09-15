//
//  main.c
//  list-partition: partition a linked list around a value X, where elements less than X go to the left,
//  and more or equal go to the right part of the list.
//

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

#define LIST_END (struct node*) 0

struct node *makeList();
struct node *partition(struct node *nd, int x);
void printList();

struct node *partition(struct node *nd, int x) {
    struct node *head = nd, *tail = nd;

    while (nd != LIST_END) {
        struct node *next = nd->next;

        if (nd->value >= x) {
            tail->next = nd;
            tail = nd;
        } else {
            nd->next = head;
            head = nd;
        }

        nd = next;
    }

    tail->next = LIST_END;

    return head;
}

void printList(struct node *head) {
    printf("Your list is: ");

    while (head != LIST_END) {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

struct node *makeList(void) {
    int nodes = 0, value = 0;
    struct node *head = LIST_END, *previous = LIST_END;

    printf("Please enter nodes number: ");
    scanf("%d", &nodes);

    while (nodes-- > 0) {
        printf("Enter node value: ");
        scanf("%d", &value);

        struct node *item = malloc(sizeof(struct node));
        if (item == NULL) {
            fprintf(stderr, "Memory allocating error.");
            exit(EXIT_FAILURE);
        }

        item->value = value;
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

int main(void) {
    struct node *list = makeList();
    printList(list);

    int x;
    printf("Please enter X value: ");
    scanf("%d", &x);

    list = partition(list, x);
    printList(list);

    return 0;
}
