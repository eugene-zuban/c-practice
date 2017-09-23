//
//  main.c
//  palindrome: check if a given linked list is a palindrome.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIST_END (node *) 0

typedef struct node {
    char data;
    struct node *next;
} node;

node *makeList();
void printList(node *head);
bool isPalindrome(node *head, node *end, int *length, int *offset);

void printList(node *head) {
    while (head != LIST_END) {
        printf("%c ", head->data);
        head = head->next;
    }

    printf("\n");
}

node *makeList() {
    int nodes = 0;
    node *head = LIST_END, *previous = LIST_END;

    printf("Please enter number of nodes: ");
    scanf("%d", &nodes);

    while ((nodes--) > 0) {
        char value;

        node *item = (node *) malloc(sizeof(node));
        if (item == NULL) {
            printf("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }

        printf("Enter value: ");
        scanf(" %c", &value);

        item->data = value;
        item->next = LIST_END;

        if (head == LIST_END) {
            head = item;
        } else {
            previous->next = item;
        }

        previous = item;
    }

    return head;
}

// comparing elements pairs that have the same distance to the middle of the list
// the list is a palindrome if all the pairs comparisons return true
bool isPalindrome(node *head, node *runner, int *length, int *offset) {
    // we will move the runner till it reaches the end
    runner = runner->next;

    if (runner == LIST_END) { // the end of the list, it doesn't have a pair and we don't need to check it
        return true;
    }

    *length += 1;

    // using recursion for getting to the list end and start checking elements from there
    bool isValid = isPalindrome(head, runner, length, offset);

    if (isValid == false) { // if any of the pairis returns false, the list is not a palindrome
        return false;
    }

    *offset += 1;
    // we need to check only the half of the list
    if (*offset > *length/2) {
        return true;
    }

    // check the pair of elements that have the same distance from/to the middle
    if (head->data != runner->data) {
        return false;
    }

    // move to the next element
    head = head->next;

    return true;
}

int main(void) {
    node *list = makeList();
    printf("Your list: ");
    printList(list);

    int length = 0, offset = 0;
    printf("This is %s\n", isPalindrome(list, list, &length, &offset) ? "a palindrome" : "not a palindrome");
    return 0;
}
