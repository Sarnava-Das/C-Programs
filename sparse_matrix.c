#include <stdio.h>

int main() {
    int m, n, i, j, c = 0;
    printf("Enter the number of rows of the matrix \n");
    scanf("%d", &m);
    printf("Enter the number of columns of the matrix \n");
    scanf("%d", &n);
    int a[m][n];

    for (i = 0; i < m; i++) {
        printf("Enter the row of the matrix \n");
        for (j = 0; j < n; j++)
           { 
            scanf("%d", &a[i][j]);
            if (a[i][j] != 0)
                c++;

           }
    }

    int b[3][c], p = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                b[0][p] = i;
                b[1][p] = j;
                b[2][p] = a[i][j];
                p++;
            }
        }
    }

    printf("Printing the sparse matrix \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < p; j++)
            printf("%d \t", b[i][j]);
        printf("\n");
    }

    return 0;
}
