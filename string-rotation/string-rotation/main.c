//
//  main.c
//  string-rotation: check if string s1 is a rotation of s2.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isRotation(char *s1, char *s2) {
    bool isSubstring(char *s1, char *s2);
    void appendString(char *s1, char *s2);

    appendString(s2, s2); // copy s2 into s2

    return isSubstring(s2, s1);
}

bool isSubstring(char *s1, char *s2) {
    return strstr(s1, s2) ? true : false;
}

void appendString(char *s1, char *s2) {
    int s1length = (int) strlen(s1);
    int i = 0;

    while (i++ < s1length && *s2) {
        *(s1++ + s1length) = *s2++;
    }

    *(s1 + s1length) = '\0';
}

int main(void) {
    bool isRotation(char *s1, char *s2);
    char s1[40] = {}, s2[80] = {};

    fputs("Please enter s1 string: ", stdout);
    scanf("%40s", s1);

    fputs("Please enter s2 string: ", stdout);
    scanf("%40s", s2);

    printf("s1 is a rotation of s2: %s\n", isRotation(s1, s2) ? "Yes" : "No");

    return 0;   
}

