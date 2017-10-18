//
//  main.c
//  triple-step: count how many possible ways a child can run up a staircase with n steps
//  jumping 1, 2 or 3 steps at a time.
//

#include <stdio.h>
#include <stdlib.h>

// count the number of ways using memorization in cache array
unsigned long long int countWays(int n, unsigned long long int cache[]) {
    if (n < 0) {
        return 0;
    }

    if (n == 0) {
        return 1;
    }

    if (cache[n] != 0) {
        return cache[n];
    }

    cache[n] = countWays(n - 1, cache) + countWays(n - 2, cache) + countWays(n - 3, cache);

    return cache[n];
}

int main(void) {
    int steps = 0;
    printf("Please enter number of steps: ");
    scanf("%i", &steps);

    unsigned long long int *cache = (unsigned long long int *) calloc(steps + 1, sizeof(unsigned long long int));
    for (int i = 0; i <= steps; i++) {
        cache[i] = 0;
    }

    printf("Number of ways is: %llu\n", countWays(steps, cache));

    return 0;
}
