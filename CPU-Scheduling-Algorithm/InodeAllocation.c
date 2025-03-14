#include <stdio.h>
#include <string.h>

#define MAX_FILES 10

char filenames[MAX_FILES][20];
int inodes[MAX_FILES], count = 0;

void createFile() {
    if (count >= MAX_FILES) {
        printf("File limit reached!\n");
        return;
    }
    printf("Enter filename: ");
    scanf("%s", filenames[count]);
    inodes[count] = count + 1; // Assign inode number
    count++;
}

void listFiles() {
    printf("Files in System:\n");
    for (int i = 0; i < count; i++)
        printf("Filename: %s, Inode: %d\n", filenames[i], inodes[i]);
}

int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        createFile();
    listFiles();
    return 0;
}
