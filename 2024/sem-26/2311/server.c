#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8085

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in  my_addr;
    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bind(fd, (struct sockaddr *) &my_addr, sizeof(my_addr));
    listen(fd, 2311);
    int sz_addr = sizeof(my_addr);
    int client_fd = accept(fd, (struct sockaddr *) &my_addr, (socklen_t*)&sz_addr);

    char t[1024];
    read(client_fd, &t, 1024);
    printf("%s\n", t);

    char* ans = "Hi, ";
    send(client_fd, ans, sizeof(ans), 0);
    send(client_fd, t, strlen(t), 0);

    close(client_fd);
    close(fd);
}
