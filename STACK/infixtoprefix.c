#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>
#define MAX 100

int top = -1;
char stack[MAX];
// checking if stack is full
int isFull ()
{
  return top == MAX - 1;
}
// checking is stack is empty
int isEmpty ()
{
  return top == -1;
}
void push (char item)
{
  if (isFull ())
    return;
  top++;
  stack[top] = item;
}
// Function to remove an item from stack.  It decreases top by 1 
int pop ()
{
  if (isEmpty ())
    return INT_MIN;
  // decrements top and returns what has been popped      
  return stack[top--];
}
// Function to return the top from stack without removing it 
int peek ()
{
  if (isEmpty ())
    return INT_MIN;
  return stack[top];
}
// A utility function to check if the given character is operand 
int checkIfOperand (char ch)
{ 
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
// Fucntion to compare precedence
// If we return larger value means higher precedence 
int precedence (char ch)
{
  switch (ch)
    {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    }
  return -1;
}
// The driver function for infix to postfix conversion 
int getPostfix (char *expression)
{
  int i, j;
  for (i = 0, j = -1; expression[i]; ++i)
    {
      // If the character is an operand, add it to the expression
      if (checkIfOperand (expression[i]))
	expression[++j] = expression[i];
      // If the character is an opening parenthesis, push it to the stack
      else if (expression[i] == '(')
	push (expression[i]);
      // If the character is a closing parenthesis, pop elements from the stack and add them to the expression until an opening parenthesis is encountered
      else if (expression[i] == ')')
	{
	  while (!isEmpty (stack) && peek (stack) != '(')
	    expression[++j] = pop (stack);
	  if (!isEmpty (stack) && peek (stack) != '(')
	    return -1;		// invalid expression              
	  else
	    pop (stack);
	}
      else			// if an operator
	{
// Pop operators from the stack and add them to the expression until an operator with lower precedence is encountered
	  while (!isEmpty (stack)
		 && precedence (expression[i]) <= precedence (peek (stack)))
	    expression[++j] = pop (stack);
	  push (expression[i]);
	}
    }

  // Once all initial expression characters are traversed,
  // add all remaining elements from stack to expression
  while (!isEmpty (stack))
  expression[++j] = pop (stack);
  expression[++j] = '\0';
}
// Function to reverse a string
void reverse (char *exp)
{
  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];
  temp[j--] = '\0';
  while (exp[i] != '\0')
    {
      temp[j] = exp[i];
      j--;
      i++;
    }
  strcpy (exp, temp);
}
// Function to change opening and closing brackets
void brackets (char *exp)
{
  int i = 0;
  while (exp[i] != '\0')
    {
      if (exp[i] == '(')
	exp[i] = ')';
      else if (exp[i] == ')')
	exp[i] = '(';
      i++;
    }
}
// Function to convert infix expression to prefix
void InfixtoPrefix (char *exp)
{
  int size = strlen (exp);
  // Reverse the string
  reverse (exp);
  // Change the brackets
  brackets (exp);
  // Get the postfix expression
  getPostfix (exp);
  // Reverse the string again to get the prefix expression
  reverse (exp);
}

int main ()
{
	char expression[100];
	printf ("Enter The Expression: ");
	scanf("%s",&expression);
	printf ("Your Expression Is: %s\n", expression);
	InfixtoPrefix (expression);
	printf ("The prefix Expression is: ");
	printf ("%s\n", expression);

  return 0;
}

