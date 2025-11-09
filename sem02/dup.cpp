#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2 failed");
        close(fd);
        return 1;
    }

    printf("This goes to output.txt!\n");

    close(fd);
    return 0;
}
