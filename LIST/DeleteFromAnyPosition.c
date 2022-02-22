#include <stdio.h>

int main() {
    int array[10] = {500, 1000, 1500, 2000, 2500};
    int position, i;

    // Print the original array
    printf("Original Array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    // Input the position to delete
    printf("\nEnter the position to delete: ");
    scanf("%d", &position);

    if (position < 0 || position >= 5) {
        printf("Invalid position!\n");
        return 1;
    }

    // Shift elements to the left to overwrite the deleted element
    for (i = position; i < 4; i++) {
        array[i] = array[i + 1];
    }

    // Decrement the size of the array
    int newSize = 4;

    // Print the updated array
    printf("\nArray After Deleted: ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
