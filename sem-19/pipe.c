#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2];

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0) {
        close(fd[0]);
        
        char name[] = "Alice";
        write(fd[1], name, strlen(name) + 1);
        
        close(fd[1]);
        _exit(0);
    } else {
        close(fd[1]);

        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("My child's name is: %s\n", buffer);
        
        close(fd[0]);
    }
    
    return 0;
}
