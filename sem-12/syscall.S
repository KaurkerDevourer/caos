    #include <sys/syscall.h>
.intel_syntax noprefix
.text
    .global main
main:
    mov rax, SYS_exit
    mov rdi, 0

    syscall
