#include <stdio.h>

int main (void)
{
		int firstVal, secondVal;

		printf("Please enter two integers for dividing by module: ");
		scanf("%i%i", &firstVal, &secondVal);

		printf("%i %% %i = %i\n", firstVal, secondVal, firstVal % secondVal);

		return 0;	
}
