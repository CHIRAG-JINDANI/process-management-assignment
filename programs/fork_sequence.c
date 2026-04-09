#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: %s <positive integer>\n", argv[0]);
        exit(1);
    }

    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (!isdigit(argv[1][i])) {
            printf("error: input must be a positive integer\n");
            exit(1);
        }
    }

    int n = atoi(argv[1]);

    if (n <= 0) {
        printf("error: input must be greater than 0\n");
        exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
        printf("fork failed\n");
        exit(1);
    }

    else if (pid == 0) {
        printf("child pid: %d\n", getpid());
        printf("sequence: ");
        while (n >= 1) {
            printf("%d", n);
            if (n == 1) break;
            printf(", ");
            n = n / 2;
        }
        printf("\n");
        exit(0);
    }

    else {
        printf("parent pid: %d, child pid: %d\n", getpid(), pid);
        wait(NULL);
        printf("child finished. parent exiting.\n");
        exit(0);
    }
}

