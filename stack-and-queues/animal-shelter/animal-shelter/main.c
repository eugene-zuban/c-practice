//
//  main.c
//  animal-shelter: make a FIFO equeue that accepts dogs and cats and returns the "oldest" cat or dog as requested.
//

#include <stdio.h>
#include <stdio.h>
#include <stdbool.h>

#define LIST_END (animalList *) 0

enum animalType {dog, cat};

// structure for handing an animal-related info
typedef struct animalNode {
    char *name;
    enum animalType type;
} animal;

// structure for supporting animals independent queues (cats and dogs) using linked lists
typedef struct animalListNode {
    animal pet;
    int order;
    struct animalListNode *next;
} animalList;

// global shelter queue
struct animalQueueShelter {
    animalList *dogs;
    animalList *cats;
    int order;
} shelter = {LIST_END, LIST_END, 0};

// function declarations
animal peek(animalList *listHead);
animal poll(animalList **listHead);
void add(animalList **listHead, animal petToAdd, int order);

void enqueue(animal animalToAdd); // adds new animal to the shelter
animal dequeueAny(void); // returns the "oldest" dog or cat fromt he shelter
animal dequeueDog(void); // returns the "oldest" dog from the shelter
animal dequeueCat(void); // returns the "oldest" cat from the shelter

int main(void) {

    return 0;
}
