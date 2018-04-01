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

node *searchSuccessorInTheLeftNodes(node *nd) {
    while (nd->left != NULL_NODE) {
        nd = nd->left;
    }

    return nd;
}

node *searchSuccessorInTheParents(node *nd) {
    while (nd->parent != NULL_NODE) {
        if (nd->parent->left == nd) {
            return nd->parent;
        }

        nd = nd->parent;
    }

    // if we are here, there is no successor because the given node is the last node on the tree.
    return NULL_NODE;
}

node *getSuccessor(node *nd) {
    // if node has right subtree node, search successor there
    if (nd->right != NULL_NODE) {
        return searchSuccessorInTheLeftNodes(nd->right);
    }

    // if the right node has no subtree, search successor in parents
    return searchSuccessorInTheParents(nd->parent);
}


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
    if (nd == NULL_NODE) {
        printf("NULL_NODE");
        return;
    }

    printf("%i ", nd->key);
}

void clearMemory(node *nd) {
    free(nd);
}

node *buildTestBst() {
    node *root = createNode(NULL_NODE, 20);
    root->left = createNode(root, 10);
    root->right = createNode(root, 40);

    root->left->left = createNode(root->left, 7);
    root->left->right = createNode(root->left, 15);
    root->right->left = createNode(root->right, 30);
    root->right->right = createNode(root->right, 50);

    root->left->left->left = createNode(root->left->left, 2);
    root->left->left->right = createNode(root->left->left, 9);
    root->left->right->left = createNode(root->left->right, 12);
    root->left->right->right = createNode(root->left->right, 18);

    root->right->left->left = createNode(root->right->left, 29);
    root->right->left->right = createNode(root->right->left, 32);
    root->right->right->left = createNode(root->right->right, 42);
    root->right->right->right = createNode(root->right->right, 57);

    return root;
}

int main(int argc, const char * argv[]) {
    // build a test BST tree and test the algorithm
    node *root = buildTestBst();
    printf("Printing a given tree: ");
    doInOrderTraversal(root, printNode);
    printf("\n");

    printf("Successor of 10 is ");
    printNode(getSuccessor(root->left));
    printf("\n");

    printf("Successor of 2 is ");
    printNode(getSuccessor(root->left->left->left));
    printf("\n");

    printf("Successor of 18 is ");
    printNode(getSuccessor(root->left->right->right));
    printf("\n");

    printf("Successor of 50 is ");
    printNode(getSuccessor(root->right->right));
    printf("\n");

    printf("Successor of 57 is ");
    printNode(getSuccessor(root->right->right->right));
    printf("\n");

    // clear the tree
    doInOrderTraversal(root, clearMemory);

    return 0;
}
