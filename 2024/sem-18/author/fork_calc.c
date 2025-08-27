#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000000
#define NUM_PROCESSES 5

int main() {
    bool numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = (i + 1) % 2;
    }

    int chunk_size = ARRAY_SIZE / NUM_PROCESSES;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (fork() == 0) {
            int start = i * chunk_size;
            int end = (i == NUM_PROCESSES - 1) ? ARRAY_SIZE : (i + 1) * chunk_size;
            bool res = 0;
            for (int j = start; j < end; j++) {
                res ^= numbers[j];
            }
            _exit(res);
        }
    }

    long total_res = 0;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int status;
        wait(&status);
        total_res ^= WEXITSTATUS(status);
    }

    printf("Res: %ld\n", total_res);
    return 0;
}
