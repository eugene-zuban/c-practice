//
//  main.c
//  tower-of-hanoi: a classic Tower Of Hanoi problem using stack.
//

#include <stdio.h>
#include <stdlib.h>

#define LIST_END (struct stackItem *) 0

typedef struct stackItem {
    int diskId;
    struct stackItem *next;
} stackItem;

typedef struct stack {
    char *name;
    struct stackItem *item;
} stack;

// create a linked list stask helper
stack *createStack(char *name) {
    stack *newStack = (stack *) malloc(sizeof(stack));   
    if (newStack == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    newStack->name = name;
    newStack->item = LIST_END;

  
  return newStack;
}

// remove the top disk from a given stack
int popDisk(stack *st) {
    if (st->item == LIST_END) {
        return -999;
    }

    stackItem *topItem = st->item;
    int diskId = topItem->diskId;

    st->item = topItem->next;
    free(topItem);

    return diskId;
}

// add a new disk into the stack
void pushDisk(stack *st, int diskId) {
    stackItem *item = (stackItem *) malloc(sizeof(stackItem));
    if (item == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    item->diskId = diskId;
    item->next = st->item;
    st->item = item;
}

// print out all disks from a given linked list
void printList(stackItem *item) {
    while(item != LIST_END) {
        printf("Disk %i\n", item->diskId); 
        item = item->next;
    }
}

// moving one disk from origin to destination
void moveTop(stack *origin, stack *dest) {    
    int diskId = popDisk(origin);
    printf("Moving disk %i from %s to %s\n", diskId, origin->name, dest->name);

    if (diskId) {
        pushDisk(dest, diskId);
    }
}

// move disks recursivelly move all the disks
void moveDisks(int n, stack *origin, stack *dest, stack *buffer) {
    if (n <= 0) {
        return;
    }

    // move from origin into the buffer using *dest as a buffer
    moveDisks(n - 1, origin, buffer, dest);

    // move the top from origin to the dest
    moveTop(origin, dest);

    // move from the buffer into the dest using *origin as a buffer
    moveDisks(n - 1, buffer, dest, origin);
}

int main(int argc, const char * argv[]) {
    if (argc < 2)
        return -1;

    int disks = atoi(argv[1]);

    // create all stacks
    stack *origin = createStack("Origin");
    stack *buffer = createStack("Buffer");
    stack *dest = createStack("Dest");

    // fill the origin with disks
    for (int i = disks; i >= 1; i--) {
        pushDisk(origin, i);
    }

    // print origin tower/stack
    printf("Origin Tower:\n");
    printList(origin->item);

    printf("\nMove disks from Origin to Destination...\n");
    moveDisks(disks, origin, dest, buffer);

    printf("\nDestination Tower:\n");
    printList(dest->item);

    return 0;
}
