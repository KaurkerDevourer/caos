#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// Задача 1: Обрезать файл до указанной длины, затем дописать в конец строку "TRUNCATED".
// Пример: файл "123456789", max_len=5 → "12345TRUNCATED".
void truncate_and_append(const char *filename, off_t max_len) {
    int fd = open(filename, O_RDWR | O_APPEND, 0666);
    if (fd == -1) {
        perror("Something went wrong");
        return;
    }
    
    if (ftruncate(fd, max_len) == -1) {
        close(fd);
        perror("Trunctating failed");
        return;
    } 

    const char* buf = "TRUNCATED";
    if (write(fd, buf, strlen(buf)) == -1) {
        close(fd);
        perror("Writing failed");
        return;
    }

    close(fd);
}

void reverse_file(const char *filename) {
    int fd = open(filename, O_RDONLY, 0666);
    if (fd == -1) {
        perror("file not found");
        return;
    }

    off_t offset = lseek(fd, 0, SEEK_END);
    if (offset == (off_t) -1) {
        close(fd);
        perror(":(");
        return;
    }

    while (offset != -1) {
        offset = lseek(fd, -1, SEEK_CUR);
        if (offset == -1) {
            close(fd);
            return;
        }

        char c;
        if (read(fd, &c, 1) == 0) {
            close(fd);
            perror(":(((");
            return;
        }

        if (write(STDOUT_FILENO, &c, 1) == -1) {
            close(fd);
            perror(":((((");
            return;
        }

        offset = lseek(fd, offset, SEEK_SET);

    }
}

// Задача 3: Прочитать каждый N-й символ из файла и вывести в stdout.
// Пример: файл "abcde", N=2 → "ace".
void read_every_nth_char(const char *filename, int n) {
    int fd = open(filename, O_RDWR, 0666);
    char c;
    while (read(fd, &c, 1) == 1) {
        write(STDOUT_FILENO, &c, 1);
        lseek(fd, n - 1, SEEK_CUR);
    }
}

void replace_chars_in_file(const char *filename, char from, char to){
    int fd = open(filename, O_RDWR, 0666);
    char c;
    while(read(fd, &c, 1) == 1){
        if (c == from){
            lseek(fd, -1, SEEK_CUR);
            c = to;
            write(fd, &c, 1);
        }
    }
    close(fd);
}

// Задача 5: Конкатенация файлов
// Написать функцию, которая добавляет содержимое второго файла в конец первого.
// Пример: файл1 "A", файл2 "B" → после concat_files("file1", "file2") → файл1 "AB".
// Использовать: open (O_APPEND), read, write.
void concat_files(const char *dest, const char *src) {
    int fd1 = open(dest, O_RDONLY, 0666);
    int fd2 = open(src, O_WRONLY | O_APPEND, 0666);
    char c;
    while (read(fd1, &c, 1) == 1) {
        write(fd2, &c, 1);
    }
    close(fd1);
    close(fd2);
}

int main() {
    // truncate_and_append("test.txt", 5);
    // reverse_file("test.txt");s
    //replace_chars_in_file("test.txt", 'd', 'g');
    concat_files("test.txt", "example.txt");
}
