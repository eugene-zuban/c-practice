//
//  main.c
//  add-without-plus: add two numbers without using any arithmetic aperators.
//

#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) {
    while ((a & b) != 0) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        a = sum;
        b = carry;
    }

    return a | b;
}

int main(void) {
    int a = 0, b = 0;

    while (a != 999 || b != 999) {
        printf("\nAdding a + b.For exit enter 999.\n");
        printf("Please enter a: ");
        scanf("%i", &a);
        printf("Please enter b: ");
        scanf("%i", &b);

        printf("a + b = %i\n", add(a, b));
    }

    return 0;
}

