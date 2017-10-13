//
//  main.c
//  route-between-nodes: check is there is a route between two nodes in a given directed graph
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define EMPTY_NODE (struct node *) 0

enum status {unvisited, visited, visiting};

// vertex node
struct node {
    int vertex;
    enum status statuses;
    struct node *next;
};

// adjacency list
struct adjList {
    struct node *head;
};

// A structure to represent a directed graph. A graph is a list (array of adjacency lists)
struct graph {
    int vertices;
    struct adjList *nodes;
};

// create a new node, vertex for graph
struct node *createNode(int vertexId) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->vertex = vertexId;
    newNode->next = EMPTY_NODE;

    return newNode;
};
 
struct graph *createGraph(int vertices) {
    struct graph *newGraph = (struct graph *) malloc(sizeof(struct graph));
    newGraph->vertices = vertices;

    newGraph->nodes = (struct adjList *) calloc(vertices, sizeof(struct adjList));

    for (int i = 0; i < vertices; i++) {
        newGraph->nodes[i].head = EMPTY_NODE;
    }

    return newGraph;
}

void addEdge(struct graph *g, int src, int dst) {
    
}

int main(void) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
