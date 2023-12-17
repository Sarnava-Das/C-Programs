#include <stdio.h>
#include <string.h>
int main() {
    char filename[100];
    FILE *file;
    char line[1000];
     printf("Enter the filename with path: ");
 
    fgets(filename, sizeof(filename), stdin);
 
    // size_t len = strlen(filename);
    // if (len > 0 && filename[len - 1] == '\n') 
    //     filename[len - 1] = '\0';
    

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return 1;
    }
    printf("Contents of the file '%s':\n", filename);
    while (fgets(line, sizeof(line), file) != NULL) 
        printf("%s", line);
    

    fclose(file);
    return 0;
}
