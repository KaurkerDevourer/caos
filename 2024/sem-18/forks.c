#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // 1 -> 2
    printf("pid is %d\n", pid);
    pid_t pid2 = fork(); // 2 -> 4
    printf("pid2 is %d\n", pid2);
    pid_t pid3 = fork(); // 4 -> 8
    printf("pid3 is %d\n", pid3);
    printf("Current pid is %d\n", getpid());
}
