/*
Создайте программу, которая выполняет конвейер из трех команд:
'cat file.txt | grep "error" | sort'
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Ваш код здесь
    int fd[2];

    pipe(fd);

    pid_t pd = fork();
    if (pd == 0){
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp("cat", "cat", "../file.txt", NULL);
    }


    int fddd[2];

    pipe(fddd);

    pid_t pdd = fork();
    if (pdd == 0){
        close(fddd[0]);

        dup2(fd[0], STDIN_FILENO);
        dup2(fddd[1], STDOUT_FILENO);
        close(fd[1]);
        close(fd[0]);
        close(fddd[1]);

        execlp("grep", "grep", "error", NULL);
    }


    pid_t pddd = fork();
    if (pddd == 0){
        close(fd[1]);
        close(fd[0]);
        close(fddd[1]);

        dup2(fddd[0], STDIN_FILENO);
        close(fddd[0]);

        execlp("sort", "sort", NULL);
    }

    

    return 0;
}
