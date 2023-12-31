#include <stdio.h>
#include <string.h>
int main() {
    char filename[100];
    FILE *file;
    char ch;
    int lineCount = 0;

     printf("Enter the filename with path: ");
    
    // Use fgets to read a line of input
    fgets(filename, sizeof(filename), stdin);

    // Remove the newline character at the end (if present)
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }
    fclose(file);
    if (ch != '\n' && lineCount > 0) {
        lineCount++;
    }
    printf("The number of lines in the file is: %d\n", lineCount);
    return 0;
}
