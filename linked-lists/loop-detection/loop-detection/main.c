//
//  main.c
//  loop-detection: find if a given linked list has a loop, return the head of the loop if it exists.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

#define LIST_END (node *) 0

// main functions
node *findLoopStart(node *head);
int getListLength(node *head);

// helpers
node *makeList(void);
void makeLoop(node *head);
void printList(node *head);

node *makeList() {
    node *head = LIST_END;
    node *previous = LIST_END;
    int items = 0;

    printf("Please enter number of items: ");
    scanf("%d", &items);

    for (int i = 1; i <= items; i++) {
        node *item = (node *) malloc(sizeof(node *));
        if (item == NULL) {
            printf("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        int value = 0;
        printf("Please enter node %i value: ", i);
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

void printList(node *head) {
    while (head != LIST_END) {
        printf("%i ", head->data);
        head = head->next;
    }

    printf("\n");
}

void makeLoop(node *head) {
    int loopStartIndex = 0;
    int listLength = 0;

    listLength = getListLength(head);

    // get the node id for starting the loop
    while (loopStartIndex == 0) {
        printf("Please enter a node index from which the loop needs to start: ");
        scanf("%i", &loopStartIndex);

        if (loopStartIndex > listLength) {
            printf("Loop start can't be more then list length\n");
            loopStartIndex = 0;
        }
    }

    node *loopStartNode = LIST_END;
    int currentNode = 0;
    while (head->next != LIST_END) {
        currentNode++;

        if (currentNode == loopStartIndex) {
            loopStartNode = head;
        }

        head = head->next;
    }

    // connect the loop starting node to the end of the list
    head->next = loopStartNode;
}

int getListLength(node *head) {
    int length = 0;
    while (head != LIST_END) {
        length++;
        head = head->next;
    }

    return length;
}

// finding the loop start using fast and slow runner pointers
node *findLoopStart(node *listHead) {
    node *slow = listHead;
    node *fast = listHead;

    // move the runners till they collide so they will be the same number of steps from the beginning of the list
    // and the same number of steps behind the loop head
    while (fast != LIST_END && fast->next != LIST_END) {
        fast = fast->next->next;
        slow = slow->next;

        // collision point, stop the loop
        if (fast == slow) {
            break;
        }
    }

    // check if there is no loop
    if (fast == LIST_END || fast->next == LIST_END) {
        return LIST_END;
    }

    // set the fast pointer to the start of the list and move it and the slow pointer till they collide at the start of the loop
    fast = listHead;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    // return the loop head
    return fast;
}

int main(void) {
    node *list = makeList();
    printList(list);
    makeLoop(list);
    
    node *loopStart = findLoopStart(list);
    if (loopStart == LIST_END) {
        printf("The list doesn't have a loop.");
    } else {
        printf("The loop starts at node with value: %i\n", loopStart->data);
    }

    return 0;
}
