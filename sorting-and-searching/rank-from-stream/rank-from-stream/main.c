//
//  main.c
//  rank-from-stream: in a given range of integers (imaginary input stream) find the rank of a number X.
//  Finding the rank of X means to return number of values less than or equal to x (excluding the x itself).
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_NODE (node *) 0

typedef struct node {
    struct node *left;
    struct node *right;
    int data;
    int leftNodesCount;
} node;

node *insert(node *root, int data) {
    if (root == EMPTY_NODE) {
        root = (node *) malloc(sizeof(node));
        if (root == NULL) {
            fprintf(stderr, "Memory alloc error\n");
            exit(EXIT_FAILURE);
        }

        root->left = EMPTY_NODE;
        root->right = EMPTY_NODE;
        root->data = data;
        root->leftNodesCount = 0;

        return root;
    }

    if (data <= root->data) {
        root->leftNodesCount++;
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

int getRank(node *root, int x) {
    int rank = -1;

    if (root == EMPTY_NODE) {
        return rank; // no X found
    }

    if (root->data == x) {
        return root->leftNodesCount;
    }

    if (x < root->data) {
        rank = getRank(root->left, x);
    } else {
        rank = getRank(root->right, x);

        if (rank != -1) {
            rank = rank + root->leftNodesCount + 1;
        }
    }

    return rank;
}

int main(void) {
    int stream[] = {5, 3, 2, 4, 10, 20, 15, 15};
    int x = 0;
    node *root = EMPTY_NODE;

    // make a binary tree and print out the given stream.
    for (int i = 0; i < sizeof(stream) / sizeof(int); i++) {
        root = insert(root, stream[i]); // store the input stream in a binary tree
        printf("%i ", stream[i]);
    }

    printf("\n");

    while (true) {
        printf("Please enter the number for returning its rank, or -999 for exit: ");
        scanf("%i", &x);

        if (x == -999) {
            break;
        }

        printf("The rank for %i is: %i\n", x, getRank(root, x));
    }

    return 0;
}
