//
//  main.c
//  stack-min: stack with min() function that returns the minimum element in O(1) time
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    int min;
    struct node *next;
} node;

#define STACK_END (node *) 0
#define EMPTY_STACK_VALUE -99999

bool isEmpty(node *stack);
int min(node *stack);
void push(node **stack, int value);
int pop(node **stack);
int peek(node *stack);

// return the current stack min value
int min(node *stack) {
    if (isEmpty(stack)) {
        return EMPTY_STACK_VALUE;
    }

    return stack->min;
}

// create a new node and ad it to the stack top
void push(node **stack, int value) {
    node *newItem = (node *) malloc(sizeof(node));
    if (newItem == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    newItem->value = value;

    // add newItem to the head
    if (isEmpty(*stack)) {
        newItem->min = value;
        newItem->next = STACK_END;
    } else {
        newItem->min = value < (*stack)->min ? value : (*stack)->min; // store new min value or use from the current stack top
        newItem->next = *stack;
    }

    *stack = newItem;
}

// return the top node's value and remove the node from the stack
int pop(node **stack) {
    if (isEmpty(*stack)) {
        return EMPTY_STACK_VALUE;
    }

    node *top = *stack;
    int value = top->value;
    *stack = top->next; // remove the top
    free(top); // release memory

    return value;
}

// return the top node without removing it
int peek(node *stack) {
    if (isEmpty(stack)) {
        return EMPTY_STACK_VALUE;
    }

    return stack->value;
}

// check if the stasck is empty
bool isEmpty(node *stack) {
    return stack == STACK_END;
}

int main(void) {
    // create a new pointer for new stack
    node *stack = STACK_END;

    // push some values to our stack
    push(&stack, 100); // stack: 100->END
    push(&stack, 200); // stack: 200->100->END

    // test results
    printf("Expected min value: 100, actual is: %i\n", min(stack)); // stack: 200->100->END
    printf("Expected pop: 200, actual: %i\n", pop(&stack)); // stack: 100->END;
    printf("Expected peek: 100, actual: %i\n", peek(stack)); // stack: 100->END;

    // set new min
    push(&stack, 1); // stack: 1->100->END
    printf("Expected min: 1, actual: %i\n", min(stack));

    // return all the stack from stack 1->100->END
    int value;
    do {
        value = pop(&stack);
        printf("Current value: %i\n", value);
    } while (value != EMPTY_STACK_VALUE);

    return 0;
}
