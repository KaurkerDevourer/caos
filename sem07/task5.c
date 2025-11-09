#include <stdio.h>

void print_seven_args(
    long long a, long long b, long long c, long long d,
    long long e, long long f, long long g
) {
    printf("C function received:\n");
    printf("  a = %lld (from RDI)\n", a);
    printf("  b = %lld (from RSI)\n", b);
    printf("  c = %lld (from RDX)\n", c);
    printf("  d = %lld (from RCX)\n", d);
    printf("  e = %lld (from R8)\n", e);
    printf("  f = %lld (from R9)\n", f);
    printf("  g = %lld (from Stack)\n", g);
}
