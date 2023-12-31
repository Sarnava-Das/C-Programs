#include <stdio.h>

// Function to compare two strings using pointers
int compareStrings(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0; // Strings are not equal
        }

        // Move to the next character in both strings
        str1++;
        str2++;
    }

    // If both strings are of equal length, return 1; otherwise, return 0
    return (*str1 == '\0' && *str2 == '\0');
}

int main() {
    // Example strings
    const char *string1 = "Hello";
    const char *string2 = "Hello";
    
    // Compare strings
    if (compareStrings(string1, string2)) {
        printf("The strings are equal.\n");
    } else {
        printf("The strings are not equal.\n");
    }

    return 0;
}
