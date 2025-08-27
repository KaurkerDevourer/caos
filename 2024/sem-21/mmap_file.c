#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    const char *filename = "example.txt";
    int fd = open(filename, O_RDWR); // Открываем файл
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Получаем размер файла
    off_t file_size = lseek(fd, 0, SEEK_END);

    // Отображаем файл в память
    char *mapped = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        close(fd);
        return 1;
    }

    // Работаем с файлом как с массивом байт
    printf("Содержимое файла: %s\n", mapped);

    // Закрываем отображение
    munmap(mapped, file_size);
    close(fd);
    return 0;
}
