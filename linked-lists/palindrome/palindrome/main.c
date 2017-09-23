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
bool isPalindrome(node *head, node *end, int length, int offset);

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



int main(void) {
    node *list = makeList();
    printf("Your list: ");
    printList(list);

    return 0;
}
