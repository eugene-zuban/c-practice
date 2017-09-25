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
node *makeList(void);
node *getIntersection(node *list1, node *list2);
void printList(node *head);
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

node *makeList(void) {
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
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("END \n");
}

// add intersectLength elements from the end of the list 2 to the list1 end
void makeIntersection(node *list1, node *list2, int intersectLength) {
    int len2 = listLength(list2);
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

// checking for an intersection using a recursive approach
// assuming that list1 and list2 have the same length (which was done before the first call)
node *getIntersection(node *list1, node *list2) {
    if (list1 == LIST_END) {
        return LIST_END;
    }

    // using recursive call get to the end of the list and check for an intersection from the end
    node *intersection = getIntersection(list1->next, list2->next);

    // if we have already a node that represents intersection start OR if it's the last node
    if (intersection != LIST_END || list1->next == LIST_END) {
        if (list1 == list2) { // if current elements point to the same node, make it a new intersection start
            return list1;
        }

        // return previous intersection start node
        return intersection;
    }

    return LIST_END; // no matches, return the empty node
}

int main(void) {
    node *list1 = LIST_END, *list2 = LIST_END;
    int intersectLength = 0;

    puts("Filling the first list");
    list1 = makeList();

    puts("Filling the second list");
    list2 = makeList();

    printf("Please enter number of element to merge from the end of the second list to the end of the first: ");
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

    printf("Intersection:\n");
    printList(getIntersection(list1, list2));

    return 0;
}
