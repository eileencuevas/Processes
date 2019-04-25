// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as
// `execl()`, `execle()`, `execv()`, and others. Why do you think there
// are so many variants of the same basic call?

// I guess which one you'd use depends on whether or not you know
// how many arguments you need in the function call

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    // Your code here

    pid_t pid = fork();

    if (pid == 0)
    {
        // child process

        // execl(const char *path, con char *arg, (char *) NULL)
        // execl("/bin/ls", "ls", "-l", (char *)NULL);

        // execv(const char *path, char *const argv[])
        char *args[] = {"ls", "-l", NULL};
        execv("/bin/ls", args);
    }
    else
    {
        // parent process
        printf("This is the parent process\n");
    }

    return 0;
}
