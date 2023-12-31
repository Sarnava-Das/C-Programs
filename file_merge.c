#include <stdio.h>

int main() {
    FILE *file1, *file2, *mergedFile;
    char ch;

    // Open the first file in read mode
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        perror("Error opening file1.txt");
        return 1;
    }

    // Open the second file in read mode
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        perror("Error opening file2.txt");
        fclose(file1);
        return 1;
    }

    // Open the third file in write mode
    mergedFile = fopen("mergedFile.txt", "w");
    if (mergedFile == NULL) {
        perror("Error opening mergedFile.txt");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    // Copy contents of file1 to mergedFile
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, mergedFile);
    }

    // Copy contents of file2 to mergedFile
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, mergedFile);
    }

    // Close all the files
    fclose(file1);
    fclose(file2);
    fclose(mergedFile);

    printf("Files merged successfully!\n");

    return 0;
}
