#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

uint64_t fact(int n) {
    if (n == 1) {
        return 1;
    }

    if (n == 0) {
        return 0;
    }

    return fact(n - 1) * n;
}

int main(void) {
    int32_t n = 0;
    
    while (true) {
        printf("Please enter n or 999 for exit: ");
        scanf("%i", &n);
        if (n == 999) {
            break;
        }

        printf("(%i!) = %llu\n", n, fact(n));
    }

    exit(EXIT_SUCCESS);
}

