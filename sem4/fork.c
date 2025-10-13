#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        printf("Родитель: PID = %d, PID ребёнка = %d\n", getpid(), pid);
    } else if (pid == 0) {
        printf("Ребёнок: PID = %d\n", getpid());
    } else {
        perror("fork() failed");
    }
    
    return 0;
}
