#include <stdio.h>

void sq(int a, double b, double* c) {
    *c = a * a + b * b;
    return;
}

int main() {
    double a, b;
    scanf("%lf", &a);
    scanf("%lf", &b);

    double c;

    sq(a, b, &c);
    printf("My:\t%lf\n", c);
    return 0;
}
