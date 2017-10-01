//
//  main.c
//  stack-in-array: implement 3 stacks using the same array
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned int stackSize;
    unsigned int stacks;
    int *storage;
    int *sizes;
} stack;

#define STACKS_NUMBERS 3

bool push(stack *st, int stackId, int value);
int pop(stack *st, int stackId);
int peek(stack *st, int stackId);
bool isEmpty(stack *st, int stackId);
int topIndex(stack *st, int stackId);

stack *initializeStack(void);
void memoryAllocationError();

void memoryAllocationError() {
    printf("Memory allocation error\n");
    exit(EXIT_FAILURE);
}

// stack initialization
stack *initializeStack(void) {
    stack *arrayStack = (stack *) malloc(sizeof(stack));
    if (arrayStack == NULL) {
        memoryAllocationError();
    }

    arrayStack->stackSize = 0;
    arrayStack->stacks = STACKS_NUMBERS;

    // compute all stacks length
    while (arrayStack->stackSize <= 0) {
        printf("Please enter the size of a stack: ");
        scanf("%u", &arrayStack->stackSize);
    }

    int stackLength = arrayStack->stacks * arrayStack->stackSize; 
 
    // allocating memory for all stacks
    arrayStack->storage = calloc(stackLength, sizeof(int));
    if (arrayStack->storage == NULL) {
        memoryAllocationError();
    }

    for (int i = 0; i < stackLength; i++) {
        arrayStack->storage[i] = 0;
    }

    // set number of elements for each stack
    arrayStack->sizes = (int *) calloc(arrayStack->stacks, sizeof(int));
    if (arrayStack->sizes == NULL) {
        memoryAllocationError();
    }

    for (int i = 0; i < arrayStack->stacks; i++) {
        arrayStack->sizes[i] = 0;
    }

    return arrayStack;
}

//
// stack in array operations
//

bool isEmpty(stack *st, int stackId) {
    return st->sizes[stackId] == 0;
}

bool push(stack *st, int stackId, int value) {
    if (st->sizes[stackId] >= st->stackSize) {
        return false; // the stack is full
    }

    st->sizes[stackId]++;
    st->storage[topIndex(st, stackId)] = value;

    return true;
}

int pop(stack *st, int stackId) {
    if (isEmpty(st, stackId)) {
        return 0;
    }

    int currentTop = topIndex(st, stackId);
    int value = st->storage[currentTop];
    st->storage[currentTop] = 0; // erase current value
    st->sizes[stackId]--; //shrink the stack

    return value;
}

int peek (stack *st, int stackId) {
    if (isEmpty(st, stackId)) {
        return 0;
    }

    return st->storage[topIndex(st, stackId)];
}

int topIndex(stack *st, int stackId) {
    int offset = st->stackSize * (stackId - 1);

    return offset + st->sizes[stackId] - 1;
}

int main(void) {
    stack *arrayStack = initializeStack();

    printf("Done\n");

    return 0;
}
