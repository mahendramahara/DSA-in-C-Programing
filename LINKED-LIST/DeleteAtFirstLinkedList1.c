#include<stdio.h>
#include<stdlib.h>

void beginsert(int);
void begdelete();
void display();

struct node
{
    int data;
    struct node *next;
};

struct node *head, *temp;

void main()
{
    int items[] = {10, 20, 30, 40, 50};
    int i;
    int numItems = sizeof(items) / sizeof(items[0]);
    
    for (i = 0; i < numItems; i++)
    {
        beginsert(items[i]);
    }
    
    printf("\n\n Items in the list before deletion are: ");
    display();

    begdelete();

    printf("\n\n Items in the list after deletion are: ");
    display();
}

void beginsert(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n ****************OVERFLOW**************** \n");
    }
    else
    {
        ptr->data = item;
        ptr->next = head;
        head = ptr;
    }
}

void begdelete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n List is empty");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\n Node Deleted From The Beginning....");
    }
}

void display()
{
    for (temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
}

