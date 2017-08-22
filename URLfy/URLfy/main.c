//
//  main.c
//  URLfy: replace spaces with '%20'. Currently the string is processing from the end.
//
//  Created by Jack Zuban on 8/21/17.
//  Copyright © 2017 Jack Zuban. All rights reserved.
//

#include <stdio.h>

void readLine(char *buffer)
{
    do {
        *(buffer++) = getchar();
    } while(*(buffer - 1) != '\n');

    *(--buffer) = '\0';
}

void replaceSpaces(char *origStrPt)
{
    int origStrLen = 0, numberOfSpaces = 0;
    char *newStrPt;

    // count spaces and string length
    while(*origStrPt) {
        if (*origStrPt == ' ') {
            numberOfSpaces++;
        }

        origStrLen++;
        origStrPt++;
    };

    // set pointer for new string at the end
    newStrPt = (--origStrPt) + numberOfSpaces * 2;
    *(newStrPt + 1) = '\0';

    for (int i = origStrLen - 1; i >= 0; i--) {
        if (*origStrPt == ' ') {
            *(newStrPt--) = '0';
            *(newStrPt--) = '2';
            *(newStrPt--) = '%';
        } else {
            *(newStrPt--) = *origStrPt;
        }

        origStrPt--;
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
