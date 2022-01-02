#include <stdio.h>
#include <math.h>

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    } 
	else if (n == 1) {
        return 1;
    } 
	else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;
    printf("Enter The Number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
    } else {
        int fib = fibonacci(num);
        printf("Fibonacci of %d is %d\n", num, fib);
    }

    return 0;
}

