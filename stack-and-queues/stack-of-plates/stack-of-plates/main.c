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
} set = {0, STACK_SIZE, NUMBER_OF_STACKS};

void initSet(void);
void testSet(void);
stack *createNode(void);
int currentStackId(void);
int pop(void);
int peek(void);
void push(int value);
bool isEmpty(void);

// initialize setOfStacks
void initSet(void) {
    for (int i = 0; i < set.numberOfStacks; i++) {
        set.sizes[i] = (int *) calloc(1, sizeof(int)); // the i-stack counter
        set.stacks[i] = STACK_END; // create pointers for each of stacks in the set
    }
}

int currentStackId() {
    return set.currentStack;
};

// if the first stack is empty, all the set is empty
bool isEmpty() {
    return set.stacks[0] == STACK_END;
}

// return value of the current top item
int peek() {
    if (isEmpty()) {
        return EMPTY_STACK;
    }

    return set.stacks[currentStackId()]->value;
}

// push value into a stack that can accept it (current or the next one)
void push(int value) {
    // check if the current stack is full
    if (*set.sizes[currentStackId()] == STACK_SIZE) {
        if (currentStackId() - 1 == NUMBER_OF_STACKS) { // do nothing if all stacks are full
            return;
        }

        set.currentStack++; // move to the next stack in the set
    }

    // create a new node and add it to the current top
    stack *newNode = createNode();
    newNode->value = value;
    newNode->next = set.stacks[currentStackId()];
    set.stacks[currentStackId()] = newNode;

    *set.sizes[currentStackId()] += 1;
}

// pop the top node from the set of stacks
int pop(void) {
    if (isEmpty()) {
        return EMPTY_STACK;
    }

    stack *top = set.stacks[currentStackId()]; // get the current top
    int value = top->value; // store its value
    set.stacks[currentStackId()] = top->next; // move the stack top
    free(top); // free the old top memory

    // decrease the current stack size and move to the previous stack if case if the current is empty
    *set.sizes[currentStackId()] -= 1;
    if (*set.sizes[currentStackId()] == 0 && currentStackId() > 0) {
        set.currentStack--;
    }

    return value;
}

// helper function for creating a new stack element
stack *createNode(void) {
    stack *node = (stack *) malloc(sizeof(stack));
    node->next = STACK_END;

    return node;
}

int main(void) {
    initSet();
    testSet();

    return 0;
}

void testSet(void) {
    // tests
    printf("After initialization: current stack set is %s, current stack is %i, current stack size is %i\n", isEmpty() ? "empty" : "not empty", currentStackId(), *set.sizes[currentStackId()]);
    push(1); // {1->END}
    printf("push(1): Expected: 1, actual: %i\n", peek());
    push(2); // {2->1->END}
    printf("push(2): Expected: 2, actual: %i\n", peek());
    push(3); // {3->2->1->END}
    printf("push(3): Expected: 3, actual: %i\n", peek());

    //pop values()
    printf("pop() test. Expected: 3, actual: %i\n", pop()); // {2->1->END}
    printf("pop() test. Expected: 2, actual: %i\n", pop()); // {1->END}
    printf("pop() test. Expected: 1, actual: %i\n", pop()); // {END}

    // needs to be empty
    printf("The set is empty: %s", isEmpty() ? "true" : "false");

    // fill all the stacks with values 1-25
    for(int i = 1; i < 26; i++) {
        push(i);
    }

    printf("Efter pushing 25 values. The current set of stacks is %s, ", isEmpty() ? "empty" : "full");
    printf("current stack id is: %i, and the current stack size is: %i\n", currentStackId(), *set.sizes[currentStackId()]);

    // pop all the values
    int value;
    fputs("pop() till the end: ", stdout);
    do {
        value = pop();
        printf("%i ", value);
    } while(value != EMPTY_STACK);
    putc('\n', stdout);
}
