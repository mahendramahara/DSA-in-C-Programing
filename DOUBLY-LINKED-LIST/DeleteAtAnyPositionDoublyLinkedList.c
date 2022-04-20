#include<stdio.h>
#include<stdlib.h>

void beginsert(int);
void deleteat();
void display();

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head, *temp;

void main()
{
    int choice,item;
    do {
        printf("Enter the item which you want to insert: \n");
        scanf("%d", &item);
        beginsert(item);
        printf("\nPress 0 to insert more: \n");
        scanf("%d", &choice);
    } while(choice==0);

    printf("\n\nItems in the list before deletion are:");
    display();

    deleteat();

    printf("\n\nItems in the list after deletion are:\t");
    display();
}

void beginsert(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\n****************OVERFLOW****************\n");
    }
    else
    {
        ptr->data = item;
        ptr->next = head;
        ptr->prev = NULL;
        if (head != NULL)
            head->prev = ptr;
        head = ptr;
        printf("\n****************Node Inserted****************\n\n");
    }
}

void deleteat()
{
    int pos, i;
    printf("\nEnter the position: \n");
    scanf("%d",&pos);

    if (head == NULL)
    {
        printf("Underflow!\n");
    }
    else
    {
        temp = head;
        for (i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        
        if (temp->next != NULL) // To handle deletion from the end
            temp->next->prev = temp->prev;
        
        if (temp->prev != NULL) // To handle deletion from the beginning
            temp->prev->next = temp->next;
        
        if (temp == head) // If the node to delete is the head
            head = temp->next;

        free(temp);
        printf("\nNode Deleted\n");
    }
}

void display()
{
    printf("\n\nItems in the list are:");
    // Print items in the node
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
}

