#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <time.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    const char* shm_name = "/collector_shm";
    const char* sem_name = "/collector_sem";
    int shm_size = sizeof(int);

    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    printf("%d\n", shm_size);
    ftruncate(shm_fd, shm_size);

    int* data = (int*)mmap(0, shm_size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    sem_t* sem = sem_open(sem_name, O_CREAT, 0666, 1);

    int i = 0;
    while(1) {
        // sem_wait(sem);
        // data->timestamp = time(NULL);
        *data = i++;
        // printf("%d\n", data->value);
        // sem_post(sem);
        sleep(1);
    }

    munmap(data, shm_size);
    close(shm_fd);
    shm_unlink(shm_name);
    sem_close(sem);

    return 0;
}
