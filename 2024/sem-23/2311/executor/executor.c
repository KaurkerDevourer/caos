#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int processor_pid, collector_pid;

int call(char* proc){
    int pid = fork();
    if(pid == 0){
        execl(proc, proc, NULL);
        printf("err run execl");
    }
    return pid;
}

void handle(int signum){
    kill(processor_pid, signum);
    kill(collector_pid, signum);

    if(signum == SIGINT){
        printf("success!\n");
        exit(0);
    }
}

int main() {
    processor_pid = call("./processor/processor");
    collector_pid = call("./collector/collector");
    signal(SIGINT, handle);
    
    sigset_t empty;
    while(1){
        sigemptyset(&empty);
        sigsuspend(&empty);
    }

    return 0;
}
