#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Enter one positive number\n");
        return 1;
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        printf("Number must be positive\n");
        return 1;
    }

    int pid = fork();

    if (pid == 0)   // child process
    {
        printf("Child PID: %d\n", getpid());

        printf("Sequence: ");
        while (n >= 1)
        {
            printf("%d ", n);
            n = n / 2;
        }

        printf("\n");
    }
    else            // parent process
    {
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        printf("Child finished\n");
    }

    return 0;
}
