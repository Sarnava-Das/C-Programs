#include <stdio.h>

int main() {
    char filename[100];

    // Get the filename from the user
    printf("Enter the filename to delete: ");
    scanf("%s", filename);

    // Attempt to delete the file
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }

    return 0;
}
