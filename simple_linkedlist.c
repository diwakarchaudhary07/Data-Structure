#include <stdio.h>
#include <stdlib.h>

// Creating node
struct Node {
    int data;
    struct Node* next;
};

int main() {

    // Creating 3 nodes
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // Allocate memory
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // First node
    head->data = 10;
    head->next = second;

    // Second node
    second->data = 20;
    second->next = third;

    // Third node
    third->data = 30;
    third->next = NULL;

    // Traversing linked list
    struct Node* temp = head;

    printf("Linked List Elements:\n");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}