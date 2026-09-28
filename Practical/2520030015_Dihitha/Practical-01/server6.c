#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO1 "client_to_server"
#define FIFO2 "server_to_client"

int main()
{
    char message[100];
    char response[100];

    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    printf("Server waiting for client...\n");

    int fd1 = open(FIFO1, O_RDONLY);

    read(fd1, message, sizeof(message));
    printf("Server received: %s\n", message);

    close(fd1);

    strcpy(response, "Message processed successfully.");

    int fd2 = open(FIFO2, O_WRONLY);
    write(fd2, response, strlen(response) + 1);
    close(fd2);

    printf("Server response sent.\n");

    unlink(FIFO1);
    unlink(FIFO2);

    return 0;
}
