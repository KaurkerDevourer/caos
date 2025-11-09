#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int x = 42;
    pid_t pid = fork();

    if (pid == 0) {
        x = 100;
        printf("Ребёнок: x = %d\n", x);
    } else {
        wait(NULL);
        printf("Родитель: x = %d\n", x);
    }

    return 0;
}
