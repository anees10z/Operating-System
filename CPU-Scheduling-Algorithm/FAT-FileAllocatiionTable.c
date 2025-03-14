#include <stdio.h>
#include <string.h>
#define MAX 100

char filenames[MAX][20];
int sizes[MAX], starts[MAX], fat[MAX], count = 0;

void createFile() {
    if (count >= MAX) {
        printf("File limit reached!\n");
        return;
    }
    char name[20];
    int size, start;
    printf("Enter filename, size (in bytes), and start block: ");
    scanf("%s %d %d", name, &size, &start);
    
    if (start >= MAX) {
        printf("Invalid start block!\n");
        return;
    }
    
    strcpy(filenames[count], name);
    sizes[count] = size;
    starts[count] = start;
    fat[start] = -1;
    count++;
}

void listFiles() {
    printf("Files:\n");
    for (int i = 0; i < count; i++)
        printf("%s, %dB, Start: %d\n", filenames[i], sizes[i], starts[i]);
}

int main() {
    int n;
    printf("Enter number of files: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        createFile();
    }
    listFiles();
    return 0;
}
