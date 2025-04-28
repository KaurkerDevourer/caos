#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8085

void listen_server(int fd) {
    int pid = fork();

    if (pid == 0) {
        while (1) {
            char t[1024];
            int e = read(fd, &t, sizeof(t));

            if (e == -1) {
                perror("read\n");
                break;
            }

            if(e == 0) {
                continue;
            }

            printf("%s\n", t);
        }
    }
}

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in my_addr;
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);

    socklen_t sz_addr = sizeof(my_addr);
    connect(fd, (struct sockaddr *) &my_addr, sz_addr);
    listen_server(fd);

    char* str = "test";
    send(fd, str, sizeof(str), 0);

    close(fd);
    wait(NULL);
}
