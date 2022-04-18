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
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;

    printf("\nNode inserted.\n");
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("\nLinked list is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);

    printf("\nNode from the beginning deleted.\n");
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
    insert(30);
    insert(20);
    insert(10);

    display();

    deleteFromBeginning();
    display();

    return 0;
}

