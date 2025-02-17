/*
Создайте программу, которая выполняет конвейер из трех команд:
'cat file.txt | grep "error" | sort'
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("cat", "cat", "../file.txt", NULL);
    }

    int fd2[2];
    pipe(fd2);
    pid = fork();

    if (pid == 0) {
        dup2(fd[0], STDIN_FILENO);
        dup2(fd2[1], STDOUT_FILENO);
        close(fd[1]);
        close(fd[0]);
        close(fd2[1]);
        close(fd2[0]);

        execlp("grep", "grep", "error", NULL);
    }

    dup2(fd2[0], STDIN_FILENO);
    close(fd[1]);
    close(fd[0]);
    close(fd2[1]);
    close(fd2[0]);

    execlp("sort", "sort", NULL);

    return 0;
}
