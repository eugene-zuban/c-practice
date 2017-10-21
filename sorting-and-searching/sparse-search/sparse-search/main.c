//
//  main.c
//  sparse-search: find the index of a given string in an array of sorted strings
//  that is interspersed with empty strings.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isEmpty(char *str);
bool isEqual(char *str1, char *str2);
bool isLess(char *str1, char *str2);

int findString(char *arrWithStrings[], char *stringToFind, int lowIndex, int hightIndex);
// check if str is empty
bool isEmpty(char *str) {
    return *str == '\0';
}

// check if given strings are equal
bool isEqual(char *str1, char *str2) {
    while (*(str1) && *(str2)) {
        if (*(str1++) != *(str2++)) {
            return false;
        }
    }

    return *str1 == *str2;
}

// return true if str1 less than str2
bool isLess(char *str1, char *str2) {
    while (*str1 && str2) {
        if (*str1 != *str2) {
            break;
        }

        str1++;
        str2++;
    }

    return *str1 < *str2;
}

// return the indes of a given str string in the array of strings arr or -1 if string is not there
// using modified binary search
int findString(char *arr[], char *str, int low, int hight) {
    int mid;
    while (low <= hight) {
        mid = (low + hight) / 2;
        if (isEmpty(arr[mid])) { // if arr[mid] points to empty string we need to find next non-emty string
            int left = mid - 1;
            int right = mid + 1;

            do {
                if (left >= low && ! isEmpty(arr[left])) {
                    mid = left;
                } else if (right <= hight && ! isEmpty(arr[right])) {
                    mid = right;
                } else if (left < low && right > hight) {
                    return -1; // no entries of str string
                }

                --left;
                ++right;
            } while(isEmpty(arr[mid]));
        }

        if (isEqual(str, arr[mid])) {
            return mid;
        } else if (isLess(str, arr[mid])) {
            hight = mid -1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main(void) {
    char *arr[11] = {"abc", "", "bcc", "", "", "cda", "cdf", "", "", "", "fdc"};
    
    printf("Array of strings: \n");
    for (int i = 0; i < 11; i++) {
        printf("[%i] => %s\n", i, arr[i]);
    }
    
    printf("Index of %s string in the array is: %i\n", "\"abc\"", findString(arr, "abc", 0, 10));
    printf("Index of %s string in the array is: %i\n", "\"bcc\"", findString(arr, "bcc", 0, 10));
    printf("Index of %s string in the array is: %i\n", "\"cda\"", findString(arr, "cda", 0, 10));
    printf("Index of %s string in the array is: %i\n", "\"cdf\"", findString(arr, "cdf", 0, 10));
    printf("Index of %s string in the array is: %i\n", "\"fdc\"", findString(arr, "fdc", 0, 10));

    return 0;
}
