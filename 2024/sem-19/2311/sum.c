#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 1000000
#define NUM_PROCESSES 10

int main() {
    long long numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = i;
    }
    int fd[NUM_PROCESSES][2];
    for (size_t i = 0; i < NUM_PROCESSES; i++) {
        pipe(fd[i]);
    }
    int chunk_size = ARRAY_SIZE / NUM_PROCESSES;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (fork() == 0) {
            close(fd[i][0]);

            int start = i * chunk_size;
            int end = (i == NUM_PROCESSES - 1) ? ARRAY_SIZE : (i + 1) * chunk_size;
            long long res = 0;
            for (int j = start; j < end; j++) {
                res += numbers[j];
            }
            write(fd[i][1], &res, sizeof(res));
            close(fd[i][1]);

            _exit(0);
        }
    }
    
    long long total_res = 0;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        long long res;
        read(fd[i][0], &res, sizeof(res));
        total_res += res;
        close(fd[i][0]);
        close(fd[i][1]);
    }

    printf("Res: %lld\n", total_res);
    return 0;
}
