//
//  main.c
//  string-rotation: check if one string is a rotation of another.
//
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isRotation(char *s1, char *s2) {
    bool isSubstring(char *s1, char *s2);
    void appendString(char *s1, char *s2);

    appendString(s2, s2); // s2 = s2 + s2

    // if s1 is a substring of s2 + s2, means that s1 is a rotation of s2
    return isSubstring(s2, s1);
}

bool isSubstring(char *haystack, char *needle) {
    return strstr(haystack, needle) ? true : false;
}

void appendString(char *appendTo, char *appendFrom) {
    int offset = (int) strlen(appendTo);
    int i = 0;
    while (i++ < offset && *appendFrom) {
        *(appendTo++ + offset) = *appendFrom++;
    }

    *(appendTo + offset) = '\0';
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

