#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/*
Напишите простой бесконечный тикер. Пусть он тикает раз в секунду.
*/

void handler(int x) {
    printf("Tick: %d\n", x);
}

int main() {

    signal(SIGALRM, &handler);
    alarm(1);

    while(1) {
        pause();
    }
    
    return 0;
}
