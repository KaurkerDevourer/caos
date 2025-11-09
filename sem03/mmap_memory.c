#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdint.h>

int main() {
    const size_t SIZE = 1 << 20; // 1 Mb
    const size_t COUNT = SIZE / sizeof(uint32_t);

    uint32_t *nums = mmap(
        NULL,
        SIZE,
        PROT_READ | PROT_WRITE,
        MAP_PRIVATE | MAP_ANONYMOUS,
        -1,
        0
    );

    if (nums == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    for (size_t i = 0; i < COUNT; i++) {
        nums[i] = i;
    }

    uint64_t sum = 0;
    for (size_t i = 0; i < COUNT; i++) {
        sum += nums[i];
    }

    printf("Sum of numbers: %lu\n", sum);

    munmap(nums, SIZE);
    return 0;
}
