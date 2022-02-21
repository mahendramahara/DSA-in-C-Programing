#include <stdio.h>

int main() {
    int array[10] = {10, 20, 30, 40, 50};
    int newElement, i;

    // Print the original array
    printf("Original Array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    // Input the new element to be inserted
    printf("\n\nEnter the new element: ");
    scanf("%d", &newElement);

    // Shift elements to the right to make space for the new element
    for (i = 4; i >= 0; i--) {
        array[i + 1] = array[i];
    }

    // Insert the new element at the beginning
    array[0] = newElement;

    // Print the updated array
    printf("\nArray After Updated: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

