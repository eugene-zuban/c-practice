#include <stdio.h>

int main (void)
{
		int n, number, triangularNumber = 0;

		printf("What triangular number do you want? ");
		scanf("%i", &number);

		for ( n = 1; n <= number; ++n ) {
				triangularNumber += n;
		}

		printf("triangular number %i is %i\n", number, triangularNumber);

		return 0;
}
