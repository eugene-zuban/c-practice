//
//  main.c
//  sum-reverse-lists: sum two linked lists represent integer numbers in reverse order.
//  Write result to a new linked list in reverse order too.
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
node *addLists(node *list1, node *list2);

node *addLists(node *list1, node *list2) {
    int carry = 0, add1 = 0, add2 = 0, sum = 0;
    node *result = (node *) malloc(sizeof(node));
    node *head = result;

    // spin throught all the elements in two lists adding them digit by digit from left to right
    // carrying their overflow to next digit(s).
    while (list1 != LIST_END || list2 != LIST_END) {
        add1 = (list1 != LIST_END) ? list1->data : 0;
        add2 = (list2 != LIST_END) ? list2->data : 0;
        sum = add1 + add2 + carry;
        carry = sum / 10; // will give 1 if > 10, and 0 if < 10
        result->data = sum % 10; // take the second digit

        // need this to determine do we need to create a new node for the result
        list1 = (list1 != LIST_END) ? list1->next : LIST_END;
        list2 = (list2 != LIST_END) ? list2->next : LIST_END;
        if (list1 != LIST_END || list2 != LIST_END) {
            result->next = (node *) malloc(sizeof(node));
            result = result->next;
        }
    }

    // if list1 or list2 is bigger than the other one, we need to create additional nodes for the result.
    if (carry) {
        result->next = (node *) malloc(sizeof(node));
        result = result->next;
        result->data = carry;
    }

    result->next = LIST_END; // close the list.

    return head;
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

    node *sum = addLists(list1, list2);
    printf("List 1 + List 2: ");
    printList(sum);

    return 0;
}
