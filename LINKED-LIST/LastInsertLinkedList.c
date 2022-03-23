#include<stdio.h> 
#include<stdlib.h> 

void lastInsert(int);
void display();

struct node {
    int data;
    struct node *next;
};

struct node *head;

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

void lastInsert(int item) 
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    
    if (ptr == NULL) {
        printf("\n LinkedList OVERFLOW");
    } else {
        ptr->data = item;
        
        if (head == NULL) {
            ptr->next = NULL;
            head = ptr;
            printf("\n Node inserted ");
        } else {
            temp = head;
            
            while (temp->next != NULL) {
                temp = temp->next;
            }
            
            temp->next = ptr;
            ptr->next = NULL;
            printf("\n Node inserted");
        }
    }
}

void display() {
    struct node *temp = head;
    
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

