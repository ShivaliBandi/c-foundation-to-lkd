#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];

    // Create pipe
    if (pipe(fd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // Child Process
    if (pid == 0)
    {
        char buffer[100];

        // Child only reads
        close(fd[1]);

        int n = read(fd[0], buffer, sizeof(buffer) - 1);

        if (n == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[n] = '\0';

        printf("Child received: %s\n", buffer);

        close(fd[0]);
    }

    // Parent Process
    else
    {
        char *msg = "Hello Child from Parent";

        // Parent only writes
        close(fd[0]);

        if (write(fd[1], msg, strlen(msg)) == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }

        close(fd[1]);

        wait(NULL);
    }

    return 0;
}