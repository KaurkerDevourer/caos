#include <stdio.h>
#include <time.h>

void print(unsigned num) {
    clock_t t;

    t = clock();

    for (unsigned i = 0; i != num; ++i) {
        printf("hello, num %u", i);
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    fprintf(stderr, "%f seconds\n", time_taken);
}

int main() {

    unsigned iters = 10000000;

    // 0.75 секунды
    print(iters);

    // Устанавливаем пустой буфер, тем самым отключая буферизацию
    setbuf(stdout, NULL);

    // 11 секунды
    print(iters);

}
