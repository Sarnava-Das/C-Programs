#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int *arr, int low, int high) {
    int pivot = *(arr + low);  // Choose the leftmost element as the pivot
    int i = low + 1;            // Index of the element to be checked

    for (int j = low + 1; j <= high; j++) {
        // If the current element is smaller than the pivot
        if (*(arr + j) < pivot) {
            // Swap arr[i] and arr[j]
            swap(arr + i, arr + j);
            i++;
        }
    }

    swap(arr + low, arr + i - 1);  // Swap the pivot element with the rightmost element of the smaller elements
    return i - 1;                  // Return the partition index
}

// Function to perform quicksort
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        // Find the partition index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the subarrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
