#include <stdio.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    
    if (fork() == 0) {
        close(fd1[1]); close(fd2[0]);
        int num;
        while (read(fd1[0], &num, sizeof(int)) > 0 && num < 10) {
            printf("Child: %d\n", num + 1);
            num++;
            write(fd2[1], &num, sizeof(int));
        }
    } else {
        close(fd1[0]); close(fd2[1]);
        int num = 1;
        printf("Parent: %d\n", num);
        write(fd1[1], &num, sizeof(int));
        
        while (read(fd2[0], &num, sizeof(int)) > 0 && num < 10) {
            printf("Parent: %d\n", num + 1);
            num++;
            write(fd1[1], &num, sizeof(int));
        }
    }
    return 0;
}
