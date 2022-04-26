#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insert(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;

    printf("\nNode inserted.\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("\nLinked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev == NULL) {
        free(current);
        head = NULL;
        printf("\nLast node deleted.\n");
        return;
    }

    current->prev->next = NULL;
    free(current);

    printf("\nLast node deleted.\n");
}

void display() {
    struct Node* current = head;
    printf("Doubly linked list: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    display();

    deleteFromEnd();
    display();

    return 0;
}

