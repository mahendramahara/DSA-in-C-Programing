#include<stdio.h>
#define SIZE 5
int items[SIZE];
int front =-1, rear= -1;
// check the queue is full or not
int isFull()
{
	if((front == rear+1) || (front == 0 && rear == SIZE -1))
	return 1;
	return 0;
}
// check the queue is empty or not
int isEmpty()
{
	if(front == -1)
	return 1;
	return 0;
}
// Adding an element
void enQueue(int element)
{
	if (isFull())
	printf("\n Queue is full!! \n");
	else{
		if (front==-1) front =0;
		rear = (rear + 1) % SIZE;
		items[rear] = element;
		printf("\n Inserted -> %d", element);
	}
}
// Removing an element
int deQueue()
{
	int element;
	if(isEmpty())
	{
	printf("\n Queue is Empty!! \n");
	return (-1);
	}
	else{
		element= items[front];
		if(front == rear)
		{
			front= -1;
			rear= -1;
		}
	else{
		front= (front +1)%SIZE;
		}
	printf("\n Deleted element -> %d \n", element);
	return (element);
	}
}
// display the queue
void display(){
	int i;
	if(isEmpty())
	printf("\n Empty Queue \n");
	else
	{
	printf("\n Front -> %d", front);
	printf("\n items -> ");	
	for(i=front; i!=rear; i=(i+1)%SIZE)
	{
		printf("%d", items[i]);
	}
	printf("%d", items[i]);
	printf("\n Rear -> %d \n", rear);
	}
}
int main()
{
//Fails because front = -1
	deQueue();
	enQueue(5);
	enQueue(6);
	enQueue(7);
	enQueue(8);
	enQueue(9);
//Fails because front = 0 && rear == SIZE -1	
	enQueue(1);
	display();
	deQueue();
	display();
	enQueue(0);
	display();
//Fails because front = rear+1	
	enQueue(2);
	return 0;
}
