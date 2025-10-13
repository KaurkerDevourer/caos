#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int status = 123123;
    char* params[] = {"echo", "array!", NULL};
    char* envs[] = {"PWD=hello", "Hi=2", NULL};
    pid_t pid = fork();
    if (pid == 0) {
        status = execl("/usr/bin/echo", "echo", "hello world", NULL);
    } else {
        wait(NULL);
    }
    printf("%d\n", status);
    // printf("123!\n");
    // status = execlp("sleep", "awake", "1000", NULL);

    pid = fork();
    if (pid == 0) {
        status = execv("/usr/bin/echo", params);
    } else {
        wait(NULL);
    }
    printf("%d\n", status);

    // status = execvp("echo", params);

    // status = execle("/usr/bin/printenv", "printenv", NULL, envs);
}
