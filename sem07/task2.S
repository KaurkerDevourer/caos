.intel_syntax noprefix

.global main
.extern printf

.section .rodata
    message:
        .string "Hello from Assembly! The number is %d\n"

.section .text
main:
    push rbp
    mov rbp, rsp

    lea rdi, [rip + message]
    mov rsi, 100

    call printf

    mov rax, 0
    pop rbp
    ret
