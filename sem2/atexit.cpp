#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void bye() { printf("\nBye!\n"); }

int main() {
    atexit(bye);

    // char s[10];
    // scanf("%s", &s[0]);
    printf("hello from main");

    _exit(0);
}
