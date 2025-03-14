#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void createFile() {
    FILE *fp = fopen("heap.txt", "a");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    char filename[20];
    int size, randomPos;
    
    // Random Position Generate Karna (Unordered Storage Ka Concept)
    srand(time(0));  // Random seed set karna
    randomPos = rand() % 100;  // Random Position (Example: 0-99)

    printf("Enter filename and size (KB): ");
    scanf("%s %d", filename, &size);
    fprintf(fp, "%d %s %d\n", randomPos, filename, size);
    fclose(fp);

    printf("File stored at random position %d (unordered)!\n", randomPos);
}

void listFiles() {
    FILE *fp = fopen("heap.txt", "r");
    if (!fp) {
        printf("No files found!\n");
        return;
    }

    int pos, size;
    char filename[20];
    printf("Stored Files (Unordered):\n");
    while (fscanf(fp, "%d %s %d", &pos, filename, &size) != EOF)
        printf("Position: %d | %s - %d KB\n", pos, filename, size);
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
