//
//  main.c
//  list-of-depth: create a linked list of all the nodes of a specified depth from a given binary try.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_END (list *) 0
#define EMPTY_LEAF (tree *) 0
#define EMPTY_Q_ITEM (qItem *) 0

typedef struct list_node {
    struct list_node *next;
    struct tree_node *node;
} list;

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree;

typedef struct queue_item {
    tree * treeNode;
    struct queue_item *next;
} qItem;

typedef struct queue_queue {
    qItem *head;
    qItem *tail;
} queue;

tree *createBinarytree(int numberOfNodes);
tree *createTreeNode(int nodeId);
queue *createQueue(void);
void queueAdd(queue *q, tree *treeNode);
bool isQueueEmpty(queue *q);
tree *dequeueTreeNode(queue *q);
list *getListFromDepth(tree *root, int currentDepth, int requestedDepth);

// check if the queue is empty
bool isQueueEmpty(queue *q) {
    return q->head == EMPTY_Q_ITEM;
}

// return the oldest treeNode from the queue
tree *dequeueTreeNode(queue *q) {
    if (q->head == EMPTY_Q_ITEM) {
        return EMPTY_LEAF;
    }

    // the queue keeps the oldes item on its head
    qItem *item = q->head;
    tree *treeNode = item->treeNode;
    q->head = q->head->next;
    free(item);

    if (q->head == EMPTY_Q_ITEM) {
        q->tail = EMPTY_Q_ITEM;
    }

    return treeNode;
}

// add new item to the tail of the queue so the oldest item will always be on its head
void queueAdd(queue *q, tree *treeNode) {
    qItem *item = (qItem *) malloc(sizeof(qItem));
    if (item == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    item->treeNode = treeNode;
    item->next = EMPTY_Q_ITEM;

    if (q->head == EMPTY_Q_ITEM) {
        q->tail = item;
        q->head = item;        
    } else {
        q->tail->next = item;
        q->tail = item;
    }
}

// create empty queue
queue *createQueue(void) {
    queue *q = (queue *) malloc(sizeof(queue));
    if (q == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    q->head = EMPTY_Q_ITEM;
    q->tail = EMPTY_Q_ITEM;

    return q;
}

// create a simple binary tree with a given number of nodes using DFS approach
tree *createBinaryTree(int numberOfNodes) {
    if (numberOfNodes <= 0) {
        return EMPTY_LEAF;
    }

    int currentNodeId = 0;
    tree *root = createTreeNode(currentNodeId);
    queue *q = createQueue();
    queueAdd(q, root);

    while(! isQueueEmpty(q) && currentNodeId < numberOfNodes) {
        tree *parent = dequeueTreeNode(q);

        int currentChildId = 2;
        while (currentChildId > 0 && currentNodeId < numberOfNodes) {
            tree *child = createTreeNode(++currentNodeId);
            if (currentChildId % 2 == 0) {
                parent->left = child;
            } else {
                parent->right = child;
            }

            currentChildId--;
            queueAdd(q, child);
        }
    }

    return root;
}

// create a new tree node
tree *createTreeNode(int nodeId) {
    tree *node = (tree *) malloc(sizeof(tree));
    if (node == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    node->data = nodeId + 1;
    node->left = EMPTY_LEAF;
    node->right = EMPTY_LEAF;

    return node;
}

// create a linked list for a given depth
list *getListFromDepth(tree *root, int currentDepth, int requestedDepth) {
    if (currentDepth == requestedDepth) {
        list *item = (list *) malloc(sizeof(list));
        if (item == NULL) {
            fprintf(stderr, "Memory alloc error\n");
            exit(EXIT_FAILURE);
        }

        item->node = root;
        item->next = LIST_END;

        return item;
    }

    if (root != EMPTY_LEAF) {
        currentDepth++;
        list *nodeLeft = getListFromDepth(root->left, currentDepth, requestedDepth);
        list *nodeRight = getListFromDepth(root->right, currentDepth, requestedDepth);

        if (nodeLeft != LIST_END && nodeRight != LIST_END) {
            list *leftTail  = nodeLeft;
            while (leftTail->next != LIST_END) {
                leftTail = leftTail->next;
            }

            leftTail->next = nodeRight;
            
            return nodeLeft;
        } else if (nodeLeft != LIST_END) {
            return nodeLeft;
        }

        return nodeRight;
    }

    return LIST_END;
}

void printList(list *head) {
    while (head != LIST_END) {
        printf("%i%s", head->node->data, head->next != LIST_END ? " -> " : "\n");
        head = head->next;
    }
}

int main(void) {
    // make a binary tree
    tree *binaryTree = createBinaryTree(16);
    int requestedDepth = 0;

    while (requestedDepth != -1) {
        printf("Please enter depth for printing its nodes or -1 for exit: ");
        scanf("%i", &requestedDepth);
   
        printf("List from depth %i:\n", requestedDepth);
        printList(getListFromDepth(binaryTree, 1, requestedDepth));
    }
   
    return 0;
}
