#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    char filename[] = "test.txt";
    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    // dup2(fd, STDOUT_FILENO);
    printf("Hi there\n");
}
