#include <stdio.h>

int main() {
    int array[10] = {60, 70, 80, 90, 100};
    int i;

    // Print the original array
    printf("Original Array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    // Delete the element from the last position
    array[4] = 0;  // Set the last element to 0

    // Decrement the size of the array
    int newSize = 4;

    // Print the updated array
    printf("\nArray After Deleted: ");
    for (i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
