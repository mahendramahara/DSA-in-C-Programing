#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};
struct node* last = NULL;

void addatlast(int data) {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if (last == NULL) {
        temp->info = data;
        temp->next = temp;
        last = temp;
    } else {
        temp->info = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void deleteAtPosition(int position) {
    if (last == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    if (position <= 0) {
        printf("\nInvalid position.\n");
        return;
    }

    struct node* temp = last->next;
    struct node* previous = NULL;
    int count = 1;

    while (count < position && temp != last) {
        previous = temp;
        temp = temp->next;
        count++;
    }

    if (temp == last && count < position) {
        printf("\nPosition out of range.\n");
        return;
    }

    if (previous == NULL) {
        struct node* temp2 = last->next;
        last->next = temp2->next;
        free(temp2);
        if (last->next == last) {
            free(last);
            last = NULL;
        }
    } else {
        previous->next = temp->next;
        if (temp == last) {
            last = previous;
        }
        free(temp);
    }
}

void viewList() {
    if (last == NULL)
        printf("\nList is empty\n");
    else {
        struct node* temp;
        temp = last->next;
        do {
            printf("\nData = %d", temp->info);
            temp = temp->next;
        } while (temp != last->next);
    }
}

int main() {
    addatlast(10);
    addatlast(20);
    addatlast(30);

    printf("Before Deletion:\n");
    viewList();

    int position;
    printf("\nEnter the position of node to delete: ");
    scanf("%d", &position);
    deleteAtPosition(position);

    printf("\n\nAfter Deletion:\n");
    viewList();

    return 0;
}

