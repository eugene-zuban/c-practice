//
//  main.c
//  Check if a string has all unique characters by counting how many times each character appears using ASCII codes.
//
//  Created by Jack Zuban on 8/20/17.
//  Copyright © 2017 Jack Zuban. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

bool isUniqueChars(char *str) {
    // create an array for counting chars frequency, and set all the elements in the array to 0
    int frequencyDictionary[127] = {};

    // go through all the characters in the string, counting their frequency
    while(*str) {
        frequencyDictionary[(int) *str]++;
        
        // if more than 1, means that the current character is not unique.
        if (frequencyDictionary[(int) *str] > 1) {
            return false;
        }

        str++;
    }

    return true;
}

int main(void) {
    bool isUniqueChars(char *string);
    char inputString[127] = {};

    printf("Please enter your string: ");
    fgets(inputString, 128, stdin);

    printf("This string with %s\n", isUniqueChars(inputString) ? "unique characters." : "duplicates.");

    return 0;
}
