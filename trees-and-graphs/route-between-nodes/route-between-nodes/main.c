//
//  main.c
//  route-between-nodes: check is there is a route between two nodes in a given directed graph
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_NODE (struct node *) 0

enum statuses {unvisited, visited, visiting};

// A graph node (vertex)
struct node {
    int nodeId;
    int edgesCount;
    enum statuses status;

    struct node *next; // for supporting queue
    struct node **children; // holding adjacency nodes
};
 
// A structure to represent a graph
struct graph {
    int vertices;
    struct node *nodes;
};

// queue for supporting BSF search
struct queue {
    struct node *head;
    struct node *tail;
};

// create a new graph with all the nodes
struct graph *createGraph(int vertices) {
    struct graph *newGraph = (struct graph *) malloc(sizeof(struct graph));

    // create all vertices/nodes for the graph
    newGraph->vertices = vertices;
    newGraph->nodes = (struct node *) malloc(vertices * sizeof(struct node));

    // init all the nodes
    for (int i = 0; i < vertices; i++) {
        newGraph->nodes[i].nodeId = i;
        newGraph->nodes[i].edgesCount = 0;
        newGraph->nodes[i].children = (struct node **) malloc(vertices * sizeof(struct node *));
        newGraph->nodes[i].next = EMPTY_NODE; // for supporting queue
    }

    return newGraph;
}

// add new edge to the directed graph g
void addEdge(struct graph *g, int srcNodeId, int dstNodeId) {
    struct node *parentNode = &(g->nodes[srcNodeId]);
    struct node *child = &(g->nodes[dstNodeId]);

    parentNode->children[parentNode->edgesCount] = child;
    parentNode->edgesCount++;
}

// print the graph and all its nodes adjacencies
void printGraph(struct graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        struct node *v = &(g->nodes[i]);

        printf("Adjacency list of vertex (node) %i:\n", v->nodeId);
        printf("\thead");
        for (int i = 0; i < v->edgesCount; i++) {
            printf(" -> %i", v->children[i]->nodeId);
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

    // set tail to EMPTY_NODE in case of empty queue
    if ((*q)->head == EMPTY_NODE) {
        (*q)->tail = EMPTY_NODE;
    }

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
        g->nodes[i].status = unvisited;
    }

    // put the start node into the queue
    struct queue *q = createQueue();
    queueAdd(&q, &(g->nodes[start]));
    g->nodes[start].status = visiting;

    while(! isQueueEmpty(q)) {
        struct node *root = removeFirstFromQueue(&q);
        if (root != EMPTY_NODE) {
            for (int i = 0; i < root->edgesCount; i++) {
                struct node *child = root->children[i];
                if (child->status == unvisited) {
                    if (child->nodeId == end) {
                        return true;
                    }

                    child->status = visiting;
                    queueAdd(&q, child);
                }
            }
        }

        root->status = visited;
    }

    return false;
}

int main(void) {
    struct graph *g = createGraph(6);
    addEdge(g, 0, 3);
    addEdge(g, 1, 3);
    addEdge(g, 3, 5);
    addEdge(g, 2, 4);
    addEdge(g, 4, 5);
 
    printGraph(g);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("Route between node %i and node %i: %s\n", i, j, searchRoute(g, i, j) ? "exists" : "doesn't exist");
        }
    }
 
    return 0;
}
