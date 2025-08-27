#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum) {
    printf("\nВремя вышло!\n");
    _exit(1);
}

int main() {
    signal(SIGALRM, handler);
    
    printf("У вас есть 5 секунд чтобы ввести число: ");
    alarm(5);
    
    int number;
    scanf("%d", &number);

    printf("Спасибо! Вы ввели: %d\n", number);
    
    alarm(0);
    sleep(20);
    
    return 0;
}
