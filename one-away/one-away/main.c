//
//  main.c
//  One Away. Given two strings, check if they are one or none edit away from each other.
//  Allowed type of edits: insert a character, remove a character, replace a character.
//

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool cheakThatOnlyOneReplace(char *str1, char *str2) {
    bool editFlag = false;

    while (*str1) {
        if (*(str1++) != *(str2++)) {
            if (editFlag) { // if true, means that we already have one replase
                return false;
            }

            editFlag = true;
        }
    }

    return true; // no or only one replace
}

bool isOneEditAway(char *str1, char *str2)
{
    bool cheakThatOnlyOneReplace(char *str1, char *str2);
    unsigned long int strLen1, strLen2;

    strLen1 = strlen(str1);
    strLen2 = strlen(str2);

    if (abs(strLen1 - strLen2) > 1) { // more than 2 edits
        return false;
    } else if (strLen1 == strLen2) { // equal length means check for replace only
        return cheakThatOnlyOneReplace(str1, str2);
    }

    return true;
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
