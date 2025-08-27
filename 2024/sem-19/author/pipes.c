#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipe1[2], pipe2[2];
    pipe(pipe1);
    pipe(pipe2);
    
    if (fork() == 0) {
        close(pipe1[0]);
        close(pipe2[0]);
        close(pipe2[1]);
        dup2(pipe1[1], STDOUT_FILENO);
        execlp("cat", "cat", "../file.txt", NULL);
    }
    
    if (fork() == 0) {
        close(pipe1[1]);
        close(pipe2[0]);
        dup2(pipe1[0], STDIN_FILENO);
        dup2(pipe2[1], STDOUT_FILENO);
        execlp("grep", "grep", "error", NULL);
    }

    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[1]);
    dup2(pipe2[0], STDIN_FILENO);
    execlp("sort", "sort", NULL);
    
    return 0;
}
