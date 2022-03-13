#include<stdio.h> 
#include<stdlib.h>

void randominsert(int);
void create(int);
void display();
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void main()
{
    int choice, item, loc;
    do
    {
        printf("\n Enter the item which you want to insert? \n");
        scanf("%d", &item);
        if (head == NULL)
        {
            create(item);
        }
        else
        {
            randominsert(item);
        }
        printf("\n Press 0 To insert More? \n");
        scanf("%d", &choice);
    } while (choice == 0);

    printf("\n Displaying the items in the linked list:\n");
    display();
}

void create(int item)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\n Node inserted");
    }
}

void randominsert(int item)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    struct node *temp;
    int i, loc;
    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }
    else
    {
        printf("Enter The location: ");
        scanf("%d", &loc);
        ptr->data = item;
        temp = head;
        for (i = 0; i < loc - 1; i++) // Adjusted loop limit to be loc-1 for proper insertion
        {
            if (temp == NULL)
            {
                printf("\n Can't Insert \n");
                return;
            }
            temp = temp->next;
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\n Node inserted");
    }
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Linked List is empty.\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

