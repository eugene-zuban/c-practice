//
//  main.c
//  recursive-multiply: multiply two numbers without using * or / operators.
//

#include <stdio.h>
#include <stdlib.h>

int absProduct(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }

    if (b == 1) {
        return a;
    }

    return a + absProduct(a, b - 1);
}

int product(int a, int b) {
    int a_abs = a > 0 ? a : (~a) + 1;
    int b_abs = b > 0 ? b : (~b) + 1;
    int abs_res = absProduct(a_abs, b_abs);

    if (a < 0 && b < 0) {
        return abs_res;
    }

    if (a < 0 || b < 0) {
        return (~abs_res) + 1;
    }

    return abs_res;
}

int main(void) {
    int a;
    int b;

    printf("Please enter a and b: ");
    scanf("%i %i", &a, &b);
    printf("a*b = %i\n", product(a, b));

    return 0;
}

