#include <stdio.h>
#define MAX_SIZE 20

int topOfStack = -1;
int stack[MAX_SIZE];
int main()
{
    while (1)
    {
        int keyPress;
        printf("\n\nPress a key according to the operation you want.\n1. Push\n2. Pop\n3. Display\n: ");
        scanf("%d", &keyPress);
        switch (keyPress)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;

        default:
            printf("Enter a vaild option!");
            break;
        }
    }
}

void push()
{
    if (topOfStack == 20)
    {
        printf("\nStack Overflow!\nCan't add any more items.");
    }
    else
    {
        printf("\nEnter the element to push into the stack: ");
        scanf("%d", &stack[++topOfStack]);
        printf("\nPushed successfully!");
    }
}

void pop()
{
    if (topOfStack == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("%d", stack[topOfStack--]);
    }
}

void display()
{
	int i;
    if (topOfStack == -1)
    {
        printf("\nStack Underflow!");
    }
    else
    {
        printf("\nStack:\n");
        for ( i = topOfStack; i > -1; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}
