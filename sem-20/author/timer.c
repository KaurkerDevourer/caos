#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("Тик!\n");
    alarm(1);  // Перезапускаем таймер
}

int main() {
    signal(SIGALRM, handler);
    alarm(1);  // Первый запуск таймера
    
    while(1) {
        pause();  // Ждем сигнал
    }
    
    return 0;
}
