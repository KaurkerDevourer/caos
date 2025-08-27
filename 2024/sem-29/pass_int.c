#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#define N 5


void *func(uintptr_t arg) {
    int i = (int)arg;

    printf("Got number: %d\n", i);

    return NULL;
}

int main() {
    pthread_t tids[N];

    for (int i = 0; i < N; ++i) {
        pthread_create(&tids[i], NULL, func, (uintptr_t)i);
    }

    for (int i = 0; i < N; ++i) {
        pthread_join(tids[i], NULL);

    }

    return 0;
}
