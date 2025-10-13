#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = open("test.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    char text[200];
    for (size_t i = 0; i < 200; i++) {
        text[i] = 'j';
    }
    ssize_t bytes_written = write(fd, text, 200);
    if (bytes_written == -1) {
        perror("write failed");
        close(fd);
        return 1;
    }

    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }

    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    char buf[100];
    for (size_t i = 0; i < 100; i++) {
        buf[i] = 'i';
    }
    ssize_t bytes_read = read(fd, buf, 100);
    if (bytes_read == -1) {
        perror("read failed");
        close(fd);
        return 1;
    }

    buf[bytes_read] = '\0';
    printf("Read: %s", buf);

    if (close(fd) == -1) {
        perror("close failed");
        return 1;
    }

    return 0;
}
