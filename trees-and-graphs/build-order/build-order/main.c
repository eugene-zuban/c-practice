//
//  main.c
//  Build Order: make a build order from a given list of projects and a list of their interdependencies.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NULL_PROJECT (project *) 0

enum projectState {VISITING, VISITED, NOT_VISITED};

typedef struct project {
    char name;
    int incomingEdges;
    struct project **children;
    int numberOfChildren;
    enum projectState state;
} project;

typedef struct {
    struct project *node;
    struct projectsStack *next;
} projectsStack;

int getNameIndex(char projectName) {
    return projectName - 'A';
}

int main(int argc, const char * argv[]) {
    int numberOfProjects = 6;
    int numberOfDependencies = 6;
    char dependencies[6][2];

    project **projectsToBuild = (project **) malloc(sizeof(project *) * numberOfProjects);
    for (int i = 0; i < numberOfProjects; i++) {
        projectsToBuild[i] = (project *) malloc(sizeof(project));
        projectsToBuild[i]->name = 'A' + (i % CHAR_MAX);
        projectsToBuild[i]->incomingEdges = 0;
        projectsToBuild[i]->children = (project **) 0;
        projectsToBuild[i]->numberOfChildren = 0;
        projectsToBuild[i]->state = NOT_VISITED;
    }

    // build adjacency graph
    projectsToBuild[getNameIndex('A')]->state = VISITING;

    return 0;
}
