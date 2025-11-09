.intel_syntax noprefix
    .global main
main:
    call    readi32
    cmp     eax, 12
    jz else
    mov edi, 1
    jmp end
else:
    mov edi, 0
end:
    call writei32

    call    finish
