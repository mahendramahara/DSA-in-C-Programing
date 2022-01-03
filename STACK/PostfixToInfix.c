#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void push(char *str) {
    strcpy(stack[++top], str);
}

void pop(char *str) {
    strcpy(str, stack[top--]);
}

void postfixtoinfix(char *postfix, char *infix) {
    int len = strlen(postfix);
    int i;

    for ( i = 0; i < len; i++) {
        if (isOperator(postfix[i])) {
            char operand2[MAX], operand1[MAX];
            char temp[MAX];

            pop(operand2);
            pop(operand1);

            sprintf(temp, "(%s%c%s)", operand1, postfix[i], operand2);
            push(temp);
        } else {
            char temp[MAX];
            temp[0] = postfix[i];
            temp[1] = '\0';
            push(temp);
        }
    }

    pop(infix);
}

int main() {
    char postfix[MAX], infix[MAX];

    printf("Enter the postfix expression: ");
    fgets(postfix, sizeof(postfix), stdin);
    postfix[strlen(postfix) - 1] = '\0'; 
	// Remove the newline character from fgets

    postfixtoinfix(postfix, infix);

    printf("Infix expression is: %s\n", infix);

    return 0;
}
