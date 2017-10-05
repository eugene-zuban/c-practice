//
//  main.c
//  queue-via-stacks: implement a queue using two stacks.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_END (stack *) 0

typedef struct node {
    int value;
    struct node *next;
} stack;

struct stackQueue {
    stack *newElements;
    stack *oldElements;
} queue = {STACK_END, STACK_END};

// queue related functions declaration
void add(int value);
bool isEmpty(void);
int peek(void);
int extract(void);

// stsack-related functions declaration
int peekFromStack(stack *stackPointer);
void pushToStack(int value, stack *stackPtr);
int popFromStack(stack *stackPtr);
bool isStackEmpty(stack *stackPtr);
void shiftStack(stack *from, stack *to);

bool isEmputy(void) {
    return isStackEmpty(queue.newElements) && isStackEmpty(queue.oldElements);
}

void add(int value) {
    pushToStack(value, queue.newElements);
}

int main(void) {

    return 0;
}
