.intel_syntax noprefix
.text
.global dot_product

dot_product:
    push    rbp
    mov     rbp, rsp

    // size - rdi
    // double* - rsi
    // double* - rdx
    // rbx - counter
    xor     rbx, rbx
    // xmm0 - result
    xorpd   xmm0, xmm0

for:
    cmp    rdi, rbx
    je      fin

    // 1st double array
    movsd   xmm2, [rsi]
    // 2st double array
    movsd   xmm1, [rdx]
    mulsd   xmm2, xmm1
    addsd   xmm0, xmm2

    add    rsi, 8
    add    rdx, 8
    inc    rbx
    jmp    for
fin:
    mov     rbp, rsp
    pop     rbp
    ret
