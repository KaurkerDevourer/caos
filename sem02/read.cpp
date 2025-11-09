#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("large_file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    char buf[4096];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, bytes_read);
    }

    if (bytes_read == -1) {
        perror("read failed");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
