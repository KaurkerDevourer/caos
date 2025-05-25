#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void* func(void*) {
    int fd = open("output.txt", O_CREAT | O_RDWR);
    write(fd, "hello\n\0", 8);
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, func, NULL);
    // pthread_join(tid, NULL);
}
