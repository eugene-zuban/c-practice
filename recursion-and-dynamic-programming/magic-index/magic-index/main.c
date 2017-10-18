//
//  main.c
//  magic-index: find a magic index if exists in a sorted array of unique integers.
//  A magic index in an array A[0..n-1] is an index where A[i] = i
//

#include <stdio.h>
#include <stdlib.h>

// using modified binary search
int getMagicIndex(int arr[], int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;
    if (arr[mid] == mid) {
        return mid;
    }

    if (arr[mid] > mid) {
        return getMagicIndex(arr, left, mid - 1);
    }

    if (arr[mid] < mid) {
        return getMagicIndex(arr, mid + 1, right);
    }

    return -1;
}

int main(void) {
    int arraySize = 0;   
    while (arraySize <= 0) {
        printf("Plese enter the array size: ");
        fscanf(stdin, "%i", &arraySize);
    }

    fprintf(stdout, "Please enter unique array elements in increasing order one element at a time: \n");
    int *array = (int *) malloc(arraySize * sizeof(int));
    for (int i = 0; i < arraySize; i++) {
        fprintf(stdout, "A[%i]: ", i);
        fscanf(stdin, "%i", &array[i]);
    }

    fprintf(stdout, "Magic element index is: %i\n", getMagicIndex(array, 0, arraySize - 1));

    return 0;
}
