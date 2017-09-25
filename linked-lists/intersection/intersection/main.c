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
void makeIntersection(node *list1, node *list2, int elementsToMerge);

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

// add intersectLength elements from the end of the list 2 to the list1 end
void makeIntersection(node *list1, node *list2, int intersectLength) {
    int len1 = listLength(list1), len2 = listLength(list2);
    int offset = len2 - intersectLength;

    // go the the list1 tail
    while (list1->next != LIST_END) {
        list1 = list1->next;
    }

    // go to the node from where we need to start the intersection
    for (int i = 0; i < offset; i++) {
        if (list2 != LIST_END) {
            list2 = list2->next;
        }
    }

    // making the intersection
    list1->next = list2;
}

int main(void) {
    node *list1 = LIST_END, *list2 = LIST_END;
    int intersectLength = 0;

    puts("Filling the first list");
    list1 = makeList();

    puts("Filling the second list");
    list2 = makeList();

    printf("Please enter number of element to merge from the end of the second list to the ond of the first: ");
    scanf("%d", &intersectLength);
    makeIntersection(list1, list2, intersectLength);

    printList(list1);

    // adjusting lists length
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
