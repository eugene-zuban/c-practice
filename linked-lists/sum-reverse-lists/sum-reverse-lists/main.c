//
//  main.c
//  sum-reverse-lists: sum two linked lists represent integer numbers in reverse order.
//  Write result to a new linked list in reverse order too.
//  Example: (1 -> 3 -> 5) + (2 -> 3 -> 4) = (3 -> 6 -> 9), which represents 531 + 432 = 963
//

#include <stdio.h>
#include <stdlib.h>

#define LIST_END (struct node *) 0

struct node {
    int data;
    struct node *next;
};

struct node *makeList(void);
void printList(struct node *head);
struct node *addLists(struct node *list1, struct node *list2);

struct node *makeList(void) {
    struct node *head = LIST_END, *previous = LIST_END;
    int items = 0, value = 0;

    printf("Please enter number of elements: ");
    scanf("%d", &items);

    while (items-- > 0) {
        struct node *item = (struct node*) malloc(sizeof(struct node));
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

void printList(struct node *list) {
    printf("List values: ");

    while (list != LIST_END) {
        printf("%d ", list->data);
        list = list->next;
    }

    printf("\n");
}

int main(void) {
    struct node *list1 = LIST_END, *list2 = LIST_END;

    list1 = makeList();
    list2 = makeList();

    printList(list1);
    printList(list2);

    return 0;
}
