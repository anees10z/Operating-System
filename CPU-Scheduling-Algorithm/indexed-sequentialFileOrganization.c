#include <stdio.h>
#include <string.h>

void createFile() {
    FILE *fp = fopen("indexed-seq.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    char filename[20];
    int size, index;
    printf("Enter filename, size (KB), and index: ");
    scanf("%s %d %d", filename, &size, &index);
    fprintf(fp, "%d %s %d\n", index, filename, size);
    fclose(fp);

    printf("File stored with index!\n");
}

void listFiles() {
    FILE *fp = fopen("indexed-seq.txt", "r");
    if (!fp) {
        printf("No files found!\n");
        return;
    }

    char filename[20];
    int size, index;
    printf("Stored Files:\n");
    while (fscanf(fp, "%d %s %d", &index, filename, &size) != EOF)
        printf("Index: %d | %s - %d KB\n", index, filename, size);
    fclose(fp);
}

int main() {
    int choice;
    do {
        printf("\n1. Add File\n2. List Files\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) createFile();
        else if (choice == 2) listFiles();
    } while (choice != 3);

    return 0;
}
