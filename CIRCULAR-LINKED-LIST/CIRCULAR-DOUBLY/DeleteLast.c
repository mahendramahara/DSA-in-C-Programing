#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insertAtLast(int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head->prev = newNode;
    } else {
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev->next = newNode;
        head->prev = newNode;
    }
}

void deleteFromLast() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {  // Only one node in the list
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head->prev;
        head->prev = temp->prev;
        temp->prev->next = head;
        free(temp);
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    insertAtLast(100);
    insertAtLast(200);
    insertAtLast(300);

    printf("Before deletion:\n");
    displayList();

    deleteFromLast();

    printf("After deletion from last:\n");
    displayList();

    return 0;
}
