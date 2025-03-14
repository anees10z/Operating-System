#include <stdio.h>
#include <string.h>

typedef struct {
    char filename[20];
    int size;
} File;

void createFile() {
    FILE *fp = fopen("random.dat", "ab");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }

    File f;
    printf("Enter filename and size (KB): ");
    scanf("%s %d", f.filename, &f.size);
    fwrite(&f, sizeof(File), 1, fp);
    fclose(fp);

    printf("File stored!\n");
}

void readFile(int position) {
    FILE *fp = fopen("random.dat", "rb");
    if (!fp) {
        printf("No files found!\n");
        return;
    }

    File f;
    fseek(fp, position * sizeof(File), SEEK_SET);
    if (fread(&f, sizeof(File), 1, fp))
        printf("File at position %d: %s - %d KB\n", position, f.filename, f.size);
    else
        printf("Invalid position!\n");

    fclose(fp);
}

int main() {
    int choice, pos;
    do {
        printf("\n1. Add File\n2. Read File at Position\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) createFile();
        else if (choice == 2) {
            printf("Enter position: ");
            scanf("%d", &pos);
            readFile(pos);
        }
    } while (choice != 3);

    return 0;
}
