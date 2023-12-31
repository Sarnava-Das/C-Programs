#include <stdio.h>

void addMatrices(int (*mat1)[2], int (*mat2)[2], int (*result)[2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // Add corresponding elements and store the result
            *(*(result + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}

void displayMatrix(int (*mat)[2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d\t", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int mat1[2][2] = {{1, 2}, {3, 4}};
    int mat2[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];

    printf("Matrix 1:\n");
    displayMatrix(mat1);

    printf("\nMatrix 2:\n");
    displayMatrix(mat2);

    // Add the matrices
    addMatrices(mat1, mat2, result);

    printf("\nSum of Matrices:\n");
    displayMatrix(result);

    return 0;
}
