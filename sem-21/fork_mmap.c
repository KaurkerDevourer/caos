#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Создаём общую память (анонимное отображение)
    size_t size = 4096; // 4 KB
    void *mapped = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (mapped == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    // Создаём дочерний процесс
    pid_t pid = fork();

    if (pid == 0) {
        // Дочерний процесс: записываем данные
        sprintf((char *)mapped, "Hello from child!");
        printf("Дочерний процесс записал данные.\n");
        _exit(0);
    } else {
        // Родительский процесс: ждём завершения дочернего и читаем данные
        wait(NULL);
        printf("Родительский процесс прочитал: %s\n", (char *)mapped);
    }

    // Освобождаем память
    munmap(mapped, size);
    return 0;
}
