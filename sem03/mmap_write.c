#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("output.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char *text = "Hello, mmap!";
    size_t size = strlen(text);
    ftruncate(fd, size);

    char *mapped = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    memcpy(mapped, text, size);

    msync(mapped, size, MS_SYNC);
    munmap(mapped, size);
    close(fd);
    return 0;
}
