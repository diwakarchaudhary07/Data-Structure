#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Insert at beginning
void insert_begin(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Insert at end
void insert_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

// Insert at position
void insert_pos(int pos, int data) {
    if (pos == 0) {
        insert_begin(data);
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    struct Node* temp = head;
    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            printf("Position out of range\n");
            return;
        }
        temp = temp->next;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Delete from beginning
void delete_begin() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

// Delete by value
void delete_value(int key) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Search element
int search(int key) {
    struct Node* temp = head;
    int pos = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            return pos;
        }
        temp = temp->next;
        pos++;
    }

    return -1;
}

// Display list
void display() {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insert_begin(10);
    insert_begin(5);
    insert_end(20);
    insert_pos(1, 15);

    printf("Linked List:\n");
    display();

    printf("Search 15: %d\n", search(15));

    delete_begin();
    delete_end();
    delete_value(15);

    printf("After Deletions:\n");
    display();

    return 0;
}