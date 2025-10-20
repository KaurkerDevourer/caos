#include <stdio.h>

extern int asm_sum_and_swap(int* a, int* b);

int main() {
    int x = 10;
    int y = 20;

    printf("Before: x = %d, y = %d\n", x, y);

    int sum = asm_sum_and_swap(&x, &y);

    printf("After:  x = %d, y = %d\n", x, y);
    printf("Sum returned from asm: %d\n", sum);

    return 0;
}
