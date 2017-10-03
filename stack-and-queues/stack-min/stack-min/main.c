//
//  main.c
//  stack->min: stack->with min() function that returns the minimum element in O(1) time
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stackItem {
    int value;
    int min;
    struct stackItem *next;
} node;

node *stack;

#define STACK_END (node *) 0
#define EMPTY_STACK_VALUE -99999

bool isEmpty(void);
int min(void);
void push(int value);
int pop(void);
int peek(void);

// return the current stack min value
int min(void) {
    return isEmpty() ? EMPTY_STACK_VALUE : stack->min;
}

// create a new node and ad it to the stack top
void push(int value) {
    node *newItem = (node *) malloc(sizeof(node));
    if (newItem == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newItem->value = value;
    newItem->next = STACK_END;

    // add newItem to the head
    if (isEmpty()) {
        newItem->min = value;
    } else {
        newItem->min = value < stack->min ? value : stack->min; // store new min value or use from the current stack top
        newItem->next = stack;
    }

    stack = newItem;
}

// return the top node's value and remove the node from the stack
int pop(void) {
    if (isEmpty()) {
        return EMPTY_STACK_VALUE;
    }

    int value = stack->value;

    node *top = stack;
    stack = stack->next; // move the head
    free(top); // release memory

    return value;
}

// return the top node without removing it
int peek(void) {
    return isEmpty() ? EMPTY_STACK_VALUE : stack->value;
}

// check if the stack is empty
bool isEmpty() {
    return stack == STACK_END;
}

int main(void) {
    // push some values to our stack
    push(100); // stack-> 100->END
    push(200); // stack-> 200->100->END

    // test results
    printf("Expected min value: 100, actual is: %i\n", min()); // stack 200->100->END
    printf("Expected pop: 200, actual: %i\n", pop()); // stack 100->END;
    printf("Expected peek: 100, actual: %i\n", peek()); // stack 100->END;

    // set new min
    push(1); // stack 1->100->END
    printf("Expected min: 1, actual: %i\n", min());

    // return all stack values. stack: 1->100->END
    int value;
    do {
        value = pop();
        printf("Current value: %i\n", value);
    } while (value != EMPTY_STACK_VALUE);

    return 0;
}
