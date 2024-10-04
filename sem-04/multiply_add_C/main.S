// ** Условие **
// Написать программу которая вызывает функцию multiply_add(int a, int b)
// которая возвращает a * 2 + b и напечатать результат

.intel_syntax noprefix
    .global main
main:
    call readi64
    mov rdi, rax

    push rdi

    call readi64
    mov rsi, rax

    pop rdi

    call multiply_add

    mov rdi, rax
    call writei64

    call finish
