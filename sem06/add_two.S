.intel_syntax noprefix
    .global main
main:
    call    readi32
    mov     ebx, eax 

    call    readi32

    add     ebx, eax
    mov     edi, ebx

    call    writei32
    call    finish
