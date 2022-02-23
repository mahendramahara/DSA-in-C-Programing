#include <stdio.h>

int main() {
    int array[10] = {60, 70, 80, 90, 100};
    int newElement, i;

    // Print the original array
    printf("Original Array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    // Input the new element to be inserted
    printf("\nEnter the new element: ");
    scanf("%d", &newElement);

    // Insert the new element at the end
    array[5] = newElement;

    // Print the updated array
    printf("Arrey After Updated: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
