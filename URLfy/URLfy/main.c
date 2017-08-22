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

void replaceSpaces(char dataString[])
{
    int origStrLen = 0, newStrLen = 0, numberOfSpaces = 0;

    for (origStrLen = 0; dataString[origStrLen] != '\0'; origStrLen++) {
        if (dataString[origStrLen] == ' ') {
            numberOfSpaces++;
        }
    }

    newStrLen = origStrLen + numberOfSpaces * 2;
    dataString[newStrLen] = '\0';

    for (int i = origStrLen - 1; i >= 0; i--) {
        if (dataString[i] == ' ') {
            dataString[--newStrLen] = '0';
            dataString[--newStrLen] = '2';
            dataString[--newStrLen] = '%';

        } else {
            dataString[--newStrLen] = dataString[i];
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
