#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main() {
    /*
        Нужно заблокировать Cntl + C, чтобы мы не могли прервать программу пока она спит.
        Соответственно, потом нужно разблокировать чтобы завершить программу.
        Внутри цикла.
    */
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    
    while(true) {
        printf("sleep started\n");
        sigprocmask(SIG_BLOCK, &set, NULL);
        sleep(10);
        printf("sleep ended\n");
        sigprocmask(SIG_UNBLOCK, &set, NULL);
    }
    

    return 0;
}
