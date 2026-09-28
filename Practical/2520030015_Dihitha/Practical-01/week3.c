#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    printf("Parent Process\n");
    printf("Parent PID: %d\n", getpid());
    printf("Parent PPID: %d\n", getppid());
    printf("Parent State: Running\n");

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed.\n");
        return 1;
    }

    if (pid == 0)
    {
        printf("\nChild Process\n");
        printf("Child PID: %d\n", getpid());
        printf("Child PPID: %d\n", getppid());
        printf("Child State: Running\n");

        sleep(2);

        printf("Child State: Terminated\n");
    }
    else
    {
        printf("\nParent Process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        printf("Parent State: Waiting\n");

        wait(NULL);

        printf("Parent State: Running\n");
        printf("Child has terminated.\n");
    }

    return 0;
}
