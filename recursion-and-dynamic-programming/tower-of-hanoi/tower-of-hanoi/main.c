//
//  main.c
//  tower-of-hanoi: a classic Tower Of Hanoi problem using stack.
//

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_STACK (struct stack *) 0

typedef struct stack {
    char *name;
    struct stack *item;
} stack;

// moving one disk from origin to destination
void moveTop(stack *orig, stack *dest) {
    return;
}

// move disks recursivelly move all the disks
void moveDiscs(int n, stack *orig, stack *dest, stack *buffer) {
    if (n <= 0) {
        return;
    }

    // move from origin into the buffer using *dest as a buffer
    moveDiscs(n - 1, orig, buffer, dest);

    // move the top from origin to the dest
    moveTop(orig, dest);

    // move from the buffer into the dest using *orig as a buffer
    moveDiscs(n - 1, buffer, dest, orig);
}

// create linked list stask helper
stack *createStack(char *name) {
    stack *newStack = (stack *) malloc(sizeof(stack));   
    if (newStack == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    newStack->name = name;
    newStack->item = EMPTY_STACK;

    return newStack;
}

int main(int argc, const char * argv[]) {
    if (argc < 2)
        return -1;

    int disks = atoi(argv[1]);

    // create all stacks
    stack *origin = createStack("origin");
    stack *buffer = createStack("buffer");
    stack *dest = createStack("Dest");
    
    printf("Number of disks: %i\n", disks);

    return 0;
}
