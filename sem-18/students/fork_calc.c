/*
total_res = numbers[0] ^ numbers[1] ^ numbers[2] ... ^ numbers[n - 1] 
*/





#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 10
#define NUM_PROCESSES 5

int main() {
    bool numbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numbers[i] = (i + 1) % 2;
        printf("%d, ", numbers[i]);
    }
    printf("\n");
    
    int number_of_this_process = 0;
    
    int chunk_size = ARRAY_SIZE / NUM_PROCESSES;
    
    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            long local_res = 0;
            int start = i * chunk_size;
            int end = (i == NUM_PROCESSES - 1) ? ARRAY_SIZE : (i + 1) * chunk_size;
            while (start < end) {
                local_res ^= numbers[start++];
            }
            _exit(local_res); // Артёмов Михаил
        }
    }

    int count_of_processes = NUM_PROCESSES;
    
    long total_res = 0;
    while (count_of_processes != 0){
        --count_of_processes;
        int status;
        wait(&status);
        total_res ^= WEXITSTATUS(status);
    }
    
    printf("Res: %ld\n", total_res);
    return 0;
}
