#include <stdio.h>

void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        // Swap elements using pointers
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move pointers towards each other
        start++;
        end--;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Reverse the array
    reverseArray(arr, size);

    printf("\nReversed Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
