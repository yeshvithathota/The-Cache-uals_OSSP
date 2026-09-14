#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char command[100];

    printf("Enter Linux command: ");
    scanf("%s", command);

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
    }
    else if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());

        execlp(command, command, NULL);

        printf("Command execution failed\n");
    }
    else
    {
        printf("Parent PID: %d\n", getpid());

        wait(NULL);

        printf("Child process completed\n");
    }

    return 0;
}
