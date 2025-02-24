#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

int main() {
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    while(true) {
        sigprocmask(SIG_BLOCK, &set, NULL);
        printf("sleep started\n");
        sleep(10);
        printf("sleep ended\n");
        sigprocmask(SIG_UNBLOCK, &set, NULL);
    }

    return 0;
}
