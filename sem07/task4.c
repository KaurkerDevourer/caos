#include <stdio.h>

extern long long sum_seven_args(
    long long a, long long b, long long c, long long d,
    long long e, long long f, long long g
);

int main() {
    printf("Calling assembly function with 1, 2, 3, 4, 5, 6, 7...\n");

    long long result = sum_seven_args(1, 2, 3, 4, 5, 6, 7);

    printf("Result from assembly: %lld\n", result);

    return 0;
}
