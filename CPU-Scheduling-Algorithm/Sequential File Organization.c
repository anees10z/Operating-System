#include <stdio.h>
#include <string.h>

void createFile() {
    FILE *fp = fopen("sequential.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    char filename[20];
    int size;
    printf("Enter filename and size (KB): ");
    scanf("%s %d", filename, &size);
    fprintf(fp, "%s %d\n", filename, size);
    fclose(fp);

    printf("File stored sequentially!\n");
}

void listFiles() {
    FILE *fp = fopen("sequential.txt", "r");
    if (!fp) {
        printf("No files found!\n");
        return;
    }

    char filename[20];
    int size;
    printf("Stored Files:\n");
    while (fscanf(fp, "%s %d", filename, &size) != EOF) {
        printf("%s - %d KB\n", filename, size);
    }
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
