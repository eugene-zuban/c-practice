//
//  main.c
//  Build Order: make a build order from a given list of projects and a list of their interdependencies.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NULL_PROJECT (project *) 0
#define EMPTY_EDGES (project **) 0

enum projectState {VISITING, VISITED, NOT_VISITED};

typedef struct project {
    char name;
    int incomingEdges;
    struct project **edges;
    int numberOfEdges;
    enum projectState state;
} project;

typedef struct graph {
    project **nodes;
    int numberOfNodes;
} graph;

typedef struct {
    struct project *node;
    struct projectsStack *next;
} projectsStack;

void memoryAllocationCheck(void *pointer) {
    if (pointer == NULL) {
        fprintf(stderr, "Memory allocation error.");
        exit(EXIT_FAILURE);
    }
}

/**
 * Returns the project index by its given name.
 */
int getIndex(char name) {
    return name - 'A';
}

/**
 * Creates a new project and set its default values.
 */
project *createProject(char projectName) {
    project *p = (project *) malloc(sizeof(project));
    memoryAllocationCheck(p);
    p->name = projectName;
    p->edges = NULL_PROJECT;
    p->numberOfEdges = 0;
    p->incomingEdges = 0;
    p->state = NOT_VISITED;

    return p;
}

/**
 * Returns a list of projects to build.
 */
graph *initProjectsGraph(int numberOfProjects) {
    // create a graph
    graph *projectGraph = (graph *) malloc(sizeof(graph));
    memoryAllocationCheck(projectGraph);

    // init graph's nodes
    projectGraph->nodes = (project **) malloc(sizeof(project *) * numberOfProjects);
    memoryAllocationCheck(projectGraph->nodes);

    // fill the graph with projects
    for (int i = 0; i < numberOfProjects; i++) {
        projectGraph->nodes[i] = createProject('A' + (i % CHAR_MAX));
        projectGraph->numberOfNodes++;
    }

    return projectGraph;
}

/**
 * Adds a new edge to the graph based on the graphEdge array.
 */
void addEdgeToProjectGraph(graph *projectGraph, const char graphEdge[1]) {
    // get projects from their names
    char dependencyProjectName = graphEdge[0];
    char dependentProjectName = graphEdge[1];
    project *dependency = projectGraph->nodes[getIndex(dependencyProjectName)];
    project *dependent = projectGraph->nodes[getIndex(dependentProjectName)];

    // reallocate memory to fit the new edge
    dependency->edges = (project **) realloc(dependency->edges, (dependency->numberOfEdges + 1) * sizeof(project *));

    // add the edge to dependency and increase the total number of its edges
    dependency->edges[dependency->numberOfEdges] = dependent;
    dependency->numberOfEdges++;

    // increase the number of incoming projects on the dependent project
    dependent->incomingEdges++;
}

/**
 * Returns the adjacency list as a multi dimension array.
 */
char **getFirstDependenciesSet() {
    int rows = 7, cols = 2;
    char **dep = (char **) malloc(sizeof(char *) * rows * cols);
    for (int row = 0; row < 7; row++) {
        dep[row] = (char *) malloc(sizeof(char) * cols);
    }

    dep[0][0] = 'F'; dep[0][1] = 'G';
    dep[1][0] = 'F'; dep[1][1] = 'C';
    dep[2][0] = 'F'; dep[2][1] = 'B';
    dep[3][0] = 'C'; dep[3][1] = 'A';
    dep[4][0] = 'C'; dep[4][1] = 'D';
    dep[5][0] = 'B'; dep[5][1] = 'E';
    dep[6][0] = 'E'; dep[6][1] = 'D';

    return dep;
}

int main(int argc, const char * argv[]) {
    graph *projectsGraph = initProjectsGraph(7);
    // create and test the first project dependencies list size of 7.

    char **dep = getFirstDependenciesSet();
    for (int i = 0; i < 7; i++) {
        addEdgeToProjectGraph(projectsGraph, dep[i]);
    }

    return 0;
}
