#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t child1, child2;
    int status;

    printf("Parent PID: %d\n", getpid());

    child1 = fork();

    if (child1 == 0)
    {
        printf("Child 1 PID: %d\n", getpid());
        sleep(2);
        printf("Child 1 completed.\n");
        exit(0);
    }

    child2 = fork();

    if (child2 == 0)
    {
        printf("Child 2 PID: %d\n", getpid());
        sleep(3);
        printf("Child 2 completed.\n");
        exit(0);
    }

    printf("Parent created Child 1: %d\n", child1);
    printf("Parent created Child 2: %d\n", child2);

    printf("\nUsing waitpid() for Child 1...\n");
    waitpid(child1, &status, 0);
    printf("Child 1 has been collected.\n");

    printf("\nUsing wait() for Child 2...\n");
    wait(&status);
    printf("Child 2 has been collected.\n");

    printf("\nAll child processes completed.\n");

    return 0;
}
