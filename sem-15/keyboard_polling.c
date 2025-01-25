#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("/dev/tty", O_RDONLY);
    if (fd == -1) {
        perror("Cannot open /dev/tty");
        return 1;
    }

    struct termios old_term, new_term;
    tcgetattr(fd, &old_term);
    new_term = old_term;
    new_term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(fd, TCSANOW, &new_term);

    printf("Press keys (Ctrl+C to exit)...\n");

    char c;
    while (read(fd, &c, 1) > 0) {
        printf("Key pressed: %d\n", (int)c);
    }

    tcsetattr(fd, TCSANOW, &old_term);
    close(fd);
    return 0;
}
