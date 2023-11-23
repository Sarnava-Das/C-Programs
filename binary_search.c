#include <stdio.h>

// Function to perform binary search
int binarySearch(int *arr, int size, int key) {
    int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

        // Check if the key is present at the middle
        if (*(arr + mid) == key)
            return mid;

        // If the key is greater, ignore the left half
        else if (*(arr + mid) < key)
            left = mid + 1;

        // If the key is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If the key is not present in the array
    return -1;
}

// Function to print an array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", *(arr + i));
    printf("\n");
}

int main() {
    int arr[] = {11, 22, 34, 45, 56, 67, 78, 89, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 56;

    printf("Sorted array: ");
    printArray(arr, n);

    // Perform binary search
    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element %d is present at index %d.\n", key, result);
    else
        printf("Element %d is not present in the array.\n", key);

    return 0;
}
