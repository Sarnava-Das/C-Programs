#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings using pointers
char* concatenateStrings(const char *str1, const char *str2) {
    // Calculate the total length of the concatenated string
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int totalLen = len1 + len2;

    // Allocate memory for the concatenated string
    char *result = (char *)malloc((totalLen + 1) * sizeof(char));

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Copy the first string into the result string
    strcpy(result, str1);

    // Use pointer arithmetic to move to the end of the result string
    char *end = result + len1;

    // Copy the second string to the end of the result string
    strcpy(end, str2);

    return result;
}

int main() {
    // Example strings
    const char *string1 = "Hello, ";
    const char *string2 = "world!";
    
    // Concatenate strings
    char *result = concatenateStrings(string1, string2);

    // Print the concatenated string
    printf("Concatenated String: %s\n", result);

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
