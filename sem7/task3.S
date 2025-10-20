.intel_syntax noprefix

.global asm_sum_and_swap

asm_sum_and_swap:

    push rbp
    mov rbp, rsp


    mov rax, [rdi]
    mov rcx, [rsi]
    mov [rdi], rcx
    mov [rsi], rax

    add rax, rcx

    leave
    ret


