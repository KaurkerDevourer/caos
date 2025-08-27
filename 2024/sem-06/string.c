#include <stdio.h>
#include <string.h>

int main() {

    char input[9];
    char password[9] = "password";

    // Чтобы избежать ошибки, нужно всегда указывать в scanf размер ввода:
    // scanf("%8s", input);
    scanf("%8s", input);

    // echo -e 'aaaaaaaa\0aaaaaaaa\0'
    if (strcmp(input, password) == 0) {
        printf("Access granted\n");
    } else {
        printf("Access denied\n");
    }

    printf("%s", password);

}
