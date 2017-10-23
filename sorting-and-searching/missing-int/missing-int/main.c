//
//  main.c
//  missing-int: given a file with four billion non-negative integers.
//  Write an algorithm to generate a missing integer from the file using only 1GB of memory.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

unsigned char *createBitVector(long int vectorSize);
long int findMissingInt(long int fileDataEmul[], long int DataSize);

// bit vector for mapping all the integers from the given file
// the bit vector allows to map integers from 0 to 2147483648
unsigned char *createBitVector(long int vectorSize) {
    unsigned char *vector = (unsigned char *) malloc(vectorSize * sizeof(unsigned char));

    // set all values to 0
    for (long int i = 0; i < vectorSize; i++) {
        vector[i] = 0;
    }

    return vector;
}

// finding missing integer using a bit vector with mapping all the integers to their bits on the vector
long int findMissingInt(long int fileDataEmul[], long int dataSize) {
    long int maxIntegers = (long int) INT_MAX + 1;
    long int vectorSize = maxIntegers / 8;
    unsigned char *bitVector = createBitVector(vectorSize);

    // getting each int form the array and set its bit on bitVector
    for (long int i = 0; i < dataSize; i++) {
        long int n = fileDataEmul[i];

        bitVector[n / 8] |= (1 << (n % 8));
    }

    // get integers back from the bitvector and search for a missing one (when its corresponding bit is set to 0)
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
    // emulate a file with integers using an array with integers.
    // Limiting the array size to 200000 just for speed purpose.
    // In a real "life" its size can be up to ~4 billion numbers
    int dataSize = 200000;
    long int *values = (long int *) malloc(dataSize * sizeof(long int));
    for (long int i = 0; i < dataSize; i++) {
        values[i] = i;
    }

    // unset one of the integers
    values[100549] = 0;

    // and find the missing int
    printf("Missing integer is: %li\n", findMissingInt(values, dataSize));

    return 0;
}

