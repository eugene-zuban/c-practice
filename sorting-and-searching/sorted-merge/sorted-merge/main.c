//
//  main.c
//  sorted-merge: given two sorted arrays A and B, where A has enough space at the end to hold B.
//  Merge B into A in sorted order.
//

#include <stdio.h>
#include <stdlib.h>

// merge B into A starting from the end of A and B
void merge(int a[], int b[], int aLength, int bLength) {
    int aIndex = aLength - 1;
    int bIndex = bLength - 1;
    int mergeIndex = aLength + bLength - 1;

    while (bIndex >= 0) { // if bIndex < 0 exit, we don't need to copy A elements because they are already there
        if (aIndex >= 0 && a[aIndex] > b[bIndex]) {
            a[mergeIndex] = a[aIndex];
            aIndex--;
        } else {
            a[mergeIndex] = b[bIndex];
            bIndex--;
        }

        mergeIndex--;
    }
}

void arrayPrint(int a[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        printf("%i ", a[i]);
    }

    printf("\n");
}

int main(void) {
    int a[] = {1, 2, 3, 4, 0, 0}; // the last 2 elements form a buffer in the A for holding B
    int b[] = {5, 6};
    int aSize = sizeof(a)/sizeof(int);
    int bSize = sizeof(b)/sizeof(int);

    printf("array A: ");
    arrayPrint(a, aSize - bSize); // print only A array without the buffer for B
    printf("array B: ");
    arrayPrint(b, bSize);
    
    merge(a, b, aSize - bSize, bSize); // send the size of A without buffer

    printf("array A after merging: ");
    arrayPrint(a, aSize);

    return 0;
}
