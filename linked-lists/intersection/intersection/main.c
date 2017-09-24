//
//  main.c
//  intersection: find if two linked lists intersect with each other checking by nodes references not values.
//  Return the first intersecting node.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

#define LIST_END (node *) 0

int listLength(node *head);
node *moveHead(node *head, int steps);
node *makeList();
void printList(node *head);
void printListBack(node *head);

int listLength(node *head) {
    int i = 0;

    while (head != LIST_END) {
        i++;
        head = head->next;
    }

    return i;
}

// move the head number of steps forward
node *moveHead(node *head, int steps) {
    while (steps-- > 0) {
        if (head != LIST_END && head->next != LIST_END) {
            head = head->next;
        }
    }

    return head;
}

node *makeList() {
    int items = 0, value = 0;
    node *head = LIST_END, *previous = LIST_END;

    printf("Please enter number of items: ");
    scanf("%d", &items);

    for (int i = 1; i <= items; i++) {
        printf("Item %d value: ", i);
        scanf("%d", &value);

        node *item = (node *) malloc(sizeof(node));
        if (item == NULL) {
            printf("Memory alloc error\n");
            exit(EXIT_FAILURE);
        }

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
    while (head != LIST_END) {
        printf("%d\n", head->data);
        head = head->next;
    }

    printf("\n");
}

void printListBack(node *head) {
    if (head != LIST_END) {
        printListBack(head->next);
        printf("%d\n", head->data);
    }
}

int main(void) {
    node *list1 = LIST_END, *list2 = LIST_END;

    puts("Filling the first list");
    list1 = makeList();

    puts("Filling the second list");
    list2 = makeList();

    // adjusting the length of the lists by "cutting" the extra elements from the beginning of the list
    int length1 = listLength(list1);
    int length2 = listLength(list2);
 
    if (length1 > length2) {
        list1 = moveHead(list1, length1 - length2);
    } else {
        list2 = moveHead(list2, length2 - length1);
    }

    puts("Adjusted first list");
    printList(list1);

    puts("Adjusted second list");
    printList(list2);

    return 0;
}
