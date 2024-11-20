#include<stdio.h>
#include<unistd.h>

int main(){
    printf("Name : Robin Rathore\nSection : B2\nRoll No.: 51\n");
    pid_t p1 = fork();

    if(p1 < 0){
        printf("FORK FAILED\n");
    }else if(p1 == 0){
        printf("child process\n");
    }else{
        printf("Parent Process\n");
    }

    return 0;
}