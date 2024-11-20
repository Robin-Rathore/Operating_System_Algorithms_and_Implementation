// WAP-to-open-a-directory-and-list-its-content

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *dirpath = argv[1];
    // const char *dirpath = ".";
    DIR *dir = opendir(dirpath);

    //check if directory was sucessfully opened
    if(dir == NULL){
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while((entry = readdir(dir)) != NULL){
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return EXIT_FAILURE;

}