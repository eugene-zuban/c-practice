//
//  main.c
//  animal-shelter: make a FIFO queue that accepts dogs and cats and returns the "oldest" cat or dog as requested.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_END (animalList *) 0

enum animalType {dog, cat};

// structure for handling animal-related info
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

//
// Linked list related functions for supporting separate lists for cats and dogs
//
animalList *peek(animalList *listHead);
animal take(animalList **listHead);
void add(animalList **listHead, animal petToAdd, int order);

//
// Queue related functions
//
void enqueue(animal animalToAdd); // add a new animal to the shelter
animal dequeueAny(void); // return the "oldest" dog or cat from the shelter
animal dequeueDog(void); // return the "oldest" dog from the shelter
animal dequeueCat(void); // return the "oldest" cat from the shelter

void testShelter(void); // ahelper for test

// put pet into appropriate animalList linked list
void enqueue(animal pet) {
    shelter.order++;

    // find where we need to add the pet
    animalList **listToAdd;
    if (pet.type == cat) {
        listToAdd = &shelter.cats;
    } else {
        listToAdd = &shelter.dogs;
    }

    add(listToAdd, pet, shelter.order);
}

// return the "oldest" (FIFO) dog from the shelter
animal dequeueDog(void) {
    if (shelter.dogs == LIST_END) {
        fprintf(stderr, "There are no dogs in the shelter.\n");
        exit(EXIT_FAILURE);
    }

    return take(&shelter.dogs);
}

// return the "oldest" (FIFO) cat from the shelter
animal dequeueCat(void) {
    if (shelter.cats == LIST_END) {
        fprintf(stderr, "There are no cats in the shelter.\n");
        exit(EXIT_FAILURE);
    }

    return take(&shelter.cats);
}

// return the oldest cat or dog from the shelter
animal dequeueAny(void) {
    if (shelter.dogs == LIST_END && shelter.cats != LIST_END) {
        return dequeueCat();
    } else if (shelter.cats == LIST_END && shelter.dogs != LIST_END) {
        return dequeueDog();
    }

    if (peek(shelter.dogs)->order < peek(shelter.cats)->order) {
        return dequeueDog();
    }

    return dequeueCat();
}

void add(animalList **list, animal pet, int order) {
    animalList *newItem = (animalList *) malloc(sizeof(animalList));

    if (newItem == NULL) {
        fprintf(stderr, "Malloc error\n");
        exit(EXIT_FAILURE);
    }

    newItem->pet = pet;
    newItem->order = order;
    newItem->next = LIST_END;

    if (*list == LIST_END) {
        *list = newItem;
    } else {
        animalList *item = *list;
        while(item->next != LIST_END) {
            item = item->next;
        }

        item->next = newItem;
    }
}

// return the first (it's the oldest one) animalList node from the list
animalList *peek(animalList *listHead) {
    if (listHead == LIST_END) {
        fprintf(stderr, "List is empty.\n");
        exit(EXIT_FAILURE);
    }

    return listHead;
}

 // take the first pet from the list (it's the oldest one)
animal take(animalList **listHead) {
    animal pet;
    animalList *temp;

    if (*listHead == LIST_END) {
        fprintf(stderr, "List is empty.\n");
        exit(EXIT_FAILURE);
    }

    // take the pet, move the head and free the old list node
    pet = (*listHead)->pet;
    temp = *listHead;
    *listHead = (*listHead)->next;
    free(temp);

    return pet;
}

void testShelter(void) {
    printf("Test shelter queue and all the supporting structires.\n");
    
    animal dogs[10]; 
    animal cats[10];

    for (int i = 0; i < 10; i++) {
        char *dogName = (char *) calloc(20, sizeof(char)), *catName = (char *) calloc(20, sizeof(char));

        sprintf(dogName, "Dog %i", i + 1);
        dogs[i].name = dogName;
        dogs[i].type = dog;

        sprintf(catName, "Cat %i", i + 1);
        cats[i].name = catName;
        cats[i].type = cat;
    }

    for (int i = 0; i < 3; i++) {
        printf("Adding a dog %s to the shelter.\n", dogs[i].name);
        enqueue(dogs[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("Take a dog. Expected: Dog %i, actual %s\n", i + 1, dequeueDog().name);
    }
    
    for (int i = 0; i < 3; i++) {
        printf("Adding a cat %s to the shelter.\n", cats[i].name);
        enqueue(cats[i]);
    }
    for (int i = 0; i < 3; i++) {
        printf("Take a cat. Expected: Cat %i, actual %s\n", i + 1, dequeueCat().name);
    }

    printf("\nAdd all cats and dogs to the shelter:\n");
    for (int i = 0; i < 10; i++) {
        printf("Adding cat %s\n", cats[i].name);
        enqueue(cats[i]);

        printf("Adding dog %s\n", dogs[i].name);
        enqueue(dogs[i]);
    }

    for (int i = 0; i < 10; i++) {
        printf("Take a pet. Expected index: %i, actual name: %s\n", i + 1, dequeueAny().name);
        printf("Take a pet. Expected index: %i, actual name: %s\n", i + 1, dequeueAny().name);
    }   
}

int main(void) {
    testShelter();

    return 0;
}
