#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int status;
    char* params[] = {"echo", "array!", NULL};
    char* envs[] = {"PWD=hello", "Hi=2", NULL};
    // status = execl("/usr/bin/echo", "echo", "hello world", NULL);
    // printf("%d\n", status);

    status = execlp("sleep", "awake", "1000", NULL);


    // status = execv("/usr/bin/echo", params);
    // printf("%d\n", status);

    // status = execvp("echo", params);

    // status = execle("/usr/bin/printenv", "printenv", NULL, envs);
}
