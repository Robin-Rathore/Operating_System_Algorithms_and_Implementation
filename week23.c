// This program creates a file and stores your details in it. 
// It then creates a second file to store your friend's details. 
// After both files are created, the program compares them and prints any matching lines found in both files.


// 1. File Types and Hierarchy:

//     Standard C File Handling: In C, file handling primarily deals with regular files, which can be created, opened, read from, written to, and closed using standard library functions like fopen(), fread(), fwrite(), and fclose().
//     OS File Operations: The OS interacts with different file types (e.g., regular files, directories, symbolic links, devices) and maintains a hierarchy of files and directories. System calls (like open(), read(), write(), mkdir(), rmdir()) allow for more advanced operations, such as managing directories, handling permissions, and performing atomic operations.
// In summary, while standard C file handling provides a higher-level, more user-friendly interface for file operations, OS-level file operations allow for finer control and management of files and directories, making them suitable for applications that require direct interaction with the operating system's file system. Understanding both methods is important for developing robust applications that handle files efficiently and safely.
#include <stdio.h>
#include <string.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>


int main() {
    
    return 0;
}
