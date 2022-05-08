#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    int i;
    struct Node* current = *head;
    for (i = 1; i < position - 1; ++i) {
        current = current->next;
        if (current == *head) {
            printf("Position out of range.\n");
            free(newNode);
            return;
        }
    }

    newNode->next = current->next;
    current->next = newNode;
}

void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int data, position;

    // Inserting elements
    insertAtPosition(&head, 10, 1);  // 10
    insertAtPosition(&head, 20, 2);  // 10 20
    insertAtPosition(&head, 30, 1);  // 30 10 20
    insertAtPosition(&head, 40, 4);  // 30 10 20 40

    // Printing the list
    printf("Circular Linked List: ");
    printList(head);

    // Getting user input for new insertion
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert at: ");
    scanf("%d", &position);
    
    // Inserting user input at specified position
    insertAtPosition(&head, data, position);
    
    // Printing the updated list
    printf("Updated Circular Linked List: ");
    printList(head);

    return 0;
}

