//
//  main.c
//  URLfy: replace spaces with '%20' processing given string from the end.
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
    int numberOfSpaces = 0;
    char *newStrPt, *strStartPt;

    strStartPt = origStrPt;

    // count spaces and string length
    for (; *origStrPt != '\0'; origStrPt++) {
        if (*origStrPt == ' ') {
            numberOfSpaces++;
        }
    }

    // set pointer for new string to the end
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
