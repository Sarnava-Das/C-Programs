#include <stdio.h>

int totalSteps = 0;


void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        totalSteps++;
        return;
    }
   
    towerOfHanoi(n - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    totalSteps++;
  
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Invalid input. Please enter a positive integer.\n");
    } else {
        printf("Steps to solve the Tower of Hanoi with %d disks:\n", n);
        towerOfHanoi(n, 'A', 'B', 'C');
        printf("Total steps: %d\n", totalSteps);
    }

    return 0;
}
