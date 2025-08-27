/* Создать программу, которая защищена от Ctrl+C и завершается только по Ctrl+\. Вызов Cntl+C должен печатать "Нельзя завершить программу по Ctrl+C!"*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ctrlc_handler(int sig) {
    printf("u cant kill me: %d\n", sig);
}

int main() {
    printf("Программа работает. Используйте Ctrl+\\ для выхода\n");

    signal(SIGINT, ctrlc_handler);
    signal(SIGQUIT, ctrlc_handler);

    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    while(1) {
        printf("sleep started\n");
        sigprocmask(SIG_BLOCK, &set, NULL);
        sleep(1);
        printf("sleep ended\n");
        sigprocmask(SIG_UNBLOCK, &set, NULL);
    }

    return 0;
}
