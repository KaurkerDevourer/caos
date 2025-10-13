#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("123\n");
    pid_t pid = fork();

    if (pid == 0) {
        printf("Дочерний процесс\n");
        // Что использовать: exit() или _exit()?
        exit(0);
    } else {
        printf("Родительский процесс\n");
    }

    return 0;
}
