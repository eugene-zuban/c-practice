//
//  main.c
//  palindrome-permutation
//  Check if a given string is a permutation of a palidrome.
//
//

#include <stdio.h>
#include <stdbool.h>

void removeSpaces(char *originalString)
{
    char *withoutSpaces;

    withoutSpaces = originalString; // set pointer to the start of originalString

    while(*originalString && *originalString != '\n') {
        if (*originalString != ' ') {
            *(withoutSpaces++) = *originalString;
        }

        originalString++;
    }

    *withoutSpaces = '\0'; // we need to "close" the string properly because both pointers poin to the same string in the memory
}

int countStrLength(char *string)
{
    int length = 0;

    while (*string++) {
        length++;
    }

    return length;
}

bool isPalindromePermutation(char *string)
{
    int countStrLength(char *string);

    // if length is odd, it's not a palindrome
    if (countStrLength(string) % 2 == 0) {
        return false;
    }

    // count characters states

    return true;
}

int main(int argc, const char * argv[]) {
    void removeSpaces(char * str1);
    bool isPalindromePermutation(char *stringForCheck);

    char providedString[80] = {};

    printf("Please enter your string: ");
    fgets(providedString, 80, stdin);

    removeSpaces(providedString);

    printf("The string is %s a permutation of a palindrome\n", isPalindromePermutation(providedString) ? "" : "not");

    return 0;
}
