//
//  main.c
//  permutation-without-dups: Compute all the permutations of a given string with unique characters.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define EMPTY_ITEM (stackItem *) 0
#define EMPTY_STACK (stack *) 0

typedef struct stackItem {
    char *string;
    struct stackItem *next;
} stackItem;

typedef struct stack {
    stackItem *head;
} stack;

void memError(void) {
    fprintf(stderr, "Memory alloc error\n");
    exit(EXIT_FAILURE);
}

// permutation related functions
stack *permutations(char *str);

// stack related functions
stack *createStack(void);
stackItem *createStackItem(char *str);
void stackAdd(stack *st, char *str);
char *stackPop(stack *st);

// strings related function
char *substring(char *str, int start, int end);
char *strconcat(char *str1, char *str2);

// create a new linked list stack
stack *createStack() {
    stack *st = (stack *) malloc(sizeof(stack));
    if (st == NULL)
        memError();

    st->head = EMPTY_ITEM;

    return st;
}

// linked list item
stackItem *createStackItem(char *str) {
    stackItem *item = (stackItem *) malloc(sizeof(stackItem));
    if (item == NULL)
        memError();

    item->string = str;
    item->next = EMPTY_ITEM;

    return item;
}

// push str to the stack
void stackAdd(stack *st, char *str) {
    stackItem *item = createStackItem(str);

    item->next = st->head;
    st->head = item;
}

// remove the top item from the stack
char *stackPop(stack *st) {
    if (st->head == EMPTY_ITEM) {
        return (char *) 0;
    }

    char *string = st->head->string;
    stackItem *item = st->head;
    st->head = item->next;
    free(item);

    return string;
}

// return str3 = str1 + str2;
char *strconcat(char *str1, char *str2) {
    int str1Len = (int) strlen(str1);
    int str2Len = (int) strlen(str2);
    int resLen = str1Len + str2Len + 1;

    char *result = (char *) malloc(sizeof(char) * resLen);
    if (result == NULL)
        memError();

    memcpy(result, str1, str1Len);
    memcpy(result + str1Len, str2, str2Len);
    *(result + resLen - 1) = '\0';

    return result;
}

// return substring from str
char *substring(char *str, int start, int end) {
    if (strlen(str) < end) {
        end = (int) strlen(str);
    }

    int subLength = end - start;
    if (subLength < 0) {
        subLength = 0;
    }

    char *substr = (char *) malloc(sizeof(char) * (subLength + 1));
    if (substr == NULL)
        memError();

    memcpy(substr, str + start, subLength);
    *(substr + subLength) = '\0';

    return substr;
}

// compute all the permutations.
// the algorithm's runtime is n! and because it's recursive we need to take care of releasing unused memory.
stack *permutations(char *str) {
    int length = (int) strlen(str);
    stack *result = createStack();

    if (length == 0) { // base case
        char *empty = (char *) malloc(sizeof(char)); // for being able to use free()
        if (empty == NULL)
            memError();
        *empty = '\0';
        stackAdd(result, empty);
        
        return result;
    }

    for (int i = 0; i < length; i++) {
        char *prefix = substring(str, 0, i);
        char *suffix = substring(str, i + 1, length);
        char *partial = strconcat(prefix, suffix);

        stack *partialPermutations = permutations(partial); // compute all the partial's permutations
        while (partialPermutations->head != EMPTY_ITEM) {
            char *part1 = substring(str, i, i + 1);
            char *part2 = stackPop(partialPermutations);
            char *permutation = strconcat(part1, part2); // "build" permutation using previously saved in the stack part
            stackAdd(result, permutation); // save it into the resulting stack

            free(part1);
            free(part2);
        }

        free(prefix);
        free(suffix);
        free(partial);
        free(partialPermutations);
    }

    return result;
}

void printPermutations(stack *st) {
    stackItem *head = st->head;
    int count = 0;
    while(head != EMPTY_ITEM) {
        printf("%s\n", head->string);
        head = head->next;
        count++;
    }

    printf("Total number of permutations is: %i\n", count);
}

int main(int argc, const char * argv[]) {
    if (argc < 2) {
       return 0;
    }

    stack *st = permutations((char *) argv[1]);
    printPermutations(st);

    return 0;
}

