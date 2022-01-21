#include<stdio.h>
#include<ctype.h>
char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;  // Pushes a character onto the stack
}

char pop()
{
    if (top == -1)
        return -1;  // Checks if the stack is empty and returns -1
    else
        return stack[top--];  // Pops the topmost character from the stack and returns it
}

int priority(char x)
{
    if (x == '(' || x == ')')
        return 0;  // Returns priority 0 for parentheses
    if (x == '+' || x == '-')
        return 1;  // Returns priority 1 for addition and subtraction
    if (x == '*' || x == '/')
        return 2;  // Returns priority 2 for multiplication and division
    if (x == '^')
        return 3;  // Returns priority 3 for exponentiation
    else
        return 0;  // Returns priority 0 for other characters
}

int main()
{
    char exp[100];
    char *e, x;
    printf("Enter The Expression:");
    scanf("%s", &exp);  // Reads the infix expression from the user
    printf("\n");
    e = exp;

    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c", *e);  // Prints alphanumeric characters directly
        else if (*e == '(')
            push(*e);  // Pushes an opening parenthesis onto the stack
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                printf("%c", x);  // Pops and prints characters until matching opening parenthesis is found
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                printf("%c", pop());  // Pops and prints characters with higher or equal priority
            push(*e);  // Pushes the current character onto the stack
        }
        e++;
    }

    while (top != -1)
    {
        printf("%c", pop());  // Pops and prints remaining characters from the stack
    }

    return 0;
}

