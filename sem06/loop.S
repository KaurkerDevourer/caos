.intel_syntax noprefix
    .global main
main:
    call    readi32
    inc     eax
    mov     r12d, eax 
    xor     ebx, ebx
loop:
    mov edi, ebx

    call writei32

    inc ebx

    cmp ebx, r12d

    jnz loop

    call    finish
