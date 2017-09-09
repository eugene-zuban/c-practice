//
//  main.c
//  string-compression: compress a given string using the counts of repeated characters.
//

#include <stdio.h>
#include <string.h>

// store compressed string using out pointer
void compress(char *in, char *out) {
    char currentChar;
    int counter;

    while (*in) {
        counter = 1;
        currentChar = *in;

        while (currentChar == *(++in)) {
            counter++;
        }

        *out++ = currentChar;
        *out++ = counter + '0'; // assuming that counter <= 9 for simplicity
    }

    *out = '\0';
}

int main(void) {
    void compress(char *in, char *out);
    char originalString[80] = {}, compressedString[80] = {};

    printf("Please enter your string for compression: ");
    scanf("%s79", originalString);

    compress(originalString, compressedString);

    // return compressed string if its length less than original
    printf("Compressed string: %s\n", strlen(compressedString) < strlen(originalString) ? compressedString : originalString);
    return 0;
}
