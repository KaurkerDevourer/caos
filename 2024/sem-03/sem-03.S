.intel_syntax noprefix
    .global main
main:
    call readi64
    xor rbx, rbx
    inc rbx
    push rax
loop:
    mov rdi, [rsp]
    call readi64
    jc end
    cmp rax, [rsp]
    jnz pup
    dec rbx
    pop rax
    jmp loop
pup:
    inc rbx
    push rax
    jmp loop
end:
    cmp rbx, 0
    jnz bad
    mov rdi, 1
    jmp writing
bad:
    mov rdi, 0
writing:
    call writei64
    call finish
