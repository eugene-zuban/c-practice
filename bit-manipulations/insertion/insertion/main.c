//
//  main.c
//  insertion: insert bits from 32-bit number M into 32-bit number N into position starts from bit j and ends on bit i.
//  example: N = 100000, M = 000111, j = 3, i = 1, result = 101110
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t insertBits(int32_t original, int32_t bitsToInsert, int fromIndex, int toIndex) {
    if (fromIndex - toIndex <= 0) {
        fprintf(stderr, "toIndex needs to be less than fromIndex\n");
        exit(EXIT_FAILURE);
    }

    // prepare a mask for setting bits from j to i into 0 on the original number
    int32_t mask = 0;
    mask = (1 << fromIndex) - 1; // set bits equals number of bits to insert to 1
    mask = ~(mask << toIndex);
    
    bitsToInsert = bitsToInsert << toIndex; // move bits into their position before inserting into the original number
    original = original & mask;

    return original | bitsToInsert;
}

char *intToBaseString(int32_t number, int base) {
    char *buffer = (char *) malloc(sizeof(char) * 33);
    *(buffer + 32) = '\0';
    int i = 31;

    do {
        *(buffer + i) = "0123456789abcdef"[number % base];
        number = number / base;
        i--;
    } while (number != 0);

    return buffer + i + 1;
}

void insertionBitsTester(int32_t original, int32_t bitsToInsert, int j, int i) {
    char *originalBitString = intToBaseString(original, 2);
    char *bitsToInsertBitString = intToBaseString(bitsToInsert, 2);

    printf("N: %s, M: %s, j: %d, i: %i\n", originalBitString, bitsToInsertBitString, j, i);
}

int main(int argc, const char * argv[]) {
    int32_t original = 0b100000000;
    int32_t bitsToInsert = 0b1101;
    int j = 6, i = 2;
    
    insertionBitsTester(original, bitsToInsert, j, i);
    char *insertedBitsString = intToBaseString(insertBits(original, bitsToInsert, j, i), 2);
    printf("Inserted bits: %s\n", insertedBitsString);

    return 0;
}

