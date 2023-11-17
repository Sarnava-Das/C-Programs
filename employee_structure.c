#include <stdio.h>

struct Employee {
    int employeeId;
    char name[50];
    char department[50];
    float salary;
};

int main() {
    struct Employee emp; 

    printf("Enter Employee Details:\n");
    printf("Employee ID: ");
    scanf("%d", &emp.employeeId);

    printf("Name: ");
    scanf(" %49[^\n]", emp.name); 

    printf("Department: ");
    scanf(" %49[^\n]", emp.department); 

    printf("Salary: ");
    scanf("%f", &emp.salary);

    printf("\nEmployee Details:\n");
    printf("Employee ID: %d\n", emp.employeeId);
    printf("Name: %s\n", emp.name);
    printf("Department: %s\n", emp.department);
    printf("Salary: %.2f\n", emp.salary);

    return 0;
}
