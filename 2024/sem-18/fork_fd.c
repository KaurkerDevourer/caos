#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    char buffer[10];
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        close(fd);
        return 1;
    }

    if (pid == 0) {
        int n = read(fd, buffer, 5);
        buffer[n] = '\0';
        printf("Child read: %s\n", buffer);
        
        close(fd);
        _exit(1);
    } else {
        int n = read(fd, buffer, 5);
        buffer[n] = '\0';
        printf("Parent read: %s\n", buffer);
        int status;
        wait(&status);
        printf("%d\n", WEXITSTATUS(status));
        close(fd);
    }

    return 0;
}
