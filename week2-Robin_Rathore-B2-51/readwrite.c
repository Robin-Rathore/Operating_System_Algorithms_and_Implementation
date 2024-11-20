#include<stdio.h>
#include<string.h>


void write_details_to_file(const char *details, const char *file_name){
    FILE *file = fopen(file_name, "w");
    if(file == NULL){
        printf("Error opening file : %s\n", file_name);
        return;
    }

    fprintf(file, "%s" ,details);
    fclose(file);
}

void find_matching_lines(const char *f1, const char *f2) {
    FILE *file1 = fopen(f1, "r");
    FILE *file2 = fopen(f2, "r");

    if(file1 == NULL || file2 == NULL){
        printf("Error opening one of the file");
        return ;
    }

    char line1[100], line2[100];
    printf("Matching Lines\n");

    while(fgets(line1, 100, file1) != NULL){
        rewind(file2);
        line1[strcspn(line1, "\n")] = '\0';

        while(fgets(line2, 100, file2) != NULL){
            line2[strcspn(line1, "\n")] = '\0';
            if(strcmp(line1, line2) == 0){
                printf("%s\n", line1);
            }
        }
    }
}

int main(){
    printf("Name : Robin Rathore\nSection : B2\nRoll No.: 51\n");

    const char *my_details = "Name: Robin Rathore\nSection : B2\nRoll no.: 51";
    const char *friend_details = "Name: Gaurav Rathore\nSection : B1\nRoll no.: 30";

    write_details_to_file(my_details, "my_details.txt");
    write_details_to_file(friend_details, "friend_details.txt");
    find_matching_lines("my_details.txt", "friend_details.txt");
}