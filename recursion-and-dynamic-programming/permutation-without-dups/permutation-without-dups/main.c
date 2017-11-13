//
//  main.c
//  permutation-without-dups: compute all permutainos of a string if unique characters.
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
    if (item == NULL) {
        memError();
    }

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
    if (result == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

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
    if (substr == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    memcpy(substr, str + start, subLength);
    *(substr + subLength) = '\0';

    return substr;
}

stack *permutations(char *str) {
    int length = (int) strlen(str);
    stack *result = createStack();

    if (length == 0) { // base case
        stackAdd(result, "");
        
        return result;
    }

    for (int i = 0; i < length; i++) {
        char *prefix = substring(str, 0, i);
        char *suffix = substring(str, i + 1, length);
        char *partial = strconcat(prefix, suffix);

        stack *partialPermutations = permutations(partial);

        while (partialPermutations->head != EMPTY_ITEM) {
            char *part1 = substring(str, i, i + 1);
            char *part2 = stackPop(partialPermutations);
            char *permutation = strconcat(part1, part2);

            stackAdd(result, permutation);   
            free(part1);
        }

        free(prefix);
        free(suffix);
        free(partial);
        free(partialPermutations);
    }

    return result;
}

void printPermutations(stack *st) {
    while(st->head != EMPTY_ITEM) {
        printf("%s\n", stackPop(st));
    }
}

int main(int argc, const char * argv[]) {
    if (argc < 2) {
       return 0;
    }

    stack *st = permutations((char *) argv[1]);
    printPermutations(st);

    return 0;
}

