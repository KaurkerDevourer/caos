#include <stdio.h>

int main() {
    int n = 10;
    float a[10] = {1000001, 1000002, 1000003, 1000004, 1000005, 1000006, 1000007, 1000008, 1000009, 1000010};

    // avg = sum[i] / i -> * i

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum = (sum * i + a[i]) / (i + 1);
    }
    printf("%f\n", sum);


    sum = 0;
    for (int i = 0; i < n; i++) {
        sum = sum / (i + 1) * i + a[i] / (i + 1);
    }
    printf("%f\n", sum);
}
