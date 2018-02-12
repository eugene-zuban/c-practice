//
//  main.c
//  URLfy: replace all the spaces in a given string with '%20'.
//  Assuming the string has enough space to handle all the additional characters.
//

#include <stdio.h>

void readLine(char *buffer)
{
    do {
        *(buffer++) = getchar();
    } while(*(buffer - 1) != '\n');

    *(--buffer) = '\0';
}

// Replace all the spaces starting from the end of the string
void replaceSpaces(char *origStrPt)
{
    int numberOfSpaces = 0;
    char *newStrPt, *strStartPt;

    strStartPt = origStrPt;

    // count spaces and string length
    for (; *origStrPt != '\0'; origStrPt++) {
        if (*origStrPt == ' ') {
            numberOfSpaces++;
        }
    }

    // set pointer of the new string to the end
    newStrPt = (--origStrPt) + numberOfSpaces * 2;

    // copy values from the end using original and new strings pointers diff as a buffer for inserint extra characters
    for (; origStrPt >= strStartPt; origStrPt--) {
        if (*origStrPt == ' ') {
            *(newStrPt--) = '0';
            *(newStrPt--) = '2';
            *(newStrPt--) = '%';
        } else {
            *(newStrPt--) = *origStrPt;
        }
    }
}

int main(int argc, const char * argv[]) {
    void readLine(char *dataString);
    void replaceSpaces(char *dataString);

    char dataString[150] = {};

    printf("Please enter your string: ");
    readLine(dataString);

    replaceSpaces(dataString);
    printf("Resulting string is %s\n", dataString);

    return 0;
}
