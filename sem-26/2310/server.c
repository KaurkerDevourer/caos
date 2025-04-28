#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PORT 8081

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket otvalilsa");
        return 1;
    }

    // Для переиспользования порта
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *) &my_addr, sizeof(my_addr)) == -1) {
        perror("bind otvalilsa");
        return 1;
    }

    printf("Waiting for connections on port: %d\n", PORT);
    
    // message queue size = 3
    if (listen(sock, 3) == -1){
        perror("listen");
        return 1;
    }

    socklen_t size = sizeof(my_addr);
    int client_socket;
    client_socket = accept(sock, (struct sockaddr*)&my_addr, &size);
    if (client_socket == -1){
        perror("accept");
        return 1;
    };

    // read msg
    char msg[4096];
    ssize_t read_bytes = read(client_socket, msg, 4096);
    if (read_bytes == -1){
        perror("read socket");
        return 1;
    }

    printf("receive msg: %s\n", msg);

    char* mesg = "anton samolet";
    if (send(client_socket, mesg, strlen(mesg), 0) == -1) {
        perror("Send error");
        return 1;
    }

    close(client_socket);
    close(sock);
    return 0;
}
