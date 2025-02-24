#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

void timer_handler(int signum) {
    static int count = 0;
    printf("Тик! (%d)\n", ++count);
}

int main() {
    struct itimerval timer;
    signal(SIGALRM, timer_handler);
    
    // Сигнал каждую секунду
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 4;
    timer.it_value.tv_usec = 0;
    
    setitimer(ITIMER_REAL, &timer, NULL);
    
    while(1) {
        pause();
    }
    
    return 0;
}
