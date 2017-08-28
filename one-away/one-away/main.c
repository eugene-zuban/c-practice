//
//  main.c
//  One Away. Given two strings, check if they are one or none edit away from each other.
//  Allowed type of edits: insert a character, remove a character, replace a character.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// go through all the characters and check them till second difference or the end of the string
bool checkThatOnlyOneReplace(char *str1, char *str2) {
    bool diffFlag = false;

    while (*str1 && *str2) {
        if (*(str1++) != *(str2++)) {
            if (diffFlag) { // if true, means that we already have one replace
                return false;
            }

            diffFlag = true;
        }
    }

    return true; // none or only one replace
}

// the logic is almost identical to checkThatOnlyOneReplace() function, and they could be merged into a one function
// but we use a separate function just for illustrative purpose.
// str1 needs to be longer than str2.
bool checkThatOnlyOneInsertOrRemove(char *str1, char *str2)
{
    bool diffFlag = false;

    while (*str1 && *str2) {
        if (*(str1++) != *(str2++)) {
            if (diffFlag) {
                return false;
            }

            diffFlag = true;
            str1++; // move the pointer to the next character only on str1 (it is longer, so we need to "adjust" indexes)
        }
    }

    return true;
}

bool isOneEditAway(char *str1, char *str2)
{
    bool checkThatOnlyOneReplace(char *str1, char *str2);
    bool checkThatOnlyOneInsertOrRemove(char *str1, char *str2);
    unsigned long int strLen1, strLen2;

    strLen1 = strlen(str1);
    strLen2 = strlen(str2);

    if (strLen1 == strLen2) { // equal length means check for replace only
        return checkThatOnlyOneReplace(str1, str2);
    }

    if ((strLen1 - 1) == strLen2) { // first string is longer by 1 character
        return checkThatOnlyOneInsertOrRemove(str1, str2);
    }

    if ((strLen1 + 1) == strLen2) { // second string is longer by one character
        return checkThatOnlyOneInsertOrRemove(str2, str1);
    }

    return false; // strings lengths difference more than 1 character, so they can't be one edit away
}

int main(void) {
    char str1[80] = {}, str2[80] = {};
    bool isOneEditAway(char *str1, char *str2);

    printf("Please enter first string:");
    scanf("%s79", str1);

    printf("Please enter second string:");
    scanf("%s79", str2);

    printf("The strings are one edit away: %s\n", isOneEditAway(str1, str2) ? "true" : "false");

    return 0;
}
