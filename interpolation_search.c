#include <stdio.h>

// Function to perform interpolation search
int interpolationSearch(int *arr, int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high && key >= *(arr + low) && key <= *(arr + high)) {
        // Calculate the position using linear interpolation formula
        int pos = low + ((double)(high - low) / (*(arr + high) - *(arr + low))) * (key - *(arr + low));

        // If the key is found
        if (*(arr + pos) == key)
            return pos;

        // If the key is in the right half
        else if (*(arr + pos) < key)
            low = pos + 1;

        // If the key is in the left half
        else
            high = pos - 1;
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

    // Perform interpolation search
    int result = interpolationSearch(arr, n, key);

    if (result != -1)
        printf("Element %d is present at index %d.\n", key, result);
    else
        printf("Element %d is not present in the array.\n", key);

    return 0;
}
