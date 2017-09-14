//
//  main.c
//  delete-middle-node: Delete the middle node from a linked list given access to this node only.
//

#include <stdio.h>
#include <stdlib.h>

#define END_LIST (struct node *) 0

struct node {
    int value;
    struct node *next;
};

void removeNode(struct node *nd);
void printList(struct node *head);
struct node *getMiddle(struct node *head);
struct node *makeList();

// removing the current node by copying its next node's values into it and removing the next node from the memory.
void removeNode(struct node *nd) {
    struct node *nextNode;

    if (nd->next != END_LIST) {
        nextNode = nd->next;
        *nd = *nextNode;
        free(nextNode);
    }
}

struct node *getMiddle(struct node *head) {
    struct node *p1 = head, *p2 = head;
    int i = 0;

    while (p2 != END_LIST) {
        p2 = p2->next;
        
        if ((++i) % 2 == 0) {
            p1 = p1->next;
        }
    }

    return p1;
}

struct node *makeList() {
    struct node *head = END_LIST, *previous = END_LIST, *item;
    int nodes = 0;

    printf("Please enter number of nodes: ");
    scanf("%d", &nodes);

    while ((nodes)-- > 0) {
        item = malloc(sizeof(struct node));

        if (item == NULL) {
            fprintf(stderr, "Error memory allocation\n");
            exit(EXIT_FAILURE);
        }

        printf("Please enter node's value: ");
        scanf("%d", &item->value);
        item->next = END_LIST;

        if (head == END_LIST) {
            head = item;
        } else {
            previous->next = item;
        } 

        previous = item;
    }

    return head;
}

void printList(struct node *head) {
    printf("your current linked list: ");

    while (head != END_LIST) {
        printf("%d ", head->value);
        head = head->next;
    }

    printf("\n");
}

int main(void) {
    struct node *list = makeList();
    printList(list);

    struct node *middleNode = getMiddle(list);
    if (middleNode) {
        printf("Removing a node with value: %d\n", middleNode->value);     
        removeNode(middleNode);
    }
    printList(list);

    return 0;
}
