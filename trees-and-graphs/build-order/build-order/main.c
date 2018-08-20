//
//  main.c
//  Build Order: make a build order from a given list of projects and a list of their interdependencies.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NULL_PROJECT (project *) 0
#define STACK_END (stackItem *) 0
#define EMPTY_EDGES (project **) 0

#define FIRST_SET_DEP_NUMBER 7
#define SECOND_SET_DEP_NUMBER 7

enum projectState {VISITING, VISITED, NOT_VISITED};

typedef struct project {
    char name;
    struct project **edges;
    int numberOfEdges;
    enum projectState state;
} project;

typedef struct graph {
    project **nodes;
    int numberOfNodes;
} graph;

typedef struct stackItem {
    struct project *node;
    struct stackItem *next;
} stackItem;

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
    p->edges = EMPTY_EDGES;
    p->numberOfEdges = 0;
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
}

/**
 * Projects stack empty checker.
 */
bool isStackEmpty(stackItem *stack) {
    return stack == STACK_END;
}

/**
 * Add a new project to the stack
 */
void pushToStack(stackItem **stack, project *node) {
    stackItem *newItem = (stackItem *) malloc(1 * sizeof(stackItem));
    memoryAllocationCheck(newItem);

    newItem->node = node;
    newItem->next = *stack;

    *stack = newItem;
}

/**
 * Pop the top project from the stack.
 */
project *popFromStack(stackItem **stack) {
    stackItem *top = *stack;
    if (isStackEmpty(top)) {
        return NULL_PROJECT;
    }

    project *node = top->node;
    *stack = top->next;
    free(top);

    return node;
}

/**
 * do DFS on the project and its edges (dependent projects) to find out an order that allow to complete the projects
 * @param node is the project to check
 * @param buildOrder stack represents a correct build order
 * @return true on success and false on a cycle detection
 */
bool projectsDfs(project *node, stackItem **buildOrder) {
    if (node->state == VISITING) {
        return false; // a cycle has been detected
    }

    node->state = VISITING;
    for (int i = 0; i < node->numberOfEdges; ++i) { // go through all the projects that depend on it
        project *dependent = node->edges[i];
        if (dependent->state != VISITED) { // we need to look at not visited projects only
            if (! projectsDfs(dependent, buildOrder)) {
                return false;
            }
        }
    }

    pushToStack(buildOrder, node);
    node->state = VISITED;

    return true;
}

/**
 * Take each project from the projects graph and do DFS on them.
 * DFS allows as to find a possible order to build all the projects satisfying all the dependencies.
 */
stackItem *determineBuildOrder(graph *projects) {
    stackItem *buildOrder = STACK_END;
    for (int i = 0; i < projects->numberOfNodes; ++i) {
        if (projects->nodes[i]->state == NOT_VISITED) {
            if (! projectsDfs(projects->nodes[i], &buildOrder)) {
                return STACK_END; // projects graph has a cycle
            }
        }
    }

    return  buildOrder;
}

void printProjects(graph *projects) {
    printf("Projects list:");

    for (int i = 0; i < projects->numberOfNodes; ++i) {
        printf(" %c", projects->nodes[i]->name);
    }
}

void printDependencyMap(char **array, int size) {
    printf("\nDependency map [dependency, dependent]:");
    for (int i = 0; i < size; ++i) {
        printf(" [%c, %c]", array[i][0], array[i][1]);
    }
}

void printBuildOrder(stackItem *buildOrder) {
    printf("\nItems from the stack: ");
    if (buildOrder == STACK_END) {
        printf("No build order can be build, a cycle has been detected in projects interdependencies.");
    }

    while (! isStackEmpty(buildOrder)) {
        printf("%c ", popFromStack(&buildOrder)->name);
    }
}

/**
 * Adds dependencies to the graph nodes to have a complete graph.
 */
void buildGraph(graph *projects, char **adjacencyArray, int adjacencySize) {
    for (int i = 0; i < adjacencySize; i++) {
        addEdgeToProjectGraph(projects, adjacencyArray[i]);
    }
}

/**
 * Returns the adjacency list as a multi dimension array.
 */
char **getFirstDependenciesSet() {
    int rows = FIRST_SET_DEP_NUMBER, cols = 2;
    char **dep = (char **) malloc(sizeof(char *) * rows * cols);
    for (int row = 0; row < rows; row++) {
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

char **getSecondDependenciesSet() {
    int rows = FIRST_SET_DEP_NUMBER, cols = 2;
    char **dep = (char **) malloc(sizeof(char *) * rows * cols);
    for (int row = 0; row < rows; row++) {
        dep[row] = (char *) malloc(sizeof(char) * cols);
    }

    dep[0][0] = 'A'; dep[0][1] = 'B';
    dep[1][0] = 'A'; dep[1][1] = 'E';
    dep[2][0] = 'B'; dep[2][1] = 'C';
    dep[3][0] = 'C'; dep[3][1] = 'F';
    dep[4][0] = 'C'; dep[4][1] = 'G';
    dep[5][0] = 'D'; dep[5][1] = 'A';
    dep[6][0] = 'E'; dep[6][1] = 'D';

    return dep;
}

void firstTestCaseNoCycle() {
    printf("\nFirst case: projects with no cycle.\n");
    graph *projectsGraph = initProjectsGraph(7);
    char **dep = getFirstDependenciesSet();

    buildGraph(projectsGraph, dep, FIRST_SET_DEP_NUMBER);
    stackItem *buildOrder = determineBuildOrder(projectsGraph);

    printProjects(projectsGraph);
    printDependencyMap(dep, FIRST_SET_DEP_NUMBER);
    printBuildOrder(buildOrder);
}

void secondTestCaseCycle() {
    printf("\n\nSecond case: projects with a cycle.\n");
    graph *projectsGraph = initProjectsGraph(7);
    char **dep = getSecondDependenciesSet();

    buildGraph(projectsGraph, dep, SECOND_SET_DEP_NUMBER);
    stackItem *buildOrder = determineBuildOrder(projectsGraph);

    printProjects(projectsGraph);
    printDependencyMap(dep, SECOND_SET_DEP_NUMBER);
    printBuildOrder(buildOrder);
}

int main(int argc, const char * argv[]) {
    firstTestCaseNoCycle();
    secondTestCaseCycle();

    return 0;
}
