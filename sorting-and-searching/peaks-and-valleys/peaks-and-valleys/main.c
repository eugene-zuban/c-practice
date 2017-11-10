//
//  main.c
//  peaks-and-valleys: sort a given array of integers into an alternating sequence of "peaks" and "valleys".
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void sortPeaksValleys(int *arr, int size);
int getMinElementIndex(int *arr, int size, int a, int b, int c);
void swap(int *arr, int a, int b);

// sorting by taking 3 elements and putting their minimum in the middle. repeat for each even element.
void sortPeaksValleys(int *arr, int size) {
    for (int i = 1; i < size; i += 2) {
        int minElementIndex = getMinElementIndex(arr, size, i, i - 1, i + 1);
        if (i != minElementIndex) {
            swap(arr, i,  minElementIndex);
        }
    }
}

void swap(int *arr, int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

// return index of the minimum value of arr[a], arr[b], arr[c]
int getMinElementIndex(int *arr, int size, int a, int b, int c) {
    int aVal = (a <= size - 1) ? arr[a] : INT_MAX;
    int bVal = (b <= size - 1) ? arr[b] : INT_MAX;
    int cVal = (c <= size - 1) ? arr[c] : INT_MAX;

    int minIndex = aVal < bVal ? a : b;
    minIndex = arr[minIndex] > cVal ? c : minIndex;

    return minIndex;
}

void arrayPrint(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%i ", arr[i]); 
    }

    printf("\n");
}

int main(int argc, const char * argv[]) {
    int arr[] = {1, 4, 2, 0, 5, 5, 2, 7, 8, 9, 65, 44, 1};
    int arraySize = sizeof(arr)/sizeof(int);

    printf("Original: ");
    arrayPrint(arr, arraySize);
    
    printf("Sorted: ");
    sortPeaksValleys(arr, arraySize);
    
    arrayPrint(arr, arraySize);

    return 0;
}
