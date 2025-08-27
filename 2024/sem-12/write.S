   // ** Условие **
   // Используя системные вызовы read, write напечатать 2 строки в stderr и stdout.

   #include <sys/syscall.h>

    // 0 stdin
    // 1 stdout
    // 2 stderr
.intel_syntax noprefix
.text
    .global main
main:

   // ssize_t write(int fd, const void *buf, size_t count);
   mov      rax, SYS_write
   mov      rdi, 1
   lea      rsi, [rip + hello_out]
   // Чтобы получить длину строки, можно использовать знание, что метки содержат адреса,
   // поэтому разность меток - разность адресов, то есть размер области памяти между метками, то есть длина строки
   mov      rdx, hello_out_end - hello_out
   syscall

   // ssize_t write(int fd, const void *buf, size_t count);
   mov      rax, SYS_write
   mov      rdi, 2
   lea      rsi, [rip + hello_err]
   mov      rdx, hello_err_end - hello_err
   syscall

   // void _exit(int status);
    mov rax, SYS_exit
    mov rdi, 4

    syscall
.data
hello_out:
    .ascii  "hello from stdout\n"
hello_out_end:

hello_err:
    .ascii  "hello from stderr\n"
hello_err_end:
