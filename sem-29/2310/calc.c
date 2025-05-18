#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 1000
#define THREADS 4

int array[ARRAY_SIZE];
int partial_sums[THREADS];

void *sum_part(void *arg) {

}

int main() {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    return 0;
}
