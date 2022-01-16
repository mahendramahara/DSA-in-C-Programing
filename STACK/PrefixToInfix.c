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

void prefixtoinfix(char *prefix, char *infix) {
    int len = strlen(prefix);
    int i;

    for ( i = len - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            char operand1[MAX], operand2[MAX];
            char temp[MAX];

            pop(operand1);
            pop(operand2);

            sprintf(temp, "(%s%c%s)", operand1, prefix[i], operand2);
            push(temp);
        } else {
            char temp[MAX];
            temp[0] = prefix[i];
            temp[1] = '\0';
            push(temp);
        }
    }

    pop(infix);
}

int main() {
    char prefix[MAX], infix[MAX];

    printf("Enter the prefix expression: ");
    fgets(prefix, sizeof(prefix), stdin);
    prefix[strlen(prefix) - 1] = '\0'; 
	// Remove the newline character from fgets

    prefixtoinfix(prefix, infix);

    printf("Infix expression is: %s\n", infix);

    return 0;
}
