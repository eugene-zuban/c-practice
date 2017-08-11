#include <stdio.h>

int main (void)
{
		int value1, value2, sum;

		value1 = 10;
		value2 = 20;
		sum = value1 + value2;
		printf ("The sum of %i and %i is %#X\n", value1, value2, sum);

		return 0;
}
