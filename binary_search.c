#include <stdio.h>


int binarySearch(int *arr, int size, int key) {
    int left = 0, right = size - 1, mid;

    while (left <= right) {
        mid = left + (right - left) / 2;

      
        if (*(arr + mid) == key)
            return mid;

     
        else if (*(arr + mid) < key)
            left = mid + 1;

     
        else
            right = mid - 1;
    }

 
    return -1;
}


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

    
    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element %d is present at index %d.\n", key, result);
    else
        printf("Element %d is not present in the array.\n", key);

    return 0;
}
