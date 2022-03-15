#include<stdio.h>
#include<stdlib.h>
void beginsert(int);
struct node
{
	int data;
	struct node *next;
};
struct node *head, *temp;
void main()
{
	int choice,item;
	do{
		printf("Enter the item which you want to insert: \n");
		scanf("%d", &item);
		beginsert(item);
		printf("\nPress 0 to insert more: \n");
		scanf("%d", &choice);
	}while(choice==0);
	printf("\n\nItems in the list are:");
    //Print items in the node
    for (temp = head ; temp!=NULL ; temp=temp->next )
	{
    printf("%d\t",temp -> data );
	}
}
void beginsert(int item)
{
	struct node *ptr = (struct node *)malloc(sizeof(struct node*));
	if(ptr == NULL)
	{
		printf("\n ****************OVERFLOW**************** \n");
	}
	else
	{
		ptr->data = item;
		ptr->next = head;
		head = ptr;
		printf("\n ****************Node Inserted**************** \n\n");
	}
}
