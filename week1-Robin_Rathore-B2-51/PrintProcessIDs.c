#include <stdio.h>
#include <unistd.h>
int main()
{

    printf("Name\t: Robin Rathore\nSection\t: B2\nRoll no.: 51\n\n");

    pid_t pid = fork();
    if (pid < 0)
        printf("FORK FAILED\n");
    else if (pid == 0)
        printf("CHILD PROCESS\nProcess ID\t: %d\nParent ID\t: %d\n\n", getpid(), getppid());
    else
        printf("PARENT PROCESS\nProcess ID\t: %d\nCHILD ID\t: %d\n\n", getpid(), pid);
    return 0;
}