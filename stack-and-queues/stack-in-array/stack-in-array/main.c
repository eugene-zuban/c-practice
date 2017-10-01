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
    int *values;
    int *sizes;
} stack;

#define STACKS_NUMBERS 3

// stack-related functions
bool push(stack *st, int stackId, int value);
int pop(stack *st, int stackId);
int peek(stack *st, int stackId);
bool isEmpty(stack *st, int stackId);
int topIndex(stack *st, int stackId);

// helpers
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
    arrayStack->values = calloc(stackLength, sizeof(int));
    if (arrayStack->values == NULL) {
        memoryAllocationError();
    }

    for (int i = 0; i < stackLength; i++) {
        arrayStack->values[i] = 0;
    }

    // set number of elements for each stack
    arrayStack->sizes = (int *) calloc(arrayStack->stacks, sizeof(int));
    if (arrayStack->sizes == NULL) {
        memoryAllocationError();
    }

    // set size (number of element) in each stack to 0 by default
    for (int i = 0; i < arrayStack->stacks; i++) {
        arrayStack->sizes[i] = 0;
    }

    return arrayStack;
}

//
// stack in array operations
//

bool isEmpty(stack *arrayStack, int stackId) {
    return arrayStack->sizes[stackId] == 0;
}

// push the value into the top of the stack specified by stackId
bool push(stack *arrayStack, int stackId, int value) {
    if (arrayStack->sizes[stackId] >= arrayStack->stackSize) {
        return false; // the stack is full
    }

    // increase stack elements count
    arrayStack->sizes[stackId]++;

    // push the value into the stack
    arrayStack->values[topIndex(arrayStack, stackId)] = value;

    return true;
}

// return the top value from the stack specified by stackId and shrink the stack after that
int pop(stack *arrayStack, int stackId) {
    if (isEmpty(arrayStack, stackId)) {
        return 0;
    }

    int currentTop = topIndex(arrayStack, stackId);
    int value = arrayStack->values[currentTop];

    arrayStack->values[currentTop] = 0; // erase the current top value
    arrayStack->sizes[stackId]--; //shrink the stack

    return value;
}

// return the top value from the stack specified by stackId without decreasing stack's size
int peek (stack *arrayStack, int stackId) {
    if (isEmpty(arrayStack, stackId)) {
        return 0;
    }

    return arrayStack->values[topIndex(arrayStack, stackId)];
}

// return current top index for a specified stack
int topIndex(stack *arrayStack, int stackId) {
    int offset = arrayStack->stackSize * (stackId); // the first stack has offset 0

    return offset + arrayStack->sizes[stackId] - 1; 
}

int main(void) {
    stack *arrayStack = initializeStack();

    // here can go code for working with the stack
    // example: push(arrayStack, 0, 10); for pushing value 10 to the first stack
    // pop(arrayStack, 0); return the current top value fromt he first stack

    printf("Done\n");

    return 0;
}
