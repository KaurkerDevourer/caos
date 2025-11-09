#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// void fork_bomb(int cnt) {
//     int pid = fork();
//     cnt += 1;

//     if (pid == -1) {
//         printf("%d\n", cnt);
//         return;
//     } 

//     fork_bomb(cnt + 1);
// }

int main() {
    int cnt = 0;
    
    while (1) {
        int pid = fork();
        cnt += 1;
        if (pid == -1) { 
            printf("%d\n", cnt);
            return 0;
        } else if (pid == 0) {
            break;
        } else {
            continue;
        }
    }
}
