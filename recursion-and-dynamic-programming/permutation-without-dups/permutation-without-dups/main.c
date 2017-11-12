//
//  main.c
//  permutation-without-dups: compute all permutainos of a string if unique characters.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

