//
//  main.c
//  sort-stack: sort a given stack using only one additional stack as a temp storage.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node *next;
} stack;

#define STACK_END (stack *) 0

stack *sort(stack **s);
int peek(stack *s);
void push(stack **s, int value);
int pop(stack **s);
bool isEmpty(stack *s);

int peek(stack *s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    return s->value;
}

void push(stack **s, int value) {
    stack *newNode = (stack *) malloc(sizeof(stack));
    if (newNode == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->next = *s;
    *s = newNode;
}

int pop(stack **s) {
    if (isEmpty(*s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    stack *temp = *s;
    int value = temp->value;
    *s = temp->next;
    free(temp);

    return value;
}

bool isEmpty(stack *s) {
    return s == STACK_END;
}

stack *sort(stack **unsorted) {
    stack *sorted = STACK_END;

    while (! isEmpty(*unsorted)) {
        int temp = pop(unsorted);
        
        while (! isEmpty(sorted) && temp > peek(sorted)) {
            push(unsorted, pop(&sorted));
        }

        push(&sorted, temp);
    }

    return sorted;
}


// helper test functions
stack *fillTestStack(void) {
    stack *s = STACK_END;
    push(&s, 123);
    push(&s, 1);
    push(&s, 0);
    push(&s, 99);

    printf("Unsorted stack: 123 1 0 99\n");

    return s;
}

int main(void) {
    stack *unsorted = fillTestStack();

    printf("Sorted stack values: ");
    stack *sorted = sort(&unsorted);

    while (sorted != STACK_END) {
        printf("%i ", pop(&sorted));
    }
    
    printf("\n");

    return 0;
}
