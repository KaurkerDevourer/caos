.intel_syntax noprefix
    .global main
    .extern add_nums
main:
    push rbp
    mov rbp, rsp
    mov rdi, 50
    mov rsi, 100
    call add_nums
    mov rax, 0
    pop rbp
    ret
