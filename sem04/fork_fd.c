#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("file.txt", O_WRONLY | O_CREAT, 0644);
    write(fd, "Родитель\n", 9);

    pid_t pid = fork();

    if (pid == 0) {
        write(fd, "Ребёнок\n", 8);
        close(fd);
    } else {
        wait(NULL);
        close(fd);
    }

    return 0;
}
