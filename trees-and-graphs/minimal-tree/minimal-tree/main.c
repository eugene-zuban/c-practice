//
//  main.c
//  minimal-tree: create a minimal binary search tree from a sorted (INC order) array with unique integers.
//

#include <stdio.h>
#include <stdlib.h>

#define EMPTY_NODE (struct node *) 0

struct node {
    int id;
    struct node *left;
    struct node *right;
};

struct node *makeNewNode(int id) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    newNode->id = id;

    return newNode;
}

// recursively make a minimal binary search tree using middle element as a root
struct node *makeMinimalBST(int nodesIds[], int left, int right) {
    if (left > right) {
        return EMPTY_NODE;
    }

    int mid = (left + right) / 2;
    struct node *newNode = makeNewNode(mid);
    newNode->left = makeMinimalBST(nodesIds, left, mid - 1);
    newNode->right = makeMinimalBST(nodesIds, mid + 1, right);

    return newNode;
}

void printTree(struct node *root) {
    if (root != EMPTY_NODE) {
        printf("[%i] ", root->id);
        printTree(root->left);
        printTree(root->right);
        printf("\n");
    }
}

int main(int argc, const char * argv[]) {
    int nodes[] = {1, 2, 3, 4, 5, 6, 7, 8};
    struct node *minimalBst = makeMinimalBST(nodes, 0, 7);
    printTree(minimalBst);

    return 0;
}
