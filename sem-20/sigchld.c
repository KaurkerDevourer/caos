#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void handler(int n) {
    const char msg[] = "Got signal\n";
    write(STDOUT_FILENO, msg, sizeof(msg) - 1);
}

void child_handler(int n) {
    printf("Child got signal: %d\n", n);
}

int main() {
    int pid = fork();
    if (!pid) {
        printf("parent_pid: %d, child_pid: %d\n", getppid(), getpid());
        sleep(2);
        _exit(1);
    }

    signal(SIGCHLD, &child_handler);
    sleep(2);

    int status;
    if (waitpid(pid, &status, 0) == -1) {
        perror("");
        exit(1);
    }

    if (WIFEXITED(status)) {
        printf("Exit status: %d\n", WEXITSTATUS(status));
    }

    if (WIFSIGNALED(status)) {
        printf("Exit signal: %d\n", WTERMSIG(status));
    }

}
