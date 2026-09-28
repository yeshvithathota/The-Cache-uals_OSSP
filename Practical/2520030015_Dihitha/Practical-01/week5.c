#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        close(pipefd[1]);

        read(pipefd[0], buffer, sizeof(buffer));

        printf("Child (Consumer) received: %s\n", buffer);

        close(pipefd[0]);
    }
    else
    {
        close(pipefd[0]);

        strcpy(buffer, "Hello from Parent Producer!");

        write(pipefd[1], buffer, strlen(buffer) + 1);

        printf("Parent (Producer) sent: %s\n", buffer);

        close(pipefd[1]);

        wait(NULL);

        printf("\nExecuting: ls -l | grep \".c\"\n\n");

        int pipe2[2];
        pipe(pipe2);

        pid_t p1 = fork();

        if (p1 == 0)
        {
            close(pipe2[0]);
            dup2(pipe2[1], STDOUT_FILENO);
            close(pipe2[1]);

            execlp("ls", "ls", "-l", NULL);
            perror("exec ls");
            exit(1);
        }

        pid_t p2 = fork();

        if (p2 == 0)
        {
            close(pipe2[1]);
            dup2(pipe2[0], STDIN_FILENO);
            close(pipe2[0]);

            execlp("grep", "grep", ".c", NULL);
            perror("exec grep");
            exit(1);
        }

        close(pipe2[0]);
        close(pipe2[1]);

        waitpid(p1, NULL, 0);
        waitpid(p2, NULL, 0);

        printf("\nPipeline execution completed.\n");
    }

    return 0;
}
