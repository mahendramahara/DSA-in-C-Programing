#include <stdio.h>

int main() {
    int array[10] = {500, 1000, 1500, 2000, 2500};
    int newElement, position, i;

    // Print the original array
    printf("Original Array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    // Input the new element and position
    printf("\nEnter the new element: ");
    scanf("%d", &newElement);
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    if (position < 0 || position > 5) {
        printf("Invalid position!\n");
        return 1;
    }

    // Shift elements to the right to make space for the new element
    for (i = 4; i >= position; i--) {
        array[i + 1] = array[i];
    }

    // Insert the new element at the specified position
    array[position] = newElement;

    // Print the updated array
    printf("Arrey After Updated: ");
    for (i = 0; i < 6; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
