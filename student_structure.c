#include <stdio.h>

// Define the structure named 'Student'
struct Student {
    int rollNo;
    char name[50];
    char address[100];
    int age;
    float averageMarks;
};

// Function to read student details
void readStudentDetails(struct Student students[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("\nEnter details for Student %d:\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter Name: ");
        scanf("%s", students[i].name);

        printf("Enter Address: ");
        scanf("%s", students[i].address);

        printf("Enter Age: ");
        scanf("%d", &students[i].age);

        printf("Enter Average Marks: ");
        scanf("%f", &students[i].averageMarks);
    }
}

// Function to display student details
void displayStudentDetails(struct Student students[], int size) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < size; ++i) {
        printf("\nDetails for Student %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Address: %s\n", students[i].address);
        printf("Age: %d\n", students[i].age);
        printf("Average Marks: %.2f\n", students[i].averageMarks);
    }
}

int main() {
    // Define an array of structures to store details for 12 students
    struct Student bctStudents[12];

    // Function call to read student details
    readStudentDetails(bctStudents, 12);

    // Function call to display student details
    displayStudentDetails(bctStudents, 12);

    return 0;
}
