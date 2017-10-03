//
//  main.c
//  stack-of-plates: implement a data structure setOfStacks that includes several stacks
//  and it should create a new stack if previous is full.
//  pop() and push() on the setOfStacks need to work identical to a regular stack.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 5
#define NUMBER_OF_STACKS 5
#define STACK_END (stack *) 0
#define EMPTY_STACK -9999

typedef struct stackItem {
    int value;
    struct stackItem *next;
} stack;

struct setOfStacks {
    int currentStack;
    int stackSize;
    int numberOfStacks;
    int *sizes[NUMBER_OF_STACKS];
    stack *stacks[NUMBER_OF_STACKS];
} setOfStacks = {0, STACK_SIZE, NUMBER_OF_STACKS};

void initSet(void);
stack *getActiveStack(void);
stack *createNode(void);
int pop(void);
int peek(void);
void push(int value);
bool isEmpty(void);

void initSet(void) {
    for (int i = 0; i < setOfStacks.numberOfStacks; i++) {
        setOfStacks.sizes[i] = (int *) calloc(1, sizeof(int));
        setOfStacks.stacks[i] = STACK_END;
    }
}

stack *getActiveStack() {
    return setOfStacks.stacks[setOfStacks.currentStack];
}

bool isEmpty() {
    return getActiveStack() == STACK_END;
}

int peek() {
    if (isEmpty()) {
        return EMPTY_STACK;
    }

    return getActiveStack()->value;
}

void push(int value) {
    if (*setOfStacks.sizes[setOfStacks.currentStack] == STACK_SIZE) {
        if (setOfStacks.currentStack == NUMBER_OF_STACKS) {
            return;
        }

        setOfStacks.currentStack++;
    }

    stack *node = getActiveStack();

    if (node == STACK_END) {
        node = createNode();
        node->value = value;
    } else {
        stack *newNode = createNode();
        newNode->value = value;
        newNode->next = node;
        node = newNode;
    }

    *setOfStacks.sizes[setOfStacks.currentStack] += 1;
}

int pop(void) {
    if (isEmpty()) {
        return EMPTY_STACK;
    }

    stack *currentTop = getActiveStack();
    int value = currentTop->value;
    stack *temp = currentTop;
    currentTop = currentTop->next;
    free(temp);
    *setOfStacks.sizes[setOfStacks.currentStack] -= 1;

    if (*setOfStacks.sizes[setOfStacks.currentStack] == 0 && setOfStacks.currentStack > 0) {
        setOfStacks.currentStack--;
    }

    return value;
}

stack *createNode(void) {
    stack *node = (stack *) malloc(sizeof(stack));
    node->next = STACK_END;

    return node;
}

int main(void) {
    initSet();
    int i = 0;
    return 0;
}
