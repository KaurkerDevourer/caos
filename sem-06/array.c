#include <stdio.h>

int a[100];

int main() {
    int n;
    scanf("%d", &n);
    // int a[n];
    // for (size_t i = 0; i < n; i++) {
    //     a[i] = 0;
    // }
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += a[i];
        printf("%ld\t", i);
    }
    printf("%d\n", sum);
}
