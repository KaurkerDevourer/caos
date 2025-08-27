#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int counter = 1;
    pid_t pid = 0;
          
    while (pid != -1) {
        ++counter;
        pid = fork();
        if (pid == -1) {
            perror("error");
        }

        if (pid == 0) {
            break;
        }
    }

    if (pid > 0) {
        wait(NULL);
    }
    if (pid == -1) {
        printf("%d\n", counter);
    }
    
    return 0;
}  
