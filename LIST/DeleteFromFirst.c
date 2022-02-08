#include <stdio.h>

int main() {
    int array[10] = {10, 20, 30, 40, 50};
    int i;

    // Print the original array
    printf("Original Array: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }

    // Delete the element from the first position
    for (i = 0; i < 4; i++) {
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
