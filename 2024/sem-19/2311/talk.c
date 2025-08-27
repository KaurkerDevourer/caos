#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main() {
    /*
        Реализуйте считалку, в которой создается дочерний процесс,
        и родительский по очереди с ним считает от 1 до 10.
        Вывод должен выглядеть так:
        Parent: 1
        Child: 2
        Parent: 3
        Child: 4
        ...
    */
    int fd[2];
    int fd2[2];
    pipe(fd);
    pipe(fd2);
    int count = 1;
    pid_t id = fork();
    if (id == 0) {
        while(true) {
            int cur;
            read(fd[0], &cur, sizeof(cur));
            cur += 1;
            if (cur > 20) {
                break;
            }
            printf("Child: %d\n", cur);
            write(fd2[1], &cur, sizeof(cur));
        }

        
        close(fd2[0]);
        close(fd2[1]);
        close(fd[0]);
        close(fd[1]);
        
    } else {
        printf("Parent: 1\n");
        write(fd[1], &count, sizeof(count));
        
        while(true) {
            int cur;
            read(fd2[0], &cur, sizeof(cur));
            cur += 1;
            if (cur > 20) {
                break;
            }
            printf("Parent: %d\n", cur);
            write(fd[1], &cur, sizeof(cur));
        }

        close(fd2[0]);
        close(fd2[1]);
        close(fd[0]);
        close(fd[1]);
    }
}
