//
//  main.c
//  missing-int: given a file with four billin non-negative integers.
//  Write an algorithm to generate a missing integer from the file using only 1GB of memory.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

unsigned char *createBitVector(long int vectorSize);
long int findMissingInt(long int fileDataEmul[], long int DataSize);

unsigned char *createBitVector(long int vectorSize) {
    unsigned char *vector = (unsigned char *) malloc(vectorSize * sizeof(unsigned char));

    // set all values to 0
    for (long int i = 0; i < vectorSize; i++) {
        vector[i] = 0;
    }

    return vector;
}

long int findMissingInt(long int fileDataEmul[], long int dataSize) {
    long int maxIntegers = INT_MAX + (long int) 1;
    long int vectorSize = maxIntegers / 8;
    unsigned char *bitVector = createBitVector(vectorSize);

    // getting each int form the array and set its bit on bitVector
    for (long int i = 0; i < dataSize; i++) {
        long int n = fileDataEmul[i];

        bitVector[n / 8] |= (1 << (n % 8));
    }

    // get integerst back from the bitmask and check if some of them is missing (when its bit is set to 0)
    for (long int i = 0; i < vectorSize; i++) {
        for (int j = 0; j < 8; j++) {
            if ((bitVector[i] & (1 << j)) == 0) {
                return (i * 8 + j);
            }
        }
    }

    return -1;
}

int main(void) {
    int dataSize = 200000;

    // emulate some data
    long int *values = (long int *) malloc(dataSize * sizeof(long int));
    for (long int i = 0; i < dataSize; i++) {
        values[i] = i;
    }   

    // unset one of the integers
    values[65444] = 0;

    printf("Mising integer is: %li\n", findMissingInt(values, dataSize));

    return 0;
}

