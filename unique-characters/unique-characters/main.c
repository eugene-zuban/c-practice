//
//  main.c
//  Check if a string has all unique characters by counting how many times each character appears using ASCII codes.
//
//  Created by Jack Zuban on 8/20/17.
//  Copyright © 2017 Jack Zuban. All rights reserved.
//

#include <stdio.h>

_Bool isUniqueChars(char *str) {
    int frequencyDictionary[127] = {};

    while(*str) {
        frequencyDictionary[(int) *str]++;

        if (frequencyDictionary[(int) *str] > 1) {
            return 0;
        }

        str++;
    }

    return 1;
}

int main(void) {
    _Bool isUniqueChars(char *string);
    char inputString[127] = {};

    printf("Please enter your string: ");
    fgets(inputString, 128, stdin);

    printf("This string with %s\n", isUniqueChars(inputString) ? "unique characters." : "duplicates.");

    return 0;
}
