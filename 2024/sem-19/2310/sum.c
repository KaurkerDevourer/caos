#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 5000
#define NUM_PROCESSES 5

int main() {
    int numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = i;
    }

    int chunk_size = ARRAY_SIZE / NUM_PROCESSES;

    int pipes[NUM_PROCESSES][2];

    for (int i = 0; i<NUM_PROCESSES; ++i){
        pipe(pipes[i]);
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (fork() == 0) {
            close(pipes[i][0]);
            int start = i * chunk_size;
            int end = (i == NUM_PROCESSES - 1) ? ARRAY_SIZE : (i + 1) * chunk_size;
            int res = 0;
            for (int j = start; j < end; j++) {
                res += numbers[j];
            }

            write(pipes[i][1], &res,sizeof(res));
            close(pipes[i][1]);
            _exit(0);
        }
        close(pipes[i][1]);
    }

    long total_res = 0;
    for (int i = 0; i < NUM_PROCESSES; i++) {
        int cur = 0;
        read(pipes[i][0],&cur,sizeof(cur));
        total_res += cur;
        close(pipes[i][0]);
    }

    printf("Res: %ld\n", total_res);
    return 0;
}
