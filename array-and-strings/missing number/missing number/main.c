//
//  main.c
//  Missing number: find a missing number in an array from 0 to n
//  with a constrain that array doesn't provide a constant access time to its elements (we can't do numbers[i]).
//  We can have access only to a number's bit in O(1) time (i.e. a bit from number[i]).
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Look at the least significant bit on number to search which number is missing from the numbers array.
 * Use recursion to seatch all the bits in 32-bit integer numbers.
 **/
int find_missing(int32_t *numbers, int size, int bit_id) {
    if (bit_id >= 32 || size <= 0) { // bse case when no numbers are left or when bit_id is more than int range
        return 0;
    }

    int32_t *ones = (int32_t *) malloc(1 + (sizeof(int32_t) * size / 2));
    int32_t *zeros = (int32_t *) malloc(1 + (sizeof(int32_t) * size / 2));
    if (ones == NULL || zeros == NULL) {
        exit(EXIT_FAILURE);
    }

    int ones_count = 0;
    int zeros_count = 0;
    // split the numbers to 2 arrays: odd and even based on their LSB bit value in bit_id position.
    for (int i = 0; i < size; i++) {
        bool bit = (numbers[i] & (1 << bit_id)) != 0;
        if (bit) { // "even" numbers, numbers with LSB at bit_id position = 1
            ones[ones_count++] = numbers[i];
        } else { // "odd" numbers.
            zeros[zeros_count++] = numbers[i];
        }
    }

    if (ones_count >= zeros_count) { // we are missing a number with the value at bit_id potision of 0
        int missing_bit = find_missing(zeros, zeros_count, bit_id + 1);

        return missing_bit << 1;
    } else { // we are missing a number with the value at bit_id potision of 1
        int missing_bit = find_missing(ones, ones_count, bit_id + 1);

        return (missing_bit << 1) | 1;
    }
}

int32_t *range_with_missing_number(int32_t range_from, int32_t range_to, int32_t number_to_skip) {
    int32_t range_size = range_to - range_from;
    int32_t *range = (int32_t *) malloc(sizeof(int32_t) * range_size);
    if (range == NULL) {
        exit(EXIT_FAILURE);
    }

    for (int32_t i = 0; i <= range_size; i++) {
        if (i < number_to_skip) {
            range[i] = i;
        } else if (i > number_to_skip){
            range[i - 1] = i;
        }
    }

    return range;
}

int main(int argc, const char * argv[]) {
    printf("Expect to find missing 9, found: %i\n", find_missing(range_with_missing_number(0, 10, 9), 9, 0));
    printf("Expect to find missing 99, found: %i\n", find_missing(range_with_missing_number(0, 99999, 99), 99, 0));
    printf("Expect to find missing 112, found: %i\n", find_missing(range_with_missing_number(0, 99999, 112), 112, 0));

    return 0;
}
