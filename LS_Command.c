#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = fork();  // Fork a child process

    if (pid < 0) {  // Error in fork
        perror("Fork failed\n");
        return 1;
    } else if (pid == 0) {  // Child process
        // Execute the 'ls' command
        char *args[] = {"ls", NULL};
        execvp("ls", args);  // Replace child process with 'ls' command
        perror("\nexecvp failed\n");  // Execvp only returns if an error occurred
        exit(1);  // Exit child process if execvp fails
    } else {  // Parent process
        int status;
        wait(&status);  // Wait for the child process to finish
        if (WIFEXITED(status)) {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process did not exit successfully\n");
        }
    }

    return 0;
}
