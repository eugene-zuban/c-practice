//
//  main.c
//  One Away. Given two strings, check if they are one or none edit away from each other.
//  Allowed type of edits: insert a character, remove a character, replace a character.
//

#include <stdio.h>
#include <stdbool.h>

// make hash table with string's characters count and return string length
int analyzeString(char *string, int * charactersFrequency)
{
    int length = 0;

    while(*(string + length)) {
        charactersFrequency[*(string + length)]++;

        length++;
    }

    return length;
}

bool doesStringsHaveOneOrLessChanges(char *str1, char *str2)
{
    int analyzeString(char *string, int * charactersFrequency);
    int frequencyStr1[127] = {}, frequencyStr2[127] = {};
    int editsCount = 0, characterChangeRange = 0, strLen1 = 0, strLen2 = 0;

    strLen1 = analyzeString(str1, frequencyStr1);
    strLen2 = analyzeString(str2, frequencyStr2);

    int lengthDiff = strLen1 - strLen2;

    if (lengthDiff < 0) {
        lengthDiff = -lengthDiff;
    }

    if (lengthDiff > 1) {
        return false;
    }

    for (int i = 0; i <= 127; i++) {
        characterChangeRange = frequencyStr1[i] - frequencyStr2[i]; // count difference between similar letters
        if (characterChangeRange < 0) {
            characterChangeRange = -characterChangeRange;
        }

        editsCount += characterChangeRange;

        if (editsCount > 1) {
            return false;
        }
    };

    return true;
}

int main(void) {
    char str1[80] = {}, str2[80] = {};
    bool doesStringsHaveOneOrLessChanges(char *str1, char *str2);

    printf("Please enter first string:");
    scanf("%s79", str1);

    printf("Please enter second string:");
    scanf("%s79", str2);

    printf("The strings have %s edits\n", doesStringsHaveOneOrLessChanges(str1, str2) ? "one or none" : "more than one");

    return 0;
}
