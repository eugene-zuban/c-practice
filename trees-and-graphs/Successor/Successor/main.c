//
//  main.c
//  Successor: the algorithm for finding the "next" node of a given node in a BST tree.
//

#import <stdlib.h>
#import <stdio.h>

#define NULL_NODE (node *) 0

typedef struct node {
    int32_t key;
    struct node *parent;
    struct node *left;
    struct node *right;
} node;

node *createNode(node *parent, int32_t key) {
    node *newNode = (node *) malloc(sizeof(node));
    if (newNode == NULL) {
        exit(EXIT_FAILURE);
    }

    newNode->parent = parent;
    newNode->key = key;
    newNode->left = NULL_NODE;
    newNode->right = NULL_NODE;

    return newNode;
}

void doInOrderTraversal(node *nd, void (*operation) (node *)) {
    if (nd == NULL_NODE) {
        return;
    }

    doInOrderTraversal(nd->left, operation);
    operation(nd);
    doInOrderTraversal(nd->right, operation);
}

void printNode(node *nd) {
    printf("%i ", nd->key);
}

void clearMemory(node *nd) {
    free(nd);
}

node *getSuccessor(node *nd) {
    if (nd->right != NULL_NODE) {
        nd = nd->right;

        while (nd->left != NULL_NODE) {
            nd = nd->left;
        }

        return nd;
    }

    while (nd->parent != NULL_NODE) {
        if (nd->parent->left == nd) {
            return nd;
        }

        nd = nd->parent;
    }

    return nd;
}

int main(int argc, const char * argv[]) {
    node *root = createNode(NULL_NODE, 40);
    root->left = createNode(root, 30);
    root->right = createNode(root, 50);
    root->left->left = createNode(root->left, 20);

    doInOrderTraversal(root, printNode);
    doInOrderTraversal(root, clearMemory);

    printf("\n");

    return 0;
}
