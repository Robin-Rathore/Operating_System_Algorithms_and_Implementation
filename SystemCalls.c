#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int p = fork();
    // wait(NULL);
    if(p > 0){
        // Parent process executing
        printf("Child ID : %d\n", p); // Child ID
        printf("Parent ID : %d\n", getpid());// Parent ID
    }else if(p == 0){
        // child process executing
        sleep(3);
        printf("Child process ID : %d\n", getpid());// Child process ID
        printf("parent process ID : %d\n", getppid());// parent process ID
    }else{
        printf("Fork Unsucessfull");
    }
    return 0;
}