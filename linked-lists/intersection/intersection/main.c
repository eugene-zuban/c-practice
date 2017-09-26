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

typedef struct listInfo {
    node *tail;
    int length;
} listInfo;

#define LIST_END (node *) 0

node *moveHead(node *head, int steps);
node *makeList(void);
node *getIntersection(node *list1, node *list2);
listInfo *getListTailAndLength(node *list);
void printList(node *head);
void makeIntersection(node *list1, node *list2, int elementsToMerge);

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
    // go the the list1 tail
    while (list1->next != LIST_END) {
        list1 = list1->next;
    }

    // go to the node from where we need to start the intersection
    listInfo *list2Info = getListTailAndLength(list2);
    int offset = list2Info->length - intersectLength;
    for (int i = 0; i < offset; i++) {
        if (list2 != LIST_END) {
            list2 = list2->next;
        }
    }

    // making the intersection
    list1->next = list2;
}

listInfo *getListTailAndLength(node *list) {
    listInfo *info = (listInfo *) malloc(sizeof(listInfo));
    if (info == NULL) {
        printf("Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    info->length = 0;
    while (list != LIST_END) {
        info->tail = list;
        info->length++;
        list = list->next;
    }

    return info;
}

// return the first intersection node (if exists)
node *getIntersection(node *list1, node *list2) {
    listInfo *listInfo1 = getListTailAndLength(list1);
    listInfo *listInfo2 = getListTailAndLength(list2);

    // if last elements are not pointing to the same node the lists don't intersect
    if (listInfo1->tail != listInfo2->tail) {
        return LIST_END;
    }

    // adjust lists length
    if (listInfo1->length > listInfo2->length) {
        list1 = moveHead(list1, listInfo1->length - listInfo2->length);
    } else {
        list2 = moveHead(list2, listInfo2->length - listInfo1->length);
    }

    // search for the first shared node and return it if found
    // at this point list1 & list2 have the same length
    while (list1 != LIST_END) {
        if (list1 == list2) {
            return list1;
        }

        list1 = list1->next;
        list2 = list2->next;
    }

    // no intersection
    return LIST_END;
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
    makeIntersection(list1, list2,  intersectLength);
    printList(list1);

    printf("Intersection:\n");
    printList(getIntersection(list1, list2));

    return 0;
}
