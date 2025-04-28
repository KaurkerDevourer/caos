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
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in my_addr;
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    socklen_t size = sizeof(my_addr);
    if (connect(sock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1){
        perror("accept");
        return 1;
    };

    printf("Connected on port: %d\n", PORT);

    // read msg
    char* msg = "keril samokat";
    if (send(sock, msg, strlen(msg), 0) == -1) {
        perror("Send error");
        return 1;
    }

    char mesg[4096];
    ssize_t read_bytes = read(sock, mesg, 4096);
    if (read_bytes == -1){
        perror("read socket");
        return 1;
    }

    printf("Client received msg: %s\n", mesg);

    close(sock);
    return 0;
}
