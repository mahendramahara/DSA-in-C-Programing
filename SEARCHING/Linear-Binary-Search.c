#include <stdio.h>
#include <stdlib.h>
int linearSearch(int arr[], int n, int target);
int binarySearch(int arr[], int n, int target);

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void printSearchResult(int result, int target) {
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
}

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    int target2 = 3;
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int result = binarySearch(arr, n, target);
    printf("\n\nUsing Binary Search:\n");
    printSearchResult(result, target);
    int result2 = linearSearch(arr, n, target2);
    printf("\n\nUsing Linear Search:\n");
    printSearchResult(result, target2);
    return 0;
}
