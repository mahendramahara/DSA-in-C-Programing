#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *head = NULL;

void insert(int item, int loc) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nOVERFLOW");
        return;
    }
    newNode->data = item;

    if (loc == 0) {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    } else {
    	int i;
        struct Node *temp = head;
        for ( i = 0; i < loc - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("\nCan't Insert\n");
            free(newNode);
            return;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next != NULL) {
            newNode->next->prev = newNode;
        }
    }

    printf("\nNode inserted\n");
}

void display() {
    struct Node *ptr = head;
    if (ptr == NULL) {
        printf("Linked List is empty.\n");
    } else {
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

int main() {
    int choice, item, loc;
    do {
        printf("\nEnter the item you want to insert: ");
        scanf("%d", &item);
        printf("Enter the location: ");
        scanf("%d", &loc);
        insert(item, loc);

        printf("\nPress 0 to insert more, or any other key to exit: ");
        scanf("%d", &choice);
    } while (choice == 0);

    printf("\nDisplaying the items in the linked list:\n");
    display();

    return 0;
}

