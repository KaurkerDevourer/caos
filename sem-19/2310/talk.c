#include <stdio.h>
#include <unistd.h>

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

    int fdP[2];
    pipe(fdP);

    int fdC[2];
    pipe(fdC);

    int i = 1;

    pid_t pd = fork();
    
    if (pd == 0) {
        close(fdP[1]);
        close(fdC[0]);
        while (i <= 20) {
            read(fdP[0], &i, sizeof(int));
            i++;
            printf("Child: %d\n", i);
            write(fdC[1], &i, sizeof(int));
        }
        close(fdP[0]);
        close(fdC[1]);
        
    } else {
        close(fdC[1]);
        close(fdP[0]);
        printf("Parent: %d\n", i);

        write(fdP[1], &i, sizeof(int));

        while (i <= 20) {
            read(fdC[0], &i, sizeof(int));
            i++;
            printf("Parent: %d\n", i);
            write(fdP[1], &i, sizeof(int));
        }  

        close(fdC[0]);
        close(fdP[1]); 
    }
    
}
