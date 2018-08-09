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
    int numberOfProjects = 0;
    int numberOfDependencies = 0;

    // enter projects
    while (numberOfProjects <= 0 || numberOfProjects > 20) {
        printf("Enter number of projects [1-20]: ");
        scanf("%n", &numberOfProjects);
    }

    // enter dependencies
    while (numberOfDependencies < 0 || numberOfDependencies > 10) {
        printf("Enter number of the projects dependencies [0-10]: ");
        scanf("%n", &numberOfDependencies);
    }

    return 0;
}
