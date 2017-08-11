#include <stdio.h>

int main (void)
{
		int 		intVar = 321;
		float		floatVar = 1.123;
		double	doubleVar = 8.22e+11;
		char		charVar = 'S';

		_Bool		boolVar = 1;

		printf("intVar = %i\n", intVar);
		printf("floatVar = %f\n", floatVar);
		printf("doubleVar = %e\n", doubleVar);
		printf("doubleVar = %g\n", doubleVar);
		printf("charVar = %c\n", charVar);
		printf("boolVar = %i\n", boolVar);

		return 0;
}
