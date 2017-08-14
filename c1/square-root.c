#include <stdio.h>

float absoluteValue(float value)
{
    return (value > 0) ? value : -value;
}

float squareRoot(float number)
{
    const   float   epsilon = .00001;
    float           guess = 1.0;

    while (absoluteValue(guess * guess - number) >= epsilon) {
        guess = (number / guess + guess) / 2.0;
    }

    return guess;
}

int main(void)
{
    float inputNumber;
    int counter = 0;

    printf("Enter your number: ");
    scanf("%f", &inputNumber);

    if (inputNumber <= 0) {
        printf("Please enter number > 0\n");

        return -1;
    }

    printf("square root %f = %f\n", inputNumber, squareRoot(inputNumber));

    return 0;
}
