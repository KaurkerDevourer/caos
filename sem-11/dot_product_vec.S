.intel_syntax noprefix
.text
.global dot_product_vec

dot_product_vec:
    push    rbp
    mov     rbp, rsp

    // size - rdi
    // double* - rsi
    // double* - rdx
    // rbx - counter
    // xmm0 - result
    dec rdi
    xorpd   xmm0, xmm0

for:
    cmp     rdi, 1
    jl      fin

    // 1st double array
    movupd   xmm2, [rsi]
    // 2st double array
    movupd   xmm1, [rdx]
    mulpd   xmm2, xmm1
    addpd   xmm0, xmm2

    add    rsi, 16
    add    rdx, 16
    sub    rdi, 2
    jmp    for
fin:
    haddpd  xmm0, xmm0
    cmp rbx, 1
    jne end


    movsd   xmm2, [rsi]
    // 2st double array
    movsd   xmm1, [rdx]
    mulsd   xmm2, xmm1
    addsd   xmm0, xmm2
end:
    mov     rbp, rsp
    pop     rbp
    ret
