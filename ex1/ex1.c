// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?
// Answer: both the child and parent processes have their own copy of x, and manage to change their own copy of x during execution

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    // Your code here

    int var_to_change = 100; // initialize this int as 100

    printf("Starting var: %d\n", var_to_change);

    pid_t pid = fork();
    // child process starts executing here

    if (pid == 0) // child variable satisfies this branch
    {
        var_to_change = 50; // change the variable in some way
        printf("Child process with pid: %d, your variable is now %d\n", pid, var_to_change);
    }
    else
    {
        var_to_change = 25; // change the variable in some way
        printf("Parent process with pid: %d, your variable is now %d\n", pid, var_to_change);
    }

    return 0;
}
