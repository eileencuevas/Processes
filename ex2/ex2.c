// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor
// returned by `fopen()`? What happens when they are written to the file concurrently?

// both the parent and child could access the opened file.
// Both processes managed to write something to the file;
// the parent process first followed by the child.
// Both strings written to the file appeared in text.txt after the termination of the processes.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    // Your code here

    FILE *textfile = fopen("text.txt", "r+"); // opens the file for reading/writing
    printf("text.txt opened.\n");

    int pid = fork(); // fork
    // child processes starts here

    if (pid > 0)
    {
        // parent process
        printf("Parent process #%d, writing to file.\n", pid);
        fprintf(textfile, "%s\n", "Written by Parent process");
    }
    else
    {
        // child process
        printf("Child process #%d, writing to file.\n", pid);
        fprintf(textfile, "%s\n", "Written by Child process");
    }

    fclose(textfile); // close the file

    return 0;
}
