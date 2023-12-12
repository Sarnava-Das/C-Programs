#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void listFilesAndDirectories(const char* path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("Files and directories in %s:\n", path);

    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dp);
}

int main() {
    char path[100];

    printf("Enter the directory path: ");
    scanf("%s", path);

    listFilesAndDirectories(path);

    return 0;
}
