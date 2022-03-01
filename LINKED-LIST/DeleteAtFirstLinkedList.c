#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to delete the first node from the linked list
void deleteFromBeginning() {
    if (head == NULL) {
        printf("Linked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted.\n");
}

// Function to display the linked list
void display() {
    struct Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtBeginning(10);

    display();

    deleteFromBeginning();
    display();

    return 0;
}

