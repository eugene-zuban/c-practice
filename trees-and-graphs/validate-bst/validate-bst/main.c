//
//  main.c
//  validate-bst: check if a given binary tree is a binary search tree.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_NODE (node *) 0

typedef struct tree_node {
    int32_t value;
    struct tree_node *left;
    struct tree_node *right;
} node;

node *createNode(int32_t value) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->value = value;
    newNode->left = EMPTY_NODE;
    newNode->right = EMPTY_NODE;

    return newNode;
}

bool isBinarySearchTree(node *root, int32_t min, int32_t max) {
    if (root == EMPTY_NODE) {
        return true;
    }

    if (root->value <= min || root->value > max) {
        return false;
    }

    bool isLeftBst = isBinarySearchTree(root->left, min, root->value);
    bool isRightBst = isBinarySearchTree(root->right, root->value, max);

    return isLeftBst && isRightBst;
}

int main(int argc, const char * argv[]) {
    // create a BST tree
    node *aTree = createNode(20);
    aTree->left = createNode(10);
    aTree->right = createNode(30);
    aTree->right->left = createNode(29);
    aTree->right->right = createNode(40);
    aTree->left->left = createNode(5);
    aTree->left->right = createNode(15);
    printf("aTree is a BST: %s\n", isBinarySearchTree(aTree, INT32_MIN, INT32_MAX) ? "true" : "false");

    // create a non BST tree by adding an "incorrect" value into its leaf.
    node *bTree = aTree;
    bTree->left->right->value = 4; // violate the BST definition
    printf("bTree is a BST: %s\n", isBinarySearchTree(bTree, INT32_MIN, INT32_MAX) ? "true" : "false");

    return 0;
}

