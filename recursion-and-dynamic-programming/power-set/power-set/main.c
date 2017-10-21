//
//  main.c
//  power-set: return all subsets of a set using a binary mask approach for that.
//

#include <stdio.h>
#include <stdlib.h>

#define NULL_SET (struct Set *) 0

struct Set {
    char *items;
    int size;
};

struct Set *getSetFromInt(int position, struct Set *set);
struct Set **getSubset2(struct Set *set);

// using binary mask for building all the subsets
struct Set **getSubsets2(struct Set *set) {
    int numberOfSubsets = 1 << set->size;
    struct Set **allSubsets = (struct Set **) malloc(numberOfSubsets * sizeof(struct Set *) + 1); // +1 for marking end of the subsets
    for (int i = 0; i < numberOfSubsets; i++) {
        struct Set *newSet = getSetFromInt(i, set);

        allSubsets[i] = (struct Set *) malloc(sizeof(struct Set));
        allSubsets[i] = newSet;
    }

    // mark the end
    allSubsets[numberOfSubsets] = NULL_SET;

    return allSubsets;
}

// create a set for a given position number
struct Set *getSetFromInt(int position, struct Set *set) {
    struct Set *subset = (struct Set *) malloc(sizeof(struct Set));
    if (subset == NULL_SET) {
        fprintf(stderr, "Memory alloc error.");
        exit(EXIT_FAILURE);
    }

    subset->size = position;
    subset->items = (char *) calloc(position, sizeof(char));

    int setIndex = 0;
    int subsetIndex = 0;

    for (int i = position; i > 0; i >>= 1) {
        if ((i & 1) == 1) {
            subset->items[subsetIndex] = set->items[setIndex];
            subsetIndex++;
        }      

        setIndex++;
    }

    return subset;
}

int main(void) {
    char *str = "abcd";
    struct Set original = { .items = str, .size = 4};
    struct Set **sets = getSubsets2(&original);

    printf("Printing all subsets of a set: %s ", str);

    int i = 0;
    while (sets[i] != NULL_SET) {
        struct Set *subset = sets[i];
        for (int c = 0; c < subset->size; c++) {
            printf("%c", subset->items[c]);
        }

        i++;
        printf("\n");
    }

    return 0;
}
