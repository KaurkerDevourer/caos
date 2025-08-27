// ** Условие **
// Написать функцию, которая примет аргументами a и b, вычислит
// a * 2 + b и вернуть значение

.intel_syntax noprefix
    .global multiply_add
multiply_add:
    push rbp
    mov rbp, rsp

    shl rdi, 1
    add rdi, rsi
    mov rax, rdi

    pop rbp
    ret
