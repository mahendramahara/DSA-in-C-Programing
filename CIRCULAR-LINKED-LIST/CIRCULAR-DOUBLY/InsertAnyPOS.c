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

void insertAtPosition(int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        head->next = head->prev = newNode;
    } else {
    	int i;
        struct Node* current = head;
        for (i = 1; i < position - 1; ++i) {
            current = current->next;
            if (current == head) {
                printf("Position out of range.\n");
                free(newNode);
                return;
            }
        }

        newNode->prev = current;
        newNode->next = current->next;
        current->next->prev = newNode;
        current->next = newNode;
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
    insertAtPosition(10, 1);
    insertAtPosition(30, 1);
    insertAtPosition(20, 2);

    printf("After initial insertions:\n");
    displayList();

    int position, data;
    printf("\nEnter the position to insert: ");
    scanf("%d", &position);
    printf("Enter the data to insert: ");
    scanf("%d", &data);

    insertAtPosition(data, position);

    printf("\nAfter insertion at position %d:\n", position);
    displayList();

    return 0;
}

