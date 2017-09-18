//
//  main.c
//  sum-reverse-lists: sum two linked lists represent integer numbers in reverse order. (Recursion variant).
//  Example: (1 -> 3 -> 5) + (2 -> 3 -> 4) = (3 -> 6 -> 9), which represents 531 + 432 = 963
//

#include <stdio.h>
#include <stdlib.h>

#define LIST_END (node *) 0

typedef struct node {
    int data;
    struct node *next;
} node;

node *makeList(void);
void printList(node *head);
node *addItems(node *item1, node *item2, int carry);

// adding items from left to right using recursion
node *addItems(node *item1, node *item2, int carry) {
    if (item1 == LIST_END && item2 == LIST_END && carry == 0) {
        return LIST_END;
    }

    int value = carry;
    if (item1 != LIST_END) {
        value += item1->data;
        item1 = item1->next;
    }

    if (item2 != LIST_END) {
        value += item2->data;
        item2 = item2->next;
    }

    carry = value / 10; // 1 if >= 10, 0 if < 10

    node *result = (node *) malloc(sizeof(node));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    result->data = value % 10; // take the second digit

    if (item1 != LIST_END || item1 != LIST_END || carry) {
        result->next = addItems(item1, item2, carry);
    }

    return result;
}

node *makeList(void) {
    node *head = LIST_END, *previous = LIST_END;
    int items = 0, value = 0;

    printf("Please enter number of elements: ");
    scanf("%d", &items);

    while (items-- > 0) {
        node *item = (node*) malloc(sizeof(node));
        if (item == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        printf("Value: ");
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

void printList(node *list) {
    while (list != LIST_END) {
        printf("%d ", list->data);
        list = list->next;
    }

    printf("\n");
}

int main(void) {
    node *list1 = LIST_END, *list2 = LIST_END;

    printf("Creating List 1. ");
    list1 = makeList();
    printf("Creating List 2 ");
    list2 = makeList();

    printf("\nList 1 values: ");
    printList(list1);

    printf("List 2 values: ");
    printList(list2);

    node *sum = addItems(list1, list2, 0);
    printf("List 1 + List 2: ");
    printList(sum);

    return 0;
}
