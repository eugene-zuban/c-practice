//
//  main.c
//  permutation-without-dups: compute all permutainos of a string if unique characters.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct permItem {
    char *string;
    struct permItem *next;
} stack;

stack *permutations(char *str);
char *substring(char *str, int start, int end);
char *strcontat(char *str1, char *str2);

// return str3 = str1 + str2;
char *strconcat(char *str1, char *str2) {
    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
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

char *substring(char *str, int start, int end) {
    if (strlen(str) < end || end == 0) {
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

int main(int argc, const char * argv[]) {

    return 0;
}

