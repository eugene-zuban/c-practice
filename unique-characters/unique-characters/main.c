//
//  main.c
//  unique-characters
//
//  Created by Jack Zuban on 8/20/17.
//  Copyright © 2017 Jack Zuban. All rights reserved.
//

#include <stdio.h>

void printCharacters(char *inputString) {
    int dictinary[30] = {};

    while (*inputString) {
        dictinary[(int) *inputString]++;
        printf("Current character is: %c\n", *inputString);

        inputString++;
    }
}

int main(int argc, const char * argv[]) {
    void printCharacters(char *inputString);
    char inputString[80] = {};

    printf("Please enter your string: ");
    scanf("%s", inputString);

    // build a hash table with caracters
    printCharacters(inputString);

    printf("Your string is: %s\n", inputString);

    return 0;
}
