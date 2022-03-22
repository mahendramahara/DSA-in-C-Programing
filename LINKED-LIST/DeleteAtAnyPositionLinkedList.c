#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node at the end of the linked list
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to delete a node from a specific position in the linked list
void deleteFromPosition(int position) {
    if (position < 1 || head == NULL) {
        printf("Invalid position or linked list is empty.\n");
        return;
    }

    if (position == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node at position %d deleted.\n", position);
        return;
    }

    struct Node* current = head;
    struct Node* previous = NULL;
    int currentPosition = 1;

    while (currentPosition < position && current != NULL) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (currentPosition != position) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    previous->next = current->next;
    free(current);
    printf("Node at position %d deleted.\n", position);
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
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    display();

    int position;
    printf("Enter the position of the node to delete: ");
    scanf("%d", &position);

    deleteFromPosition(position);
    display();

    return 0;
}

