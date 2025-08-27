#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/*
Напишите простой бесконечный тикер. Пусть он тикает раз в секунду.
*/

void hendler(int sig){
    alarm(1);
    printf("popa\n");
}

int main() {
    
    signal(SIGALRM, hendler);
    alarm(1);

    while(1) {
        pause();
    }
    
    return 0;
}
