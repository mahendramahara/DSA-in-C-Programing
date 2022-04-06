#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void lastInsert(int data) {
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
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("\nNode inserted.\n");
}

void display() {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("\nLinked List is empty\n");
    } else {
        printf("\nLinked List: ");
        
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        
        printf("\n");
    }
}

int main() 
{
    int choice, item;
    
    do {
        printf("\nEnter the item you want to insert: ");
        scanf("%d", &item);
        lastInsert(item);
        
        printf("\nPress 0 to insert more, or any other key to exit: ");
        scanf("%d", &choice);
    } while (choice == 0);
    
    // Display the linked list
    display();

    return 0;
}

