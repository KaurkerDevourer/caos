#include <stdio.h>
#include <stdint.h>
#include <pthread.h>

#define ARRAY_SIZE 100000000
#define THREADS 4
#define CACHE_LINE_SIZE 64

typedef struct {
    int sum;
    char padding[CACHE_LINE_SIZE - sizeof(int)];
} ThreadSum;

int array[ARRAY_SIZE];
ThreadSum partial_sums[THREADS];

void *sum_part(uintptr_t arg) {
    int ind = (int)arg;
    for (int i = ind; i < ind + ARRAY_SIZE / THREADS; ++i) {
        partial_sums[ind / (ARRAY_SIZE / THREADS)].sum += array[i];
    }
    return NULL;
}

int main() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    pthread_t pth[THREADS];
    for (int i = 0; i < THREADS; ++i) {
        pthread_create(&pth[i], NULL, sum_part, (uintptr_t)(i * (ARRAY_SIZE / THREADS)));
    }

    for (int i = 0; i < THREADS; ++i) {
        pthread_join(pth[i], NULL);
    }

    int otvet = 0;
    for (int i = 0; i < THREADS; ++i) {
        otvet += partial_sums[i].sum;
    }

    printf("%d\n", otvet);


    return 0;
}
