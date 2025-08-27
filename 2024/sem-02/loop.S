// Задача: считать со строки ввода два числа и вывести их сумму
.intel_syntax noprefix
    .global main
main:
    // считать из строки ввода число в eax
    call    readi32
    // переложим считанное число в edi, чтобы можно было еще раз вызвать readi32
    // и потерять считанное ранее число
    inc     eax
    mov     r12d, eax 
    xor     ebx, ebx
loop:
    mov edi, ebx

    call writei32

    inc ebx

    cmp ebx, r12d

    jnz loop

    // завершаем выполнение
    call    finish
