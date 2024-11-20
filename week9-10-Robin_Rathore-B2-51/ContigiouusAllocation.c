#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILES 100
#define MAX_BLOCKS 1000

typedef struct {
    char name[50];
    int startBlock;
    int numBlocks;
    int blocks[MAX_BLOCKS];
} File;

int main() {
    int F, i, j, k;
    char searchFile[50];
    File files[MAX_FILES];
    bool blockOccupied[MAX_BLOCKS] = {false}; 

    printf("Enter the number of files: ");
    scanf("%d", &F);

    for (i = 0; i < F; i++) {
        printf("Enter details for file %d\n", i + 1);
        printf("File name: ");
        scanf("%s", files[i].name);
        printf("Starting block number: ");
        scanf("%d", &files[i].startBlock);
        printf("Number of blocks required: ");
        scanf("%d", &files[i].numBlocks);

        bool canAllocate = true;
        for (j = 0; j < files[i].numBlocks; j++) {
            int block = files[i].startBlock + j;
            if (block >= MAX_BLOCKS || blockOccupied[block]) {
                canAllocate = false;
                break;
            }
        }

        if (canAllocate) {
            for (j = 0; j < files[i].numBlocks; j++) {
                int block = files[i].startBlock + j;
                files[i].blocks[j] = block;
                blockOccupied[block] = true;
            }
            printf("File '%s' allocated successfully.\n", files[i].name);
        } else {
            printf("Unable to allocate file '%s'. Not enough contiguous blocks available.\n", files[i].name);
            i--; 
        }
    }

    printf("Enter the name of the file to be searched: ");
    scanf("%s", searchFile);

    for (i = 0; i < F; i++) {
        if (strcmp(files[i].name, searchFile) == 0) {
            printf("File found!\n");
            printf("File name: %s\n", files[i].name);
            printf("Starting block number: %d\n", files[i].startBlock);
            printf("Number of blocks allocated: %d\n", files[i].numBlocks);
            printf("Allocated block numbers: ");
            for (j = 0; j < files[i].numBlocks; j++) {
                printf("%d ", files[i].blocks[j]);
            }
            printf("\n");
            return 0;
        }
    }

    printf("File not found.\n");

    return 0;
}
