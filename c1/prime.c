#include <stdio.h>
#include <stdbool.h>

int main (void)
{
    int p, d;
    bool isPrime;

    for (p = 2; p <= 50; ++p) {
        isPrime = true;
        
        for (d = 2; d < p; ++d) {
            if (p % d == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            printf("%i ", p);
        }
    }
    
    printf("\n");
    return 0;
}
