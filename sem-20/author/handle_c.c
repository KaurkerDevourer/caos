#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("Нельзя завершить программу по Ctrl+C!\n");
}

int main() {
    signal(SIGINT, sigint_handler);

    printf("Программа работает. Используйте Ctrl+\\ для выхода\n");

    while(1) {
        pause();
    }

    return 0;
}
