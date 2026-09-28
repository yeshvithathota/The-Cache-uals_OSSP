#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    char command[20];

    printf("Enter command: ");
    scanf("%s", command);

    int pid = fork();

    if (pid == 0)
    {
        printf("Child PID: %d\n", getpid());
        execlp(command, command, NULL);
    }
    else
    {
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        printf("Child completed\n");
    }

    return 0;
}
