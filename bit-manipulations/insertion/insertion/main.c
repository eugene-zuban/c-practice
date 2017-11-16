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

    int32_t mask = 0;
    mask = (1 << fromIndex) - 1; // set bits that equal number of bits to insert to 1
    mask = ~(mask << toIndex);
    
    bitsToInsert = bitsToInsert << toIndex; // move bits into their position before inserting into the original number
    original = original & mask;

    return original | bitsToInsert;
}

char *intToBaseString(int32_t number, int base) {
    char baseDigits[17] = "0123456789abcdef";
    char *buffer = (char *) calloc(sizeof(char), 33);
    if (buffer == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    int i = 31;
    do {
        *(buffer + i) = baseDigits[number % base];
        number = number / base;
        i--;
    } while (number != 0);

    return buffer + i + 1;
}

void insertionBitsTester(int32_t original, int32_t bitsToInsert, int from, int to) {
    printf("N: %s, M: %s, j: %d, i: %i\n", intToBaseString(original, 2), intToBaseString(bitsToInsert, 2), from, to);
    
    printf("N: %s \n", intToBaseString(insertBits(original, bitsToInsert, from, to), 2)); 
}

int main(int argc, const char * argv[]) {
    int32_t original = 0b100000000;
    int32_t bitsToInsert = 0b1101;
    int from = 6, to = 2;
    
    printf("Case 1\n");
    insertionBitsTester(original, bitsToInsert, from, to);

    printf("\nCase 2\n");
    insertionBitsTester((int32_t) 0b1100000011, (int32_t) 0b111, 6, 3);

    return 0;
}

