#include <stdio.h>
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
int getMaxDigits(int arr[], int n);
void countingSort(int arr[], int n, int exp);
void radixSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void shellSort(int arr[], int n);

// Function to perform selection sort
void selectionSort(int arr[], int n)    {
    int i, j, minIndex, temp;
    // Traverse the entire array
    for (i = 0; i < n - 1; i++)    {
        // Assume the current index is the minimum
        minIndex = i;
        // Find the index of the minimum element in the unsorted part
        for (j = i + 1; j < n; j++)      {
            if (arr[j] < arr[minIndex])    {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform Insertion Sort
void insertionSort(int arr[], int n)     {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
// Move elements of arr[0..i-1] that are greater than key to one position ahead of their current                    position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // Insert the key into its correct position
        arr[j + 1] = key;
    }
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to check if any swapping occurs in the inner loop
        // Last i elements are already in place, so no need to check them
        for (j = 0; j < n - 1 - i; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap them if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set the flag to indicate swapping occurred
            }
        }
        // If no swapping occurred in the inner loop, the array is already sorted
        if (swapped == 0) {
            break;
        }
    }
}

// Function to merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
// Create temporary arrays
    int L[n1], R[n2];
    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    // Merge the temporary arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Main function to perform merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to partition the array and return the index of the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element
    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[i+1] and arr[high] (put the pivot in its correct place)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot
        int pi = partition(arr, low, high);
        // Recursively sort the subarrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to find the maximum number of digits in an array
int getMaxDigits(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Count the number of digits in the maximum number
    int digits = 0;
    while (max > 0) {
        digits++;
        max /= 10;
    }
    return digits;
}
// Using counting sort to sort the elements based on a particular digit
void countingSort(int arr[], int n, int exp) {
    const int BASE = 10;
    int output[n];
    int count[BASE];
    // Initialize the count array
    for (int i = 0; i < BASE; i++) {
        count[i] = 0;
    }
    // Count the occurrences of each digit at the current place value
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % BASE]++;
    }
    // Update count[i] to store the position of the digit in the output array
    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
    }
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }
    // Copy the output array back to the original array
    for (int i = 0; i < n; i++) 
	{
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(int arr[], int n) {
    int maxDigits = getMaxDigits(arr, n);
    // Apply counting sort for each digit place value
    for (int exp = 1; maxDigits / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}
// Function to perform heapify on a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // If right child is larger than root
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not the root, swap and recursively heapify the affected subtree
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    // Extract elements one by one from the heap
    for (int i = n - 1; i > 0; i--) {
        // Swap the root (maximum element) with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // Reduce the size of the heap and heapify the root
        heapify(arr, i, 0);
    }
}




// Function to perform shell sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
// Function to print an array
void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Driver program to test the selectionSort function
int main() {
    int arr[] = {24, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    selectionSort(arr, n);
    printf("\n\nSorted array using Selection Sort: \n");
    printArray(arr, n);
    // Resetting the array
    int arr2[] = {24, 25, 12, 22, 11};
    insertionSort(arr2, n);
    printf("\n\nSorted array using Insertion Sort: \n");
    printArray(arr2, n);
    // Resetting the array 
    int arr3[] = {24, 25, 12, 22, 11};
    bubbleSort(arr3, n);
    printf("\n\nSorted array using Bubble Sort: \n");
    printArray(arr3, n);
    // Resetting the array 
    int arr4[] = {24, 25, 12, 22, 11};
    mergeSort(arr4, 0, n - 1);
    printf("\n\nSorted array using Merge Sort: \n");
    printArray(arr4, n);
    // Resetting the array 
    int arr5[] = {24, 25, 12, 22, 11};
    quickSort(arr5, 0, n - 1);
    printf("\n\nSorted array using Quick Sort: \n");
    printArray(arr5, n);
    // Resetting the array 
    int arr6[] = {24, 25, 12, 22, 11};
    radixSort(arr6, n);
    printf("\n\nSorted array using Radix Sort: \n");
    printArray(arr6, n);
	// Resetting the array 
    int arr7[] = {24, 25, 12, 22, 11};    
	heapSort(arr7, n);
    printf("\n\nSorted array using Heap Sort: \n");
    printArray(arr7, n);
    // Resetting the array 
    int arr8[] = {24, 25, 12, 22, 11};    
	shellSort(arr8, n);
    printf("\n\nSorted array using Shell Sort: \n");
    printArray(arr8, n);
    return 0;
}
