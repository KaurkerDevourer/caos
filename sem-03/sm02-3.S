.intel_syntax noprefix
    .global main
main:
    call  readi64
    mov   rdi, rax
    add   rdi, [rip + delta]
    call  writei64
    call  finish
delta:
    .quad 42
