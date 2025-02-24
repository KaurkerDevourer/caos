/* Создать программу, которая защищена от Ctrl+C и завершается только по Ctrl+\. Вызов Cntl+C должен печатать "Нельзя завершить программу по Ctrl+C!"*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int){
    printf("Нельзя завершить программу по Ctrl+C!\n");
}

int main() {
    printf("Программа работает. Используйте Ctrl+\\ для выхода\n");

    signal(SIGINT, &handler);

    while(1) {
        pause();
    }

    return 0;
}
