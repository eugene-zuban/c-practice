//
//  main.c
//  recursive-multiply: multiply two numbers without using * or / operators.
//

#include <stdio.h>
#include <stdlib.h>

int product(int a, int b);
int productHelper(int smaller, int bigger);

// return negative if the number is positive, and return positive is the number is negative
int flipSign(int number) {
    return (~number) + 1;
}

int product(int a, int b) {
    int smaller = a < b ? a : b;
    int bigger = a < b ? b : a;

    // compute product using numbers abolute values
    int product = productHelper(smaller > 0 ? smaller : flipSign(smaller) , bigger > 0 ? bigger : flipSign(bigger));

    // apply (-) sign to the product
    if (smaller < 0) {
        product = flipSign(product);
    }

    // change the sign for the product
    if (bigger < 0) {
        product = flipSign(product);
    }

    return product;
}

// computing the product by summing smaller number halfs using recursive calls
int productHelper(int smaller, int bigger) {
    if (smaller == 0) {
        return 0;
    }

    if (smaller == 1) {
        return bigger;
    }

    int half = smaller >> 1; // smaller / 2
    int halfProduct = productHelper(half, bigger);

    if (smaller % 2 == 0) {
        return halfProduct + halfProduct;
    }

    // if smaller is even, need to add one more bigger
    return halfProduct + halfProduct + bigger;
}

int main(void) {
    int a;
    int b;

    printf("Please enter a and b: ");
    scanf("%i %i", &a, &b);
    printf("a*b = %i\n", product(a, b));

    return 0;
}

