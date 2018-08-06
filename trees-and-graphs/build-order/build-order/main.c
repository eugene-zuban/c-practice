//
//  main.c
//  Build Order: make a build order from a given list of projects and a list of their interdependencies.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

enum projectState {VISITING, VISITED, NOT_VISITED};

typedef struct {
    char name;
    int incomingEdges;
    struct project *children;
    enum projectState state;
} project;

typedef struct {
    struct project *node;
    struct projectsStack *next;
} projectsStack;

projectsStack *buildOrder();
project **projectsToBuild;
char **projectDependencies;

int main(int argc, const char * argv[]) {
    return 0;
}
