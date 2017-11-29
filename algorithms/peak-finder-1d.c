#include <stdlib.h>
#include <stdio.h>

#define MAX_INPUT_SIZE 120

struct array_size {
    int *array;
    int size;
};

int getPeakIndex(int *arr, int size, int left, int right) {
    int mid = (left + right) / 2;
    if ((mid - 1) >= 0 && arr[mid] < arr[mid - 1]) {
        return getPeakIndex(arr,size,  left, mid - 1);
    } else if ((mid + 1) < size && arr[mid] < arr[mid + 1]) {
        return getPeakIndex(arr, size, mid + 1, right);
    }

    return mid;
}

struct array_size *getArrayFromInput(void) {
    int *array = (int *) 0;
    char *input = (char *) malloc(sizeof(char) * MAX_INPUT_SIZE);
    if (input == NULL) {
        exit(EXIT_FAILURE);
    }

    printf("Please enter the array using space for separating its elements: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    
    int numberOfElements = 0;
    while(*input) {
        if (*input >= '0' && *input <= '9') {
            array = (int *) realloc(array, sizeof(int) * (numberOfElements + 1));
            array[numberOfElements++] = (int) strtol(input, &input, 10);
        } else {
            input++;
        }
    }

    struct array_size *outputResult = (struct array_size *) malloc(sizeof(struct array_size));
    if (outputResult == NULL) {
        exit(EXIT_FAILURE);
    }

    outputResult->array = array;
    outputResult->size = numberOfElements;

    return outputResult;
}

int main(void) {
    struct array_size *array = getArrayFromInput();

    for (int i = 0; i < array->size; i++) {
        printf("a[%i] => %i\n", i, array->array[i]);
    }

    printf("Peak element index is: %i\n", getPeakIndex(array->array, array->size, 0, array->size - 1));
    
    return 0;
};

