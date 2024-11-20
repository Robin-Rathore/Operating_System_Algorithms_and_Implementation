#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    printf("Name : Robin Rathore\nSection : B2\nRoll No.: 51\n");

    pid_t p1 = fork();

    if(p1 < 0){
        printf("FORK FAILED\n");
    }else if(p1 == 0){
        printf("CHILD PROCESS\n");
        if(execlp("ls", "ls", "-1", (char*)NULL) == -1){
            printf("LS command Falied\n");
            return 1;
        }else{
            execlp("ls", "ls", "-1", (char*)NULL);
        }
    }else{
        printf("PARENT PROCESS\n");
    }
}