#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    off_t size = lseek(fd, 0, SEEK_END);

    char *mapped = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    printf("File content:\n%.*s\n", (int)size, mapped);

    munmap(mapped, size);
    close(fd);
    return 0;
}
