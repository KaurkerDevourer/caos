#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_EVENTS 10
#define BUFFER_SIZE 1024
#define PORT 8083

int main() {
    int server_fd, epoll_fd;
    struct sockaddr_in addr;
    struct epoll_event ev, events[MAX_EVENTS];
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *) &addr, sizeof(addr));
    listen(server_fd, SOMAXCONN);

    epoll_fd = epoll_create1(0);
    ev.events = EPOLLIN | EPOLLET;
    ev.data.fd = server_fd;

    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &ev);

    printf("Сервер запущен на порту %d. Ожидание подключений...\n", PORT);

    while (1) {
        int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);

        for (int i = 0; i < nfds; i++) {
            if (events[i].data.fd == server_fd) {
                // while (1) {
                    
                    int client_fd = accept4(events[i].data.fd, NULL, NULL, SOCK_NONBLOCK);
                    // if (client_fd == -1){
                    //     break;
                    // }
                    printf("Новое подключение: fd=%d\n", client_fd);

                    ev.events = EPOLLIN | EPOLLET;
                    ev.data.fd = client_fd;
                    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &ev);
                // }
            } else {
                int readed;
                while ((readed = read(events[i].data.fd, buffer, BUFFER_SIZE)) > 0){
                    buffer[readed] = '\0';
                    printf("readed: %s\n", buffer);
                }
            }
        }
    }

    close(server_fd);
    return 0;
}
