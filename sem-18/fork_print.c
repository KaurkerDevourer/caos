#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    int a = 13;
    if (pid == 0) {
        printf("Child: a=%d;\n", a);
        a = 6;
        printf("Child: a=%d;\n", a);
    } else {
        printf("Parent: a=%d;\n", a);
        a = 14;
        printf("Parent: a=%d;\n", a);
        wait(NULL);
        printf("Parent: a=%d;\n", a);
    }

    return 0;

}
