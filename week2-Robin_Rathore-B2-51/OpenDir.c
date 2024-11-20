#include<stdio.h>
#include<dirent.h>

int main(){
    printf("Name : Robin Rathore\nSection : B2\nRoll No.: 51\n");

    DIR* directory;
    struct dirent *dir_entry;
    directory = opendir("/Users/robin/Desktop/Omegle");
    if(directory == NULL){
        printf("Couldn't Open the directory\n");
        return 1;
    }
    printf("Contents of Directory:\n");
    while((dir_entry = readdir(directory)) != NULL){
        printf("%s\n", dir_entry->d_name);
    }

    closedir(directory);
    return 0;
}