#include <stdlib.h>

int main() {
    int* x = (int*)malloc(sizeof(int));
    int y = *x;
    return y;
}
