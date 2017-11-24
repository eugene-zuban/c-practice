//
//  main.c
//  check-balanced: check if a binary tree is is balanced. A balanced tree is defined to be a tree
//  such that the heights of the two subtrees of any node never differ by more than one.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_NODE (node *) 0

typedef struct tree_node {
    int value;
    struct tree_node *left;
    struct tree_node *right;
} node;

node *createNode(int value) {
    node *createNode = (node *) malloc(sizeof(node));
    if (createNode == NULL)
        exit(EXIT_FAILURE);

    createNode->value = value;
    createNode->left = EMPTY_NODE;
    createNode->right = EMPTY_NODE;

    return createNode;
}

int max(int a, int b) {
    return a > b ? a : b;
}

// recursively check each branch, return -1 if branches height diff is more than 1
int getHeight(node *root) {
    if (root == EMPTY_NODE) {
        return 0; // base case
    }

    int leftHeight = getHeight(root->left);
    if (leftHeight == -1) {
        return -1; // unbalanced
    }

    int rightHeight = getHeight(root->right);
    if (rightHeight == -1) {
        return -1; // unbalanced
    }

    int heightDiff = leftHeight - rightHeight;
    if (abs(heightDiff) > 1) {
        return -1; // unbalanced, return -1
    }

    return max(leftHeight, rightHeight) + 1; // compute hight
}

// root is a balanced tree if its height is not -1
bool isBalanced(node *root) {
    return getHeight(root) != -1;
}

int main(int argc, const char * argv[]) {
    // create a tree A
    node *aTree = createNode(1);
    aTree->left = createNode(2);
    aTree->right = createNode(3);
    aTree->left->left = createNode(4);
    aTree->left->right = createNode(5);
    aTree->right->left = createNode(6);
    aTree->right->right = createNode(7);

    // create a tree B
    node *bTree = createNode(1);
    bTree->left = createNode(2);
    bTree->right = createNode(3);
    bTree->right->left = createNode(4);
    bTree->right->right = createNode(5);
    bTree->right->left->left = createNode(6);

    printf("Tree A is: %s\n", isBalanced(aTree) ? "balanced" : "unbalanced");
    printf("Tree B is: %s\n", isBalanced(bTree) ? "balanced" : "unbalanced");

    return 0;
}

