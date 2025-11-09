#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
    int fd = open("data.bin", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open failed");
        return 1;
    }

    if (write(fd, "ABCDEFGHIJ", 10) != 10) {
        perror("write failed");
        close(fd);
        return 1;
    }

    if (lseek(fd, 5, SEEK_SET) == -1) {
        perror("lseek failed");
        close(fd);
        return 1;
    }

    if (write(fd, "X", 1) != 1) {
        perror("write failed");
        close(fd);
        return 1;
    }

    if (ftruncate(fd, 7) == -1) {
        perror("ftruncate failed");
        close(fd);
        return 1;
    }

    close(fd);
    printf("File modified successfully.\n");
    return 0;
}
