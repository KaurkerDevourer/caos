.intel_syntax noprefix
.text
    .global thypot
thypot:
        push    rbp
        mov     rbp, rsp

        mulsd   xmm0, xmm0
        mulsd   xmm1, xmm1
        addsd   xmm0, xmm1
        sqrtsd  xmm0, xmm0

        // xmm0 -> sqrt(a^2 + b^2)

        mov     rsp, rbp
        pop     rbp
        ret
