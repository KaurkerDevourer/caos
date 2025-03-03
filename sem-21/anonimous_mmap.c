#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main() {
    // Создаём анонимное отображение (без файла)
    size_t size = 4096; // 4 KB
    void *mapped = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Работаем с отображённой памятью
    sprintf((char *)mapped, "Hello, mmap!"); // Записываем данные
    printf("Содержимое памяти: %s\n", (char *)mapped);

    // Освобождаем память
    munmap(mapped, size);
    return 0;
}
