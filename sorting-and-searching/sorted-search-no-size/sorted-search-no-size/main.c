//
//  main.c
//  sorted-search-no-size: given a list structure that holds only positive int elements in a sorted order.
//  The structure can't provide the number of its elements, but it provides getElementAt(i) method
//  that returns the element at index i in O(1) time. If i is out of the range, the method returns -1.
//  Find the index at which given element X occurs in the structure or -1 if it doesn't exist.
//

#include <stdio.h>
#include <stdlib.h>

// array-like data structure for storing int elements
struct Listy {
    int *data;
    int maxIndex;
};

int findIndex(struct Listy *list, int val);
int binarySearch(struct Listy *list, int val, int low, int hight);
int getElementAt(struct Listy *list, int index);

struct Listy *createListy(void);

// return the element at index "index" if it exists, or return -1 if the index is out of range
int getElementAt(struct Listy *list, int index) {
    if (index < 0 || index > list->maxIndex) {
        return -1;
    }

    return list->data[index];
}

// first, find the range where X exist in the structure, and after that use binarySearch for searching its index
int findIndex(struct Listy *list, int x) {
    int index = 1;
    while (getElementAt(list, index) && getElementAt(list, index) < x) {
        index *= 2; // double the index every time for running out of the list range
    }

    // now use binarySearch within index/2 and index range for getting index of X
    return binarySearch(list, x, index / 2, index);
}

// binary search implementation with checking out-of range status
int binarySearch(struct Listy *list, int x, int low, int hight) {
    int mid, midValue;

    while (low <= hight) {
        mid = (low + hight) / 2;
        midValue = getElementAt(list, mid);

        if (midValue > x || midValue == -1) { // additional out of range check since getElementAt() returns -1 when index is out of range
            hight = mid - 1; // search left
        } else if (midValue < x) {
            low = mid + 1; // search right
        } else {
            return mid; // found
        }
    }

    return -1; // x is not on the list
}

// create a new data structure for test
struct Listy *createListy(void) {
    int elements = 0;
    struct Listy *list = (struct Listy *) malloc(sizeof(struct Listy));
    if (list == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    while (elements <= 0) {
        fprintf(stdout, "Please enter number of elements in Listy: ");
        fscanf(stdin, "%i", &elements);
        if (elements <= 0) {
            fprintf(stdout, "The number must be positive and more than 0\n");
        }
    }   

    list->data = (int *) malloc(elements * sizeof(int));
    list->maxIndex = elements - 1;
    for (int i = 0; i < elements; i++) {
        list->data[i] = i;
    }

    return list;
}

// print structure
void printListy(struct Listy *list) {
    printf("Listy's data-aray:\n");
    for (int i = 0; i <= list->maxIndex; i++) {
        printf("[%i] => %i\n", i, list->data[i]);
    }
}

int main(void) {
    struct Listy *list = createListy();
    printListy(list);
    
    int search = 0;
    fprintf(stdout, "Please enter element for searh: ");
    fscanf(stdin, "%i", &search);
    fprintf(stdout, "Element %i has index %i in a given Listy structure\n", search, findIndex(list, search));
    
    return 0;
}
