#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 100000000
#define THREADS 4
#define CACHE_LINE 64

typedef struct {
    int sum;
    char padding[CACHE_LINE - sizeof(int)];
} ThreadSum;

int array[ARRAY_SIZE];
int partial_sums[16 * THREADS];

void *sum_part(void *arg) {
    int n = (int)arg;
    for (int i = n * ARRAY_SIZE / THREADS; i < (n + 1) * ARRAY_SIZE / THREADS; ++i) {
        partial_sums[16 * n] += array[i];
    }
    return NULL;
}

int main() {
    pthread_t tids[THREADS];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < THREADS; ++i) {
        pthread_create(&tids[i], NULL, sum_part, (void *)i);
    }

    for (int i = 0; i < THREADS; ++i) {
        pthread_join(tids[i], NULL);
    }

    int sum = 0;
    for (int i = 0; i < THREADS; ++i) {
        sum += partial_sums[16 * i];
    }

    printf("%d\n", sum);
    return 0;
}
