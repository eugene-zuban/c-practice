//
//  main.c
//  list-of-depths: create a linked list of all the nodes at each depth from the given binary tree.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_LINKED_LIST (list *) 0
#define EMPTY_TREE_LEAF (tree *) 0
#define EMPTY_LIST_NODE (list_node *) 0
#define EMPTY_Q_ITEM (qItem *) 0

typedef struct list_node {
    struct list_node *next;
    struct tree_node *node;
} list_node;

typedef struct linked_list {
    struct list_node *head;
    struct list_node *tail;
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

// tree related functions
tree *createBinaryTree(int numberOfNodes);
tree *createTreeNode(int nodeId);

// queue related functions
queue *createQueue(void);
void queueAdd(queue *q, tree *treeNode);
bool isQueueEmpty(queue *q);
tree *dequeueTreeNode(queue *q);

// generation list of depth related functions
void addTreeNodeIntoList(list **lists, tree *node, int depth);
void getLists(list **lists, tree *root, int depth);

// check if the queue is empty
bool isQueueEmpty(queue *q) {
    return q->head == EMPTY_Q_ITEM;
}

// return the oldest item from the queue
tree *dequeueTreeNode(queue *q) {
    if (q->head == EMPTY_Q_ITEM) {
        return EMPTY_TREE_LEAF;
    }

    // queue keeps the oldes item on its head
    qItem *item = q->head;
    tree *treeNode = item->treeNode;
    q->head = q->head->next;
    free(item); // we don't need that pointer anymore

    // if the queue is empty, cler the tail
    if (q->head == EMPTY_Q_ITEM) {
        q->tail = EMPTY_Q_ITEM;
    }

    return treeNode;
}

// add a new item to the tail of the queue so the oldest item will always be on its head
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
        return EMPTY_TREE_LEAF;
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

tree *createTreeNode(int nodeId) {
    tree *node = (tree *) malloc(sizeof(tree));
    if (node == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    node->data = nodeId + 1;
    node->left = EMPTY_TREE_LEAF;
    node->right = EMPTY_TREE_LEAF;

    return node;
}

void printLists(list **arrayOfLists, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        list *listOfTreeNodes = arrayOfLists[i];
        
        if (listOfTreeNodes == EMPTY_LINKED_LIST) {
            return;
        }

        list_node *head = listOfTreeNodes->head;
        while (head != EMPTY_LIST_NODE) {
            printf("%i%s", head->node->data, head->next != EMPTY_LIST_NODE ? " -> " : "\n");
            head = head->next;
        }
    }
}

// main function for forming the lists of depths
void getLists(list **lists, tree *root, int depth) {
    if (root == EMPTY_TREE_LEAF) {
        return;
    }

    addTreeNodeIntoList(lists, root, depth); // add the current tree node into its list
    getLists(lists, root->left, depth + 1); // go into the left branch
    getLists(lists, root->right, depth + 1); // go into the right branch
}

// add the node to the lists[depth]
void addTreeNodeIntoList(list **lists, tree *node, int depth) {
    if (lists[depth] == EMPTY_LINKED_LIST) { // create a new list if it doesn't exit
        lists[depth] = (list *) malloc(sizeof(list));
        if (lists[depth] == NULL) {
            fprintf(stderr, "Memory alloc error\n");
            exit(EXIT_FAILURE);
        }
        lists[depth]->head = EMPTY_LIST_NODE;
        lists[depth]->tail = EMPTY_LIST_NODE;
    }   

    // create a new list node for inserting it into the linked list of the nodes for its depth level
    list_node *newItem = (list_node *) malloc(sizeof(list_node));
    if (newItem == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }
    
    newItem->node = node;
    newItem->next = EMPTY_LIST_NODE;

    // insert the node into the linked list keeping tracking the tail
    if (lists[depth]->head == EMPTY_LIST_NODE) {
        lists[depth]->head = newItem;
        lists[depth]->tail = newItem;
    } else {
        lists[depth]->tail->next = newItem;
        lists[depth]->tail = lists[depth]->tail->next;
    }
}

int main(void) {
    // make a binary tree
    int maxElementValue = 0;
    while (maxElementValue <= 0 || maxElementValue > 60) {
        printf("Please enter max leaf value for the binary tree in the range [1..60]: ");
        scanf("%i", &maxElementValue);
    }

    tree *binaryTree = createBinaryTree(maxElementValue);

    // create an array of linked lists for holding all the linked lists for each level of the binary tree
    int maxDepth = 10;
    list **arrayOfLists = (list **) malloc(maxDepth * sizeof(list *));
    for (int i = 0; i < maxDepth; i++) {
        arrayOfLists[i] = EMPTY_LINKED_LIST;
    }

    getLists(arrayOfLists, binaryTree, 0);
    printLists(arrayOfLists, maxDepth);

    return 0;
}

