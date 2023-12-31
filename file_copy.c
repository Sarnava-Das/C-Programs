#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char ch;

    // Input the source file name
    printf("Enter the source file name: ");
    fgets(sourceFileName, sizeof(sourceFileName), stdin);

    // Input the destination file name
    printf("Enter the destination file name: ");
     fgets(destinationFileName, sizeof(destinationFileName), stdin);

    // Open the source file in read mode
    sourceFile = fopen(sourceFileName, "r");
    
    // Check if the source file exists
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    // Open the destination file in write mode
    destinationFile = fopen(destinationFileName, "w");
    
    // Check if the destination file is created/opened successfully
    if (destinationFile == NULL) {
        printf("Unable to create/open the destination file.\n");
        fclose(sourceFile); // Close the source file before exiting
        return 1;
    }

    // Copy contents from source file to destination file
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destinationFile);
    }

    // Close both files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copy successful.\n");

    return 0;
}
