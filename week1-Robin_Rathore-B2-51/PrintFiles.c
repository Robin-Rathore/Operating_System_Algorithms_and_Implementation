#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    printf("Name\t: Robin Rathore\nSection\t: B2\nRoll no.: 51\n\n");

    pid_t p1, p2;
    p1 = fork();

    if(p1 < 0){
        printf("FORK FAILED");
    }else if(p1 == 0){
        printf("CHILD PROCESS 1 (PID: %d)\n Listing Files....\n", getpid());
        execlp("ls", "ls", "-1", (char*)NULL);
        exit(0);
    }else{
        wait(NULL);
        printf("PARENT PROCESS (PID: %d)\nFirst Child Completed\n", getpid());
        p2 = fork();

        if(p2 < 0){
            printf("FORK FAILED\n");
        }else if(p2 == 0){
            printf("CHILD PROCESS 2 (PID: %d)\nI am Second Child\n", getpid());
            sleep(5);
            printf("CHILD PROCESS 2 (PID: %d)\nWork Done\n", getpid());
            exit(0);
        }else{
            printf("\nParent Process (PID: %d)\nExiting now\n", getpid());
        }
    }

    return 0;
}