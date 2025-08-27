#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

int tty_fd;

void handle_input(int signo) {
    char c;
    read(tty_fd, &c, 1);
    printf("Key pressed: %c\n", c);
}

int main() {
    struct termios term;

    tty_fd = open("/dev/tty", O_RDONLY);
    if (tty_fd == -1) {
        perror("Cannot open /dev/tty");
        return 1;
    }

    tcgetattr(tty_fd, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(tty_fd, TCSANOW, &term);

    signal(SIGIO, handle_input);
    fcntl(tty_fd, F_SETOWN, getpid());
    fcntl(tty_fd, F_SETFL, fcntl(tty_fd, F_GETFL) | FASYNC);

    printf("Press keys (Ctrl+C to exit)...\n");

    while(1) {
        pause();
    }

    close(tty_fd);
    return 0;
}
