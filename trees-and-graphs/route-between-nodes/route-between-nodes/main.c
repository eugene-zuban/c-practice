//
//  main.c
//  route-between-nodes: check is there is a route between two nodes in a given directed graph
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_NODE (struct node *) 0
#define ADJ_LIST_END (struct adjListNode *) 0

enum statuses {unvisited, visited, visiting};

// vertex node
struct node {
    int nodeId;
    enum statuses status;

    struct node *next; // for supporting queue
    struct adjListNode *adjList; // holding all the edges/adjacencies
};

// A structure for holding adjacencies (edges) of a vertex node
struct adjListNode {
    int destNode;
    struct adjListNode *next;
};

// helper for creating an adjListNode
struct adjListNode *createAdjNode(int destNodeId) {
    struct adjListNode *newNode = (struct adjListNode *) malloc(sizeof(struct adjListNode));
    newNode->destNode = destNodeId;
    newNode->next = ADJ_LIST_END;

    return newNode;
};
 
// A structure to represent a directed graph. A graph is a list (array of adjacency lists)
struct graph {
    int vertices;
    struct node *nodes;
};

// a queue for BFS
struct queue {
    struct node *head;
    struct node *tail;
};

// create a new graph with number of node = vertices and empty adjacency lists
struct graph *createGraph(int vertices) {
    struct graph *newGraph = (struct graph *) malloc(sizeof(struct graph));

    // create all vertices/nodes for the graph
    newGraph->vertices = vertices;
    newGraph->nodes = (struct node *) malloc(vertices * sizeof(struct node));

    for (int i = 0; i < vertices; i++) {
        struct node *nd = newGraph->nodes;

        (newGraph->nodes + i)->nodeId = i;
        (newGraph->nodes + i)->adjList = ADJ_LIST_END; // by default no adjacencies
    }

    return newGraph;
}

// add new edge to the directed graph g
void addEdge(struct graph *g, int srcNodeId, int dstNodeId) {
    struct adjListNode *newNode = createAdjNode(dstNodeId);
 
    // add the edge to the head of node's adjacency list
    newNode->next = g->nodes[srcNodeId].adjList;
    g->nodes[srcNodeId].adjList = newNode;
}

// printing the graph and all its nodes adjacencies
void printGraph(struct graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        struct node *v = (g->nodes + i);
        struct adjListNode *adj = v->adjList;

        printf("Adjacency list of vertex (node) %i:\n", v->nodeId);
        printf("\thead");
        while(adj != ADJ_LIST_END) {
            printf(" -> %i", adj->destNode);
            adj = adj->next;
        }

        printf("\n");
    }
}

// create a new queue for storing graph's nodes during BFS
struct queue *createQueue(void) {
    struct queue *q = malloc(sizeof(struct queue));
    q->head = EMPTY_NODE;
    q->tail = EMPTY_NODE;

    return q;
}

// add a new node to the queue and update tail and head
void queueAdd(struct queue **q, struct node *n) {
    if ((*q)->tail == EMPTY_NODE) {
        (*q)->head = n;
        (*q)->tail = (*q)->head;
    } else {
        (*q)->tail->next = n;
    }

    n->next = EMPTY_NODE;
}

// remove the first node from the queue and move the head
struct node *removeFirstFromQueue(struct queue **q) {
    if ((*q)->head == EMPTY_NODE) {
        return EMPTY_NODE;
    }

    struct node *n = (*q)->head;
    (*q)->head = (*q)->head->next;

    return n;
}

// check if queue is empty
bool isQueueEmpty(struct queue *q) {
    return q->head == EMPTY_NODE;
}

bool searchRoute(struct graph *g, int start, int end) {
    if (start == end) {
        return true;
    }

    // mark all nodes as unvisited
    for (int i = 0; i < g->vertices; i++) {
        (g->nodes + i)->status = unvisited;
    }

    // put the start node into the queue
    struct queue *q = createQueue();
    queueAdd(&q, (g->nodes + start));
    (g->nodes + start)->status = visited;

    return false;
}

int main(void) {
    struct graph *g = createGraph(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
 
    printGraph(g);
 
    return 0;
}
