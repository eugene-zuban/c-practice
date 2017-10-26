//
//  main.c
//  find-duplicates: find and print all the duplocates in an array from 1..N where N is max 32000
//  Assuming that the N is not known, and only 4K of memory is available
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void findDuplicates(int arr[], int arraySize);
unsigned char *createBitVector(int vectorSize);
bool checkNum(unsigned char *vector, int num);
void markNum(unsigned char *vector, int num);

// create and initialize a bitVector
unsigned char *createBitVector(int sizeInBits) {
    int sizeInBytes = sizeInBits / 8 + 1; // space to hold all the bits in bytes
    unsigned char *vector = (unsigned char *) malloc(sizeInBytes * sizeof(unsigned char *));
    if (vector == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    // fill with 0
    for (int i = 0; i < sizeInBytes; i++) {
        vector[i] = 0;
    }

    return vector;
}


// search duplicates by setting and checking each number from the array using bitvector
void findDuplicates(int arr[], int arraySize) {
    unsigned char *bitVector = createBitVector(arraySize);

    for (int i = 0; i < arraySize; i++) {
        int num = arr[i];
        int num0 = num - 1; // because arr range starts from 1

        if (checkNum(bitVector, num0)) { // if bitVector has a corresponding to num bit, the num is duplicate
            printf("%i ", num);
        } else { // set the bit on the bitVector related to the num
            markNum(bitVector, num0);
        }
    }
}

// check if corresponding to num bit is set on bitvector
bool checkNum(unsigned char *vector, int num) {
    int byteNumber = num >> 3; // div 8
    int mask = 1 << (num & 7); // mod 8

    return (vector[byteNumber] & mask) != 0;
}

// set/mark corresponding to num bit in bitvector
void markNum(unsigned char *vector, int num) {
    int byteNumber = num >> 3; // div 8
    int mask = 1 << (num & 7); // mod 8

    vector[byteNumber] |= mask;
}

int main(void) {
    // initialize a test array
    int arraySize = 32000;
    int array[arraySize];
    for (int i = 0; i < arraySize; i++) {
        array[i] = i + 1;
    }

    // make some duplicates
    array[1] = 1;
    array[4] = 4;
    array[118] = 118;
    array[31900] = 31900;
    array[31999] = 31999;

    // find and print the duplicates
    printf("Print duplicates from the array: ");
    findDuplicates(array, arraySize);

    printf("\n");

    return 0;
}
