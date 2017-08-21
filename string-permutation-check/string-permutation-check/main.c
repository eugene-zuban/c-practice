//
//  main.c
//  Check if two strings are permutations by checking if they have identical character counts.
//
//  Created by Jack Zuban on 8/20/17.
//  Copyright © 2017 Jack Zuban. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool areStringsHaveSameLength(char *str1, char *str2)
{
    while (*str1 && *str2) {
        str1++;
        str2++;
    }

    return (*str1 == '\0' && *str2 == '\0');
}

bool isPermutation(char *str1, char *str2)
{
    bool areStringsHaveSameLength(char *str1, char *str2);
    int charactersFrequency[127] = {};

    if (! areStringsHaveSameLength(str1, str2)) {
        return false;
    }

    while (*str1) {
        charactersFrequency[(int) *str1]++;
        str1++;
    }

    while (*str2) {
        charactersFrequency[(int) *str2]--;

        if (charactersFrequency[(int) *str2] < 0) {
            return false;
        }

        str2++;
    }

    return true;
}

int main(void) {
    bool isPermutation(char *str1, char *str2);
    char str1[80];
    char str2[80];

    printf("First string: ");
    fgets(str1, 79, stdin);

    printf("Second string: ");
    fgets(str2, 79, stdin);

    printf("Strings are: %s\n", isPermutation(str1, str2) ? "permutations." : "not permutations.");

    return 0;
}
