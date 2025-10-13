#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define MMAP_THRESHOLD 1024

typedef struct {
    void *ptr;
    size_t size;
    bool is_mmap;
} Block;

int main() {
    int *small = mmap_alloc(100 * sizeof(int));
    int sum = 0;
    for (int i = 0; i < 100; i++) small[i] = i;
    for (int i = 0; i < 100; i++) sum += small[i];
    printf("%d\n", sum);
    mmap_free(small, 100 * sizeof(int));

    int *large = mmap_alloc(2000 * sizeof(int));
    sum = 0;
    for (int i = 0; i < 2000; i++) large[i] = i;
    for (int i = 0; i < 2000; i++) sum += large[i];
    printf("%d\n", sum);
    mmap_free(large, 2000 * sizeof(int));

    return 0;
}
