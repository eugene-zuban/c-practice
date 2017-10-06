//
//  main.c
//  queue-via-stacks: implement a FIFO queue using two stacks.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_END (stack *) 0
#define EMPTY_STACK -9999

typedef struct node {
    int value;
    struct node *next;
} stack;

struct stackQueue {
    stack *newElements;
    stack *oldElements;
} queue = {STACK_END, STACK_END};

// queue-related functions declaration
void add(int value);
bool isEmpty(void);
int peek(void);
int take(void);

// stack-related functions declaration
int peekFromStack(stack *stackPointer);
void pushToStack(stack **stackPtr, int value);
int popFromStack(stack **stackPtr);
bool isStackEmpty(stack *stackPtr);
void shiftStack(stack **from, stack **to);

// check if the queue is empty
bool isEmpty(void) {
    return isStackEmpty(queue.newElements) && isStackEmpty(queue.oldElements);
}

// add a new value to the end of the queue
void add(int value) {
    pushToStack(&queue.newElements, value);
}

// return the first (the oldest) element from the queue without removing it
int peek(void) {
    shiftStack(&queue.newElements, &queue.oldElements);
    
    return peekFromStack(queue.oldElements);
}

// return and remove the first (the oldest) element from the queue
int take(void) {
    shiftStack(&queue.newElements, &queue.oldElements);
    
    return popFromStack(&queue.oldElements);
}

// by shifting the stack we move elements from {from} to {to} stack so that elements will be sorted in backorder
// it's a lazy shift: shift only if oldElements (stack *to) stack is empty
void shiftStack(stack **from, stack **to) {
    if (isStackEmpty(*to)) {
        while (! isStackEmpty(*from)) {
            pushToStack(to, popFromStack(from));
        }
    }
}

// peek the first (head) element from the stack
int peekFromStack(stack *stackPt) {
    return stackPt != STACK_END ? stackPt->value : EMPTY_STACK;
}

// push the value into the head of the stack
void pushToStack(stack **stackPt, int value) {
    stack *newNode = (stack *) malloc(sizeof(stack));
    if (newNode == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->next = *stackPt;
    (*stackPt) = newNode;
}

// pop() the head from the stack
int popFromStack(stack **stackPt) {
    if (isStackEmpty(*stackPt)) {
        return EMPTY_STACK;
    }

    int value = (*stackPt)->value;
    stack *temp = *stackPt;
    (*stackPt) = temp->next;
    free(temp);

    return value;
}

// check if the stack is empty
bool isStackEmpty(stack *stackPt) {
    return stackPt == STACK_END;
}

int main(void) {
    // small testing
    printf("At the beginning the queue is: %s\n", isEmpty() ? "empty" : "full");

    add(1);
    printf("Add 1 to the queue. Peek() returns: %i\n", peek());

    add(2);
    printf("Add 2 to the queue. Peek() returns: %i\n", peek());

    add(3);
    printf("Add 3 to the queue. Peek() returns: %i\n", peek());

    printf("take() test. Expect 1, returns: %i\n", take());
    printf("take() test. Expect 2, returns: %i\n", take());
    printf("take() test. Expect 3, returns: %i\n", take());

    printf("At the end the queue is: %s\n", isEmpty() ? "empty" : "full");

    return 0;
}
