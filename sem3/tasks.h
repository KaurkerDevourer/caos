#include <unistd.h>
#include <fcntl.h>

// Задача 1: Обрезать файл до указанной длины, затем дописать в конец строку "TRUNCATED".
// Пример: файл "123456789", max_len=5 → "12345TRUNCATED".
void truncate_and_append(const char *filename, off_t max_len);

// Задача 2: Чтение файла задом наперёд
// Написать функцию, которая читает файл и выводит его содержимое в обратном порядке.
// Пример: файл "abcde" → "edcba".
// Использовать: open, read, lseek, write.
void reverse_file(const char *filename);

// Задача 3: Прочитать каждый N-й символ из файла и вывести в stdout.
// Пример: файл "abcde", N=2 → "ace".
void read_every_nth_char(const char *filename, int n);

// Задача 4: Заменить все вхождения символа 'A' на 'B' в файле.
void replace_chars_in_file(const char *filename, char from, char to);

// Задача 5: Конкатенация файлов
// Написать функцию, которая добавляет содержимое второго файла в конец первого.
// Пример: файл1 "A", файл2 "B" → после concat_files("file1", "file2") → файл1 "AB".
// Использовать: open (O_APPEND), read, write.
void concat_files(const char *dest, const char *src);

// Задача 6: Найти все вхождения слова в файле (без чтения построчно).
// Пример: mmap_grep("file.txt", "hello") → выводит позиции, где встречается "hello".
// Использовать: mmap, strstr, printf.
void mmap_grep(const char *filename, const char *word);
