#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

pid_t collector = 0;
pid_t processor = 0;

void sigint_handler(int sig_id) {
    kill(collector, sig_id);
    kill(processor, sig_id);
}

int main() {
    signal(SIGINT, sigint_handler);

    collector = fork();
    if (collector == 0) {
        int err = execl("collector/collector", NULL);
        printf("%d\n", err);

        return 1;
    }
    
    processor = fork();
    if (processor == 0) {
        int err = execl("processor/processor", NULL);
        printf("%d\n", err);

        return 1;
    }

    waitpid(processor, NULL, 0);
    waitpid(collector, NULL, 0);
 
    return 0;
}
