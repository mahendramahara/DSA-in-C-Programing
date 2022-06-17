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

void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
	int i;
    struct Node* current = head;
    for (i = 1; i < position; ++i) {
        current = current->next;
        if (current == head) {
            printf("Position out of range.\n");
            return;
        }
    }

    if (current == head && head->next == head) {  // Only one node in the list
        free(head);
        head = NULL;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == head) {
            head = current->next;
        }
        free(current);
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
    insertAtLast(922);
    insertAtLast(138);
    insertAtLast(203);

    printf("Before deletion:\n");
    displayList();

    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    deleteFromPosition(position);

    printf("After deletion from position %d:\n", position);
    displayList();

    return 0;
}

