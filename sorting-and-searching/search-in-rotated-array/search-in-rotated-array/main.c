//
//  main.c
//  search-in-rotated-array: return index of a given element in a sorted array that has been rotated
//  any number of times. Ex: find 2 in {4, 5, 1, 2, 3}. Output 3 (index of 2 in the array).
//

#include <stdio.h>
#include <stdlib.h>

int search(int arr[], int left, int right, int x);

// modified binary search
int search(int arr[], int left, int right, int x) {
    int mid = (left + right) / 2;
    if (arr[mid] == x) {
        return mid;
    }

    if (left > right) {
        return -1;
    }

    if (arr[left] < arr[mid]) { // left side is sorted ok
        if (x >= arr[left] && x < arr[mid]) { // search left
            return search(arr, left, mid - 1, x);
        } else {
            return search(arr, mid + 1, right, x); // search right
        }
    } else if (arr[mid] < arr[left]) { // right side is sorted ok
        if (x > arr[mid] && x <= arr[right]) { // search right
            return search(arr, mid + 1, right, x);
        } else { // search left
            return search(arr, left, mid - 1, x);
        }
    } else if (arr[mid] == arr[left]) { // duplicates in array
        if (arr[mid] != arr[right]) { // if right side is not the same, search it
            return search(arr, mid + 1, right, x);
        } else { // search left
            int result = search(arr, left, mid - 1, x);

            if (result == -1) { // search right if left doesn't have X element
                return search(arr, mid + 1, right, x);
            } else {
                return result; // we have found X, return its index
            }
        }
    }

    return -1; // no X in the array
}

void arrayPrint(int array[], int arraySize) {
    printf("Printing array:\n");
    for (int i = 0; i < arraySize; i++) {
        printf("[%i] => %i\n", i, array[i]);
    }
}

int main(void) {
    printf("Test case 1:\n");
    int x = 5;
    int testArray[] = {4, 5, 6, 7, 1, 2, 3};
    arrayPrint(testArray, sizeof(testArray)/sizeof(int));
    printf("Index of element %i is %i\n", x, search(testArray, 0, sizeof(testArray)/sizeof(int) - 1, x));

    printf("\nTest case 2:\n");
    x = 4;
    int testArray1[] = {3, 3, 3, 4, 5, 3};
    arrayPrint(testArray1, sizeof(testArray1)/sizeof(int));
    printf("Index of element %i is %i\n", x, search(testArray1, 0, sizeof(testArray1)/sizeof(int) - 1, x));

    printf("\nTest case 3:\n");
    x = 10;
    int testArray2[] = {20, 30, 40, 50, 60, 10};
    arrayPrint(testArray2, sizeof(testArray2)/sizeof(int));
    printf("Index of element %i is %i\n", x, search(testArray2, 0, sizeof(testArray2)/sizeof(int) - 1, x));
    
    x = 20;
    printf("Index of element %i is %i\n", x, search(testArray2, 0, sizeof(testArray2)/sizeof(int) - 1, x));
 
    x = 30;
    printf("Index of element %i is %i\n", x, search(testArray2, 0, sizeof(testArray2)/sizeof(int) - 1, x));
    
    return 0;
}
