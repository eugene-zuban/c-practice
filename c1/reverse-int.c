#include <stdio.h>

int main (void)
{
    long long int number, right_digit;

    printf("Enter a number\n");
    scanf("%lli", &number);

    while (number != 0) {
        right_digit = number % 10;
        printf("%lli", right_digit);
        number /= 10;
    }

    printf("\n");

    return 0;
}
