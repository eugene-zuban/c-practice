//
//  main.c
//  group-anagrams: sort an array of strings so that all anagrams are next to each other.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NULL_HASH (struct hash *) 0
#define HASH_SIZE 2069

struct hash {
    char *string;
    struct hash *next;
};

// anagrams-related functionality
void groupAnagrams(char *array[], int arraySize);

void sort(char arr[], int left, int right);
int partition(char arr[], int left, int right);
void copyString(char *from, char *to);

// hash-related functions
struct hash **initHashMapTable(void);
int hashKey(char *s);
void addStringToHash(struct hash ** hashTable, char *s, int key);

// using quick sort for sorting a given string
void sort(char string[], int left, int right) {
    int index = partition(string, left, right);

    if (left < index - 1) {
        sort(string, left, index - 1);
    }

    if (right > index) {
        sort(string, index, right);
    }
}

// quick sort partition
int partition(char string[], int left, int right) {
    int pivot = (int) string[(left + right) / 2]; // take int value of the middle element from the string

    while (left <= right) {
        // find elements on left that need to be on right
        while ((int) string[left] < pivot) {
            left++;
        }

        //find elements on right that need to be on left
        while ((int) string[right] > pivot) {
            right--;
        }

        if (left <= right) {
            char temp = string[left];
            string[left] = string[right];
            string[right] = temp;
            left++;
            right--;
        }
    }

    return left;
}

void copyString(char *from, char *to) {
    while (*from != '\0') {
        *(to++) = *(from++);
    }

    *to = '\0';
}

// create hash table with size HASH_SIZE
struct hash **initHashMapTable(void) {
    struct hash **hashTable = (struct hash **) malloc(HASH_SIZE * sizeof(struct hash *));
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL_HASH;
    }

    return hashTable;
}

// compute hash function assuming that HASH_SIZE is a prime number that helps to avoid collisions
int hashKey(char *s) {
    int key = 0;
    int position = 0;

    // use a character position on the s string for computing string's unique key
    while (*s != '\0') {
        key += (int) *s * (position + 1);
        s++;
        position++;
    }

    return key % HASH_SIZE - 1;
}

// add given string to the headh of the list in the hash table with index = key
void addStringToHash(struct hash **hashTable, char *s, int key) {
    if (key < 0 || key > HASH_SIZE - 1) {
        fprintf(stderr, "Provided hash jey is out of hash table range.");
        exit(EXIT_FAILURE);
    }

    struct hash *newItem = (struct hash *) malloc(sizeof(struct hash));
    if (newItem == NULL) {
        fprintf(stderr, "Memory alloc error\n");
        exit(EXIT_FAILURE);
    }

    newItem->string = s;
    newItem->next = hashTable[key];
    hashTable[key] = newItem;
}

// group next to each other anagrams from the array
void groupAnagrams(char *array[], int arraySize) {
    struct hash **hashMap = initHashMapTable();

    // take each string from the array, sort it,
    // compute hash key from the sorted string and store the original string into hash map using the key
    for (int i = 0; i < arraySize; i++) {
        char *sortedAnagram = (char *) calloc(strlen(array[i]) + 1, sizeof(char));
        copyString(array[i], sortedAnagram);

        sort(sortedAnagram, 0, strlen(sortedAnagram) - 1); // sort the anagram
        int key = hashKey(sortedAnagram); // compute the unique per string variant key
        addStringToHash(hashMap, array[i], key); // strore the original string into the hash map under the key using linked list structure
    }

    // move anagrams from hashMap back to the array
    int strIndex = 0;
    for (int key = 0; key < HASH_SIZE; key++) {
        while(hashMap[key] != NULL_HASH) {
            array[strIndex] = hashMap[key]->string;
            hashMap[key] = hashMap[key]->next;
            strIndex++;
        }
    }
}

// printing array of strings
void printArrayOfStrings(char *array[], int arraySize) {
    printf("Printing the array of size %i:\n", arraySize);
    for (int i = 0; i < arraySize; i++) {
        printf("array[%i]: %s\n", i, array[i]);
    }
}

int main(void) {
    int arraySize = 5;
    char *array[] = {"ab", "cd", "ba", "dc", "abcd"};
    printArrayOfStrings(array, arraySize);   

    // grouping anagrams
    printf("Grouping the anagrams:\n");
    groupAnagrams(array, arraySize);
    printArrayOfStrings(array, arraySize);

    return 0;
}
