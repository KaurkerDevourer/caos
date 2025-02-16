#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // COPY ON WRITE (COW)
    
    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }
    printf("Forked\n");

    if (pid == 0) {
        while(1) {
            printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
            sleep(1);
        }
    } else {
        while(1) {
            printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
            sleep(1);
        }

        wait(NULL);
    }

    return 0;
}
