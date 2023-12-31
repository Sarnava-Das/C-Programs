#include <stdio.h>

// Define the structure named 'company'
typedef struct  {
    char name[50];
    char address[100];
    char phone[15];
    int noOfEmployee;
}Company;

int main() {
    // Declare a variable of type 'struct Company'
     Company myCompany;

    // Read input for the company members
    printf("Enter the name of the company: ");
    scanf("%s", myCompany.name);

    printf("Enter the address of the company: ");
    scanf("%s", myCompany.address);

    printf("Enter the phone number of the company: ");
    scanf("%s", myCompany.phone);

    printf("Enter the number of employees in the company: ");
    scanf("%d", &myCompany.noOfEmployee);

    // Display the entered values
    printf("\nCompany Information:\n");
    printf("Name: %s\n", myCompany.name);
    printf("Address: %s\n", myCompany.address);
    printf("Phone: %s\n", myCompany.phone);
    printf("Number of Employees: %d\n", myCompany.noOfEmployee);

    return 0;
}
